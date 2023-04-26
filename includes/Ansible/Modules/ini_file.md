```yaml
- name: Syncronize "simple_allow_users"
  community.general.ini_file:
    path: /etc/sssd/sssd.conf
    section: "{{ default_domain }}"
    option: simple_allow_users
    value: "{% for ag in (ad['allowedusers'] | default([])) %}{{ ag.name }}{% if not loop.last %}, {% endif %}{% endfor %}"
    mode: '0600'
    state: present
    exclusive: true
  when: "(ad['allowedusers'] | default([])) | length"
- name: Remove "simple_allow_users" when no users are listed
  community.general.ini_file:
    path: /etc/sssd/sssd.conf
    section: "{{ default_domain }}"
    option: simple_allow_users
    state: absent
    exclusive: true
  when: "((ad['allowedusers'] | default([])) | length) < 1"
```