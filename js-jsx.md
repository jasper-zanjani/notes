# JSX
Syntactic sugar for the `React.createElement(component,props,...children)` function. 

`<MyComponent param1="1" param2={2}>Text</MyComponent>` compiles to:

    React.createElement(
     myComponent,
     {param1: "1", param2: 2},
     'Text'
    )

## React element type
First part of a JSX tag determines type of React element. Lower-case type indicates it is an HTML tag and it will compile to a string, but a capitalized type indicates the type is a React component. Thus, user-defined components must be capitalized.

- React must always be in scope
Even if React is loaded from a `<script>` tag, it is in scope as the `React` global.
- Components can be called using dot-notation

## Props
Any JavaScript expression can be passed as a prop by surrounding it with curly braces `{}`

    <MyComponent foo={1 + 2 + 3 + 4} /> // props.foo = 10

Curly braces can be used to embed a JavaScript expression in an attribute:

    const element = <img src={user.avatarUrl}></img>;

- Conditionals and loops are not expressions but statements, so they must be placed in surrounding code.
- Default values for props with no value is `true`
- String literals can be passed as a prop `<MyComponent message={'hello world'}/>` or `<MyComponent message="hello world"/>`
- Spread operator can pass all props if they're defined in an object. These two are equivalent:

        return <Greeting firstName="Ben" lastName="Hector"/>

        const props={firstName: 'Ben', lastName: 'Hector'}
        return <Greeting {...props} />

## Children
If there are no children, tags can self-close
`<span className="sidebar"/>` compiles to:

    React.createElement(
     'span',
     {className: 'sidebar'},
     null
    )

Valid children
- String literals
- Arrays of elements
- JavaScript expressions
- Functions
- Booleans, `null`, and `undefined` do not render. Because JavaScript returns the last value in an `&&` expression, this can be used to show or hide elements based on truthiness: `{showHeader && <Header />}` will only render `<Header />` if `showHeader` is `true`.