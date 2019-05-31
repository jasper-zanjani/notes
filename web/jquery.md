# jQuery

## Terms
-- stack
-- set of matched elements, matched set
-- target
-- content
-- event propagation, event delegation
-- click listener
-- AJAX: asynchronous Java and XML
-- binding a method to an event

## Shorthand
-- e for event

## Event handling

Most common events:
-- .on('click', () => {}) or .click()
-- .hover()

### Constraining the scope of an event
Event propagation or bubbling describes how an event is passed from child to parent up the DOM tree.
-- event.stopPropagation() prevents propagation up the DOM
-- event.preventDefault() prevents default action of following links, submitting forms, etc
-- event.isDefaultPrevented() returns true or false value

Event delegation refers to the exploitation of event bubbling to allow a single element to do the work of many.

### Keyboard events
-- keyup and keydown which key was pressed by the user
-- keypress which character was produced
-- .which property contains identifier of key that was pressed, for alphabetic keys the uppercase ASCII value

## jQuery styling methods
-- .addClass() adding a CSS class
-- .removeClass() parameter is optional, without parameters it removes all classes from the targeted set
-- .toggleClass()
-- .css(property, value) requires two strings, doesn't seem to work with margin or padding...
-- .show() and .hide()

## Selectors

CSS selectors
-- '.' class
-- '#' id
-- element
-- etc.

Attribute selectors:
-- `[name="value"]` equals "value"
-- `[name!="value"]` not equal
-- `[name^="value"]` starts with
-- `[name$="value"]` ends with "value"
-- `[name*="value"]` contains "value"
-- `[name]` has the attribute 'name' with any value
-- `[name="value"][name2="value2"]` multiple attributes

jQuery selectors:
-- :even similar to CSS :nth-child(2n+0)
-- :odd
-- :nth-child(odd)
-- :contains(string) filters for selectors with the string value
-- event.target DOM element that initiated the event

Index-related selectors:
-- :eq() select element at index equal to matched set
-- :lt() select all elements at an index less than the index within the matched set
-- :gt() select all elements at an index greater than that within the matched set

Form selectors:
-- :input input, text-area, select, and button elements
-- :button button elements and input elements of type 'button'
-- :enabled form elements that are enabled
-- :disabled form elements that are disabled
-- :checked radio buttons or checkboxes that are checked
-- :selected option elements that are selected

## DOM traversal
-- .parent(), .children(), .siblings() may optionally take a selector as argument
-- .next() selects next sibling
-- .nextAll() selects all following siblings
-- .addBack() includes originally selected element (used after .next() or .nextAll() methods)
-- .filter() method may take a lambda function which will iterate over every element in the matched set and, if evaluated as true, add that element to the filtered set

## DOM Insertion
-- .prepend() insert content as the first child
-- .append() insert content as the last child
-- .before() add content before the matched set
-- .after() add content after the matched set
-- .wrapAll() wrap the entire matched set
-- .wrap() wrap each member of matched set

Alternative syntax (content to be added precedes method, with matched set in the parentheses following)
-- .insertAfter()
-- .insertBefore()
-- .appendTo()
-- .prependTo()

Manipulating attributes:
Multiple attributes can be manipulating by passing the attributes and their values in a JavaScript object
-- .attr()
-- .removeAttr()


# JavaScript

## Functions
- Typical syntax:
`function triple(x) {return 3 * x}`
- Functions can also be restated as variables
`var triple = function(x) {return 3 * x;}`

When a function restated as a variable is passed into another function, it is called a **higher-order function** or a **callback function**. The most commonly encountered such function in JavaScript is .filter()


- Lambda or "arrow" expressions (so-called because of the use of the '=>' arrow operator) offers shorter syntax for anonymous functions.
`(param1, param2, param3...) => { function }`
- Parentheses are optional if only one parameter is being passed, and brackets are optional if the functional is a single expression.
`param => function`

## Running Functions
Within HTML, use the onload attribute to specify the function to be run

## AJAX

node.js

## Loops
`for (statement1; statement2; statement3) {...}`
- Statement 1 sets a variable before the loop starts and is usually `var i = 0;` but it is optional.
- Statement 2 defines the condition for the loop to run, usually `i < n;` but it, too, is optional. So long as it returns true, the loop will start again. If it returns false, the loop ends.
- Statement 3 increments the value of the initial variable, and is usually `i++` but it is optional.

Abbreviated for loop:
`for ( ; i < n; i++ ) { ... }`

## Template literals
back-tick (` `) character encloses template literals (also known as template strings), which can include multi-line strings and use expressions

Ternary operator:
`condition ? expr1 : expr2` If condition is true, then expr1, else expr2

## Animation
including a duration with .show() or .hide()
- 'slow' = 600ms
- 'fast' = 200ms
- 'default' = 400ms
- any number (representing milliseconds)

Fading animations are useful for items that are outside the flow of the document, but using the .fadeIn() method causes the document to jump to accomodate the space needed, which is not ideal. In these cases, .slideUp() and .slideDown() are better choices

### .animate()
comes in two forms, with two patterns for passing arguments
1- 
-- an object of style properties and values
-- duration (optional)
-- easing (optional)
-- callback function (optional)
2-
-- an object of properties
-- an object of options

## Design patterns

### Composite pattern
Treat a collection of objects in the same way we treat a single object instance, such that applying a method on a collection will apply the method to each part of it. In jQuery, the composite pattern is an integral part of the archietcture, where by the matched set of elements is an **Array-like object** that wraps the retrieved elements. 

Array-like object refers to a JavaScript object with a numeric length property as well as a quantity of numbered properties which matches that length. Such that, with a length of 2, the properties 0 and 1 are defined. The numerical indexes allow the object to be traversed using simple for loops (**Bracket Property Accessor syntax**).

### Iterator pattern
Use of a function with the **single responsibility** to traverse a collection and provide access to its items. Single responsibility refers to the concept that a class should only have one reason to change.

### Observer pattern
Observers are objects that watch for changes in an observable, or the subject, during its lifetime. Plain anonymous callback functions are observers, traditionally achieved by EventTarget.addEventListener() method to listen for a click. In jQuery, the .on() method is the go-to.

## Object-oriented JavaScript terms

- **encapsulate** storing neatly in an object
- **abstraction** a simple model of a more complex thing and which represents its most important aspects in a way that is easy to work with
- **object instances** objects that contain data and functionality defined in the class (information about actual individuals following the Person class)
- **constructor function** the function run to define an object instance from a class. By convention constructor function names usually start with a capital letter.
- **instantiation** process of creating an object instance from a class
- **child classes** classes which **inherit** data and code features from a **parent class**
- **polymorphism** the ability of multiple object types to implement the same functionality
- **prototype-based language** refers to how in JavaScript each object has a **prototype object** from which it inherits properties.
- **closure** combination of a function and the lexical environment in which the function was declared
- **callback** function that is passed as an argument to another function/method or assigned to a property of an object and expected to be executed at a later point in time.