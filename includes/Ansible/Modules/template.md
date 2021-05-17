[https://www.linuxjournal.com/content/ansible-part-iii-playbooks]: https://www.linuxjournal.com/content/ansible-part-iii-playbooks "Ansible, Part III: Playbooks"

Works similar to mail merge in a word processor. Ansible uses the Jinja2 templating language, which has a syntax similar to Ansible variable substitution.
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>

This example creates a HTML document on each client that is customized using Ansible variables. 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>

```yaml
---
- hosts: webservers
  become: yes

  tasks:
   - name: install apache2
     apt: name=apache2 state=latest update_cache=yes
     when: ansible_os_family == "Debian"

   - name: install httpd
     yum: name=httpd state=latest
     when: ansible_os_family == "RedHat"

   - name: start apache2
     service: name=apache2 state=started enable=yes
     when: ansible_os_family == "Debian"

   - name: start httpd
     service: name=httpd state=started enable=yes
     when: ansible_os_family == "RedHat

   - name: install index
     template:
       src: index.html.j2
       dest: /var/www/html/index.html
```
Jinja template file 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>
```j2
<html><center>
<h1>This computer is running {{ ansible_os_family }},
and its hostname is:</h1>
<h3>{{ ansible_hostname }}</h3>
{# this is a comment, which won't be copied to the index.html file #}
</center></html>
```
