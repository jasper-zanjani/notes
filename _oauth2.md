OAuth is an open standard for access delegation, commonly used by Internet users to grant third-party applications access to their data on other websites without transferring passwords. OAuth 2.0 was published in 2012.

It is an authorization protocol, rather than an authentication protocol (OpenID)

Roles
- user
- application
- API
  - authorization server, which will display a prompt to the user asking if they are sure they want to authorize the application to access account information. It also sends an authorization code back to the application to request an access token from the authorization server.
  - resource server, which is responsible for serving requests from the application for protected resources.

For example, when Spotify allows a user to register via a social network like Facebook, Facebook is taking on the role of API.

Passwords are never passed from server to server using this framework

