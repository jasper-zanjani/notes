# Azure Key Vault

- Data protection
- Encryption models
- Application security

**Azure Key Vault** is a managed secrets solution offered by Azure.
Key Vault can store three types of secrets: keys, secrets, and certificates.

Key Vault integrates with other Azure services

- Storage accounts
- Azure disk encryption (i.e. Bitlocker keys for encrypted Windows disks)
- Azure App Service (i.e. certificates or API keys)
- **SQL Always Encrypted** which ensures that data is stored encrypted even on the client

Azure Key Vault likes x509 certificates in PFX format.

Certificates are merged with existing CSRs .