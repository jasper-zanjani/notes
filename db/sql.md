# Query Languages
## SQL syntax
Syntax        | Effect
:---          | :---
CREATE DATABASE db;
USE db;
CREATE TABLE tbl;

#### `INNER JOIN`
Using `INNER JOIN` in a query allows you to combine row data across two separate tables using the **primary key**, the unique identifier for the underlying entity.
```sql
SELECT * FROM table1 INNER JOIN table2 on table1.id = table2.id
```
#### `OUTER JOIN`
The commands `LEFT JOIN`, `RIGHT JOIN`, and `FULL JOIN` allow you to join tables with asymmetric data. `LEFT JOIN` includes rows from A regardless if whether a matching row is found in B. `RIGHT JOIN` includes rows from B regardless if a matching row is found in A. `FULL JOIN` means rows from both tables are kept, regardless of whether a matching row exists in either table.
#### `INSERT INTO` ... `VALUES`
The **database schema** describes the structure of each table and the datatypes that each column of the table can contain. `INSERT INTO` is used to add data to a table, in conjunction with `VALUES`.
```sql
INSERT INTO mytable (col1, col2, col3, ...) VALUES (val1, val2, val3, ...);
```
#### `UPDATE` ... `SET`
Change the value of a record
```sql
UPDATE mytable SET col1 = val1, col2 = val2, col3 = val3 WHERE condition;
```
#### `DELETE FROM` ... `WHERE`
Delete rows matching a condition
```sql
DELETE FROM mytable WHERE condition;
```
#### `CREATE TABLE`
```sql
CREATE TABLE IF NOT EXISTS mytable (col1 DataType TableConstraint DEFAULT val1, col2 DataType TableConstraint DEFAULT val2 ...);
```
- `DataType` can be one of the following types: `INTEGER`, `BOOLEAN`, `FLOAT`, `DOUBLE`, `REAL`, `CHARACTER(n)` where n is the maximum number of characters, `VARCHAR(n)`, `TEXT`, `DATE`, `DATETIME`, `BLOB`.
- `TableConstraint` can be one of the following values: `PRIMARY KEY`, `AUTOINCREMENT`, `UNIQUE`, `NOT NULL`, `CHECK (expression)`, `FOREIGN KEY`
```sql
CREATE TABLE movies (
  id INTEGER PRIMARY KEY,
  title TEXT,
  director TEXT,
  year INTEGER,
  length_minutes INTEGER
);
```
#### `ALTER TABLE`
```sql
ALTER TABLE mytable ADD col1 DataType TableConstraint DEFAULT val1;
```
#### `DROP TABLE`

