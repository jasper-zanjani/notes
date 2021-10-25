#### sosreport
:   
    **SOS** is an open-source data collection tool that can be used to collect system configuration details and diagnostic information from a Unix-like operating system. It is installed by default on Ubuntu Server. 
    ([src](https://www.howtoforge.com/how-to-install-and-use-sosreport-on-ubuntu-1804/ "howtoforge.com: \"How to install and use sosreport on Ubuntu\""))

    Collect system configuration details (without arguments, the report will be generated and stored in `$TMPDIR`)
    ```sh
    sosreport
    ```
    Specify alternative temporary directory
    ```sh
    sosreport --tmp-dir /opt
    ```
    Specify alternative compression (`xz` by default)
    ```sh
    sosreport --compression-type gzip
    ```
    Generate report for only specific plugins
    ```sh
    sosreport -o apache --batch
    ```
