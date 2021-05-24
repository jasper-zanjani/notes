#### Azure AD

**Azure AD** has its own set of roles which apply to Azure AD resources and which are distinct from those of Azure [RBAC](#iam).

The terms **tenant** and **directory** are deeply connected and often confused with one another. 

- A tenant refers to an instance of Azure AD that is tied to a subscription, and refers to the organization.
- Each tenant is associated with a dedicated and trusted directory that includes the tenant's users, groups, and apps.

Roles:

- **Global Administrator** can manage access to administrative features in AAD and can grant administrator roles to other users. An AAD Global Administrator **can also [temporarily elevate](RBAC#elevate-permissions) their own access to the Azure RBAC role of User Access Administrator in order to manage all Azure subscriptions and management groups**. Whoever signs up for the directory is automatically assigned this role.
- Device administrator

In order to make sure AD users can change their password either locally or in the cloud, Azure AD has to be upgraded to **Premium**. **Enterprise State Roaming** allows users to securely synchronize user settings and application settings to Azure.

**Self-Service Password Reset (SSPR)** is supported for all users. SSPR registration can be configured by group or for all domain users, but **not** individual users.

## B2B
**Business-to-business (B2B)** collaboration allows you to invite **guest users** into your own ([What is guest user access in Azure Active Directory B2B?](https://docs.microsoft.com/en-us/azure/active-directory/external-identities/what-is-b2b))

## Joining a device
When you join a device to an Azure AD tenant's domain, Azure AD creates local administrator accounts on the device for:
- The user joining the device
- The Azure AD global administrator
- The Azure AD device administrator

## SSPR

# Tasks

Sources:
- [Portal](https://docs.microsoft.com/en-us/azure/active-directory/external-identities/b2b-quickstart-add-guest-users-portal#add-a-new-guest-user-in-azure-ad)
- [PowerShell](https://docs.microsoft.com/en-us/powershell/module/azuread/new-azureadmsinvitation?view=azureadps-2.0)


### Add users in bulk


Import members by first navigating to the group to which they will be added, then importing from a CSV. A template is available.

=== "Azure Portal"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-import-1.jpg)
    ![](/img/az-ad-import-2.jpg)
    ![](/img/az-ad-import-3.jpg)
    ![](/img/az-ad-import-5.jpg)

Sources:

- [Bulk create users in Azure Active Directory](https://docs.microsoft.com/en-us/azure/active-directory/enterprise-users/users-bulk-add)
- [Bulk add group members in Azure Active Directory](https://docs.microsoft.com/en-us/azure/active-directory/enterprise-users/groups-bulk-import-members)

### Licenses


Note: The user to be licensed must first have a **Usage location** set.

=== "Azure Portal"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-users.jpg)
    ![](/img/az-ad-users-usage-location-1.jpg)
    ![](/img/az-ad-users-usage-location-2.jpg)
    ![](/img/az-ad-users-usage-location-3.jpg)
    

Use the ISO 3166-1 A2 two-letter country or region code to set this value in PowerShell
```powershell
Set-AzureADUser -UsageLocation 'US'
```
=== "Azure Portal"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-licenses.jpg)
    ![](/img/az-ad-licenses-all-products.jpg)
    ![](/img/az-ad-licenses-all-products-1.jpg)
    ![](/img/az-ad-licenses-all-products-2.jpg)
    ![](/img/az-ad-licenses-all-products-3.jpg)

Sources

- [Assign or remove licenses in the Azure Active Directory Portal](https://docs.microsoft.com/en-us/azure/active-directory/fundamentals/license-users-groups)
- [Configure Microsoft 365 user account properties with PowerShell](https://docs.microsoft.com/en-us/microsoft-365/enterprise/configure-user-account-properties-with-microsoft-365-powershell?view=o365-worldwide)

### Enable MFA

Create a **Conditional Access policy** to enforce MFA with specified users.

=== "Azure Portal"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-security.jpg)
    ![](/img/az-ad-cap-0.jpg)
    ![](/img/az-ad-cap-1.jpg)
    ![](/img/az-ad-cap-2.jpg)
    ![](/img/az-ad-cap-3.jpg)
    ![](/img/az-ad-cap-4.jpg)


Enable [SSPR][SSPR]

=== "Azure Portal"

    ![](/img/az-ad-sspr-0.jpg)
    ![](/img/az-ad-sspr-1.jpg)

### Add custom domain name
AZ-103: 410
![](/img/az-ad-domain-name.jpg)
# Sources
- [Tutorial: Secure user sign-in events with Azure Multi-Factor Authentication](https://docs.microsoft.com/en-in/azure/active-directory/authentication/tutorial-enable-azure-mfa)
- [How to manage the local administrators group on Azure AD joined devices](https://docs.microsoft.com/en-us/azure/active-directory/devices/assign-local-admin)
- [Password policies and account restrictions in Azure AD](https://docs.microsoft.com/en-us/azure/active-directory/authentication/concept-sspr-policy#administrator-reset-policy-differences)