Azure Backup can backup on-prem servers, cloud-based VMs, and virtualized workloads like SQL Server and Sharepoint. 
However Azure SQL databases are already backed up by an automatic service by default. <sup>AZ-103 p. 159</sup>

On-prem machines can be backed up using several [agents](#agents) <sup>AZ-103 p. 162</sup>

- [MARS Agent](#mars-agent)
- System Center Data Protection Manager (DPM) or **Microsoft Azure Backup Server (MABS)** can be used as backup servers. The backup server can then be backed up to a [Recovery Services vault](#recovery-services-vault)

Azure VMs can be backed up

- Directly using an extension on the [**Azure VM Agent**](#azure-vm-agent), which comes preinstalled on Marketplace images
- Specific files and folders on a VM can be backed up by running the MARS agent
- To the MABS running in Azure, which can then be backed up to a Recovery Services vault

Storage accounts can be backed up, but **not** blob storage. Blob storage is already replicated locally, which provides fault-tolerance. Instead, you can use snapshots.


When installed, the `Get-AzVM` command exposes a `ProvisionVMAgent` property with a boolean value under `OSProfile.WindowsConfiguration`.

- 

## Containers

There appear to be resources that house items to be protected that can be [enumerated](#list-containers).

## Reports
Log Analytics workspaces must be located in the same region as the Recovery Services vault in order to store Backup reports.

## Pre-Checks
Azure Backup [pre-checks](https://azure.microsoft.com/en-us/blog/azure-vm-backup-pre-checks/) complete with various statuses that indicate potential problems

- **Passed**: VM configuration is conducive for successful backups
- **Warning**: Issues that **might** lead to backup failures
- **Critical**: Issues that **will** lead to backup failures

# Tasks

Create Recovery Services Vault

=== "Azure Portal"

    ![](/img/az-rsv-create.jpg)


=== "Azure PowerShell"

    ```powershell
    New-AzRecoveryServicesVault -Name $n -ResourceGroupName $rgName -Location $l
    ```
    
=== "Azure CLI"

    ```sh
    az backup vault create --name $n --resource-group $rgName --Location $l
    ```
    
Enable MFA

This requires [MFA](Azure-AD#enable-mfa) to be enabled.

=== "Azure Portal"

    ![](/img/az-rsv-prop.jpg)
    ![](/img/az-rsv-prop-security.jpg)
    
    Enable multi-factor authentication for the Recovery services vault by going to the vault in the Portal, then **Properties** > **Security settings: Update** > Choose **Yes** in the dropdown. An option to generate a security PIN will appear in this same blade.

Recover files

=== "Azure Portal"

    ![](/img/az-vm-backup.png)
    ![](/img/az-vm-backup-recovery.png)
    ![](/img/file-recovery-blade.png)

    Download the executable (for Windows VMs) or PowerShell script (for Linux VMs). A Python script is generated when downloading to a Linux machine.

### Configure Backup reports
Sources
- [Configure Azure Backup reports](https://docs.microsoft.com/en-us/azure/backup/configure-reports)

A Log Analytics workspace must exist.

1. Turn on [diagnostics](Monitoring#logs) in the Recovery Services vault
2. Select Archive to a storage account (**NOT** Send to Log Analytics), providing a storage account to store information needed for report.
3. Select `AzureBackupReport` under log section, which will collect all needed data models and information for the backup report.
4. Connect to Azure Backup in PowerBI using a service content pack.

![](/img/az-backup-report.png)

Define new backup protection policy

=== "Azure PowerShell"

    ```powershell
    $SchPol = Get-AzRecoveryServicesBackupSchedulePolicyObject -WorkloadType "AzureVM" 
    $SchPol.ScheduleRunTimes.Clear()
    $Dt = Get-Date
    $SchPol.ScheduleRunTimes.Add($Dt.ToUniversalTime())
    $RetPol = Get-AzRecoveryServicesBackupRetentionPolicyObject -WorkloadType "AzureVM" 
    $RetPol.DailySchedule.DurationCountInDays = 365
    New-AzRecoveryServicesBackupProtectionPolicy -Name "NewPolicy" -WorkloadType AzureVM -RetentionPolicy $RetPol -SchedulePolicy $SchPol
    ```

Configure VM backup

=== "Azure PowerShell"

    ```powershell
    $policy = Get-AzRecoveryServicesBackupProtectionPolicy -Name "DefaultPolicy"
    Enable-AzRecoveryServicesBackupProtection -ResourceGroupName $g -Name $n -Policy $policy
    ```

=== "Azure CLI"

    ```sh
    # GRS by default
    az backup protection enable-for-vm -g $g -v $v --vm vm --policy-name DefaultPolicy

    # LRS
    az backup vault backup-properties set -n $v -g $g --backup-storage-redundancy "LocallyRedundant"
    ```
    
Initiate VM backup

=== "Azure PowerShell"

    ```powershell
    $backupcontainer = Get-AzRecoveryServicesBackupContainer
        -ContainerType "AzureVM"
        -FriendlyName "myVM"

    $item = Get-AzRecoveryServicesBackupItem
        -Container $backupcontainer
        -WorkloadType "AzureVM"

    Backup-AzRecoveryServicesBackupItem -Item $item
    ```
`--container-name`/`-c` appears to accept the name of the VM itself.

=== "Azure CLI"

    ```sh
    az backup protection backup-now -g myResourceGroup -n myRecoveryServicesVault --container-name myVM
        --item-name myVM
        --retain-until 18-10-2017
        --backup-management-type AzureIaasVM
    ```
### List containers
`-BackupManagementType` accepts the following values
- `AzureVM`
- `MARS`
- `AzureWorkload`
- `AzureStorage`

`-ContainerType` accepts:
- `AzureVM`
- `Windows`
- `AzureSQL`
- `AzureStorage`
- `AzureVMAppContainer`

```powershell
$v = Get-AzRecoveryServicesVault -ResourceGroupName $rg -Name vault
Get-AzRecoveryServicesBackupContainer -ContainerType Windows -BackupManagementType MARS -VaultId $v.ID
```

This returns a list of JSON objects.
`--backup-management-type` accepts the following values:
- `AzureIaasVM`
- `AzureStorage`
- `AzureWorkload`
```sh
az backup container list -g $g -v $v --backup-management-type AzureIaasVM
```
Preserve only the "name" attribute of the first item, which itself is a semicolon-delimited string of values. ([Start backup now](#backup-vm))
```sh
az backup container list -g $g -v $v --backup-management-type AzureIaasVM --query [0].name
```
# Sources
- AZ-103: [<code>2.4</code>](AZ-103#24-implement-azure-backup "Implement Azure Backup")
- AZ-104: [<code>5.2</code>](AZ-104#52-implement-backup-and-recovery "Implement backup and recovery")

- [Azure Backup architecture and components](https://docs.microsoft.com/en-us/azure/backup/backup-architecture)
- [Azure Virtual Machine Agent overview](https://docs.microsoft.com/en-us/azure/virtual-machines/extensions/agent-windows)
- [Understanding and using the Azure Linux Agent](https://docs.microsoft.com/en-us/azure/virtual-machines/extensions/agent-linux)
- [Restore files from VM](https://docs.microsoft.com/en-us/azure/backup/backup-azure-restore-files-from-vm)
- Back up a VM - [Azure CLI](https://docs.microsoft.com/en-us/azure/backup/quick-backup-vm-cli), [PowerShell](https://docs.microsoft.com/en-us/azure/backup/quick-backup-vm-powershell)
- [`Get-AzRecoveryServicesBackupContainer`](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/get-azrecoveryservicesbackupcontainer?view=azps-4.8.0)
- [`New-AzRecoveryServicesBackupProtectionPolicy`](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/new-azrecoveryservicesbackupprotectionpolicy?view=azps-4.8.0)
- [`az backup container list`](https://docs.microsoft.com/en-us/cli/azure/backup/container?view=azure-cli-latest#az_backup_container_list)
