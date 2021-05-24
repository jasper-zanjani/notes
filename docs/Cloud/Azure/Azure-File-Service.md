# Azure File Service

### Mount Azure File Share
#### Windows

Connect to and mount an Azure File Share (Windows File Explorer)

1. Right-click on **This PC**
2. Click **Map Network Drive** option
3. Specify drive letter to be used 
4. Specify folder: `\\<storageAccount>.files.core.windows.net\<shareName>`
5. Click **Finish**
6. In the dialog box that opens login with the username: `AZURE\<storageName>`
7. Password should be access key for the storage account

```cmd
net use x \\erstandard01.file.core.windows.net\logs /u:AZURE\erstandard01 <accessKey>
```
Automatically reconnect after reboot in Windows
```
cmdkey /add:storageAccountName.file.core.windows.net /user:AZURE\storageAccountName /pass:storageAccountKey
```

```powershell
$storageKey = (Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageNAme).Value[0]
$acctKey = ConvertTo-SecureString -String $storageKey -AsPlainText -Force
$credential = New-Object System.Management.Automation.PSCredential -ArgumentList "Azure\$storageName", $acctKey
New-PSDrive -Name "Z" -PSProvider FileSystem -Root "\\$storageName.file.core.windows.net\$shareName" -Credential $credential
```

#### Linux

Mounting to `/logs`
```sh
sudo mount -t cifs //$storageAccount.file.core.windows.net/logs /logs -o "vers=3.0,username=$storageAccount,password=$storageAccountKey,dir_mode=0777,file_mode=0777,sec=ntlmssp"
```
# Sources:
- [Deploy Azure File Sync](https://docs.microsoft.com/en-us/azure/storage/files/storage-sync-files-deployment-guide?tabs=azure-powershell%2Cproactive-portal)
- AZ-103: p. 148