#### Expressions
Mathematical and string functions and operators can transform values when query is executed, with the resulting variable name being declared with the `AS` keyword. It can also be used to create aliases for unwieldy column and table names.
```sql
SELECT col_expression AS expr_description FROM mytable;
```
Boolean expressions can be used to filter search results with `WHERE`
### Aggregate functions
**Aggregate expressions** or functions allow you to summarize information about a group of rows of data, such as `COUNT`, `MIN`, `MAX`, `AVG`, and `SUM`. Aggregates can be rendered in groups using `GROUP BY`
In order to filter rows while using `GROUP BY`, instead of `WHERE` use the `HAVING` clause, which is used exclusively with `GROUP BY` for this express purpose and written the same way.
### Order of execution
1. `FROM`, `JOIN`
2. `WHERE`
3. `GROUP BY`
4. `HAVING`
5. `SELECT`
6. `DISTINCT`
7. `ORDER BY`
8. `LIMIT`, `OFFSET`
## Tasks
### Movies
Table:Movies
id | title | director | year | length_minutes
:--- | :--- | :--- | :--- | :---
1   | Toy Story           | John Lasseter   | 1995 | 81
2   | A Bug's Life        | John Lasseter   | 1998 | 95
3   | Toy Story 2         | John Lasseter   | 1999 | 93
4   | Monsters, Inc.      | Pete Docter     | 2001 | 92
5   | Finding Nemo        | Andrew Stanton  | 2003 | 107
6   | The Incredibles     | Brad Bird       | 2004 | 116
7   | Cars                | John Lasseter   | 2006 | 117
8   | Ratatouille         | Brad Bird       | 2007 | 115
9   | WALL-E              | Andrew Stanton  | 2008 | 104
10  | Up                  | Pete Docter     | 2009 | 101
11  | Toy Story 3         | Lee Unkrich     | 2010 | 103
12  | Cars 2              | John Lasseter   | 2011 | 120
13  | Brave               | Brenda Chapman  | 2012 | 102
14  | Monsters University | Dan Scanlon     | 2013 | 110
#### 1.1 Find the title of each film
```sql
SELECT "title" FROM movies;
```
```kusto
Movies
| project title
```
#### 1.2 Find the director of each film
```sql
SELECT "director" FROM movies;
```
```kusto
Movies
| project director
```
#### 1.3 Find the title and director of each film
```sql
SELECT "title","director" FROM movies;
```
```kusto
movies
| project director, title
```
#### 1.4 Find the title and year of each film
```sql
SELECT "title","year" FROM movies;
```
```kusto
movies
| project title,year
```
#### 1.5 Find all information about each film
```sql
SELECT * FROM movies;
```
#### 2.1 Find the movie with a row id of 6
```sql
SELECT * FROM movies WHERE id IS 6;
```
#### 2.2 Find the movies released between 2000 and 2010
```sql
SELECT * FROM movies WHERE year BETWEEN 2000 AND 2010;
```
#### 2.3 Find the movies not released between 2000 and 2010
```sql
SELECT * FROM movies WHERE year NOT BETWEEN 2000 AND 2010;
```
#### 2.4 Find the first 5 Pixar movies and their release year
```sql
SELECT * FROM movies ORDER BY year LIMIT 5;
```
#### 3.1 Find all the Toy Story movies
```sql
SELECT * FROM movies WHERE "Title" LIKE "Toy Story%";
```
#### 3.2 Find all the movies directed by John Lasseter
```sql
SELECT * FROM movies WHERE Director IS "John Lasseter";
```
#### 3.3 Find all the movies (and director) not directed by John Lasseter
```sql
SELECT title,director FROM movies WHERE Director IS NOT "John Lasseter"
```
#### 3.4 Find all the "WALL-*" movies
```sql
SELECT * FROM Movies where Title LIKE "WALL-%";
```
#### 4.1 List all directors of Pixar movies alphabetically, without duplicates
```sql
SELECT DISTINCT Director From Movies ORDER BY Director;
```
#### 4.2 List the last 4 Pixar movies from most to least recent
```sql
SELECT * FROM Movies ORDER BY year DESC LIMIT 4;
```
#### 4.3 List the first 5 Pixar movies sorted alphabetically
```sql
SELECT * FROM Movies ORDER BY Title LIMIT 5;
```
#### 4.4 List the next 5 Pixar movies sorted alphabetically
```sql
SELECT * FROM Movies ORDER BY Title LIMIT 5 OFFSET 5;
```
#### 12.1 Find the number of movies each director has directed
```sql
SELECT director,count(title) FROM movies GROUP BY director;
```
#### 12.2 Find the total domestic and international sales that can be attributed to each director
```sql
SELECT director,sum(domestic_sales + international_sales) AS total_sales FROM movies JOIN boxoffice ON movies.id = boxoffice.movie_id GROUP BY director;
```
#### 13.1 Add *Toy Story 4* to the list of movies
```sql
INSERT INTO Movies (title,director,year,length_minutes) VALUES ("Toy Story 4","John Lasseter",2018,90);
```
#### 13.2 Add sales data to the BoxOffice table
```sql
INSERT INTO Boxoffice (movie_id,rating,domestic_sales,international_sales) VALUES (15,8.7,340000000,270000000);
```
#### 14.1 Correct a field
```sql
UPDATE movies SET director="John Lasseter" WHERE id = 2;
```
```sql
UPDATE movies SET year=1999 WHERE id=3;
```
```sql
UPDATE movies SET title="Toy Story 3",director="Lee Unkrich" WHERE id=11;
```
#### 15.1 Remove rows
```sql
DELETE FROM movies WHERE year < 2005;
```
```sql
DELETE FROM movies WHERE Director IS "Andrew Stanton";
```
#### 17.1 Alter a table
```sql
ALTER TABLE movies ADD Aspect_ratio FLOAT;
ALTER TABLE movies ADD Language TEXT DEFAULT "English";
```
#### 18.1 Drop table
```sql
DROP TABLE IF EXISTS movies;
DROP TABLE IF EXISTS BoxOffice;
```
### Cities
Table: North_american_cities
city | country  | population  | latitude  | longitude
:--- | :---     | :---        | :---      | :---
Guadalajara | Mexico | 1500800 | 20.659699 | -103.349609
Toronto | Canada | 2795060 | 43.653226 | -79.383184
Houston | United States | 2195914 | 29.760427 | -95.369803
New York | United States | 8405837 | 40.712784 | -74.005941
Philadelphia | United States | 1553165 | 39.952584 | -75.165222
Havana | Cuba | 2106146 | 23.05407 | -82.345189
Mexico City | Mexico | 8555500 | 19.432608 | -99.133208
Phoenix | United States | 1513367 | 33.448377 | -112.074037
Los Angeles | United States | 3884307 | 34.052234 | -118.243685
Ecatepec de Morelos | Mexico | 1742000 | 19.601841 | -99.050674
Montreal | Canada | 1717767 | 45.501689 | -73.567256
Chicago | United States | 2718782 | 41.878114 | -87.629798

