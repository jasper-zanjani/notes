# React Native
_React Native_ is like react, but it uses native components instead of web components as building blocks, allowing true mobile apps to be programmed.


## Hello world
    import React, { Component } from 'react';
    import { Text, View } from 'react-native';

    export default class HelloWorldApp extends Component {
    render() {
     return (
      <View>
       <Text>Hello world!</Text>
      </View>
     );
    }}



## Components
- `Text`
Display text

- `Image`
Syntax: `<Image source={pic} style{{width: 193, height: 110}}/>` where `pic` is an object containing a `uri` property

- `View`
Similar to `<div>` or `<span>`

Two types of data control a component: 
1. `props`
set by the parent are fixed throughout the lifetime of a component
2. `state`
data that changes


### Props
Parameters associated with customizing components are called _props_. They appear similar to HTML attributes:
    
    <Greeting name='Jaina'/>
    <Greeting name='Sanjay'/>`

### State
