```yaml
# pods.redhat_subscriptions/roles/cockpit_setup/tasks/main.yml
- name: Enable and start cockpit
  ansible.builtin.systemd:
    name: cockpit.socket
    state: started
    enabled: yes

# pods.redhat_subscriptions/podman_setup/tasks/main.yml
- name: Enable Podman socket
  systemd:
    name: podman.socket
    state: restarted
    daemon_reload: yes
    enabled: true
```