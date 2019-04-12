# C programming language
## C is not a low-level programming language
Source: [Article](https://queue.acm.org/detail.cfm?id=3212479)

Despite C's reputation as a low-level programming language, in fact it merely emulates the ancient PDP-11, which is the only machine for which its abstract machine can be described as "close to the metal". 
In the age of parallel processes, C's serial nature 

### quotes
"A programming language is low level when its programs require attention to the irrelevant." - Alan Perlis

### terms
SROA
: "scalar replacement of aggregates", one of the core optimizations that a C compiler performs; attempts to replace `struct`s and arrays with fixed lengths with individual variables, which allows the compiler to treat accesses as independent and elide operations entirely if it can prove the results are neve visible, which also deletes padding sometimes

loop unswitching
: one of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control

register rename engine
: component of modern high-end cores which is one of the largest consumers of die area and power

segmented architecture
: pointers might be segment IDs and an offset

SVE
: scalar vector extensions, produced by ARM
