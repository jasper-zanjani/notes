```yaml
# pods.redhat_subscriptions/roles/cockpit_setup
- name: Permit the cockpit service
  ansible.posix.firewalld:
    service: cockpit
    permanent: yes
    immediate: yes
    state: enabled    
```