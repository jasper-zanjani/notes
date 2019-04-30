# React.js
Most popular JavaScript library for building user interfaces, built by Facebook in 2011, competing with _Angular_ and _Vue_. Every React application is a tree of _components_: independent, isolated, and reusable pieces of UI. React Elements map to DOM elements maintained in memory (Virtual DOM). React state changes are then updated to the real DOM.

- React is a library
- Angular is a framework

Setup
- `sudo npm i -g create-react-app@1.5.2 ` 
	Install _create-react-app_ package
- `create-react-app APPNAME`
- `npm start  `
	Launch development server at http://localhost:3000/

## Directory structure
These commands create a file structure within the designated folder
- _node\_modules/_
- _public/_  
	    Public-facing webpages
- _src/_  
	    App.js

## Hello World
Delete contents of _src/_ and start a new file.

#### index.js

	import React from 'react';
	import ReactDOM from 'react-dom';
	
	const element = <h1>Hello World</h1>;
	console.log(element);

Saving changes automatically updates the displayed webpage.

## Counter app
- `create-react-app counter-app`  
	    Create counter-app
- Ctrl+\` to open terminal within Code
- `npm i bootstrap@4.1.1  `
    Install Bootstrap into the app
- Cmd+P to open file explorer  
	Find _index.js_
- Append `import 'bootstrap/dist/css/bootstrap.css'` to import statements at top

## Creating a component
By convention, components are added to _src/components/_ directory

Using the Simple React Snippets extension for Code allows convenient expansion:
- `imrc`: Import React/Component
- `cc`: Class Component

React is being imported because the JSX expression will be compiled into a React object.

#### counter.jsx
	import React, { Component } from 'react';
	
	class Counter extends Component {
	 render() { 
	  return ( <h1>Hello World</h1> );
	}}
	
	export default Counter;

#### index.js
	...
	import Counter from './components/counter';
	
	ReactDOM.render(<Counter />, document.getElementById('root'));
	...

## Embedding expressions
A button is added into the HTML within counter.jsx

#### counter.jsx
	import React, { Component } from 'react';
	
	class Counter extends Component {
	 render() { 
	  return ( <div><h1>Hello World</h1><button>Increment</button></div> );
	 }
	}
	
	export default Counter;

Upon compile, the JSX expression within render() is converted to a statement using the `React.createElement()` method, which takes two arguments.

Replacing `<div>` with `<React.Fragment>`
- Cmd+D to select all instances
- *Shift+Option+F* to format document

Instead of hard-coding “Hello World”, we can display a dynamic value. We do this at the component level using the `state` property, which is an object.

#### counter.jsx
	import React, { Component } from "react";
	
	class Counter extends Component {
	 state = {
	  count: 0
	 };
	
	 render() {
	  return (
	   <React.Fragment>
	    <span>{this.state.count}</span>
	    <button>Increment</button>
	   </React.Fragment>
	  );
	}}
	
	export default Counter;

In between those curly braces, we can write any valid JavaScript expression, even arithmetic.

Adding a formatCount() method which will return the string ‘Zero’ if count is zero. 

#### counter.jsx
	import React, { Component } from "react";
	
	class Counter extends Component {
	 state = {
	  count: 0
	 };
	
	 render() {
	  return (
	   <React.Fragment>
	    <span>{this.formatCount()}</span>
	    <button>Increment</button>
	   </React.Fragment>
	  );
	 }
	
	 formatCount() {
	  const { count } = this.state;
	   return count === 0 ? 'Zero' : count;
	}}
	
	export default Counter;

Alternatively, instead of returning plaintext, we can return a JSX expression with h1: `return count === 0 ? <h1>Zero</h1> : count;`

## Setting attributes
HTML attributes can also render dynamically imported data:

#### counter.jsx
	import React, { Component } from "react";
	
	class Counter extends Component {
	  state = {
	    count: 0,
	    imageUrl: 'https://picsum.photos/200'
	  };
	
	  render() {
	    return (
	      <React.Fragment>
	        <img src={ this.state.imageUrl } alt=""/>
	        <span>{this.formatCount()}</span>
	        <button>Increment</button>
	      </React.Fragment>
	    );
	  }
	
	  formatCount() {
	    const { count } = this.state;
	    return count === 0 ? 'Zero' : count;
	  }
	}
	
	export default Counter;

Specifying HTML class requires `className` because `Class` is a reserved word in JavaScript.

	...
	render() {
	 return (
	  <React.Fragment>
	   <span className="badge badge-primary m-2">{this.formatCount()}</span>
	   <button className="btn btn-secondary btn-sm">Increment</button>
	  </React.Fragment>
	 );
	}

CSS styling can be specified in the same way, passing an object in as an HTML attribute
	...
	styles = {
	 fontSize: 50,
	 fontWeight: 'bold'
	}
	
	render() {
	 return (
	  <React.Fragment>
	   <span style = {this.styles} className="badge badge-primary m-2">{this.formatCount()}</span>
	   <button className="btn btn-secondary btn-sm">Increment</button>
	  </React.Fragment>
	 );
	}
	...

Alternatively, CSS can be defined inline by using double curly braces: `...<span style={{fontSize: 30}}>...`

## Rendering classes dynamically
CSS classes can be edited using simple string concatenation techniques that key off of conditional statements

	...
	 render() {
	  let classes = "badge m-2 badge-";
	  classes += this.state.count === 0 ? "warning" : "primary";
	
	  return (
	   <React.Fragment>
	    <span className={classes}>{this.formatCount()}</span>
	...

The lines associated with `classes` cause the `render()` method to become bloated. We can refactor within Code using Ctrl+Shift+R, which extracts the two lines to a new method.

#### counter.jsx

	...
	 getBadgeClasses() {
	  let classes = "badge m-2 badge-";
	  classes += this.state.count === 0 ? "warning" : "primary";
	  return classes;
	 }
	...

## Rendering lists
Let’s see how to render a list of tags. Loops do not exist as a concept within JSX, but we can use the `.map()` method with arrays.

#### counter.jsx

	...
	 state = {
	  count: 0,
	  tags: ['tag1','tag2','tag3']
	 };
	...
	    <ul>
	     { this.state.tags.map(tag => <li>{tag}</li>)}
	    </ul>
	...

This produces an error in the console, because React wants each DOM element to have a distinct key value. For now, we can use the same tag as a key.

	<ul>
	 { this.state.tags.map(tag => <li key ={tag}>{ tag}</li>)}
	</ul>

## Conditional rendering
Unlike Angular, JSX is not a templating engine, so there are no conditionals. We can use JavaScript outside of the JSX expression and pass that into the expression.

#### counter.jsx
 

Another technique is to take advantage of truthy expressions and how JavaScript evaluates the logical AND operator.

## Handling events
Properties based on standard DOM events placed within JSX expressions (note camelcase):
- `onClick()`
- `onDoubleClick`
- `onKeyDown`
- `onKeyUp`
- `onKeyPress`

#### counter.jsx

	...
	 handleIncrement() {
	  console.log('Increment clicked')
	 }
	...
	<button onClick={this.handleIncrement} ...

Attempting to log `this.state.count` produces an error, revealing that count is not available to the method.


## Binding event handlers
JavaScript will return undefined if `this` is used in strict mode in a standalone function without an object reference. To solve this, we use the bind method.

We have to add a constructor for every event handler

	constructor() {
	 super();
	 this.handleIncrement = this.handleIncrement.bind(this);
	 }

Alternatively, an arrow function can be used because they inherit the `this` object.

#### counter.jsx
	handleIncrement = () => {
	 console.log("Increment Clicked", this")
	};

## Updating state
State cannot be updated directly, e.g. `this.state.count++;` is ineffective. React must be told explicitly what part of the DOM has been changed, unlike Angular.

#### counter.jsx
 handleIncrement = () => {
	this.state.count++;
	this.setState({ count: this.state.count + 1 });
	 }

To solve this problem we use of the `setstate()` method available in the `Component` class (from which `Counter` inherits).

	handleIncrement = () => {
	 this.setState( { count: this.state.count + 1 });
	};

## What happens when state changes
When state changes, an asynchronous call is made to the `render` method. React compares the updated virtual DOM with the old, real DOM and updates only the DOM nodes which need updating.

## Pass arguments using arrow functions
Earlier, we saw that the `onClick()` method only takes a function reference, not a full function call with parameters.

We can declare a new method named `.doHandleIncrement()` which acts as a wrapper for `.handleIncrement()`, passing an argument.
#### counter.jsx
	doHandleIncrement = () => {
	 this.handleIncrement({ id: 1})
	}

But this is wasteful. Better is defining an inline function.

	...
	<button
     onClick={ () => this.handleIncrement(product)}
	 className="btn btn-secondary btn-sm"
	>
	...

## Summary
- JSX (JavaScript XML)
- Rendering lists
- Conditional rendering
- Handling events
- Updating state

## Composing components
Changing `Counter` component to `Counters`

Every React component has a property called `props`

## Index of React commands and methods
- `.setstate()`


# JavaScript for React Developers
## `let` vs `var` vs `const`
Variables declared with `let` are block-scoped.
#### example
	function sayHello() {
	 for (let i = 0; i < 5; i++) {
	  console.log(i);
	 }>)
	console.log(i) // undefined
	}

	sayHello();

## Objects
#### example
	const person = {
	 name: 'Mosh',
	 walk: function() {},
	 talk() {} // Alternative way of declaring a method
	}

	person.talk();
	const targetMember = 'name';
	person[targetMember.value] = 'John'

## `this` keyword
`this` can be made explicit by using the `bind` method, which will avoid complications of using `this` in top-level function calls.

Functions are objects in JavaScript.
#### example
	const person = {
	 name: 'Mosh',
	 walk() {
	  console.log(this);
	 },
	}

	person.walk(); // person {}
	 const walk = person.walk.bind(person)


In React, strict mode is enabled by default, so the `this` keyword returns `undefined`.
#### example
	const person = {
	 name: 'Mosh',
	 walk() {
	  console.log(this);
	 },
	}

	person.walk(); // person {}
	
	const walk = person.walk();
	walk();        // undefined

## Arrow functions
Arrow functions allow a good way to clean up code for the simplest functions.
	const square = function(number) {
		return number * number
	}

	const square = number => number * number;

But they do not rebind the `this` object for callback functions.

## Array.map()
One of the new array methods defined in ECMAScript 6, `.map()` is very useful in rendering lists.
	const colors = ['red','green','blue']
	const items = colors.map(color => `<li>${color}</li>`)
	})

## Object destructuring

	const address = {
		street: '',
		city: '',
		country: ''
	}

	const street = address.street;
	const city = address.city;
	const country = address.country;

The repetitive use of the object name `address` is a good object to use _destructuring syntax_.

	const {street, city, country } = address;
	const {street: st } = address;



## Classes
When we have an object with at least one method, we use classes to ensure that child objects do not reduplicate code unnecessarily.

	const person = {
	 name: 'Mosh',
	 walk() {
	  constole.log('walk') // console is mispelled
	}}

	const person2 = {
	 name: 'Mosh',
	 walk() {
	  constole.log('walk') // copying reduplicates the error
	}}

	class Person {
	 constructor(name) {
	  this.name = name;
	 }
	 walk() {
	  console.log('walk');
	}}

	const person = new Person('Mosh');

## Inheritance

	class Person {
	 constructor(name) {
	  this.name = name;
	 }
	 walk() {
	  console.log('walk');
	 }
	}

	class Teacher {           // Teacher should also be able to walk, 
	 teach() {                // but we don't want to reduplicate code...
	  console.log('teach');
	 }
	}

	class Teacher extends Person {
	 constructor(name, degree) {
	  super(name)                 // references parent class
	  this.degree = degree
	 }

	 teach() {
	  console.log('teach')
	 }
	}

	const teacher = new Teacher ('Mosh', 'MSc')

## Modules
Splitting code across multiple files, each of which is called a _module_. Class keyword must be prefixed by `export`

_person.js_
	export class Person {
	 constructor(name) {
	  this.name = name;
	 }
	 walk() {
	  console.log('walk');
	 }
	}

_teacher.js_
	import { Person } from './person'      // extension is not added

	export class Teacher extends Person {
	 constructor(name, degree) {
	  super(name)
	  this.degree = degree
	 }

	 teach() {
	  console.log('teach')
	 }
	}

#### index.js
	import Teacher from './teacher'
	
	const teacher = new Teacher ('Mosh', 'MSc')

## Named and default exports
- `default` keyword to export an entire object, after `export` and before `class`
- named exports to export functions using the `export` keyword
- named exports must be individually named and placed within braces