#### HDD serial numbers
:   
    Produce a CSV of hard disk identifiers and their serial numbers using hdparm, grep, cut, and output redirection.
    ```sh
    for l in {a..w} 
    do 
        echo -n "/dev/sd$l," >> drives
        hdparm -I /dev/sd$l | 
            grep 'Serial Number' - |
            cut -d : -f 2 | 
            tr -d '[:space:]' >> drives
        echo '' >> drives;
    done
    ```