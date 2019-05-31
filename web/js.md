# JavaScript
Programming language of the web, run by all browsers on all devices. 

## History
Originally created by Netscape and its name originated from a licensing deal with Oracle. When the language was submitted to a European standardization body, the name of the standardized version became _ECMAscript_ because of licensing issues: similarly, Microsoft’s version is referred to as JScript.

## Variables
`var a`
: declaring a variable
`var a = 0`
: initializing a variable (giving it a value for the first time)
`var A = 1`
: variable names are case-sensitive
`console.log()`:
: print text to the console `console.log('Hello world!')`

`//`
: single line comments; 

```js
/************************ 
	* Multi-line comments *
	*********************** */ 
```

## Operators
Operators perform an operation on one or more values or variables.
`typeof`
:	return data type

### Logical operators
`!`
: NOT; can be used repeatedly, e.g. `var a = !!true`
`&&`
: AND takes precedence over 
`||`
: OR 

### Comparison operators
`==`
: equality (loose) comparison
`===`
: equality and type (strict) comparison
`!=` 
: non-equality comparison
`!==`
: non-equality without type conversion

## Primitive data types
Five primitive data types in JavaScript
1. Numbers, floating-point as well as integers
2. Strings, including single characters
3. Boolean
4. Undefined, which is the data type assigned to variables which have been declared without a value assigned
5. Null, with a value of nothing
Non-primitive data types are _objects_

### Type conversion
Primitives are converted to one another automatically in many cases, but the simplest way to convert types explicitly is to use the `Boolean()`, `String()`, `Number()`, and `Object()` functions
### Numbers
JavaScript doesn't distinguish between integers and floats: both are numbers.
- `0377`, `0o377` octal (255)
- `0xff` hexadecimal (255)
- `0b111` binary literals
- `1e1`, `2e-3` exponent literals (1 x 10^1)
- `Infinity` any number larger than 1.79769...e308
- `> Infinity - Infinity;` returns `NaN` "Not a Number"
- `> x != x` only returns true for NaN values
- `typeof NaN;` returns `number` because NaN is also a number
## Strings
Any sequence of characters placed between single- or double-quotes. Empty strings can be defined.
### String conversion
```js
var s = '100'
> s = s * 1
> typeof s
```
: strings can be converted to numbers by multiplication with 2

- Numbers can be converted to strings by concatenation with an empty string (+ operator)
```
var n = 100;      // n is a number `

>n = "" + n
>typeof n         // "string"
```
#### Special strings
- `var a = 'I don\'t know'` backslash is the escape character used here to produce an actual quote character, instead of ending the string.
- 
	var a = '\\'            // Escape character is escaped

	> console.log(a);       // "\"

	> console.log('\n1\n2\n3'); // \n produces an "end of line"
	"
	1
	2
	3"

	var a = '\r1\r2\r3'     // \r produces a "carriage return"

	> console.log(a);
	"
	1
	2
	3"

	var a = '1\t2'          // \t produces a tab
	var a = '\u0421'        // \u followed by a character code allows
	                        // use of Unicode -->

### String methods
- `string.toLowerCase()`
	Convert uppercase to lowercase
- `string.length`
	Returns length of string
- `string.startsWith(searchString)`
	Searching for substring

### String template literals (2 types)
1. **Template literals**  
	Single- or multiple-line strings with embedded expressions. These can also be used simply to output multi-line strings with no embedded expressions.
2. **Tagged Template Literals**  
	An expression is prefixed to the template literal, which is then considered a function to be invoked.

Template literals are marked by the **\`** backtick character and use **${…}** expressions as placeholders for the text to be inserted.

Multi-line string output
```
console.log('This is line one \n' + 'and this is line two')
	console.log(`This is line one and this is line two`)

	var a = 'debug'
	var b = 'meltdown'

	// Using concatenation instead of template literals:
	var c = 'Log level: ' + a + ' - message : ' + b

	// Template literals with embedded expressions
	var c = `Log level: ${a} - message: ${b}`
