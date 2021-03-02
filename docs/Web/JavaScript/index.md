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
```js
const axios = require('axios')
axios.get('/user?ID=12345')   // Request user with given ID
    .then(function (res) {
        console.log(res)          // Handle success
    })
    .catch(function (err)
        {
            console.log(err)          // Handle error
        }
    )
    .then(function () {})       // Always executed
```
Alternatively
```js
axios.get('user', 
    {
      params: { ID: 12345 }
    }
)
    .then(function (response) { console.log(response) })
    .catch(function (error) { console.log(error) })
    .then(function () {})
```

#### Blade
Templating engine used in Laravel

## Directives
- `@section('component')` Used to define a section of content
- `@yield('variable')` Used to display the contents of a given section
- `@endsection`
- `@parent` append content, rather than overwrite

## Gulp

Toolkit for automating time-consuming tasks in development workflow
- `const gulp = require('gulp');`
- gulp-uglify `const uglify = require('gulp-uglify');`

```js
gulp.task('scripts', function() 
    {
        gulp.src('src/*.js')
          .pipe(uglify())
          .pipe(gulp.dest('dist'));
    }
);
```

## Laravel

PHP framework for the development of web applications following the model-view-controller architectural pattern. Developed as a more advanced alternative to the _CodeIgniter_ framework.

Installation

- XAMPP, MAMP (Mac), or WAMP (Windows) to ensure the Apache server environment
- _Composer_ dependency manager for PHP, similar to _npm_. It will want to know where the `PHP.exe` file is, which will be in the directory installed of the server environment installed above.
- VS Code, Git Bash, Git

Initialization
```sh
composer create-project laravel/laravel lsapp
cd lsapp
```

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

## TypeScript

Programming language developed and maintained by Microsoft, a strict syntactical superset of JavaScript which supports generic programming

- static typing using annotations, including `number`, `boolean`, `string`, and `any`. These declarations can be exported to a declarations file.

```js
function add(left: number, right: number): number 
{
  return left + right;
}
```

## Promises

A **promise** is the eventual result of an asynchronous operation.

Stages: 

- Wrapping
- `then`-ing
- Catching
- Chaining

Promises can be in one of 4 states:

- `fulfilled`: action relating to the promise succeeded
- `reject`: action relating to the promise failed
- `pending`: has not fulfilled or rejected yet
- `settled`: has fulfilled or rejected

Promises vs. events

- an event listener registered after an event has occurred will never fire
- an action set for resolution can fire after a promise has already resolved
- an event can fire many times, but promises can only settle once

Promise is a try/catch wrapper around code that will finish at an unpredictable time

A `Promise` takes a function as argument. That function takes two arguments: `resolve` and `reject`. They are both callbacks that will execute when the promise has succeeded or failed

any argument passed to `resolve` or `reject`, will then be received by `then` or `catch` methods, respectively

`resolve` leads to the next `then` in the chain, and `reject` leads to the next `catch`

## Glossary

#### Babel
JavaScript preprocessor