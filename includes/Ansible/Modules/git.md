[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Manage git checkouts of repos 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

```yaml
# Create git archive from repo
- git:
    repo: https://github.com/ansible/ansible-examples.git
    dest: /src/ansible-examples
    archive: /tmp/ansible-examples.zip
```
```yaml
- git:
    repo: https://github.com/ansible/ansible-examples.git
    dest: /src/ansible-examples
    separate_git_dir: /src/ansible-examples.git
```


