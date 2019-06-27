# AZ-103 Azure Administrator Exam Certification

## 1 Hello and welcome to AZ-103 course

## 2 Frequently asked questions

## 3 Multi-channel learning and other resources
  - [Microsoft Learn](https://docs.microsoft.com/en-us/learn/)
  - [Microsoft Hands-on Labs](https://www.microsoft.com/handsonlabs/)
  - [Microsoft Azure Portal](https://portal.azure.com/#home): create a Storage account
  - [Microsoft Documentation](https://docs.microsoft.com/en-us/azure)

## 9 Memorizing PowerShell and CLI commands
Patterns and similarities in Azure PowerShell and CLI commands

PowerShell                      | CLI
:---                            | :---
__`Get`__`-AzVM`                | `az vm` __`list`__
__`New`__`-AzVM`                | `az vm` __`create`__
__`Remove`__`-AzVM`             | `az vm` __`delete`__
`Get-Az`__`VirtualNetwork`__    | az network vnet list
`New-Az`__`VirtualNetwork`__    | az network vnet create
`Remove-Az`__`VirtualNetwork`__ | az network vnet delete

## 10 Details about PowerShell and CLI for managing Azure

__PowerShell__ is available on Windows machines for local use. __PowerShell Core__ is a cross-platform version of PowerShell available for many different systems. __Azure CLI__ is also cross-platform. There are also __Azure-specific modules__ for both of these.

__Azure Cloud Shell__ requires an __Azure file share__ to run. It is accessible from within the browser, clicking the terminal icon. The CLI commands also work within PowerShell.

Microsoft recently switched from the __AzureRM__ to the __Az__ module. They cannot both be installed in the same instance of PowerShell, but you can have two different versions of Powershell installed if you need the __AzureRM__ module instead of the newer __Az__ one.

Syntax | Effect
:---  | :---
`Install-Module -Name Az -AllowClobber` | Install or update __Az__ module
`Connect-AzAccount` | login to Azure account

### Assignment: 
- [x] Install __PowerShell Core 6.2__ from GitHub and install __Az__ module.

## 11 Live Demo: installing PowerShell Core with Az Module

## 12 Assign administrator permissions

GUI interaction
:---
Azure Portal > Access control (IAM) > Add > Add role assignment
__Add permissions__ modal dialog box
In __Role__ select __Owner__

By default, the owner of the account is added to __Access control (IAM)__

## 13 Cost Center and tagging
3 basic ways of managing costs:
  1. __Resource groups__
  2. __Tags__ allow you to assign billing codes to individual resources
  3. __Multiple subscriptions__

__Policy__ can enforce tags or tag inheritance

## 14 Managing policy 

PowerShell                          | CLI                   | Effect
:---                                | :---                  | :---
`Register-AzureRmResourceProvider`  |                       | register a new resource provider
`New-AzureRmPolicyDefinition`       | `az policy create`    | define a new policy
`New-AzureRmPolicyAssignment`       | `az policy assignment`| assign the new policy to the account

## Azure policy
Azure policy isn't limited to tagging, but can be used to define policies that will enforce corporate standards and service-level agreements (SLA) across all or specific resources. These can be restricted to particular geographic locations, virtual machines, etc.


