# Node.js
Open-source, cross-platform runtime environment for executing JS, often used to build back-end services (application programming interfaces) which has a large ecosystem of open-source libraries for use.

In 2009, Ryan Dahl took Chrome's JavaScript engine and embedded it inside a C++ program. Node provides a runtime environment for JavaScript code, including some objects which are different from those provided by browsers.

**Asynchronous** nature of Node is comparable to that of a waiter who can serve multiple tables while waiting for an order. The waiter is like one thread allocated to handle a request, and the synchronous counter-example would be a waiter who waits for the meal to come out from the kitchen. Node is ideal for data-intensive and realtime applications, but not those that are CPU-intensive.

##  Modules (mosh02)
In the browser environment, functions are added to the global scope, and are therefore accessible as methods of the global object:

This is a problem for maintaining complex programs, solved by modularity. In Node, every file is considered a _module_, and variables and functions defined within are scoped to that module. In order to use a variable or function outside of that file, it must be explicitly made public.

`require`
: takes one argument, the path or name of the module (file) to be loaded. It returns the exports object of the called module. Using a constant ensures that, if the variable was accidentally reset later in the code, an error would occur during compile and not during runtime.  Node does not execute module code directly, but wraps it in the Module Wrapper Function. This function contains the following arguments: `exports`, `require`, `module`, `__filename`, `__dirname`

###  Useful modules
`path`
: provides a more convenient way of handling paths than RegEx (mosh02.07)
`os`
: operating system: `freemem()`, `totalmem()`, `userInfo()`, `uptime()` (mosh02.08)
`fs`
: file system: synchronous and asynchronous flavors of many methods (mosh02.09)
`events`
: two methods used primarily: `addListener` or `on` and `emit()` (mosh02.10). 1) When magic values are passed as arguments, it is better to pass them in as an object (mosh02.11). Usually event handling is done in a module separate from the main one. Move the emitter and EventEmitter declarations as well as the event raiser to `logger.js` (mosh02.12) The event listener will not be called because there are now two different EventEmitter objects. The listener registered in `app.js` is distinct from that in `logger.js`.
	- Refactor `logger` into a class which can be instantiated within `app.js`. First letter is uppercase as per convention. `function` keyword is not necessary when defining a function within a class (method). `extends` keyword ensures that `Logger` inherits all capabilities of EventEmitter class (mosh02.12)
- `http` create a backend service for client applications by running a server off this module (mosh02.13)

##  Node Package Manager (NPM) (mosh03)
NPM is a CLI and registry of third-party libraries that can be added to an application. NPM packages are installed in /c/Users/user/AppData/Roaming/npm/ by default on windows

Beginning a new application requires a new `package.json` file which contains basic metadata about the application that appears in all Node applications as a standard

`npm init` | `npm init --yes`
: produce a package.json file (mosh03.01)
`npm install package` | `npm i underscore`
: install {package} mosh03.02)
`npm i`
: restore missing dependencies using the package.json file. (mosh03.06)


##  Express.js (mosh04)
Express is a fast and lightweight framework for building web applications, the most popular one for building web applications over Node. (mosh04.03)
All communication between Client and Server occurs over the HTTP protocol. Client can access many services exposed on the server by sending HTTP requests. _REpresentational State Transfer (REST)_ and _Create, Read, Update, and Delete Data (CRUD)_ operations correspond to _HTTP verbs_ or _methods_ `POST`, `GET`, `PUT`, and `DELETE` respectively. Let’s conceptualize an application named Vidly. On Vidly’s server, the service would be exposed at an _endpoint_ like the following: `http://vidly.com/api/customers` where `customers` is referred to as a _resource_. Various resources can be exposed at various _endpoints_. (mosh04.02)
- Refactor the server to use Express (mosh04.04)
- $`sudo npm i -g nodemon ` install Nodemon; `nodemon index.js` to run. Now `nodemon` will monitor for any changes in the application, obviating the need to manually restart the server. (mosh04.05)
- `PORT` environment variable is read through the `process` object's `env` property. Hard-coding a port number is not ideal, because there is no guarantee we will be able to use that port in our production hosting environment. The environment variable can be set from the shell using the `export` command on Mac and `set` on Windows (Git Bash accepts `export` but not `set`): `$set PORT=5000` (mosh04.06)
- Routes for this demo should have endpoints structured as `api/courses/1` where 1 is the ID of the course being queried. Navigating to `http://localhost:3000/api/courses/30/x` simply spits these arbitrary arguments back: `{"year":"30","month":"x"`
- Query string parameters (`?sortbyName`) can be accessed using the `req.query` object (mosh04.07)
- Implement a new endpoint to `GET` a single course from the server (mosh04.08)
- Implement a `POST` request. We need to read request as a JSON object, use its properties to create a new course object, which is then appended to the `courses` array. Enable the ability to parse JSON with `app.use(express.json())` and use `req.body.name`, which assumes that the body of the request contains a JSON object. (mosh04.09)
- Use _Postman_ to create an HTTP POST request (mosh04.10)
- Input must always be validated for security reasons. This can be done using simple conditionals, or preferably using an  input validation package, such as Joi. (mosh04.11)
- Implement a `PUT` request by reusing code from other request types. Refactor to abstract the validation in a separate function, which is then reused in the `POST` (mosh04.12)
- Implement a `DELETE` request (mosh04.13)

