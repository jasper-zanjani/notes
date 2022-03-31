# sqlite3

Create a `Connect` connection object and **employee.db** (binary) if it doesn't exist
```py
conn = sqlite.connect('employee.db')
```
Create a `Connect.Cursor` object
```py
c = conn.cursor()
```
Perform SQL commands with `Connect.Cursor.execute()`. Create `tablename` with fields `field` of type `type` (`null`, `integer`, `real`, `text`, `blob`); never use Python's native string operations (f-strings, etc) to form commands, because this method is vulnerable to SQL injection. <sup>[YouTube](https://youtu.be/pd-0G0MigUA)</sup>
```py
c.execute('''CREATE TABLE {tablename} ({field} {type}, {field} {type} ...))
``` 
Save changes
```py
conn.commit()
```
Close connection
```py
conn.close()
```