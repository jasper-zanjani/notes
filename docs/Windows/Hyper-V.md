# Hyper-V

#### Configure VM

=== ":fontawesome-solid-network-wired: NIC"

    === ":material-plus: Create"
    
        ``` powershell
        Add-VMNetworkAdapter -VMName $vmName -SwitchName $switchName
        ```
    
    === ":material-eye: Read"
    
        ```sh
        command get
        ```
    
    === ":material-format-list-text: List"
    
        ```sh
        command list
        ```
    
    === ":material-pencil: Update"
    
        ```sh
        command set
        ```
    
    === ":material-trash-can: Delete"
    
        ```sh
        command remove
        ```


=== ":material-harddisk: HDD"

    ```powershell
    Add-VMHardDiskDrive -VMName $vmName -ControllerType IDE -ControllerNumber 0 -Path $vhdPath
    ```

=== ":octicons-cpu-16: CPU"

=== ":fontawesome-solid-memory: RAM"