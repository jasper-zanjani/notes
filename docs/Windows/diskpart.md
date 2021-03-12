
[diskpart active]:    #diskpart 'On MBR disks, marks the partition with current focus as the active system partition, meaning it is the partition containing the operating system startup files'
[diskpart add]:       #diskpart 'Create a mirrored volume on the selected dynamic disk'
[diskpart assign]:    #diskpart 'Assign a drive letter or mount point to the selected partition, logical drive, or volume. Takes parameters "LETTER=x" or "MOUNT=path"'
[diskpart automount]: #diskpart 'Control whether Windows automatically mounts new basic volumes that are added to the system and assigns them drive letters. Takes parameters "ENABLE", "DISABLE", or "SCRUB"'
[diskpart break]:     #diskpart 'Break a mirror set. Takes parameter "DISK=n"'
[diskpart clean]:     #diskpart 'Remove all partition or volume formatting on the focused disk.'
[diskpart convert]:   #diskpart 'Convert focused disk to basic/dynamic'
[diskpart create]:    #diskpart 'Create a partition or volume of a specific type'
[diskpart delete]:    #diskpart 'Delete the focused disk, partition, or volume'
[diskpart detail]:    #diskpart 'Provide details about the focused disk, partition, or volume'
[diskpart exit]:      #diskpart 'Exit the DiskPart interpreter'
[diskpart extend]:    #diskpart 'Extend the simple volume on the selected disk or span the volume across multiple disks'
[diskpart gpt]:       #diskpart 'Change GPT attributes on the focused partition (Windows Server 2003 only)'
[diskpart help]:      #diskpart 'Display a list of commands'
[diskpart import]:    #diskpart 'Import a foreign disk'
[diskpart inactive]:  #diskpart 'On MBR disks, mark the focused partition as inactive.'
[diskpart list]:      #diskpart 'Display a list of disks or volumes and information about them, or a list of partitions on the focused disk.'
[diskpart online]:    #diskpart 'Bring the selected disk or volume online. Resynchronize the mirrored or focused RAID-5 volume.'
[diskpart rem]:       #diskpart 'Mark the start of a comment in a DiskPart script'
[diskpart remove]:    #diskpart 'Remove specified drive letter or mount point from the currently selected volume'
[diskpart repair]:    #diskpart 'Repair the focused RAID-5 volume by replacing the failed volume with the designated dynamic disk (Windows Server 2003 only)'
[diskpart rescan]:    #diskpart 'Look for new disks that may have been added to the computer'
[diskpart retain]:    #diskpart 'Prepare the selected simple volume to be used as the boot or system volume'
[diskpart select]:    #diskpart 'Focus specified disk, partition, or volume'

[`ACTIVE`][diskpart ACTIVE] 
[`ADD`][diskpart ADD] 
[`ASSIGN`][diskpart ASSIGN] 
[`AUTOMOUNT`][diskpart AUTOMOUNT] 
[`BREAK`][diskpart BREAK] 
[`CLEAN`][diskpart CLEAN] 
[`CONVERT`][diskpart CONVERT] 
[`CREATE`][diskpart CREATE] 
[`DELETE`][diskpart DELETE] 
[`DETAIL`][diskpart DETAIL] 
[`EXIT`][diskpart EXIT] 
[`EXTEND`][diskpart EXTEND] 
[`GPT`][diskpart GPT] 
[`HELP`][diskpart HELP] 
[`IMPORT`][diskpart IMPORT] 
[`INACTIVE`][diskpart INACTIVE] 
[`LIST`][diskpart LIST] 
[`ONLINE`][diskpart ONLINE] 
[`REM`][diskpart REM] 
[`REMOVE`][diskpart REMOVE] 
[`REPAIR`][diskpart REPAIR] 
[`RESCAN`][diskpart RESCAN] 
[`RETAIN`][diskpart RETAIN] 
[`SELECT`][diskpart SELECT] 

Moffitt disk formatting script
```diskpart
SELECT DISK 0
CLEAN
CONVERT gpt
CREATE PARTITION primary SIZE=1024
FORMAT QUICK FS=NTFS LABEL="Recovery"
SET ID="de94bba4-06d1-4d40-a16a-bfd50179d6ac"
CREATE PARTITION efi SIZE=750
ASSIGN LETTER=K
FORMAT QUICK FS=FAT32 LABEL="System"
CREATE PARTITION MSR SIZE=128
CREATE PARTITION PRIMARY
ASSIGN LETTER=C
FORMAT QUICK FS=NTFS
EXIT
```