### date
All output is formatted according to system's locale. The locale's timezone can be overriden by setting the `TZ` environment variable. [^](https://linuxize.com/post/linux-date-command/ "linuxize.com: \"Linux date command\"")\
`$TIME` is in the format "MMDDhhmm"
```sh
date $TIME
```
Command | Effect
:---    | :---
`date [option]... [+format]` | general syntax for `date`
`date` | display current system time and date using default formatting
`date +"Year: %Y, Month: %m, Day: %d"` | format controls preceded by `%` character can be combined to produce a formatted string
`date "+DATE: %D%nTIME: %T"` | `%n` is newline
`date -d datestring +'dateformat'` | parse <datestring> and output the results according to <dateformat>
`date -d @epochseconds` | parse <epochseconds> as epoch date
`date -d "last week"` | English phrases can be parsed
`date -r file` | display last modification time of a file
`date --set=timestring` | set system clock to <timestring> manually (not recommended)

Format character | Effect
:--- | :---
`%a` | Abbreviated weekday name ("Mon")
`%A` | Full weekday name ("Monday")
`%d` | Day of month ("01")
`%H` | Military hour ("00")
`%I` | Standard hour ("12")
`%M` | Minute (00-59)
`%S` | Second (00-59)
`%s` | Seconds since epoch (January 1, 1970)
`%j` | Day of year ("364")
`%u` | Day of week (1-7)
`%m` | Month number ("01")
`%b` | Abbreviated month name ("Jan")
`%B` | Long month name ("January")
`%Y` | Year ("2019")
