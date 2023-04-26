```yaml
# devops_solarwinds_role
- name: Install apt-transport-https
  apt:
    name: apt-transport-https
    state: present
  when: ansible_distribution == 'Debian' or ansible_distribution == 'Ubuntu'
- name: Run update for apt
  apt:
    update_cache: yes
  when: ansible_distribution == 'Debian' or ansible_distribution == 'Ubuntu'
- name: Install swiagent for apt
  apt:
    name:
      - swiagent
      - perl
      # - linux-tools
    state: latest
  when: ansible_distribution == 'Debian' or ansible_distribution == 'Ubuntu'
```