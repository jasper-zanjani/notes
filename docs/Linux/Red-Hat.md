# Red Hat

Red Hat distributions ... bla blabla

## Applications

#### TuneD
:   
    [TuneD](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/monitoring_and_managing_system_status_and_performance/getting-started-with-tuned_monitoring-and-managing-system-status-and-performance)
    is a service that monitors the system and optimizes its performance under certain workloads.
    TuneD provides predefined profiles for power-saving and performance-boosting use cases.

    - **throughput-performance** optimizes for throughput
    - **virtual-guest** optimizes for performance
    - **balanced** balances performance and power consumption
    - **powersave** optimizes for power consumption

    These can be listed from the command-line:
    ```sh
    tuned-adm list profiles
    tuned-adm active
    tuned-adm recommend
    tuned-adm profile powersave                 # Select a profile
    tuned-adm profile virtual-guest powersave   # Select a merged profile
    ```

    **Dynamic tuning** monitors system components during uptime and makes system changes dynamically.
    It is enabled by changing a setting in TuneD's config at **/etc/tuned/tuned-main.conf**:
    ```ini title="/etc/tuned/tuned-main.conf"
    dynamic_tuning=1
    ```

## Storage

--8<--
includes/Linux/Tasks/autofs.md

includes/Linux/Tasks/stratis.md

includes/Linux/Tasks/vdo.md
--8<--



## Commands

--8<--
includes/Linux/Commands/dnf.md

includes/Linux/Commands/firewall-cmd.md

includes/Linux/Commands/httpd.md

includes/Linux/Commands/podman.md

includes/Linux/Commands/rpm.md

includes/Linux/Commands/rpmkeys.md

includes/Linux/Commands/stratis.md

includes/Linux/Commands/vdo.md

--8<--


## Glossary

#### CentOS
:   
    A community distribution of Linux that was created by Gregory Kurtzer in 2004 and acquired by [Red Hat](#rhel) in 2014. 
    
    It has traditionally been [considered](https://itsfoss.com/centos-stream-fiasco/) downstream to [RHEL](#rhel), incorporating changes to RHEL after a delay of several months. 
    In fact, it is a rebuild of the publicly available **source RPMs (SRPMs)** of RHEL packages, which historically allowed CentOS maintainers to simply package and ship them [rebranded](https://fosspost.org/centos-project-suicide/).

    For years, CentOS was the [distribution of choice](https://www.zdnet.com/article/red-hat-resets-centos-linux-and-users-are-angry/#ftag=RSSbaffb68) for experienced Linux administrators who did not feel the need to pay for Red Hat's support.
    In December 2020, Red Hat [announced](https://itsfoss.com/centos-stream-fiasco/) that CentOS 8 support will end at the end of 2021 (rather than 2029), while CentOS 7 will continue to be supported until 2024. 
    This represented a shift in focus from CentOS Linux to [**CentOS Stream**](#centos-stream) and a change from a **fixed-release** (or "stable point release") to a **rolling-release** distribution model.

    **CentOS Stream** was [announced](https://itsfoss.com/centos-stream-fiasco/) in September 2019 as a distribution of CentOS maintained on a model previously misidentified as rolling-release but now described as "continuously delivered", organized into Streams. 
    CentOS Stream [originated <sup>:material-link:</sup>](https://linuxunplugged.com/383) in an effort to get more community participation in development of RHEL, rather than merely passive consumption.

#### Fedora
:   
    **Fedora** is a community distribution supported by Red Hat launched as "Fedora Core" in 2003. 
    It has traditionally been [considered](https://itsfoss.com/centos-stream-fiasco/) upstream to RHEL, serving as a testing ground for new features and improvements.
    
    **Fedora CoreOS** is a Fedora edition [built](https://fedoramagazine.org/introducing-fedora-coreos/ 'Fedora Magazine: "Introducing Fedora CoreOS"') specifically for running containerized workloads securely and at scale. 
    Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime.
    CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. 
    All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.