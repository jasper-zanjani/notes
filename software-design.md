# Principles of software design

Term                                    | Definition 
:---                                    | :---
Don't repeat yourself (DRY)             | 
High observability principle (HOP)      | principle that recommends a container provide APIs for the runtime environment to observe container health and act accordingly; this is fundamental to automating container updates and lifecycles, allowing a truly cloud-native citizen. At a minimum, APIs must be provided for __liveness__ and __readiness__, but better still is logging of important events into STDERR and STDOUTfor log aggregation by tools such as __Fluentd__ and __Logstash__
Image immutability principle (IIP)      | containers should not change between different environments, rather any change in the containerized application should result in building a new container image which is reused across all environments.
Keep it simple, stupid (KISS)           | 
Life-cycle conformance principle (LCP)  | containers should provide APIs that the managing platform can read and send signals to
Process disposability principle (PDP)   | containers need to be ad ephemeral as possible and ready to be replaced by another container instance at any given moment. This means that containerized applications must keep their __state__ externalized or distributed and redundant.
Runtime confinement principle (RCP)     | containers should not exceed the declared resource requirements, lest it become vulnerable to termination or migration when resource starvation occurs
Self-containment principle (S-CP)       | containers should contain everything it needs at build time 
Separation of concerns (SoC)            | 
Single concern principle (SCP)          | similar to __Single Responsibility Principle__, which recommends that a class should have only one responsibility, but  SCP is intended to ensure container image reuse and replaceability. Every container should address a single __concern__ in a __feature-complete__ way 
Single responsibility, Open/closed, Liskov substitution, Interface segregation, Dependency inversion (SOLID) | guidelines for object-oriented programming, introduced by Robert C. Martin
You aren't gonna need it (YAGNI)        | 

## Best practices for containerized application development
  - __Aim for small images__: remove temporary files and avoid installation of unnecessary packages. This reduces container size, build time, and networking time when copying container images
  - __Support arbitrary user IDs__: allow unprivileged users to run the container
  - __Mark important ports__: use the `EXPOSE` command to specify port numbers
  - __Use volumes for persistent data__: containers themselves must be created and destroyed, so persistent data has to be stored externally
  - __Set image metadata__: tags, labels, and annotations make container images more usable
  - __Synchronize host and image__: time and machine ID

## Software patterns
  - **Sliding window**: pattern used to perform a required operation on a specific window size of a given array or linked list 
  - **Two pointers or iterators**: pattern where two pointers iterate through a data structure in tandem until one or both of them hit a certain condition 
  - **Fast and Slow pointers**: (also Hare and Tortoise algorithm), uses two pointers which move through the data structure at different speeds. Typically used in linked lists.
  - **Merge Intervals**: Technique to deal with overlapping intervals 
  - **Cyclic sort**: iterate over an array one element at a time, placing it at its correct index, swapping it with the element already there.
  - **In-place reversal of linked list**: reverse the links between a set of nodes of a linked list.
  - **Tree Breadth First Search (BFS)**: traverse a tree by ingse a queue to keep track of all nodes of a level before jumping onto the next level. Push the root node to the queue and continue to iterate until the queue is empty. In each iteration, remove the node at the head of the queue, execute, and continue until all nodes are exhausted.
  - **Tree Depth First Search (DFS)**: use recursion or a stack to keep track of all previous nodes while traversing. If a node is not a leaf, you need to decide whether to process the current node immediately or do so while processing children.
  - **Two heaps**: Separate a set of elements into two heaps, a Min Heap and a Max Heap.
  - **Subsets**: BFS approach to create permutations and combinations of a given set of elements
  - **Modified binary search**: Binary Search is the best algorithm to use when searching for a value in a sorted data structure
  - **Top K elements**: find K elements at an extreme (i.e. top, smallest, most frequent, etc). The best data structure to use to keep track of these is a heap of size K, because it will automatically keep track of these elements.
  - **K-Way Merge**: given K sorted arrays, use a Heap to efficiently traverse all the elements of all arrays.
  - **Topological sort**: find a linear ordering of elements that have dependencies on each other. Use a HashMap to store the graph in adjacency lists.

#### In-place reversal of linked list
Without using extra memory, reverse the links betwen a set of nodes of a linked list.

## Sources
  - [redhat.com](https://www.redhat.com/en/resources/cloud-native-container-design-whitepaper?sc_cid=70160000001273HAAQ)
  - "14 Patterns to Ace Any Coding Interview Question". [Hackernoon](https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed?source=rss)