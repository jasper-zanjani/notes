# Azure IAM

Azure methods of administering access to resources can be divided into two groups

- [**Role-Based Access Controls (RBAC)**](Cloud/Azure-IAM) are supported only by Azure Portal and the ARM APIs. 
RBAC is configured by selecting a **role** and associating it with a **security principal**, such as a user, group, or service identity. 
Child reosurces inherit the roles of their parents ("role inheritance").
- [Classic subscription administrators](#classic-subscription-administrators)

## Classic subscription administrators

Classic subscription administrators have full access to a subcription. 
They can access resources through Azure Portal, ARM APIs (PowerShell and CLI), and classic deployment model APIs. 
By default, the account that is used to sign up for a subscription is automatically set as both **Account Administrator** and **Service Administrator**. 
There can only be one Account Administrator per account and only 1 Service Administrator per subscription. 
**Co-Administrators** have the same access as Service Administrators, and there can be 200 of them per subscription, but cannot change the association of subscriptions to directories.

## Roles

Components of a role assignment include:

- **Security principal**: objects associated with a role definition and a scope to apply RBAC to azure resources (i.e. a user, group, service principal, or **managed identity** which is an application registration that is managed automatically by Azure and an Azure service)
    - **User principal**: identity associated with a user or group of users.
    - **Service principal**: identity associated with an application.
- [**Role definition**](#role-definition): list of permissions which define what actions can or cannot be performed against a resource. In addition to the 4 foundational [built-in roles](#built-in-roles), there are many other built-in roles and custom roles can be defined using a JSON file.
- [**Scope**](#scopes)

### Scopes

There are **four** scopes at which RBAC can be applied:

- Management group
- Subscriptions
- Resource groups
- Resources

![](/img/rbac-scopes.png)

Azure RBAC roles can be used to grant rights to 2 types of principals:

- **User principal**: identity associated with a user or group of users.
- **Service principal**: identity associated with an application.

RBAC roles can also be applied to a subscription through **Management Groups**, which represent the recommended practice for ensuring consistent application of tenant-wide security. Management groups form a hierarchy where each child inherits policy from its single parent while having additional controls. There is a single Management Group at the root of the hierarchy, associated with the Azure AD tenant (which is associated, in turn, with a subscription) that cannot be moved or deleted. 


### Role assignments

Current assignments for classic admins can be seen in the **Properties blade** of a subscription in Azure Portal. Co-Administrator assignments can be added by opening the **Access Control (IAM)** blade of a subscription, then clicking the **Add co-administrator** button.

RBAC roles are supported only by Azure Portal and the ARM APIs. 
Access policy is applied to a **scope**, which includes subscriptions, resource groups, or resources: a policy applied to a subscription is said to be at the "subscription scope". 
Policy can also be applied to Management Groups, which is an additional scope above subscription. 
In this way, several subscriptions can inherit a single policy through a Management Group.

RBAC roles can also be applied to a subscription through **Management Groups**, which represent the recommended practice for ensuring consistent application of tenant-wide security. 
Management groups form a hierarchy where each child inherits policy from its single parent while having additional controls. 
There is a single Management Group at the root of the hierarchy, associated with the Azure AD tenant (which is associated, in turn, with a subscription) that cannot be moved or deleted. 

### Role definitions

Custom roles configure two types of privileges and are specified by two different properties of the definition JSON file: Management and Data. This provides safety from allowing unrestricted access to data.

The values of these properties is an array of strings, each of which follows the format `Company.ProviderName/ResourceType/Action` where `action` can be of values `read`, `write`, `action`, `delete`, or `*`.

| Privilege      | Property that defines allowed permissions | Property that defines denied permissions |
| -------------- | ----------------------------------------- | ---------------------------------------- |
| **Management** | `Actions`                                 | `NotActions`                             |
| **Data**       | `DataActions`                             | `NotDataActions`                         |

=== "Unrestricted"

    ```json
    "Actions": [
      "*"
    ]
    ```

=== "Network resources (read only)"

    ```json
    "Actions": [
      "Microsoft.Network/*/read"
    ]
    ```

Example role definitions:

=== "Contributor"

    ```json
    {
      "Name": "Contributor",
      "Id": "b24988ac-6180-42a0-ab88-20f7382dd24c",
      "IsCustom": false,
      "Description": "Lets you manage everything except access to resources.",
      "Actions": [
        "*"
      ],
      "NotActions": [
        "Microsoft.Authorization/*/Delete",
        "Microsoft.Authorization/*/Write",
        "Microsoft.Authorization/elevateAccess/Action",
        "Microsoft.Blueprint/blueprintAssignments/write",
        "Microsoft.Blueprint/blueprintAssignments/delete"
      ],
      "DataActions": [],
      "NotDataActions": [],
      "AssignableScopes": [
        "/"
      ]
    }
    ```

Some built-in roles:

- **Owner** has full access to all resources and **can** delegate access. Service Administrator and Co-Administrators are assigned this role at the subscription scope.
- **Contributor** can create and manage all resources (full read/write privileges), but **cannot** delegate access.
- **Reader** can view resources.
- [Cost Management Contributor][Cost Management Contributor]
- [Cost Management Reader][Cost Management Reader]
- [Resource Policy Contributor][Resource Policy Contributor]
- [User Administrator][User Administrator]
- [User Access Administrator][User Access Administrator]


# Tasks

### Create assignment

Assign the Owner role to a user at the subscription scope

- Navigate to resource group > Access Control (IAM) > Role Assignments tab > Add > Add Role Assignment
- Open Subscription > Access Control (IAM) > Add Role Assignment> select a Role > Select target principal

1. **Access control (AIM)** pane > **Add** > **Add role assignment**
2. Select a role in the **Role** dropdown and a user in the **Select** field. Then **Save**

=== "Azure Portal"

    ![](/img/add-role.png)


=== "PowerShell"

    ```powershell
    # Resource group scope
    New-AzRoleAssignment 
        -SignInName "rbacuser@example.com" 
        -RoleDefinitionName "Virtual Machine Contributor" 
        -ResourceGroupName ExamRefRG

    # Subscription scope
    New-AzRoleAssignment 
        -SignInName "rbacuser@example.com" 
        -RoleDefinitionName "Owner" 
        -Scope "/subscriptions/$subId"
    ```

=== "Azure CLI"

    ```sh
    # Resource group scope
    az role assignment create 
        --assignee "rbacuser@example.com" 
        --role "Virtual Machine Contributor" 
        --resource-group ExamRefRG

    # Subscription scope
    az role assignment create 
        --assignee "rbacuser@example.com" 
        --role "Owner" 
        --subscription $subId
    ```

### Delete assignment

Navigate to resource group > **Access Control (IAM)** > **Role Assignments** tab > Select one or more security principals > **Remove**

Remove RBAC assignments from a user

=== "Azure PowerShell"

    ```powershell
    Remove-AzRoleAssignment -SignInName "cloudadmin@opsgility.onmicrosoft.com" -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG

    Remove-AzRoleAssignment -SignInName $u -ResourceGroupName $rgName -RoleDefinitionName "Virtual Machine Contributor" 
    ```

Azure AD group
```powershell
$g = Get-AzADGroup -SearchString "Cloud Admins"
Remove-AzRoleAssignment -ObjectId $g.Id -ResourceGroupName $rg -RoleDefinitionName "Virtual Machine Contributor" 
```

```sh
az role assignment delete --assignee $u --resource-group $rg --role "Virtual Machine Contributor" 
```
Azure AD group
```sh
g=$(az ad group list --query "[?displayName=='Cloud Admins'].objectId" -o tsv)
az role assignment delete --role "Virtual Machine Contributor" -–assignee-object-id $g --resource-group $rg
```

Read assignment

=== "Azure PowerShell"

    ```powershell
    Get-AzRoleDefinition -Name "Virtual Machine Contributor" | ConvertTo-Json
    ```

=== "Azure CLI"

    ```sh
    az role definition list -n "Virtual Machine Contributor"
    ```

List custom roles available for assignment

=== "Azure PowerShell"

    ```powershell
    Get-AzRoleDefinition | Where-Object { $_.IsCustom -eq $true }
    ```

=== "Azure CLI"

    ```sh
    az role definition list --custom-role-only -o table
    ```

View all role assignments in a subscription
```sh
az role assignment list --all
```

Create role definition

=== "Azure PowerShell"

    ```powershell
    New-AzRoleDefinition -InputFile "C:\ARM_templates\customrole1.json"
    ```
    
### Configure cost center quotas and tagging

Grant an AD group RBAC rights

=== "Azure PowerShell"

    ```powershell
    $group = Get-AzADGroup -SearchString "Cloud Admins"
    New-AzRoleAssignment -ObjectId $group.Id -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG
    ```
    

Remove RBAC assignments from a group

=== "Azure PowerShell"

    ```powershell
    $adGroup = Get-AzADGRoup -SearchString "Cloud Admins"
    Remove-AzRoleAssignment 
        -ResourceGroupName $rgName
        -ObjectId $adGroup.Id 
        -RoleDefinitionName "Virtual Machine Contributor" 
    ```


### Elevate permissions
For [Azure AD](Azure-AD) Global Administrators who want to temporarily elevate permissions 

1. Sign into Azure portal as an Azure AD Global Administrator.<sup>[?](https://docs.microsoft.com/en-us/learn/modules/manage-subscription-access-azure-rbac/4-exercise-elevate-permissions)</sup>
2. Navigate to **Azure Active Directory** > **Properties**. At the bottom of the page, under "Access management for Azure resources" click **Yes** then **Save**.
![](/img/aad-elevate.png)
3. Sign out and sign in again.
4. [Assign roles](Assign-roles)
5. Revoke elevated access by returning to **Azure Active Directory** > **Properties** and selecting **No** under "Access management for Azure resources".

Sources

- [Elevating global administrator access](https://docs.microsoft.com/en-us/learn/modules/manage-subscription-access-azure-rbac/3-elevate-your-access-user-access-admin)
- [Understand Azure role definitions](https://docs.microsoft.com/en-us/azure/role-based-access-control/role-definitions)


#### SSPR

Administrator accounts are treated differently from other user accounts for SSPR and have a "strong default **two-gate** password reset policy", which requires two pieces of authentication data and foregoes the use of security questions.
