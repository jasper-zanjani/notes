

**Azure Load Balancers** are used to distribute inbound traffic across a pool of backend servers running in a VNet. 
They are defined by connecting a [**frontend**](#frontend) and **backend pool** configurations with **rules**.
- **Backend Address Pool**
- **Health Probe**, specifying port and interval, can be of types TCP, HTTP, and (Standard SKU only) HTTPS
  - HTTP and HTTPS probes will return an unhealthy status if a HTTP status code other than 200 is received.
- **Load Balancer Rule** defines how a frontend address and port is mapped to the destination port and address on the backend

Load Balancers are available in **Basic** and **Standard** SKUs.

- Standard load balancers **require a Standard Public IP** unless they are intended for internal use only. 
Standard Public IPs do not allow any inbound communication by default and must have network security rules configured. Only Standard Health Probes support HTTPS.
- Basic backend SKUs must be comprised of either a single VM, VMs in the same availability set, or a VM scale set. Basic 

By default, Azure Load Balancer is set to timeout idle TCP connections after 4 minutes, but this can be [configured](#configure-tcp-reset).

Azure load balancing rules route based on a **5-tuple hash**, calculated from source and destination IP addresses and ports, as well as protocol. This means that traffic from any IP address will typically go to the same backend node, resulting in a modicum of **affinity** that can be [configured](#specify-affinity).

## Frontend

A frontend is defined by a 3-tuple composed of an IP address, a transport protocol, and a port number. Multiple frontends can be assigned to a load balancer to serve multiple websites or services.

There are two modes:

- Internal, where the frontend references a subnet and an IP address from that subnet is allocated statically or dynamically
- Public, where a **Public IP Address** resource is used to receive inbound traffic. 
If the LB is at Standard SKU, then the IP must also be at Standard.

If the backend resources of a load balancer don't have instance-level public IP (ILPIP) addresses, they establish outbound connectivity via the frontend IP of the public load balancer. 

## Backend

Any VM can only be a member of the backend pool of a single internal load balancer and simultaneously a single external load balancer. 
But a VM may not be a member of more than one external load balancer, nor more than one internal load balancer.

Basic SKU Backend pools must comprise either a single VM or VMs in the same [**availability set**](VM#high-availability) or [**scale set**](VM#high-availability).
Only Standard SKU backends can accept VMs in a single VNet that are not explicitly assigned to an availability set.

## Outbound connections

## Floating IP

Floating IP is Azure's term for **Direct Server Return (DSR)**, which refers to the ability of nodes normally behind a load balancer to respond directly to client requests without overburdening the load balancer with return traffic. This prevents the load balancer from becoming a bottleneck.

Technically, Azure Load Balancer always operates in a DSR flow topology even if Floating IP is not enabled, using the VMs' own IP addresses. When enabled, Floating IP changes the IP address mapping to the Frontend IP address of the load balancer.

# Tasks


### Create internal load balancer

```powershell
$ip = "10.0.0.20"
$frontendIP = New-AzLoadBalancerFrontendIpConfig -Name frontend -PrivateIpAddress $ip
```

### Add to backend address pool

The process in PowerShell, counterintuitively, is actually to modify the VM's NIC to add a reference to the backend pool. <sup>AZ-103: p. 365</sup>

```powershell
$vm = Get-AzVM -Name VM1 -ResourceGroupName $g
$vmnic = Get-AzNetworkInterface -ResourceGroupName $g | where {$_.VirtualMachine.Id -eq $vm.Id}
$lb = Get-AzLoadBalancer -Name ExamRefLB -ResourceGroupName $g
$backend = Get-AzLoadBalancerBackendAddressPoolConfig -Name ExamRefBackEndPool -LoadBalancer $lb

# All IP configuration settings of the NIC have to be reapplied, there is no support for incremental changes
$ipconfig = Get-AzNetworkInterfaceIpConfig -Name ipconfig1 -NetworkInterface vm1nic
Set-AzNetworkInterfaceIpConfig -Name ipconfig1 -NetworkInterface $vm1nic -SubnetId $ipconfig.Subnet.Id -LoadBalancerBackendAddressPoolId $backend.Id
Set-AzNetworkInterface -NetworkInterface $vm1nic
```
Azure CLI supports incremental update of the NIC, which makes this command simpler than its PowerShell equivalent.
```sh
az network nic ip-config address-pool add --resource-group ExamRefRG --address-pool ExamRefBackEndPool --lb-name ExamRefLB --nic-name vm1-nic --ip-config-name ipconfig1
```
### Configure TCP reset
TCP timeout values should be greater than that used for TCP keepalives. A [new load balancing rule config object](https://docs.microsoft.com/en-us/powershell/module/az.network/new-azloadbalancerruleconfig?view=azps-5.0.0) can have idle timeout set on declaration.
```powershell
New-AzLoadBalancerRuleConfig -Name "MyLBRule" -FrontendIpConfiguration $fe -BackendAddressPool $be -Probe $hp -Protocol TCP -FrontendPort 80 -BackendPort 80 `
  -IdleTimeoutInMinutes 15 -EnableTcpReset
```
These can be manually changed on the load balancing object as well
```powershell
$lb = Get-AzLoadBalancer -Name "myLoadBalancer" -ResourceGroup "myResourceGroup"
$lb.LoadBalancingRules[0].IdleTimeoutInMinutes = '15'
$lb.LoadBalancingRules[0].EnableTcpReset = 'true'
Set-AzLoadBalancer -LoadBalancer $lb
```
```sh
az network lb rule update -g $g -n MyLBRule --lb-name myLoadBalancer 
  --idle-timeout 15 --enable-tcp-reset true
```
### Specify affinity
In the Azure Portal, affinity is specified in the **Session persistence** dropdown.

In Azure PowerShell and CLI, the option is the **load distribution** named parameter
- `New-AzLoadBalancerRuleConfig `[**`-LoadDistribution`**](https://docs.microsoft.com/en-us/powershell/module/az.network/new-azloadbalancerruleconfig?view=azps-5.0.0)
- `az network lb rule create `[**`--load-distribution`**](https://docs.microsoft.com/en-us/cli/azure/network/lb/rule?view=azure-cli-latest#az_network_lb_rule_create)

Sources:

- [Multiple frontends for Azure Load Balancer](https://docs.microsoft.com/en-us/azure/load-balancer/load-balancer-multivip-overview)
- [SNAT for outbound connections](https://docs.microsoft.com/en-us/azure/load-balancer/load-balancer-outbound-connections)
- [Azure Load Balancer Floating IP configuration](https://docs.microsoft.com/en-us/azure/load-balancer/load-balancer-floating-ip)
- AZ-103: p. 358
