# SystemD

**SystemD** is the de facto Linux init system since replacing [Sysvinit](#sysvinit) and [Upstart](#upstart) in all major distributions. 
SystemD organizes resources into [**units**](#unit-files), which can be managed by daemons and manipulated by SystemD utilities.

It was designed by a pair of Red Hat developers in 2010 to be a general purpose system manager.
It offers parallel execution, explicit dependencies between services, an escape from slow shell scripts, and per-daemon resource control and watchdogs.

## Tasks

#### Scheduling services
:   
    Services can be scheduled to start with [timers](#timers).
    ```ini title="sshd.timer"
    [Unit]
    Description=Starts sshd service at beginning of workday, and shuts it down at the end.

    [Timer]
    Unit=sshd.service
    OnCalendar=Mon..Fri *-*-* 09:00:00

    [Install]
    WantedBy=timers.target
    ```

    Now, when stopping sshd manually the following output is printed.
    ```
    Warning: Stopping sshd.service, but it can still be activated by:
      sshd.timer
    ```

    The service can be scheduled to shutdown within the service file itself using the **RuntimeMaxSec** directive.
    ```toml title="sshd.service"
    RuntimeMaxSec=36000 # i.e. 10 hours
    ```

    This unfortunately will result in the service being reported as [failed](https://unix.stackexchange.com/questions/265704/start-stop-a-systemd-service-at-specific-times).
    This failure can be cleared with this command:
    ```sh
    systemctl reset-failed
    ```


## Glossary

#### Service files
:   
    **Service files** are a type of unit file which have replaced earlier init scripts and describe how to manage a service or application on the server.
    Active services are placed in **/etc/systemd/system**, whereas inactive service files distributed with installed packages are placed in **/usr/lib/systemd/system**.

    Docker container as a service:
    ```ini
    [Unit]
    Description=Notes Container (Docker)

    [Service]
    ExecStart=/usr/bin/docker start notes

    [Install]
    WantedBy=multi-user.target
    ```

#### Slice
:   
    A **slice unit** is a unit configuration file ending in ".slice" which manages resources of a group of processes.
    SystemD slices implement and build on Linux [**cgroups**](../Cgroups).

    Slices exist in a hierarchy below the **root slice** (**-.slice**) and are used to group **scopes** and **services**
    
    - **Scopes** contain unrelated processes but not necessarily hierarchically
    - **Services** are from unit files or Transient Runtime Services and contain processes

    Root slices themselves only contain scopes and other slices.

    - **user.slice** contains all user-related slices and scopes, named after the pattern **user-UID.slice**
  
        - **session.slice** is created for every login session

    - **system.slice** contain slices, scopes, and services
    
    - **machine.slice** contains all container-related slices, scopes, and services.

    Services can be assigned to specific slices explicitly by editing the value of the **Slice** key in the service file.
    Keys like **CPUWeight** can assign cgroup resource controls.
    Other such controls can be viewed in the **systemd.resource-control(5)** man page.
    ```ini
    [Unit]
    Slice=user.slice
    CPUWeight=50
    ```

#### SysVinit
:   
    SysVInit is the oldest init system used in Linux.

    In SysVinit, which used bash scripts to run and manage servicesj, processes were started serially and synchronously, wasting time and system resources.
    For years, a common mitigation was to run services in the background, simulating concurrency.


#### Target files
:   
    **Target files** are equivalent to SysVInit runlevels.

    | SystemD target    | SysVInit runlevel |
    | ----------------- | ----------------- |
    | poweroff.target   | 0                 |
    | rescue.target     | 1                 |
    | multi-user.target | 3                 |
    | graphical.target  | 5                 |
    | reboot.target     | 6                 |
    | emergency.target  | emergency         |

#### Timers
:   
    Timer files are systemd [unit files](#unit-files) with names ending in .timer that control [service files](#service-files).
    For each timer file, a matching unit file must exist describing the unit to activate when the timer elapses.
    By default, systemd will search for a service file with a filename matching that of the timer, but failing that a specific unit can be specified with the **Unit** key within the timer file itself.

    Active timers can be displayed in a table
    ```sh
    systemctl list-timers
    ```

    Their statuses can also be displayed in more detail:
    ```sh
    systemctl status *timer
    ```

    Like other unit files, timer files may include Unit and Install sections, but must include the **Timer** section.
    
    Specifying time is done using **timestamps** which can be **monotonic** or **realtime**.
    
    - Monotonic timers are defined relative to various system hooks using the following directives: OnActiveSec, OnBootSec, OnStartupSec, OnUnitActiveSec, and OnUnitInactiveSec.
    - Realtime timers define timers according to **calendar event expressions**, denoting real-world dates and times as humans understand them. 


    Validate timestamps:
    ```sh
    systemd-analyze calendar '*-*-* 00:00:00' --iterations
    ```    

    **systemd-run** can be used for one-off events as a substitute for anacron.
    ```sh
    systemd-run --on-active=-30sec /bin/touch /home/user/file
    ```
    This command creates a **transient** unit file, whose name is provided in the output.
    ```sh
    systemctl cat run-u97.service
    ```

#### Unit files
:   
    Unit files are case-sensitive .ini files organized into sections.
    Unit files can be found in several directories:

    - **/lib/systemd/system** where the system's copy of unit files are placed by default
    - **/etc/systemd/system** where unit files override the system default
    - **/run/systemd/system** where run-time unit definitions are found and given a higher priority than the system default in /lib but lower than that in /etc. These unit files are created dynamically and lost on reboot.

    Unit files come in many different types which can be identified by their filename extension (i.e. **.service**, **target**, etc.).


#### Upstart
:   
    **Upstart** was an init system developed by Canonical for Ubuntu meant to replace [SysVinit](#sysvinit), but it was abandoned in 2014. 


## Commands

--8<-- "includes/Linux/Commands/hostnamectl.md"

--8<-- "includes/Linux/Commands/journalctl.md"

--8<-- "includes/Linux/Commands/localectl.md"

--8<-- "includes/Linux/Commands/systemctl.md"

--8<-- "includes/Linux/Commands/systemd-analyze.md"

--8<-- "includes/Linux/Commands/systemd-cgls.md"

--8<-- "includes/Linux/Commands/systemd-delta.md"

--8<-- "includes/Linux/Commands/timedatectl.md"
