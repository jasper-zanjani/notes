# Datetime
```py
datetime.date(2016,7,24)
datetime.date.today()
```

Difference between `datetime` objects is a `timedelta`
Parse strings into datetime objects
```py
datetime.strptime(datestring,formatstring)
``` 
```py
# Various metacharacters are defined for `strptime`
datetime.datetime.strptime('06/30/1992','%m/%d/%Y')
``` 
