Web Components is a suite of technologies allowing you to create reusable custom elements

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