##  Asynchronous JavaScript (mosh05)
A _middleware function_ is one that takes a request object and returns a response to the client or passes control to another middleware function, for example route handlers. Express includes a few middleware functions, and we can define our own. An Express application is ultimately a collection of middleware functions. (mosh05.02)
- Create custom middleware (mosh05.03) 
	- Each middleware function should be in its own file, to keep the main file tidy
	- Middleware functions are called sequentially
	- Express middleware functions take three arguments: `req`, `res`, and `next`
	- `next()` is an important command to ensure that responses are sent to the next function in the _request response pipeline_ and the request does not go into limbo
- Using the `urlencoded` middleware function `static` serves static files found in the _/public/_ directory which become accessible from the root of the site (mosh05.04)
- Third-party middleware: `helmet` and `morgan` (mosh05.05)
- Logging of HTTP requests using `morgan` should only be done in development, not in production (mosh05.06)
- Storing configuration settings of the application for each application: `rc` is the most popular package for managing configurations, but `config` is preferred by Mosh. Make a new directory named `config` and new files named `default.json`, `production.json`, and `development.json`. Define new properties within them such as `name: "My Express app"`, `"mail": {"host": "dev-mail-server"}`, `"mail": {"host": "prod-mail-server"}` etc. Now these settings can be switched easily by changing the `NODE_ENV` environment variable through the shell $`export NODE_ENV=development` (mosh05.07)
- Prefer the `debug` module in Node over `console.log()`. `debug` can be toggled using an environment variable to enable or disable debugging statements. (mosh05.08)
	- `DEBUG=app:startup` single namespace
	- `DEBUG=app:startup,app:db` multiple namespaces
	- `DEBUG=app:*` wildcard
	- `DEBUG=` reset
- Set a templating engine with `app.set('view engine', 'pug')` and pass dynamic webpages as HTTP responses using `res.render('index', { title: "Hello world!", message: 'Hello world!'})` (mosh05.09)
- There are various database integration options available when using Node and Express, all of which require the same steps: installation and use of the module. `Mongoose` uses a simpler API than `MongoDB`, and is built on top of it. (mosh05.10)
- Authentication is outside the scope of Express. (mosh05.11)
- For every API endpoint, there should be a separate module to handle it. Move all  (mosh05.12)

##  Asynchronous operations (mosh06)
- Asynchronous operations cause difficulties because values are not immediately available. (mosh06.01-02)
- Solutions can include:
	1. Callback functions
		- Replace the `return` keyword with callback functions, which can cause callback hell. (mosh06.03-04)
		- Named functions can resolve the nested structure of callback hell (mosh06.05)
	2. `Promise`s can be in three states: `pending`, `fulfilled` or `resolved`, or `rejected` (mosh06.06)
	3. `async` and `await` operators
		- `await` operator can be used in code that looks synchronous, if the functions return `promises`, but it requires a function decorated with `async`. It is a syntactical sugar for `promises`
		- 

### Replacing callbacks with promises

### Consuming promises

### Creating settled promises

### Running promises in parallel

### Async and await

### Exercise

##  Mongo

When the server restarts, data in memory will be lost, necessitating use of a database.
##  Mongoose
##  Authentication and Authorization
##  Error handling and logging
##  Unit testing

##  Integration testing
##  Test-driven development
##  Deployment
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
