# Random

There are [two](https://lwn.net/SubscriberLink/884875/58f88e6eb7913686/) random-number devices in the kernel. Historically:

- **/dev/random**  blocked until it had sufficient entropy to return a random value
- **/dev/urandom** never blocked but resorted to a pseudorandom number generator (PRNG) in the case of insufficient entropy

However, in 2020 the behavior of /dev/random was changed to make it behave more like the [**getrandom syscall**](/Coding/C/#getrandom), in that it blocks only on initialization and provides cryptographic-strength random numbers thereafter without blocking.
This has resulted in a blurring of the lines between the two random devices and an effort to remove /dev/urandom for good.