```
### RegEx
JavaScript defines a `RegExp()` constructor for regular expressions, which can be encoded directly by enclosing text between forward slashes
## Booleans
Boolean conversion
Double negation (!!) can convert any value to its boolean equivalent. Most values convert to truth (truthy values), except for the following 6 falsy values: `""`, `null`, `undefined`, `0`, `NaN`, `false`.
## Functions
- Defining a function function triple(x) { return 3*x }
- Functions can also be restated as variables	`var triple = function(x) { return 3*x }`
- `onload` attribute to specify JavaScript function to run upon page load

When a function restated as a variable is passed into another function, it is called a **higher-order function** or a **callback function**. The most commonly encountered such function in JavaScript is `.filter()`

### Arrow functions
Lambda or "arrow" expressions (so-called because of the use of the `=>` arrow operator) offers shorter syntax for anonymous functions. `(param1, param2, param3) => { function }` 
Parentheses are _optional if only one parameter is being passed_, and brackets are _optional if the functional is a single expression_: `param => function`

### Rest parameters and spread operator (...args)
Rest parameters condense multiple elements into an array
```
function multiply(factor, ...nums) {
	return nums.map(function(element) {  // Returns an array of each
		return factor * element            // nums argument multiplied by the factor
	}
}
multiply(3,0,2,5)) //? [0,6,15]
```
Spread operator “spreads out” array elements individually in a variety of contexts:
`var arr1 = [0,1,2]` `var arr2 = [3,4,5]`
- to concatenate arrays
	`newarray = [...arr1, ...arr2] //? [0,1,2,3,4,5]`
- to add array elements to another
	`newarray = [...arr1,3,4,5]    //? [0,1,2,3,4,5]`
- to copy arrays
```
arr4 = [...arr1]
arr4.push(4)
console.log(arr1) //? [0,1,2]   Where normally it would refer to the same array as arr4
console.log(arr4) //? [0,1,2,4]
```	
- to pass array elements as arguments of a function
	`function addNums(x,y,z) { console.log(x+y+z) }` 
	```
	addNums(...arr1) //? 3
	```
## Spread operator
```
const first = [1,2,3]
const second = [4,5,6]
// const combined = first.concat(second);  // old way
const combined = [...first, ...second]; // spread operator

const first = {name: 'Mosh'}
const second = {job: 'Instructor'}
const combined = { ...first, ...second, location: 'Australia'}
```
## Conditionals
- `if`
- `?:` ternary operator
- `switch` `case`
```
var a = '1', result = ''
switch (a) {   // Switch statement followed by an expression in parentheses
case 1:
	result = 'Number 1'
	break     // Optional break statement signals end of case block, without which the program proceeds to the next case block.
case '1':
	result = 'String 1'
	break
default:    // optional, executed if none of the previous cases evaluates to true
	result = 'I don\'t know'
	break
}
```
## Loops
4 types of loops: `while`, `do-while`, `for`, `for-in`
## Functions and methods
- `parseInt(string, [radix])` converts to integer
- `parseFloat(string)` converts strings to float numbers
- `isNaN(number)` returns true if number is NaN
- `isFinite(number)` returns true if number is finite
- `Number.isNaN()` returns true if the value in parentheses resolves to NaN: `console.log(Number.isNaN(NaN));` returns `true`
- `Number.isInteger()` returns true if the number is finite and does not contain any decimal points
## Objects
- `delete book.author` deleting properties
## ECMAScript 2018
Using spread operator with object destructuring
```
const user = {
	firstName: 'Michael',
	lastName: 'Ironside',
	twitter: 'whatever',
	city: 'Toronto',
	email: 'mirons@yahoo.com'
}
const {city, ...userNoCity} = user

city //? 'Toronto'
userNoCity //? { firstName: 'Michael', lastName: 'Ironside', twitter: 'whatever', email: mirons@yahoo.com'}
```
- `'Mattias Petter Johansson'.match(/(mattias).+(johansson)/i)` returns array of results
	- [0] : Mattias Petter Johansson
	- [1] : Mattias
	- [2] : Johansson

