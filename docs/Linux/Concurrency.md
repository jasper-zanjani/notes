# Concurrency

## Glossary

#### Linearizability
:   
    In concurrent programming, an operation is linearizable if it consists of an ordered list of callbacks that may be extended by adding response events such that:

    - The extended list is [serializable](#serializability)
    - The serializable sequential history is a subset of the original unextended list

#### Lock
:   
    When a thread wants a lock already owned by another thread, the thread is blocked and must wait until the lock becomes free.

    - [Spinning locks](#spinlock) are suitable for very short timeframes
    - Sleeping locks, including [mutexes](#mutex)

    The Linux kernel also provides CPU local locks

#### Mutex
:   
    In the Linux kernel, **mutex** refers to a particular [locking](#lock) primitive that enforces [serialization](#serializability) on shared memory systems.

#### Serializability
:   
    In transaction processing, a transaction schedule is **serializable** if its outcome is equal to the outcome of its individual transactions executed serially.
    Because transactions are normally executed concurrently, this is the major correctness criterion for concurrent transactions.

#### Spinlock
:   
    A lock that causes a thread trying to acquire it to simply wait in a loop ("spin") while repeatedly checking whether the lock is available.

#### Transaction
:   
    In computer science, transactions are individual, indivisible operations that must succeed or fail as a complete unit. Transaction processing guards against hardware and software errors that might leave a transaction partially completed. These operations are executed on databases or modern filesystems to ensure the system is in a consistent state.