```yaml title="template"
- name: install index
  template:
    src: index.html.j2
    dest: /var/www/html/index.html
# (1)!
```

1. 
```html title="Jinja2 template file"
<html>
  <h1>This computer is running {{ ansible_os_family }},
  and its hostname is:</h1>
  <h3>{{ ansible_hostname }}</h3>
  {# this is a comment, which won't be copied to the index.html file #}
</html>
```

```yaml
# devops_solarwinds_role
- name: Add mirrorlist
  template:
    src: "{{ role_path }}/templates/swiagent-amzn-2015.mirrors.j2"
    dest: /etc/yum.repos.d/swiagent-amzn-2015.mirrors
  when: ansible_os_family == "RedHat"  
# (1)!

- name: Add deb repo
  template:
    src: "{{ role_path }}/templates/swiagent-ubuntu-14.list.j2"
    dest:  /etc/apt/sources.list.d/swiagent-ubuntu-14.list
  when: ansible_distribution == 'Debian' or ansible_distribution == 'Ubuntu'
# (2)!
```

1. 
```
{% for host in groups['solarwinds'] %}
https://{{ host }}/Orion/AgentManagement/LinuxPackageRepository.ashx?path=/dists/amzn-2015/$basearch
https://{{ host }}:443/Orion/AgentManagement/LinuxPackageRepository.ashx?path=/dists/amzn-2015/$basearch
{% endfor %}
```
2. 
```
{% for host in groups['solarwinds'] %}
deb [trusted=yes] https://{{ host }}/Orion/AgentManagement/LinuxPackageRepository.ashx?path= ubuntu-14 swiagent
deb [trusted=yes] https://{{ host }}:443/Orion/AgentManagement/LinuxPackageRepository.ashx?path= ubuntu-14 swiagent
{% endfor %}
```