#### 5.1 List all Canadian cities and their populations
```sql
SELECT city,population FROM North_american_cities WHERE country IS "Canada";
```
#### 5.2 Order all cities in the United States by their latitude from north to south
```sql
SELECT city from North_american_cities WHERE country IS "United States" ORDER BY "latitude" DESC;
```
#### 5.3 List all cities west of Chicago, ordered from west to east
```sql
SELECT city from North_american_cities WHERE longitude < -87.629798 ORDER BY longitude ASC; 
```
#### 5.4 List the 2 largest cities in Mexico by population
```sql
SELECT city from North_american_cities WHERE country IS "Mexico" ORDER BY population DESC LIMIT 2;
```
#### 5.5 List the third and fourth largest cities by population in the United States and their population
```sql
SELECT city,population from North_american_cities WHERE country IS "United States" ORDER BY population DESC LIMIT 2 OFFSET 2;
```
### Movie sales
Table: Movies
id | title | director | year | length_minutes
:--- | :--- | :--- | :--- | :---
1 | Toy Story | John Lasseter | 1995 | 81
2 | A Bug's Life | John Lasseter | 1998 | 95
3 | Toy Story 2 | John Lasseter | 1999 | 93
4 | Monsters, Inc. | Pete Docter | 2001 | 92
5 | Finding Nemo | Andrew Stanton | 2003 | 107
6 | The Incredibles | Brad Bird | 2004 | 116
7 | Cars | John Lasseter | 2006 | 117
8 | Ratatouille | Brad Bird | 2007 | 115
9 | WALL-E | Andrew Stanton | 2008 | 104
10 | Up | Pete Docter | 2009 | 101
11 | Toy Story 3 | Lee Unkrich | 2010 | 103
12 | Cars 2 | John Lasseter | 2011 | 120
13 | Brave | Brenda Chapman | 2012 | 102
14 | Monsters University | Dan Scanlon | 2013 | 110

Table: Boxoffice
movie_id | rating | domestic_sales | international_sales
:--- | :--- | :--- | :---
5 | 8.2 | 380843261 | 555900000
14 | 7.4 | 268492764 | 475066843
8 | 8 | 206445654 | 417277164
12 | 6.4 | 191452396 | 368400000
3 | 7.9 | 245852179 | 239163000
6 | 8 | 261441092 | 370001000
9 | 8.5 | 223808164 | 297503696
11 | 8.4 | 415004880 | 648167031
1 | 8.3 | 191796233 | 170162503
7 | 7.2 | 244082982 | 217900167
10 | 8.3 | 293004164 | 438338580
4 | 8.1 | 289916256 | 272900000
2 | 7.2 | 162798565 | 200600000
13 | 7.2 | 237283207 | 301700000

#### 6.1 Find the domestic and international sales for each movie
```sql
SELECT title,domestic_sales,international_sales FROM movies INNER JOIN boxoffice ON movies.id=boxoffice.movie_id;
```
#### 6.2 Show the sales numbers for each movie that did better internationally than domestically
```sql
SELECT title,domestic_sales,international_sales FROM movies INNER JOIN boxoffice ON movies.id = boxoffice.movie_id WHERE domestic_sales < international_sales;
```
#### 6.3 List all movies by their ratings in descending order
```sql
 SELECT title,rating FROM movies INNER JOIN boxoffice ON movies.id = boxoffice.movie_id ORDER BY rating DESC;
```
#### 9.1 List all movies and their combines sales in millions of dollars
```sql
SELECT title,(domestic_sales + international_sales) / 1000000 AS total_sales FROM movies JOIN boxoffice ON movies.id = boxoffice.movie_id;
```
#### 9.2 List all movies and their ratings in percent
```sql
SELECT title,(rating*10) as rating_percent FROM movies JOIN boxoffice ON movies.id = boxoffice.movie_id;
```
#### 9.3 List all movies that were released on even-numbered years
```sql
SELECT title,year FROM movies WHERE (year%2) = 0;
```
### Buildings

