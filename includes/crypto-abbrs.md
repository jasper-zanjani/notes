*[3DES]: Triple Data Encryption Standard: symmetric key encryption algorithm that uses DES three times with three different keys, providing a total bit strength of 168 bits
*[AES]: Advanced Encryption Standard: also "Rijndael" after the name of the original cipher upon which AES is based, symmetric-key cyptographic algorithm using a block size of 128 bits and key sizes of 128, 192, or 256 bits
*[CCMP]: Counter-mode Cipher Block Chaining Message Authentication Code Protocol: encryption algorithm used by WPA2, using 128-bit AES encryption with a 48-bit initialization vector; based on AES and superceding TKIP
*[AES]: Advanced Encryption Standard: like 3DES, data is passed through three layers then encrypted with the keys through multiple encryption rounds before the final key is applied to the data
*[CTR]: Counter mode: every encryption operation is separate but uses a nonce and a counter; plaintext is XORed with the output of the encryption operation to produce ciphertext
*[D-H]: Diffie-Hellman key exchange: also "exponential key agreement", early asymmetric-key cryptographic algorithm, vulnerable to man-in-the-middle attacks
*[DES]: Data Encryption Standard: obsolete symmetric-key block cipher cryptographic algorithm superceded by AES; uses a random key selected from a large number of shared keys; most forms are export-controlled; Feistel cipher with a 64-bit block size and 56-bit key; adopted for use by NIST in 1977
*[DHE]: Diffie-Hellman: uses an ephemeral algorithm
*[DSA]: Digital Signature Algorithm: developed by the NSA in 1991 as an alternative to RSA which is faster in signing but slower in verifying, thus preferable if there are performance issues on the client
*[ECB]: Electronic Code Book: simplest block cipher mode of operation where each block of plaintext is encrypted separately
*[ECC]: elliptic curve cryptography: asymmetric key encryption algorithm based on complex mathematical structures; it uses smaller key sizes than traditional public-key cryptosystems and is therefore faster and less resource-intensive than traditional system
*[ECDH]: Elliptic Curve Diffie-Hellman: variant of Diffie-Hellman key agreement protocol for ECC using an ephemeral mode of operation
*[HMAC]: hash-based message authentication code: MAC based on cryptographic hash functions; provides additional security by adding an additional integrity check to the data being transmitted
*[IKE]: Internet Key Exchange: IPsec protocol that uses X.509 certificates for authentication
*[IV]: Initialization Vector: fixed-size input used in cryptography
*[MAC]: message authentication code: also "authentication tag", derived by applying a applying a message or file combined with a secret key to a cryptographic algorithm; basically an encrypted hash
*[MD5]: Message Digest series encryption algorithm: one of a series of hash algorithms created by Ronald Rivest, generating a hash of up to 128-bit strength out of any length of data
*[MIC]: message integrity code: CCMP field that provides data origin authentication and data integrity for the packet payload data
*[CBC]: Cipher Block Chaining : an initialization vector using a random public value is XORed with the plaintext prior to encryption for the first round; subsequent rounds use the ciphertext of the previous round
*[CFB]: Cipher Feedback: an initialization vector is encrypted and the result is XORed with the plaintext to create the ciphertext of the block; first block is a random value and other blocks use the previous block's ciphertext
*[PBKDF2]: Password-Based Key Derivation Function 2: applies a pseudorandom function to the password, combined with a salt of at least 64 bits, repeating the process at least 1,000 times
*[PGP]: Pretty Good Privacy: popular cryptographic program suite
*[PKI]: Public Key Infrastructure: collection of software, standards, and policies that enables users on unsecured networks to securely exchange data using a public and private cryptographic key pair obtained and shared through a trusted authority
*[PN]: packet number: CCMP field that provides replay protection
*[PSK]: Pre-Shared Key: key shared with another party
*[RIPEMD]: RACE Integrity Primitives Evaluation Message Digest: less commonly used hash algorithm; RIPEMD-160 is comparable to SHA-1
*[RSA]: Rivest, Shamir, Adelman: asymmetric-key cryptographic algorithm that can use a key of any length and which was released into the public domain in 2000; works by multiplying two large prime numbers and derives a set of numbers through other operations
*[SHA]: Secure Hash Algorithm: hash algorithms developed by NSA; SHA-224, SHA-256, SHA-384, and SHA-512 together are known as SHA-2
*[SSL]: Secure Sockets Layer: cryptographic security protocol used by Internet services and clients for authentication, message integrity, and confidentiality using an asymmetric key with cipher strength of 40 or 128 bits
*[TKIP]: temporal key integrity protocol: inferior encryption algorithm used by WPA
*[WEP]: Wired Equivalent Privacy: early wireless encryption technology
*[WPA]: Wi-Fi protected access: wireless encryption technology created to address the problems of WEP
*[GCM]: Galois Counter Mode: special case of CTR that doesn't use a nonce but relies only on a counter and calculates a MAC
*[IDEA]: International Data Encryption Algorithm: 128-bit symmetric-key cryptographic algorithm, the default used by SSH