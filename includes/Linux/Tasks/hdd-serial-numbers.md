#### HDD serial numbers
:   
    Produce a CSV of hard disk identifiers and their serial numbers using hdparm, grep, cut, and output redirection.
    ```sh
    for l in a b c d e f g h i j k l m n o p q r s t u v w 
    do 
        echo -n "/dev/sd$l," >> drives
        hdparm -I /dev/sd$l | 
            grep 'Serial Number' - |
            cut -d : -f 2 | 
            tr -d '[:space:]' >> drives
        echo '' >> drives;
    done
    ```