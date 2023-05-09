```yaml title="pods.redhat_subscriptions/roles/podman_setup/tasks/main.yml"
- name: "Add podman_nonroot_user to docker group"
  user:
    name: "{{ podman_nonroot_user }}"
    groups: docker
    append: yes
    system: yes
  ignore_errors: yes
```