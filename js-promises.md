promises

promise: eventual result of an asynchronous operation

Stages: wrapping, then-ing, catching, chaining

promises can be in one of 4 states:
- `fulfilled`: action relating to the promise succeeded
- `reject`: action relating to the promise failed
- `pending`: has not fulfilled or rejected yet
- `settled`: has fulfilled or rejected

promises vs. events
- an event listener registered after an event has occurred will never fire
- an action set for resolution can fire after a promise has already resolved
- an event can fire many times, but promises can only settle once


promise is a try/catch wrapper around code that will finish at an unpredictable time

A `Promise` takes a function as argument. That function takes two arguments: `resolve` and `reject`. They are both callbacks that will execute when the promise has succeeded or failed

any argument passed to `resolve` or `reject`, will then be received by `then` or `catch` methods, respectively

`resolve` leads to the next `then` in the chain, and `reject` leads to the next `catch`