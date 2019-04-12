Vue.js, a progressive frontend JavaScript framework, a mixture of Angular and React syntactically.

- Comparison with React
  - **HTML** Unlike React, which expresses HTML structures (and even CSS) as JSX, Vue uses templates as a simpler alternative. This allows the division of components into logical and presentational categories. It is easier and more maintainable to work with default HTML.
  - **Styling** Vue supports default CSS styling within the `style` tags. In contrast, scoping CSS in React is often done via _CSS-in-JS_ solutions, often requiring a runtime to be included for styling to work properly which increases bundle size and runtime cost.
  - **Scaling** Routing in React is done by state management solutions such as _Flux_ and _Redux_. Vue has built on this model with its own router and state management system: _Vuex_.
  - **Difficulty** React is known for a steep learning curve, requiring knowledge of JSX and ES2015+ due to React's class syntax as well as _build systems_.
  - **Native rendering** React has _React Native_. Vue has an official collaboration with a cross-platform UI framework called _Weex_ which allows the same Vue component syntax to build components for the web as well as for native applications. Another option that will be available soon is a community-driven plugin called _NativeScript_.
- Installation
  - Vue can be used through the CDN, as if it were a JavaScript library. Alternatively, you can use `npm` to install it locally and use it as a locally stored library.

- `npm i -g @vue/cli` Install Vue CLI
- `vue create vue-skills` Create a Vue project
- `cd vue-skills` Navigate into Vue project directory
- `yarn serve` or `npm run serve` Start development server
## Vue instance

- Instantiation
  - _main.js_ `new Vue({...})` generates a new _root Vue instance_.
  - an objects object is passed
- Properties
  - `computed` : computed properties associated with the component
  - `data()` : object containing values, changes to which will cause Vue to react by updating to match the new values
  - `el` : identifies the DOM element upon which the application will be mounted; only used in root components initialized using `new Vue({})`
  - `methods` : containing functions which are used as methods in `template`. Methods should be defined conventionally, because with arrow functions the `this` keyword is not bound to the component.
  - `props` : all properties that can be passed to a child component
  - `template` : where component template is set up, which wil define component output

```

new Vue({
 el: { title: 'Hello World' },
 methods: {
  changeTitle() { this.title = 'Changed Title'}
}})

```


```
#app
  button(v-on:click="changeTitle") Change title
  p {{ title }}

```

## File architecture and structure

`.vue` single file components are separated into three areas: `template`, `script`, and `style`

- Contents of _src/_ directory:
  - _src/main.js_ primary file for the application: includes imports for Vue and components

```
import Vue from 'vue'
import App from './App'

new Vue({
  el: '#app',
  components: { App },
  template: '<App/>'
})

```

- _src/App.vue_

## Components

Can be defined in 4 ways:

1. `new Vue ({ ... })` standard way of instantiating Vue when building an application that uses Vue.js in only some pages, such as a contact form or in the shopping cart.
2. `Vue.component('component-name', { ... })`
3. Using local components, only accessible by a specific component.
4. Single File components.

- `import MODULE from './components/MODULE.vue'` import modules

## Syntax
- similar to AngularJS because AngularJS inspired Vue's developers.
- _mustaches_ or double-curly-braces -  `{{ expression }}` - to _interpolate_ data values into HTML, similar to string literal syntax.
  - can contain an entire (single) JavaScript expression, such as ternary operations and arithmetic using some global objects like `Math` and `Date`.
  - not available to define HTML attributes (`v-bind` directive must be used instead).
### Lifecycle hooks
Give users the opportunity to add code at specific stages of the instance's lifecycle
1. `beforeCreate`
2. `created`
3. `beforeMount`
4. `mounted`
5. `beforeUpdate`
6. `updated`
7. `beforeDestroy`
8. `destroyed`
### Directives
Directives are special attributes prefixed with `v-` whose values are expected to be a single JavaScript expression, and which are meant to reactively apply side effects to the DOM when the expression value changes.

- `v-bind` dynamically binds one or more attributes
    - `<img v-bind:src="imageSrc">` bind an attribute
    `<img :src="imageSrc">` shorthand
    - `<img :src="'/path/to/images/' + fileName">` with inline string concatenation
    - `<div :class="{ red: isRed }"></div>` class binding
      `<div :class="[classA, classB]"></div>`
    - `<div :style="{ fontSize: size + 'px' }"></div>` style binding
    `<div :style="[styleObjectA, styleObjectB]"></div>`
    - `<div v-bind="{ id: someProp, 'other-attr': otherProp }"></div>` binding an object of attributes
    - `<div v-bind:text-content.prop="text"></div>` DOM attribute binding with prop modifier
    - `<my-component :prop="someThing"></my-component>` prop binding. "prop" must be declared in my-component.
    - `<child-component v-bind="$props"></child-component>` pass down parent props in common with a child component
    - `<svg><a :xlink:special="foo"></a></svg>` XLink
