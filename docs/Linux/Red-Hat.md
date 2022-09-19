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



## Labs

### EX200

#### IAM
:   
    We're going to lay the groundwork here and use these local accounts for all the subsequent tasks. You can write a script to do this, or do it by hand, from the data in the input file for the script. The file contents are:

    ```
    manny:1010:dba_admin,dba_managers,dba_staff 
    moe:1011:dba_admin,dba_staff 
    jack:1012:dba_intern,dba_staff 
    marcia:1013:it_staff,it_managers 
    jan:1014:dba_admin,dba_staff 
    cindy:1015:dba_intern,dba_staff 
    ```

    Set all user passwords to **dbapass**. 
    Also, change the users' PRIMARY groups' GID to match their UID. 
    Don't forget to check their home directories to make sure permisisons are correct!

    Enable the following command aliases:

    - **SOFTWARE**
    - **SERVICES**
    - **PROCESSES**

    Add a new command alias named **MESSAGES**:
    ```sh
    /bin/tail -f /var/log/messages
    ```
    Enable superuser privilages for the following local groups:

    - **dba\_managers**: everything
    - **dba\_admin**: Command aliases: SOFTWARE, SERVICES, PROCESSES
    - **dba\_intern**: Command alias: MESSAGES

#### Repos
:   
    You'll need to configure three repositories and install some software:

    - RHEL 8 BaseOS:

        - Repository ID: **[rhel-8-baseos-rhui-rpms]**
        - The mirrorlist is: **https://rhui3.REGION.aws.ce.redhat.com/pulp/mirror/content/dist/rhel8/rhui/$releasever/$basearch/baseos/os**
        - The GPG key is located at: **/etc/pki/rpm-gpg/RPM-GPG-KEY-redhat-release**
        - You will need to add SSL configuration:

        ```ini
        sslverify=1 
        sslclientkey=/etc/pki/rhui/content-rhel8.key 
        sslclientcert=/etc/pki/rhui/product/content-rhel8.crt 
        sslcacert=/etc/pki/rhui/cdn.redhat.com-chain.crt 
        ```

    - RHEL 8 AppStream:

        - Repository ID: **[rhel-8-appstream-rhui-rpms]**
        - The mirrorlist is: **https://rhui3.REGION.aws.ce.redhat.com/pulp/mirror/content/dist/rhel8/rhui/$releasever/$basearch/appstream/os**
        - The GPG key is located at: **/etc/pki/rpm-gpg/RPM-GPG-KEY-redhat-release**
        - You will need to add SSL configuration:

        ```ini
        sslverify=1
        sslclientkey=/etc/pki/rhui/content-rhel8.key
        sslclientcert=/etc/pki/rhui/product/content-rhel8.crt
        sslcacert=/etc/pki/rhui/cdn.redhat.com-chain.crt
        ```

    - EPEL:

        - Repository ID: **[epel]**
        - The baseurl is: **https://download.fedoraproject.org/pub/epel/$releasever/Everything/$basearch**

    Configure the repositories on the first server, then make an archive of the files, securely copy them to the second server, then unarchive the repository files on the second server.

    - Install the default AppStream stream/profile for container-tools
    - Install the youtube-dl package (from EPEL)
    - Check for system updates, but don't install them

#### Networking
:   
    On the first server, configure the second interface's IPv4/IPv6 addresses using nmtui.

    - IPv4: **10.0.1.20/24**
    - IPv6: **2002:0a00:0114::/64**
    - Manual, not Automatic (DHCP) for both interfaces
    - Only IP addresses, no other fields
    - Configure only, do not activate

#### Logging
:   
    By default, the systemd journal logs to memory in RHEL 8, in the location /run/log/journal. While this works fine, we'd like to make our journals persistent across reboots.
    Configure the systemd journal logs to be persistent on both servers, logging to **/var/log/journal**.

#### Scheduling
:   
    Create one **at** task and one **cron** job on the first server:

    - The at job will create a file containing the string "The at job ran" in the file named **/web/html/at.html**, two minutes from the time you schedule it.
    - The cron job will append to the **/web/html/cron.html** file every minute, echoing the date to the file.

    These files will be available via the web server on the first server after the "Troubleshoot SELinux issues" objective is completed.

#### Chrony
:   
    Time sync is not working on either of our servers. We need to fix that.

    Configure chrony to use the following server:
    ```
    server 169.254.169.123 iburst 
    ```
    Make sure your work is persistent and check your work!

#### GRUB
:   
    On **server1**, make the following changes:

    - Increase the timeout using **`GRUB_TIMEOUT=10`**
    - Add the following line: **`GRUB_TIMEOUT_STYLE=hidden`**
    - Add quiet to the end of the **`GRUB_CMDLINE_LINUX`** line

    Validate the changes in **/boot/grub2/grub.cfg**. Do not reboot the server.

#### Storage
:   
    On the second server:

    - Create a VDO device with the first unused 5GB device.

        - Name: **web\_storage**
        - Logical Size: 10GB

    - Use the VDO device as an LVM physical volume. Create the following:

    - Volume Group: **web\_vg**

        - Three 2G Logical Volumes with xfs file systems, mounted persistently at **/mnt/web_storage_{dev,qa,prod}q**:

            - web_storage_dev
            - web_storage_qa
            - web_storage_prod

    We need to increase the swap on the second server. We're going to use half of our first unused 2G disk for this additional swap space. Configure the swap space non-destructively and persistently.

    On the second server, using the second 2G disk, create the following:

    - Stratis pool: **appteam**
    - Stratis file system, mounted persistently at **/mnt/app_storage**: **appfs1**

#### Shares
:   
    Configure autofs on the first server to mount the user home directories on the second server at **/export/home**.

    - On the second server, configure a NFS server with the following export:

    ```
    /home <first_server_private_IP>(rw,sync,no_root_squash)
    ```

    - On the first server, configure autofs to mount the exported /home directory on the second server at **/export/home**. Change the home directories for our six users (manny|moe|jack|marcia|jan|cindy) to be **`/export/home/<user>`** and test.


    On the second server, create a directory at **/home/dba_docs** with:

    - Group ownership: **dba\_staff**
    - Permissions: **770**, **SGID** and **sticky bits** set

    Create a link in each shared user's home directory to this directory, for easy access.

    Set the following ACLs:

    - Read-only for jack and cindy
    - Full permissions for marcia

#### Container as service
:   
    As the cloud\_user user on the first server, create a persistent systemd container with the following:

    - Image: **registry.access.redhat.com/rhscl/httpd-24-rhel7**
    - Port mappings: 8080 on the container to 8000 on the host
    - Persistent storage at **~/web_data**, mounted at **/var/www/html** in the container
    - Container name: **web\_server**

#### SELinux
:   
    The Apache web server on the first server won't start! Investigate this issue, and correct any other SELinux issues related to httpd that you may find.

#### Firewall
:   
    Make sure the firewall is installed, enabled and started on both servers. Configure the following services/ports:

    - Server 1:

        - **ssh**
        - **http**
        - Port **85** (tcp)
        - Port **8000** (tcp)

    - Server 2:
    
        - **ssh**
        - **nfs**
        - **nfs3**
        - **rpc-bind**
        - **mountd**


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