# Microsoft Azure

## Web Apps
__Web Apps__ represent Azure's __PaaS__ product. It is part of the __App Service__ family.

Other __App Service__ family members:
  - Mobile Apps
  - API Apps
  - Logic Apps

Each App Service resource is associated with a __service plan__, which defines the amount of resources available.

Service plan tiers:
  - Free/Shared: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
  - Basic: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
  - Standard: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
  - Premium: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.

## Storage


## Role assignments and classic administrators
VMs represent Azure's __IaaS__ product.
Manage access to Azure resources using __role-based access control (RBAC)__. __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.


## Sources
  - Foulds, Iain. _Learn Azure in a Month of Lunches_. [sources/lzml.md](../sources/lzml.md)