- `v-cloak`
- `v-else` (step 15)
- `v-else-if`
- `v-html` used to include actual HTML that will render (as opposed to raw text)
- `v-if` display an element based on value of boolean value. syntax: `v-if="VALUE"` (step 15)
- `v-model` creates a two-way binding where a template element is changed based on a form input element or component (`input`, `select`, or `textarea` elements or components); syntax: `v-model="PROPERTY"`
- `v-on`
    - shorthand: `@click` instead of `v-on:click`
- `v-once` suppresses reactivity; updates to data values will not update the DOM. It is always escaped, so it cannot contain HTML (use `v-html` instead), and it takes no arguments: `<span v-once> This will never change: {{ msg}} </span>`
- `v-pre` empty directive which means markup within element will not be compiled
- `v-ref` pass a literal string, not a reactive expression.
- `v-show` toggles CSS `display` property based on truth of expression
- `v-text` essentially an alternative to interpolation; updates element's `textContent` when the expression property on the Vue instance changes:
  `<div v-text="message"></div>`
- `v-transition`

-  `v-for` requires special syntax of the form `item in items` where `item` is an alias for the array element being iterated on and `items` is the source data array

```
ul#example-1
  li(v-for="item in items")
    | {{ item.message}}

var example1 = new Vue({
  el: '#example-1',
  data: {
    items: [
      { message: 'Foo'},
      { message: 'Bar'}
    ]
  }
})
```

  - Supports an optional second argument for the index of the current item (to support ordered lists) `(item, index) in items`

```
ul#example-2
  li(v-for="(item, index) in items)
    | {{ parentMessage }} - {{ index }} - {{ item.message }}

var example2 = new Vue({
  el: '#example-2',
  data: {
    parentMessage: 'Parent',
    items: [
      { message: 'Foo'},
      { message: 'Bar'}
    ]
  }
})
```

  - Also supports use of `of` instead of `in` as the delimiter, bringing it closer to JavaScript's syntax for iterators `item of items` etc
  - Can be used to iterate through the properties of an object.

```

ul#v-for-object.demo
li(v-for="value in object")
  | {{ value }}

new Vue({
    el: '#v-for-object',
    data: {
        object: {
            firstName: 'John',
            lastName: 'Doe',
            age: 30
        }
    }
})

```

  - A second argument in such a case will produce the key

```

div(v-for="(value, key, index) in object")
 | {{ index +1 }}. {{ key }}: {{ value}}

```

  - It is recommended to provide a key with `v-for` whenever possible, using `v-bind`

- `v-on` used to listen to DOM events and run JavaScript when triggered.
  - Takes simple expressions

```

#example-1
 button(@click="counter+=1") Add 1
 p The button has been clicked
  | {{ counter }} times

new Vue({
    el: '#example-1',
    data: {
        counter: 0
    }
})

```

  - Can call methods

```

#example-2
 button(@click='greet') Hello!

new Vue({
    el: '#example-2',
    data: {
        name: 'Vue.js'
    },
    methods: {
        greet: function (event) {
            // `this` inside methods points to the Vue instance
            alert('Hello ' + this.name + '!')

            // `event` is the native DOM event
            if (event) {
                alert(event.target.tagName)
            }
        }
    }
})

```

- Arguments can be passed to methods

```

#example-3
button(@click="say('hi')) Say hi
button(@click="say('what')) Say what

methods:{
say: function() (message) {
  alert(message)
}
}

```

_Event modifiers_ are directive postfixes denoted by a dot.
  - `.stop` stops propagation: `a(@click.stop="doThis")`
  - `.prevent` prevents default action: `form(@submit.prevent="onSubmit")`
  - They can be chained: `a(@click.stop.prevent="onSubmit")`
  - `.once` will prevent more than one event: `button(@click.once)`
  Keyboard events handled using `keyCodes`, e.g. `@keyup.13`
  - Some special keys are supported by aliases: `.enter`, `.tab`, `.delete`, `.exc`, `.space`, `.up`, `.down`, `.left`, `.right`, e.g. `@keyup.enter`
  - System modifier keys are also supported: `.ctrl`, `.alt`, `.shift`, `.meta` (⌘ Command on Mac  or ⊞ on Windows computers): e.g. `@keyup.alt.67` Alt+C, @click.ctrl Ctrl+click
  - Mouse buttons: `.left`, `right`, `middle`


