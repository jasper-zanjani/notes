# Linux Journal
## Contents
#### 251
p.    | Title
---:  | :---
34    | Dave Taylor’s Work the Shell: Let's Play Cards with Acey-Deucey, Part 2
38    | Kyle Rankin’s Hack and /: Lightning Hacks: Qubes Tips
44    | Shawn Powers' The Open-Source Classroom: The Teeny Tiny $20 Tablet
58    | "Using Hiera with Puppet: Use Hiera to encrypt sensitive data in Puppet"
68    | "Managing Services in Linux: Past, Present and Future: Learn about the history of init systems in Linux and understand how these systems evolved over time"
82    | "Infinite BusyBox with systemd: Build one Linux system within another, using the latest utilities within the systemd suite of management tools"
100   | Doc Searls’ EOF: Resurrecting the Armadillo
#### 283
p.    | Title
---:  | :---
40    | Reuven M. Lerner’s At the Forge: Launching external processes in Python
48    | Dave Taylor’s Work the Shell: A Number-Guessing Game
54    | Kyle Rankin’s Hack and /: Lightning Hacks: Qubes Tips
58    | Shawn Powers’ The Open-Source Classroom: Ansible, Part IV: Putting It All Together
78    | Rapid, Secure Patching; Tools and methods: Control a heterogeneous server farm with the SSH agent.
100   | CLIC: Cluster in the Cloud: Automatically create and delete high-performance computing resources in the cloud
114   | Doc Searls’ EOF: New Hope for Digital Identity 
#### 301
p.    | Title
---:  | :---
14    | DNA Geometry with cadnano
32    | Kyle Rankin’s Hack and /: RV Offsite Backup Update
37    | Reuven M. Lerner’s At the Forge: Understanding Python's asyncio
44    | Dave Taylor’s Work the Shell: Bash Shell Games: Continuing Development of the Go Fish! Game
51    | Zack Brown's diff-u: What's New in Kernel Development
61    | Experts attempt to explain DevOps - and Almost Succeed
68    | Continuous Integration/Continuous Development with FOSS Tools
78    | Digging through the DevOps Arsenal: Introducing Ansible
88    | My favorite infrastructure
106   | Build a versatile OpenStack Lab with Kolla
127   | Running GNOME in a Container
141   | Writing GitHub Web Hooks with Bash
151   | Words, Words, Words - Introducing OpenSearchServer
166   | Glyn Moody's Open Sauce
## Projects
### Go Fish! game development in bash
#### Function to deal cards
```sh
function dealCards
{ # start with seven cards deal to each player
  i=1
  while [ $i -lt 8 ] ; do # first 8 slots = cards
    myhand[$i]=${newdeck[$i]}
    yourhand[$i]=${newdeck[$(( $i + 7 ))]}
    i=$(( $i + 1 ))
  done
  while [ $i -le 52 ] ; do # all other slots empty
    myhand[$i]=-1
    yourhand[$i]=-1
    i=$(( $i + 1 ))
  done }
```
[301: 45-46]