Table: buildings
building_name | capacity
:--- | :---
1e | 24
1w | 32
2e | 16
2w | 20

Table: employees
role | name | building | years_employed
:--- | :--- | :--- | :---
Engineer  | Becky A.    | 1e | 4
Engineer  | Dan B.      | 1e | 2
Engineer  | Sharon F.   | 1e | 6
Engineer  | Dan M.      | 1e | 4
Engineer  | Malcom S.   | 1e | 1
Artist    | Tylar S.    | 2w | 2
Artist    | Sherman D.  | 2w | 8
Artist    | Jakob J.    | 2w | 6
Artist    | Lillia A.   | 2w | 7
Artist    | Brandon J.  | 2w | 7
Manager   | Scott K.    | 1e | 9
Manager   | Shirlee M.  | 1e | 3
Manager   | Daria O.    | 2w | 6

#### 7.1 Find the list of all buildings that have employees
```sql
SELECT DISTINCT building FROM employees;
```
#### 7.2 Find the list of all buildings and their capacity
```sql
SELECT * FROM buildings;
```
#### 7.3 List all buildings and the distinct employee roles in each building (including empty buildings)
```sql
SELECT DISTINCT building_name,role FROM buildings LEFT JOIN employees ON buildings.building_name = employees.building;
```
#### 7.3 List all buildings and the distinct employee roles in each building (including empty buildings)
```sql
SELECT DISTINCT building_name,role FROM buildings LEFT JOIN employees ON buildings.building_name = employees.building WHERE role IS NOT NULL;
```
#### 8.1 Find the name and role of all employees who have not been assigned to a building
```sql
SELECT name,role FROM employees WHERE building IS NULL;
```
#### 8.2 Find the names of the buildings that hold no employees
```sql
SELECT building_name FROM buildings LEFT JOIN employees on buildings.building_name = employees.building WHERE role IS NULL;
```
#### 10.1 Find the longest time that an employee has been at the studio
```sql
SELECT MAX(years_employed) FROM employees;
```
#### 10.2 Find the average number of years employed in each role
```sql
SELECT role,AVG(years_employed) FROM employees GROUP BY role;
```
#### 10.3 Find the total number of employee years worked in each building
```sql
SELECT building,SUM(years_employed) FROM employees GROUP BY building;
```
#### 11.1 Find the number of artists in the studio (without a `HAVING` clause)
```sql
SELECT role,COUNT(role) FROM employees GROUP BY role HAVING role IS "Artist";
```
#### 11.2 Find the number of employees of each role in the studio
```sql
SELECT role,COUNT(role) FROM employees GROUP BY role;
```
#### 11.3 Find the total number of years employed by all engineers
```sql
SELECT years_employed,SUM(years_employed) FROM employees WHERE role IS "Engineer";
```

#### Create a new user and set a password
```sql
CREATE user rishabh@localhost identified BY 'pass123';
``` 
#### Revoke user privileges
```sql
REVOKE all privileges ON theitstuff.* FROM rishabh@localhost;
```
#### Generate an Azure report on Virtual MAchines
```kusto
Event
| where (EventLevelName == "Error")
| where (TimeGenerated > ago(1days))
| summarize ErrorCount = count() by Computer
| top 10 by ErrorCount desc
```
## Security
#### Reduce attack surface
- Isolate the DB server from other applications and services
- Remove unnecessary features from the DB server installation
- Block access from any other server except the application server, or at least allow SQL traffic to and from only designated IP addresses and place the SQL server in a VLAN.
#### Procedures
- Regularly update and patch the server
- Backups should be secured: restrict access to backup directories, storage hosting data, physical security of removable media, network access to backups...
- Sanitize SQL queries from a web application to prevent SQL injection
#### Human factor
- Set a strong admin password
- Use Least Privilege when assigning permissions. Grant read access to **views** instead of tables directly.
- Implement constant visibility into the DB server's configuration, with alerts when configuration changes or violates policy.
## Sources
  - "Create New Users And Grant Permissions In MySQL". [linuxandubuntu.com](http://www.linuxandubuntu.com/home/create-new-uesrs-grant-permission-mysql/):  2019/07/06.
  - "Overview of SQL Server Security". [Microsoft Docs](https://docs.microsoft.com/en-us/dotnet/framework/data/adonet/sql/overview-of-sql-server-security): 2017/03/29.
  - "11 steps to secure SQL". [upguard.com](https://www.upguard.com/blog/11-steps-to-secure-sql): 2019/07/30.
  - "SQLBolt: Learn SQL with simple, interactive exercises". [SQLBolt](https://sqlbolt.com/lesson/introduction)
