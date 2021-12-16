#### nice
:   
    Priorities range from 0-19 in `csh` (10 is default): lower values mean a higher priority.

    View priorities of jobs
    ```sh
    ps -l
    ```

    Run `cmd` at a higher priority
    ```sh
    nice -5 cmd &
    ```
    Run `$CMD` at a nice value of (positive) 10
    ```sh
    nice -10 $CMD
    nice -n 10
    nice $CMD
    ```