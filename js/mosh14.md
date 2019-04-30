##  14   - Deployment
Two options:
- Platform as a Service (PaaS)
- Docker

Several PaaS options:
- Amazon Web Services
- Google Cloud Platform
- Azure
- **Heroku**

### Installation
- $ `npm i helmet`
- $ `npm i compression`

Middleware for production environment goes into _prod.js_

### Heroku
Installing, logging in

Preparing app
- Adding “start” property to package.json
- Adding “node” property and Node version as value to engines property

Adding code to Git
- Including _node_modules/_ and _coverage/_ to _.gitignore_ file
- Git `init`, `add`, and `commit` shell commands

Heroku CLI
- `$heroku create (APPNAME)` : With no name specified, a random name is assigned, and address 
- `git push heroku master`
- heroku config: `set NODE_ENV=production`

#### Diagnosing errors
Servers are called “dynos” in Heroku
- heroku logs produces logs to diagnose errors.
- Heroku Dashboard displays logs from a dropdown.
- uncaughtExceptions file available in Heroku console

#### Creating MongoDB in the cloud
Heroku add-ons:  mLab
Creating an mLab account
- Choose cloud provider
- Create database and user
- Connection string, which contains password and username, should not be stored in a configuration file but in an environment variable
- heroku config:set `vidly_db=mongodb://vidlyuser:1234@ds012...  `, Set connection string
- Git commit and push to Heroku
- New user through POST request
- `x-auth-token`