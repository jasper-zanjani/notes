```yaml title="pods.redhat_subscriptions/roles/tasks/main.yml"
- name: Ensure group "docker" exists
  group:
    name: docker
    state: present
    system: yes
```