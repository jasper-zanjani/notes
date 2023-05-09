```yaml
# pods.redhat_subscriptions/subscribe_vm/roles/tasks/main.yml
- name: Subscribe RHEL System with RedHat
  redhat_subscription:
    state: present
    username: "{{ rhsm['redhat_subscription_manager']['username'] }}"
    password: "{{ rhsm['redhat_subscription_manager']['password'] }}"
    auto_attach: true
    # force_register: "{{ sm_status.stdout.find('Invalid') != -1 }}"
  register: subscribe_results
  when: ansible_os_family == 'RedHat' and ansible_distribution == 'RedHat'
```