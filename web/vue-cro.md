# Coursetro tutorial

### Introduction to Vue

#### Install Vue CLI and run development server
```sh
yarn serve
```
- _HelloWorld.vue_ Rename to _Skills.vue_
- _Skills.vue_ Change value of `name` property in the `export default` object to `Skills`,
- Empty `props` property within `export default` object
- Delete contents of `template div` tag, replace with string "Skills"
- _App.vue_ Replace `HelloWorld` with `Skills` in `import` statement and `components` property.
- Replace `HelloWorld` tag with `Skills` in `<template>` section, and remove `msg` argument.
- Remove `img` tag displaying logo.
- _Skills.vue_: Replace `props` property with `data()` function, returning `{ name: 'Coursetro' }`
- Replace string "Skills" with `{{ name }}`

```html
<div class="hello"> {{ name }}
```

- Insert and disable button
```
button(@click="changeName", : disabled = "btnState") Change Name

export default {
  name: 'Skills',
  data() {
    return {
      name: 'Coursetro',
      btnState: true
    }
  }
}
```

#### Use of ternary operator within double-curly braces
```jade
.hello
  | {{ name }}
  | {{ btnState ? 'The button is disabled' : 'The button is active' }}
button(@click="changeName", : disabled = "btnState") Change Name
```
- In order to demonstrate the `v-for` directive, we construct an array of objects. Remove `name` and `btnState` properties from return object.
```js
data() {
  return {
    skills: [
      { "skill": "Vue.js"},
      { "skill": "Frontend Developer"}
    ]
  }
}
```

### Directives
- Produce an unordered list using the `v-for` directive, interpolating the newly-created skills returned from the logic section.
    
```

    .hello
     .holder
      ul
       li(v-for="(data, index) in skills", :key='index')
        | {{ index }}. {{ data.skill }}
    
```

- Insert paragraphs that appear on certain conditions, using `v-if` and `v-else` directives.
    
```

    <p v-if="skills.length > 1">You have more than 1 skill</p>
    <p v-else>You have less than or equal to 1 skill</p>
    
```

### Styling
- Compare what happens with and without `scoped` keyword 

```
<style scoped>
  body { background-color: #eeeeee; } // Light grey background
</style>
    
```

- External stylesheets:
    
```
<style src="./Skills.css" scoped></style>
```
    
```
ul { list-style-type: none; }
li { font-weight: bold;     }
```

- Binding class with `v-bind` directive (will not work if reference to external stylesheet is not removed)
    Show `div.alert` only when boolean `showAlert` is true
    
```

<div v-bind:class="{ alert: showAlert }"></div>  
...
export default {
  name: 'Skills',
  data() {
  return {
    skills: [
      { "skill": "Vue.js"},
      { "skill": "Frontend Developer"}
    ],
    showAlert: true

...

.alert {
  background-color: yellow;
  width: 100%;
  height: 30px;
}
    
```

- Multiple classes can be bound by separating them with a comma
    
```

<div v-bind:class="{ alert: showAlert, 'another-class': showClass }"></div> 

data() {
  return {
    showAlert: true,
    showClass: true
...
...
another-class { border: 5px black solid; }

    
```

- Binding styling
    
```

<div v-bind:style="{ backgroundColor: bgColor, width: bgWidth, height: bgHeight}">
...
return {
  skills: [
    { "skill": "Vue.js"},
    { "skill": "Frontend Developer"}
  ],
  bgColor: 'yellow',
  bgWidth: '100%',
  bgHeight: '30px'
}

    
```

### Returning to the project
- Add a `p` reading 'These are the skills that you possess' beneath the `ul`
- Remove `{{index}}` from the `li`
- Import styling
### Handling user-submitted data: forms and form-validation
`v-model` directive enables two-way data binding to allow communication between logic and `template` sections
- Add an `input` field above `ul` with styling
    
```

input(type="text", placeholder='Enter a skill you have...', v-model="skill")
  | {{skill}}

input {
  width: calc(100% - 40px);
  border: 0;
  padding: 20px;
  font-size: 1.3em;
  background-color: #323333;
  color: #687F7F;
}
    
```

- Remove properties associated with previous tutorial segments 
- Add `skill` property, value is an empty string
- Add `form` which calls method `addSkill` upon form submission
    
```

<form @submit.prevent="addSkill">
  <input type='text' placeholder='Enter a skill you have...' v-model="skill"/>
  {{ skill }}
</form>
    
```

- Add `addSkill` method under a new `methods` property, child to the `data` method
    
