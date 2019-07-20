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

## Sources
  - [redhat.com](https://www.redhat.com/en/resources/cloud-native-container-design-whitepaper?sc_cid=70160000001273HAAQ)