## Regex
`/PATTERN/MODIFIERS`
- `const pattern = /w3schools/i`
- `const pattern = new RegExp('w3schools/i')`
Both of these create a new regExp object and assign it to the variable `pattern`
### Modifiers
- `i` case-insensitive
- `g` global match (find all matches rather than stopping after the first match)
- `m` perform multiline matching
### Methods
- `exec()` searches a string for a specified pattern and returns the found text
	`/e/.exec('The best things in life are free!')`
- `test()` test for a match in a string, returns true or false
- `toString()` returns string value of the regular expression
### Object properties
- `global` checks whether `g` modifier is set
- `ignoreCase` checks whether `i` modifier is set
- `lastIndex` specifies index at which to start the next match
- `multiline`checks whether `m` modifier is set
- `source` returns text of the RegEx pattern
### Quantifiers
`n+` matches any string that contains at least one `n`
`n*` matches any string that contains zero or more occurrences of `n`
`n?` matches any string that contains zero or one occurrences of `n`
`n{X}` matches any string that contains a sequence of X `n`s
`n{X,Y}` matches any string that contains a sequence of X to Y `n`s
`n{X,}` matches any string that contains a sequence of at least X `n`s
`n$` matches any string with `n` at the end of it
`^n` matches any string with `n` at the beginning of it
`?=n` matches any string that is followed by a specific string `n`
 `?!n` matches any string that is not followed by a specific string `n`
### Metacharacters
`.`
: single character, except newline or line terminator
`\w`
: find a word character
`\W`
: find a non-word character
`\d`
: find a digit
`\D`
: find a non-digit character
`\s`
: find a whitespace character
`\S`
: find a non-whitespace character
`\b`
: find a match at the beginning or end of a word
`\B`
: find a match not at the beginning/end of a word
`\0`
: find a NUL character
`\n`
: newline
`\r`
: carriage return
`\f`
: form feed
`\t`
: tab
`\v`
: vertical tab
`\xxx`
: character specified by octal number xxx
`\xdd`
: character specified by hex number dd
`\uxxxx`
: Unicode character specified by hexadecimal number {xxxx}

## Web components
A suite of technologies that allows you to create reusable custom elements

## 3 main technologies:

1. _Custom elements_ set of APIs that allow you to define custom elements and their behavior
2. _Shadow DOM_ set of APIs for attaching an encapsulated shadow DOM tree to an element, rendered separately from the main document DOM, to keep an element's features private.
3. _HTML templates_ write markup templates using `template` and `slot` elements that are not rendered in the rendered page.

## Basic approach:

1. Create a `class` or function in which you specify web component functionality
  - must use `super()` command at the top
  - must contain a `constructor()` function that defines structure of Shadow DOM using `appendChild()` methods

2. Use `CustomElementRegistry.define()` to link the component `class` and the custom element
3. Attach a Shadow DOM to custom element using `Element.attachShadow()` and add children, event listeners, using regular DOM methods: `const shadow = this.attachShadow({mode: 'open'})`
4. Define an HTML template using `template` and `slot`
5. Use custom element at will on page.

## 2 types of custom elements:

1. Autonomous custom elements are standalone and don't inherit from standard HTML elements, e.g. `<popup-info>` or `document.createElement('popup-info')`. They almost always extend `HTMLElement`
2. Customized built-in elements inherit from basic HTML elements, e.g. `<p is="word-count">` or `document.createElement("p",{ is: "word-count"})`

## Lifecycle callbacks

`adoptedCallback` invoked each time the custom element is moved to a new document
`attributeChangedCallback` invoked when one of the custom element's attributed is added, removed, or changed
`connectedCallback` invoked every time the custom element is appended into a document-connected element
`disconnectedCallback` invoked each time the custom element is disconnected from the document's DOM
