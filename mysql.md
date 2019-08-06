# MySQL
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
#### 1.2 Find the director of each film
```sql
SELECT "director" FROM movies;
```
#### 1.3 Find the title and director of each film
```sql
SELECT "title","director" FROM movies;
```
#### 1.4 Find the title and year of each film
```sql
SELECT "title","year" FROM movies;
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
SELECT * FROM movies ORDER BY year LIMIT 5
```
#### 3.1 Find all the Toy Story movies
```sql

```
#### 3.2 Find all the movies directed by John Lasseter
#### 3.3 Find all the movies (and director) not directed by John Lasseter
#### 3.4 Find all the "WALL-*" movies

#### Create a new user and set a password
```sql
create user rishabh@localhost identified by 'pass123';
``` 
#### Revoke user privileges
```sql
revoke all privileges on theitstuff.* from rishabh@localhost;
```

## Security
#### Isolate DB server
Production DB servers should be isolated from other applications and services. Dedicated DB servers have a smaller attack surface. If possible, they should be placed in a restricted VLAN so that only authorized traffic can access it. Ports 1433/1434 and 3306/3307 should never be open to the Internet.
#### Tailor the DB installation
Remove unnecessary features
#### Regularly update the server
Have a regular patching schedule 

## Sources
  - "Create New Users And Grant Permissions In MySQL". [linuxandubuntu.com](http://www.linuxandubuntu.com/home/create-new-uesrs-grant-permission-mysql/):  2019/07/06.
  - "Overview of SQL Server Security". [Microsoft Docs](https://docs.microsoft.com/en-us/dotnet/framework/data/adonet/sql/overview-of-sql-server-security): 2017/03/29.
  - "11 steps to secure SQL". [upguard.com](https://www.upguard.com/blog/11-steps-to-secure-sql): 2019/07/30.