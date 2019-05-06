# useradd
`useradd -s /bin/bash`
: create a new user, setting their default shell to /bin/bash

`useradd -m -g wheel luke`
: create a new user account {luke} belonging to default group {wheel}, creating a home directory

`useradd -c "comment"`
: create a new user account with {comment}

`useradd -G grp1 grp2`
: create a new user account, adding it to groups {grp1} and {grp2}

`useradd -u UUID`
: create a new user account, specifying {UUID}

