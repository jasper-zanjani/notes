Ad Hoc
:   Type of command run in realtime by an administrator working at the terminal'

Ansible Galaxy
:   Online portal where a gallery of roles made by the Ansible community can be found

Ansible Tower
:   Web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management. 
    A commercial product that is available in two versions: 
    
    - **Standard**: $13,000/yr
    - **Premium**: $17,500/yr

Ansible Vault
:   Place to keep encrypted passwords

AWX
:   Open-source project upon which Ansible Tower was built

Fact
:   System property gathered by Ansible when it executes a playbook on a node

Handler
:   Tasks executed when notified by a task

Inventory
:   Text file containing a list of servers or nodes that you are managing and configuring

Module
:   - Standalone script that enables a particular task regardless of OS, service or application
    - Discrete unit of code used in playbooks for executing commands

Play
:   Script or instruction that defines the task to be carried out in a server

Playbook
:   YAML document that represents a sequence of scripted actions which apply changes uniformly over a set of hosts

Role
:   Organize components of playbooks, allowing them to be reused'

Task
:   A single scripted action in a playbook, equivalent to an ad hoc command

Vault
:   Feature of Ansible that allows you to keep sensitive data such as passwords or keys protected at rest, rather than as plaintext in playbooks or roles

    Two types of vaulted content:
    
    - **Vaulted files**, where the full file, which can contain Ansible variables or other content, is encrypted
    - **Single encrypted variables**, where only specific variables within a normal "variable file" are encrypted.