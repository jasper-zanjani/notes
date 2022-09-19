#### journalctl
:   
    [Clean up](https://www.linuxuprising.com/2019/10/how-to-clean-up-systemd-journal-logs.html) old logs

    ```sh
    journalctl --disk-usage # (3)
    journalctl --rotate # (1)
    journalctl --vacuum-time=1d # (2)
    ```

    1. Ask journal daemon to rotate journal files, immediately archiving and renaming currently active journal files.
    2. **--vacuum-size**, **--vacuum-time**, and **--vacuum-files** can be used singly or in combination to enforce limits on archived journal files.
    3. Show current disk usage of all journal files

    Display logs

    ```sh
    journalctl -r # --reverse (1)
    journalctl -f # --follow (2)
    ```

    1. Display output in reverse (newest entries first)
    2. Continuously update the display as new log entries are created

    By default, SystemD logs to memory.
    This can be changed by adjusting **/etc/systemd/journald.conf**. 
    This requires the directory **/var/log/journal** to exist.
    
    ```ini title="Persistent logging"
    [Journal]
    Storage=persistent
    ```