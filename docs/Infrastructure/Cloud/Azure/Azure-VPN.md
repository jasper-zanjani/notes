### Authentication

Azure P2S VPN connections support several authentication methods:

- Azure AD authentication (Windows 10 only)
- RADIUS server
- VPN Gateway native certificate authentication

The VPN gateway acts as a pass-through forwarding authentication messages between the connecting device and the RADIUS server. The RADIUS server can be deployed on-premises or in the Azure VNet, and two such servers can be deployed for high availability.

- If deployed on-premises, a S2S VPN to the site is required, and ExpressRoute is not usable.
- AD domain authentication requires a RADIUS server that integrates with the AD server.

# Tasks
### Create local network gateway

```powershell
$localnw = New-AzLocalNetworkGateway -Name LocalNetGW -ResourceGroupName ExamRefRG -Location "West Europe" -GatewayIpAddress "53.50.123.195" -AddressPrefix "10.5.0.0/16" 
```
Create VPN connection
```powershell
$gateway = Get-AzVirtualNetworkGateway -Name VPNGW1 -ResourceGroupName ExamRefRG
$conn = New-AzVirtualNetworkGatewayConnection -Name OnPremConnection -ResourceGroupName ExamRefRG -Location 'West Europe' -VirtualNetworkGateway1 $gateway -LocalNetworkGateway2 $localnw -ConnectionType IPsec -SharedKey "abc123"
```
### Create a VPN Gateway

```powershell
$rg = ExamRefRG
```
Create gateway subnet in VNet1
Gateway subnets are normal subnets with the name "GatewaySubnet"
```powershell
$vnet1 = Get-AzVirtualNetwork -Name VNet1 -ResourceGroupName $rg
$vnet1.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.1.1.0/27
$vnet1 = Set-AzVirtualNetwork -VirtualNetwork $vnet1
```
Create VPN gateway in VNet1
```powershell
$gwpip = New-AzPublicIpAddress -Name VNet1-GW-IP -ResourceGroupName $rg -Location 'North Europe' -AllocationMethod Dynamic
$gwsubnet = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet1
$gwipconf = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf -Subnet $gwsubnet -PublicIpAddress $gwpip
$vnet1gw = New-AzVirtualNetworkGateway -Name VNet1-GW -ResourceGroupName $rg -Location 'North Europe' -IpConfigurations $gwipconf -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```

Create gateway subnets in VNet2 and VNet3
```sh
az network vnet subnet create --name GatewaySubnet --vnet-name VNet1 --resource-group ExamRefRG --address-prefixes 10.1.1.0/27
az network public-ip create --name VNet1-GW-IP --resource-group ExamRefRG --location NorthEurope
az network vnet-gateway create --name VNet1-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet1 --public-ip-addresses VNet1-GW-IP --location NorthEurope
```
### Create a VPN gateway and VNet peering

Create gateway subnets in VNet2 and VNet3
```powershell
$vnet2 = Get-AzVirtualNetwork -Name VNet2 -ResourceGroupName ExamRefRG
$vnet2.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.2.1.0/27
$vnet2 = Set-AzVirtualNetwork -VirtualNetwork $vnet2
$vnet3 = Get-AzVirtualNetwork -Name VNet3 -ResourceGroupName ExamRefRG
$vnet3.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.3.1.0/27
$vnet3 = Set-AzVirtualNetwork -VirtualNetwork $vnet3
```
Create VPN gateway in VNet2
```powershell
$gwpip2 = New-AzPublicIpAddress -Name VNet2-GW-IP -ResourceGroupName ExamRefRG -Location $vnet2.Location -AllocationMethod Dynamic
$gwsubnet2 = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet2
$gwipconf2 = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf2 -Subnet $gwsubnet2 -PublicIpAddress $gwpip2
$vnet2gw = New-AzVirtualNetworkGateway -Name VNet2-GW -ResourceGroupNAme ExamRefR -Location $vnet2.Location -IpConfigurations $gwipconf2 -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```
Create VPN gateway in VNet3
```powershell
$gwpip3 = New-AzPublicIpAddress -Name VNet3-GW-IP -ResourceGroupName ExamRefR -Location $vnet3.Location -AllocationMethod Dynamic
$gwsubnet3 = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet3
$gwipconf3 = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf3 -Subnet $gwsubnet3 -PublicIpAddress $gwpip3
$vnet3gw = New-AzVirtualNetworkGateway -Name VNet3-GW -ResourceGroupNAme ExamRefRG -Location $vnet3.Location -IpConfigurations $gwipconf3 -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```
Create connections
```powershell
New-AzVirtualNetworkGatewayConnection -Name VNet2-to-VNet3 -ResourceGroupName ExamRefRG -Location $vnet2.Location -VirtualNetworkGateway1 $vnet2gw -VirtualNetworkGateway2 $vnet3gw -ConnectionType VNet2VNet -SharedKey "secretkey123"
New-AzVirtualNetworkGatewayConnection -Name VNet3-to-VNet2 -ResourceGroupName ExamRefRG -Location $vnet3.Location -VirtualNetworkGateway1 $vnet3gw -VirtualNetworkGateway2 $vnet2gw -ConnectionType VNet2VNet -SharedKey "secretkey123"
```

