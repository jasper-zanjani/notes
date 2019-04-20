# Axios
Accessing RESTful web services and HTTP APIs in JavaScript. Inspired by the `$http` service in Angular, and development of Axios was an effort to provide a similar standalone service for use outside of Angular.

    axios
      .get(url)
      .then(response => console.log(response))
      .catch(error => console.log(error))

## Installation
- $ `npm install axios`
- cdn link: https://unpkg.com/axios/dist/axios.min.js

## Tutorial
GET request for a given user ID:

    const axios = require('axios')
    axios.get('/user?ID=12345')   // Request user with given ID
      .then(function (res) {
        console.log(res)          // Handle success
      })
      .catch(function (err){
        console.log(err)          // Handle error
      })
      .then(function () {})       // Always executed

Alternatively

    axios.get('user', {
      params: { ID: 12345 }
    })
      .then(function (response) { console.log(response) })
      .catch(function (error) { console.log(error) })
      .then(function () {})

## Syntax
- `.get(STRING)` GET request
- `.then(function(response) {})` method for handling success
- `.catch(function(error) {})` method for handling errors
- `async` ECMAScript 2017 keyword used on outer function
- `await` ECMAScript 2017 keyword used on outer function
# Babel
JavaScript preprocessor
# Blade
Templating engine used in Laravel

## Directives
- `@section('component')` Used to define a section of content
- `@yield('variable')` Used to display the contents of a given section
- `@endsection`
- `@parent` append content, rather than overwrite

# Gulp
Toolkit for automating time-consuming tasks in development workflow
- `const gulp = require('gulp');`
- gulp-uglify `const uglify = require('gulp-uglify');`

    gulp.task('scripts', function() {
      gulp.src('src/*.js')
      .pipe(uglify())
      .pipe(gulp.dest('dist'));
    });

# Laravel
PHP framework for the development of web applications following the model-view-controller architectural pattern. Developed as a more advanced alternative to the _CodeIgniter_ framework.

## Installation
- XAMPP, MAMP (Mac), or WAMP (Windows) to ensure the Apache server environment
- _Composer_ dependency manager for PHP, similar to _npm_. It will want to know where the `PHP.exe` file is, which will be in the directory installed of the server environment installed above.
- VS Code, Git Bash, Git

## Initialization
Terminal commands similar to working with _npm_
- $ `composer create-project laravel/laravel lsapp`
- `cd lsapp`

This project will be accessible at `localhost/lsapp/`. This is a security issue and must be fixed:
- Edit `C:/xampp/apache/conf/extra/httpd-vhosts.conf` (if using XAMPP)
- Uncomment the opening and closing tags for the `VirtualHost` tag
- Uncomment the `DocumentRoot` line, changing the path to the `public` directory
- Uncomment the `ServerName` line, which can be named arbitrarily, e.g. `lsapp.dev`
- Add another `VirtualHost` pointing to the htdocs directory (within which lsapp was created) and set `ServerName` to localhost

- Open Notepad as an administrator
  Navigate to `C:/Windows/System32/drivers/etc`, view _All files_, and open `hosts`
  Add `127.0.0.1 localhost`
  Add `127.0.0.1 lsapp.dev`

Stop and then start the Apache server

## Folder structure
- `public/` frontend of the application
- `app/` all _models_ go in this folder, including _User.php_
- `Http/Controllers/` contains all controllers
- `resources/views/` all Laravel views use the Blade template engine 
- `routes` routing middleware can be installed here
- `config/database.php` contains settings

## Syntax
- `namespace` keyword assigns an identifier
- `Illuminate` refers to Laravel core

# TypeScript
Programming language developed and maintained by Microsoft, a strict syntactical superset of JavaScript which supports generic programming

## Syntax
- static typing using annotations, including `number`, `boolean`, `string`, and `any`. These declarations can be exported to a declarations file.
function add(left: number, right: number): number 
  {
	  return left + right;
  }