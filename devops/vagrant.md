# Vagrant

Command           | Description
:---              | :---
`init`            | **init**ialize a new Vagrant project
`box add`         | download a VM image or "**box**"
`destroy $BOX`    | delete the VM from VirtualBox
`halt`            | stop all VMs
`halt $BOX`       | stop a specified VM
`ssh $BOX`        | begin a SSH session with `$BOX`
`suspend $BOX`    | suspend `$BOX`
`up`              | start all VMs in headless mode
`up $BOX`         | start a specified VM (in headless mode, by default)

## Vagrantfile
The number in parentheses is the **API version** [[1](#sources): 13:00]
```
Vagrant.configure(2) do |config}
  config.vm.box = "jasonc/centos7"
  config.vm.hostname = "linuxsvr"
  # note the lack of `=`
  config.vm.network "private_network", ip: "10.2.3.4" 
# A "provider" block overrides defaults
  config.vm.provider "virtualbox" do |vb|
    vb.gui = true
    vb.memory = "1024"                            # in megabytes
  end
  
  # "Provision" blocks or "provisioners" allow you to provision software.
  # This line runs setup.sh in the shell
  config.vm.provision "shell", path: "setup.sh"
end
```
Multi-machine setup in Vagrant [[1](#sources): 13:00]
```vagrantfile
Vagrant.configure(2) do |config|                  # server name is between pipes
  config.vm.box = "jasonc/centos7"
  config.vm.define "server1" do |server1|
    server1.vm.hostname = "server2"
    sserver2.vm.network "private_network", ip: "10.2.3.5"
  end
end
```
Making sure "Virtual Network Cable" is connected [[2](#sources): 2:00]
```vagrantfile
Vagrant.configure(2) do |config|
  config.vm.box = "jasonc/centos7"
  config.vm.provider "virtualbox" do |vb|
    ;;;vb.customize ['modifyvm', :id, '--cableconnected1', 'on']
  end
end
```

## Sources
1. "Creating a local lab environment using Vagrant and VirtualBox - Background". _Linux Shell Scripting: a Project-Based Approach to Learning_. [Udemy](https://www.udemy.com/course/linux-shell-scripting-projects/learn/lecture/7980218#overview).
2. "Vagrant and VirtualBox Troubleshooting Tips". _Linux Shell Scripting: A Project-Based Approach to Learning_. [Udemy](https://www.udemy.com/course/linux-shell-scripting-projects/learn/lecture/7980812#overview).
