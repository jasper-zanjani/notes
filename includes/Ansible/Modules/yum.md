```yaml
# pods.redhat_subscriptions/roles/cockpit_setup/tasks/main.yml
- name: Install Cockpit
  ansible.builtin.yum:
    name: cockpit
    state: latest

# pods.redhat_subscriptions/roles/insights_setup/tasks/main.yml
- name: Setup syncinsights package
  yum:
    name: "pods-syncinsights-el{{ ansible_distribution_major_version }}"
    state: latest
    update_cache: yes
  when: 
    - "'nexus' not in group_names"

# devops_solarwinds_role/tasks/main.yml
- name: Install SolarWinds Agent
  yum: 
    name:
      - swiagent
      - perl
      - perf
    state: latest
  when: ansible_os_family == "RedHat"  

```