```

methods: {
  addSkill() {
  this.skills.push({skill:this.skill}) // add to skills array in `data()`
  this.skill = ''; // clear out value of input field, which is bound to `skill`
}}
    
```

- Demonstrate that methods have access to other data by temporarily adding a `checkbox` 
    
```

<input type="checkbox" id="checkbox" v-model="checked">
...
checked: false,
...
console.log('The checkbox value is: ' + this.checked)

    
```

### Vue form validation
A popular package for validation in Vue is _vee-validate_
- $ `yarn add vee-validate`
- _main.js_
`import VeeValidate from 'vee-validate'`
    `Vue.use(VeeValidate);`
Now with the _vee-validate_ package installed and available, we can validate the form data

- Reject entries less than 5 characters. _Vee-validate_ needs an input field with a `name` attribute defined.
    
```

input(
  type='text', 
  placeholder='Enter a skill you have...', 
  v-model='skill',
  v-validate="'min:5'" ,
  name="skill")
  | {{skill}}
    
```

- Styling the new error paragraph
    
```

.alert {
  background: #fdf2ce;
  font-weight: bold;
  display: inline-block;
  padding: 5px;
  margin-top: -20px;
}
    
```

Although the error message appears, a user may still submit data that does not meet the 5-character limit. We wrap the method calls in the `addSkill()` method within a conditional that uses more `vee-validate` syntax

```

this .$validator.validateAll().then((result) => {
  if (result) {
    this.skills.push({skill:this.skill})
    this.skill = ''; // clear out value of input field, which is bound to `skill`
  } else
    console.log("not valid")
})

```

### Animations
The biggest use-case for animations is enter and leave animations. We draw our attention to the `alert` class paragraph, which we will wrap in a `transition` tag with a `name` attribute set to `alert-in`. This attribute value will serve as a prefix for CSS styling.
    
```

transition(name="alert-in")
  p.alert(v-if="errors.has('skill')")
    | {{errors.first('skill')}} 
    
```

In order to make it animate, CSS styling must be defined. The classes below reflect the "alert-in" defined in the `transition` element's `name` attribute
    
```

.alert-in-enter-active {
  animation: bounce-in 0.5s;
}
.alert-in-leave-active {
  animation: bounce-in 0.5s reverse;
}

@keyframes bounce-in {
  0%  {transform: scale(0);}
  40% {transform: scale(1.5);}
  60% {transform: scale(1);}
}
```

### Using animation libraries
A third-party animation library like _animate.css_ can be used as well. 
```
@import url('https://cdn.jsdelivr.net/npm/animate.css@3.5.1');
`
    
```
transition(
  name="alert-in", 
  enter-active-class="aniamted flipInX" 
  leave-active-class="animated flipOutX"
)
```

Use a custom component wrapper called `transition-group` to wrap the `li`s
    
```jade
transition-group(name="list", enter-active-class="animated bounceInUp", leave-active-class="animated bounceOutDown")
  li(v-for="(data,index) in skills", :key='index') {{data.skill}}
```

### Routing
- $ `yarn add vue-router`
- Create a new file within the _src_ folder: _router.js_

```
import Vue from 'vue'
import Router from 'vue-router'
import Skills from './components/Skills.vue'
import About from './components/About.vue'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'skills',
      component: Skills
    },
    {
      path: './about',
      name: 'about',
      component: About
    }
  ]
})
```

### Create a new component named _About.vue_

```jade
<template lang="pug">
  .about
    h1 This is an about page
    p Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
</template>
```

#### Import the router into _main.js_, add the router component to the Vue instance

```js
import Vue from 'vue'
import App from './App.vue'
import VeeValidate from 'vee-validate'
import router from './router'

Vue.use(VeeValidate);

Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
```

- In _App.vue_, add `nav`element with `router-link`s pointing to the routes we established 

```html
<template lang="pug">
  #app
    nav
      router-link(to='/') Home
      router-link(to='/about') About
    router-view
</template>
```

- Add styling for `nav` element

```css
nav {
  padding: 20px 20px 20px 0;
}
nav a {
  padding: 10px;
  text-decoration: none;
  background: #fff;
  border-radius: 3px;
  color: rgb(0,110,255);
  font-weight: bold;
  margin-right: 15px;
}
```

### Add a delete button to remove entries, including a new `remove` method, and including the Font Awesome library from Bootstrap
#### Template
```jade
i.fa.fa-minus-circle(v-on:click="remove(index)")
```
#### Logic
```js
remove(id) {
  this.skills.splice(id,1);
}
```
#### Style
```css
@import url('https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.mins.css');
```

