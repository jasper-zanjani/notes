# The Express Handbook by Flavio Copes
## Installation `npm i express --save` or `yarn add express`
## Hello World
```
const express = require('express')
const app = express()

app.get('/', (req,res) => res.send('Hello world!'))
app.listen(3000, () => console.log('Server ready'))
```
##  Request parameters
### Request parameeters
### How to retrieve the GET query string parameters using Express
### How to retrieve the POST query string parameters using Express
##  Sending a response
`send` method automatically sets the `Content-Type` header appropriately, to `text/html` if sending strings or `application/json` if sending an object or array
##  Sending a JSON response
##  Manage cookies
##  Work with HTTP headers
##  Redirects
##  Routing
##  CORS
##  Templating
##  Pug
##  Middleware
##  Serving static files 
##  Send files
##  Sessions
##  Validating input
##  Sanitizing input
##  Handling forms
##  File uploads in forms
##  Express HTTPS server with a self-signed certificate
##  Setup Let's Encrypt for Express