Create gateway subnets in VNet2 and VNet3
```sh
az network vnet subnet create --name GatewaySubnet --vnet-name VNet2 --resource-group ExamRefRG --address-prefixes 10.2.1.0/27
az network vnet subnet create --name GatewaySubnet --vnet-name VNet3 --resource-group ExamRefRG --address-prefixes 10.3.1.0/27
```
Create public IP addresses for use by VPN gateways
```sh
az network public-ip create --name VNet2-GW-IP --resource-group ExamRefRG --location NorthEurope
az network public-ip create --name VNet3-GW-IP --resource-group ExamRefRG --location WestEurope
```
Create VPN gateways in VNet2 and VNet 3
```sh
az network vnet-gateway create 
    --name VNet2-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet2 --public-ip-addresses VNet2-GW-IP --location NorthEurope
az network vnet-gateway create 
    --name VNet3-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet3 --public-ip-addresses VNet3-GW-IP --location WestEurope
```
Create connections between VPN gateways
```sh
az network vpn-connection create --name VNet2-to-VNet3 --resource-group ExamRefRG --vnet-gateway1 VNet2-GW --vnet-gateway2 VNet3-GW --shared-key secretkey123 --location NorthEurope
az network vpn-connection create --name VNet3-to-VNet2 --resource-group ExamRefRG --vnet-gateway1 VNet3-GW --vnet-gateway2 VNet2-GW --shared-key secretkey123 --location WestEurope
```
### Use VPN Troubleshoot

Get the Network Watcher resource
```powershell
$nw = Get-AzResource | Where ResourceType -eq Microsoft.Network/networkWatchers -and Location -eq WestEurope
$networkWatcher = Get-AzNetworkWatcher -Name $nw.Name -ResourceGroupName $nw.ResourceGroupName
```

Get the connection to troubleshoot
```powershell
$connection = Get-AzVirtualNetworkGatewayConnection -Name Vnet1-to-Vnet2 -ResourceGroupName ExamRefRG
```

Start VPN Troubleshoot

```powershell
Start-AzNetworkWatcherResourceTroubleshooting -NetworkWatcher $networkWatcher -TargetResourceId $connection.Id -StorageId $sa.Id -StoragePath "$($sa.PrimaryEndpoints.Blob)$($sc.name)"
```

Create a storage account and container for logs

```sh
az storage account create --name examrefstorage --location westeurope --resource-group ExamRefRG --sku Standard_LRS
az storage account keys list --resource-group ExamRefRG --account-name examrefstorage
az storage container create --account-name examrefstorage --account-key {storageAccountKey} --name logs
```

Start VPN Troubleshoot

```sh
az network watcher troubleshooting start --resource-group ExamRefRG --resource Vnet1-to-Vnet2 --resource-type vpnConnection --storage-account examrefstorage --storage-path https://examrefstorage.blob.core.windows.net/logs --output json
```
### Create S2S VPN
AZ-103: 395
```
$lgwip = 53.50.123.195
$key = "abc123"
```
```powershell
$lgw = New-AzLocalNetworkGateway -ResourceGroupName $g -Name $n -Location $l -GatewayIpAddress $lgwip -AddressPrefix "10.5.0.0/16"
$vgw = Get-AzVirtualNetworkGateway -ResourceGroupNAme -Name
New-AzVirtualNetworkGatewayConnection -ResourceGroupName $g -Name $n -Location $l -VirtualNetworkGateway1 $vgw -LocalNetworkGateway2 $lgw -ConnectionType IPsec -SharedKey $key
```
```sh
az network local-gateway create --gateway-ip-address $lgwip --name LocalNetGW --resource-group ExamRefRG --local-address-prefixes 10.5.0.0/16
az network vpn-connection create --name OnPremConnection --resource-group ExamRefRG --vnet-gateway1 VPNGW1 --location WestEurope --shared-key $key --local-gateway2 LocalNetGW
```

Sources

- [VPN Gateway design](https://docs.microsoft.com/en-us/azure/vpn-gateway/design)
- [Connect Azure VPN gateways to multiple on-premises policy-based VPN devices](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-connect-multiple-policybased-rm-ps)
- [About VPN Gateway configuration settings](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings)
- [Highly available cross-premises and VNet-to-VNet connectivity](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-highlyavailable)
- [ExpressRoute connectivity models](https://docs.microsoft.com/en-us/azure/expressroute/expressroute-connectivity-models)
- Connect a computer to a virtual network using P2S and RADIUS authentication: [PowerShell](https://docs.microsoft.com/en-us/azure/vpn-gateway/point-to-site-how-to-radius-ps)