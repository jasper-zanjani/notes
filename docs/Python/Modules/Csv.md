# Csv
```py
with open('file.csv', newline=''):
    data = [row for row in csv.reader(f)]
```
[csv.DictReader](https://docs.python.org/3/library/csv.html#csv.DictReader)
```py
with open('greeks.csv') as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row['name'],row['city'],row['dob'])
```
