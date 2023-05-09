```yaml
# devops_solarwinds_role/tasks/main.yml
- name: Add Solarwinds repository
  yum_repository:
    name: swiagent
    description: SolarWinds Agent
    mirrorlist: file:///etc/yum.repos.d/swiagent-amzn-2015.mirrors
    file: swiagent-amzn-2015
    enabled: yes
    gpgcheck: no
  when: ansible_os_family == "RedHat"  
```