# Microsoft Azure Concepts

## High availability, fault tolerance, and disaster recovery

Fault tolerance | a system's ability to __continue operating properly__ when one or more of its components fails | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
High availability | maintaining __acceptable continuous performance__ despite temporary load fluctuations or failures in services, hardware, or data centers | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
Disaster recovery | a system's ability to __backup and restore data/apps/resources__ when needed | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)

Data centers offer several __redundancies__ to ensure high availability: power supplies, cooling facilities, networking, etc. Availability zone redundancies offer 1 or more data centers for every region zone.

Fault tolerance approaches can be __proactive__ or __reactive__
  - Proactive
    - Backups
    - Deploying to multiple availability zones
  - Reactive

Azure allows you to backup/restore to/from Azure and AWS through the __Azure Site Recovery__ service

## Scalability and elasticity

Elasticity | ability to increase or decrease the __instance count or size__ of existing resources based on fluctuations in traffic or load, or in resource workload | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
Scalability | ability to increase the __instance count or size__ of existing resources | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
Scale out | increase __instance count__ of existing resources: non-disruptive | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
Scale up  | increase __instance size__ of existing resources: __disruptive__ | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)

## Business agility

Business agility | an organization's ability to rapidly adapt to market and environmental changes in productive and cost-effective ways | [udemy.com](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)

## Subscriptions

__Azure Regions__ are analogous to lots in a neighborhood, which are maintained and administered individually, and in fact correspond to individual data centers. Within each region, there may be tenants (residents) which have varying level of access to __resource groups__ (rooms of a house, car, etc)
__Active Directory__ combines the functions of an org chart, phonebook, access list, and central database of users. It allows developers to entirely delegate the tedium of managing users and access levels to the system, while providing a single authoritative source of user authentication and credentialing for all business applications.
__Virtual networks__ are a method of connecting resources within an Azure region, and closely imitate real-world networks. Virtual networks from different regions can be linked, but the constituent virtual networks must be within a single region.
__Virtual machines__ are simulations of physical computers, Linux or Windows. They are the most expensive component of most Azure deployments.
__Azure Storage__ allows you to access almost all documents and data generated within the Azure cloud, organized into "Accounts", further subdivided into Blobs, Tables, Queues, and Files as well as SQL databases and "Data Lakes". Azure is unique among cloud providers for providing a SQL server as an Azure service, rather than a virtual machine.

## Manage
