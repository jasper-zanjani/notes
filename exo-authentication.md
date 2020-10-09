Microsoft originally planned to cease support for Basic Authentication to connect to **Exchange Online (EXO)** for Exchange ActiveSync (EAS), POP, IMAP, and Remote PowerShell on October 13, 2020. However, in an April update Microsoft announced this deprecation was postponed to the "second half of 2021" as a result of COVID. Basic authentication will still be disabled in newly created tenants starting October 2020. <sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/basic-authentication-and-exchange-online-april-2020-update/ba-p/1275508), [src](https://techcommunity.microsoft.com/t5/exchange-team-blog/improving-security-together/ba-p/805892)</sup>

**Modern Authentication** is based on OAuth 2.0 tokens and is strongly recommended in lieu of Basic Authentication.
<sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/improving-security-together/ba-p/805892)</src> 
Modern Authentication is enabled by default for all new tenants created since August 1, 2017.
<sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/basic-authentication-and-exchange-online-july-update/ba-p/1530163)</sup>

Legacy client applications, like [Outlook](#outlook) that use Basic Authentication to connect to Exchange Online must be upgraded.

## PowerShell
Wherever PowerShell scripts using **Exchange Online** module are run, the module must be upgraded to V2 ([`ExchangeOnlineManagement`](https://www.powershellgallery.com/packages/ExchangeOnlineManagement/2.0.3)). [Installation](https://docs.microsoft.com/en-us/powershell/exchange/exchange-online-powershell-v2?view=exchange-ps#install-and-maintain-the-exo-v2-module) is done via PowerShellGet.

## Discovering Basic Auth connections
Azure AD sign-in report includes a list of users and client applications that use basic authentication to connect to EXO.

**Authentication Policies** can also be queried from PowerShell using [`Get-AuthenticationPolicy`](https://docs.microsoft.com/en-us/powershell/module/exchange/get-authenticationpolicy?view=exchange-ps).

Several parameter names control the status of Basic Authentication for various services.<sup>[src](https://docs.microsoft.com/en-us/exchange/clients-and-mobile-in-exchange-online/disable-basic-authentication-in-exchange-online#authentication-policy-procedures-in-exchange-online)</sup>

Protocol or service | Description | Parameter name
:--- | :--- | :---
Exchange Active Sync (EAS)      | Used by some email clients on mobile devices.                                             | `AllowBasicAuthActiveSync`
Autodiscover                    | Used by Outlook and EAS clients to find and connect to mailboxes in Exchange Online       | `AllowBasicAuthAutodiscover`
IMAP4                           | Used by IMAP email clients.                                                               | `AllowBasicAuthImap`
MAPI over HTTP (MAPI/HTTP)      | Used by Outlook 2010 and later.                                                           | `AllowBasicAuthMapi`
Offline Address Book (OAB)      | A copy of address list collections that are downloaded and used by Outlook.               | `AllowBasicAuthOfflineAddressBook`
Outlook Service                 | Used by the Mail and Calendar app for Windows 10.                                         | `AllowBasicAuthOutlookService`
POP3                            | Used by POP email clients.                                                                | `AllowBasicAuthPop`
Reporting Web Services          | Used to retrieve report data in Exchange Online.                                          | `AllowBasicAuthReportingWebServices`
Outlook Anywhere (RPC over HTTP) | Used by Outlook 2016 and earlier.                                                        | `AllowBasicAuthRpc`
Authenticated SMTP              | Used by POP and IMAP client's to send email messages.                                     | `AllowBasicAuthSmtp`
Exchange Web Services (EWS)     | A programming interface that's used by Outlook, Outlook for Mac, and third-party apps.    | `AllowBasicAuthWebServices`
PowerShell                      | Used to connect to Exchange Online with remote PowerShell. If you block Basic authentication for Exchange Online PowerShell, you need to use the Exchange Online V2 module to connect. For instructions, see Connect to Exchange Online PowerShell. | `AllowBasicAuthPowerShell`

## Tenant

### Enabling Modern Authentication
- Modern Authentication is enabled by default for all new tenants created since August 1, 2017.
<sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/basic-authentication-and-exchange-online-july-update/ba-p/1530163)</sup>
- Outlook clients from 2016 and later already support Modern Authentication. Outlook 2013 can support Modern Authentication with a [registry key change](#outlook-2013). 
<sup>[src](https://docs.microsoft.com/en-us/exchange/clients-and-mobile-in-exchange-online/disable-basic-authentication-in-exchange-online#authentication-policy-procedures-in-exchange-online)</sup>

### Blocking Basic Authentication
A variety of methods are available to block Basic Authenticatton
- **Security Defaults**, which is enabled by default for new tenants since October 2019, requires Modern Authentication and blocks Basic Authentication. <sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/basic-authentication-and-exchange-online-july-update/ba-p/1530163)</sup>
- For tenants with Azure AD Premium licenses, **Conditional Access** can be used to block Basic Authentication for some or all 

Basic authentication can be disabled for individual services in the M365 admin center by going to **Settings** > Org **settings** > **Modern authentication** <sup>[src](https://techcommunity.microsoft.com/t5/exchange-team-blog/basic-authentication-and-exchange-online-july-update/ba-p/1530163)</sup>


## Clients
### Outlook
Outlook clients from 2016 and later already support Modern Authentication. Outlook 2013 can support Modern Authentication with a registry key change. 
<sup>[src](https://docs.microsoft.com/en-us/exchange/clients-and-mobile-in-exchange-online/disable-basic-authentication-in-exchange-online#authentication-policy-procedures-in-exchange-online)</sup>
On Outlook 2013, the following registry keys have to be set to `1` to support Modern Authentication:
<sup>[src](https://docs.microsoft.com/en-us/microsoft-365/admin/security-and-compliance/enable-modern-authentication?view=o365-worldwide)</sup>
- `HKCU\SOFTWARE\Microsoft\Office\15.0\Common\Identity\EnableADAL`
- `HKCU\SOFTWARE\Microsoft\Office\15.0\Common\Identity\Version`

The following PowerShell commands will do the trick:
```powershell
Set-Item -Path HKCU:\SOFTWARE\Microsoft\Office\15.0\Common\Identity\EnableADAL -Value 1
Set-Item -Path HKCU:\SOFTWARE\Microsoft\Office\15.0\Common\Identity\Version -Value 1
```
