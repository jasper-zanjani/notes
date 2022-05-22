# Red Hat :material-redhat:

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
    ```

    The current profile can be displayed:
    ```sh
    tuned-adm active
    ```

    TuneD can display a recommended profile:
    ```sh
    tuned-adm recommend
    ```

    A profile can be selected:
    ```sh
    tuned-adm profile powersave
    ```

    Profiles can be merged:
    ```sh
    tuned-adm profile virtual-guest powersave
    ```

    **Dynamic tuning** monitors system components during uptime and makes system changes dynamically.
    It is enabled by changing a setting in TuneD's config at **/etc/tuned/tuned-main.conf**:
    ```ini title="/etc/tuned/tuned-main.conf"
    dynamic_tuning=1
    ```

## Commands

--8<-- "includes/Linux/Commands/rpm.md"

--8<-- "includes/Linux/Commands/rpmkeys.md"
