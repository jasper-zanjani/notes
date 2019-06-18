### netstat

  - `netstat -i` show interface statistics (LGLC: 535)
  - `netstat -r` , `netstat --route` display routing table (lxa-lpic: 109.2, itp-lpic: 39)
  - `netstat -a` show all sockets on all active interfaces (lxa-lpic: 109.2)
  - `netstat -an` show network traffic (itp-lpic.md)
  - `netstat -a | grep tcp - | wc -l` count number of TCP connections (lxa-lpic: 109.2)
  - `netstat -c 5 -a` refresh every 5 seconds (lxa-lpic: 109.2)
  - `netstat -t` TCP connections (lxa-lpic: 109.2)
  - `netstat -tp` active sessions (itp-lpic: 39)
  - `netstat -atp` all sessions (itp-lpic: 39)
  - `netstat -rn` routing table with name resolution (lxa-lpic: 109.2)
  - `watch -n 1 'netstat -an | grep ":443"'` get the list of IPs and ports that are connected via https on your webserver every second
  - `watch -n 1 'netstat -an | grep ":80" | wc -l'` get the total number of connections on port 80 every second
