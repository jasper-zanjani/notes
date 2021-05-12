In Kusto documentation `T` typically refers to the Table being queried:
```kql
T
| where Predicate
```

`<>` is equivalent to `!=`
```
SecurityEvent
| where Level <> 8
| where EventID==4672
```

Select columns to include, rename, or drop

```kusto
T
| project
    X=C,                       // Rename column C to X
    A=2*B,                     // Calculate a new column A from the old B
    C=strcat("-",tostring(C)), // Calculate a new column C from the old C
    B=2*B                      // Calculate a new column B from the old B
```

```
StormEvents
| extend label = case (
  DamageProperty < 1000, "Storm",
  DamageProperty > 1000 and DamageProperty < 10000, "Disaster",
  "Catastrophe" )
| summarize count() by label
```

The SecurityEvent table provided as part of the [Log Analytics][Log Analytics] workspace trainingg dataset contains event viewer logs typical of what a security analyst would analyze, with the following columns:

- TimeGenerated
- Account
- AccountType (Machine or User)
- Computer
- EventSourceName
- Channel
- CommandLine

Find logons, producing number of logins per Computer for computers with names beginning with "App"
```js
SecurityEvent
| where TimeGenerated between (ago(14d)..ago(7d))
| where EventID == 4624
| where Computer startswith "App"
| summarize count() by Computer
```

```js
SecurityEvent
| where EventID == 4688
| summarize count() by CommandLine, Computer
```

| id   | title               | director       | year | length_minutes |
| :--- | :------------------ | :------------- | :--- | :------------- |
| 1    | Toy Story           | John Lasseter  | 1995 | 81             |
| 2    | A Bug's Life        | John Lasseter  | 1998 | 95             |
| 3    | Toy Story 2         | John Lasseter  | 1999 | 93             |
| 4    | Monsters, Inc.      | Pete Docter    | 2001 | 92             |
| 5    | Finding Nemo        | Andrew Stanton | 2003 | 107            |
| 6    | The Incredibles     | Brad Bird      | 2004 | 116            |
| 7    | Cars                | John Lasseter  | 2006 | 117            |
| 8    | Ratatouille         | Brad Bird      | 2007 | 115            |
| 9    | WALL-E              | Andrew Stanton | 2008 | 104            |
| 10   | Up                  | Pete Docter    | 2009 | 101            |
| 11   | Toy Story 3         | Lee Unkrich    | 2010 | 103            |
| 12   | Cars 2              | John Lasseter  | 2011 | 120            |
| 13   | Brave               | Brenda Chapman | 2012 | 102            |
| 14   | Monsters University | Dan Scanlon    | 2013 | 110            |

Find the title of each film
```kusto
Movies 
| project title
```
Number of reporting computers each hour <sup>AZ-103: 53</sup>
```kusto
Heartbeat 
| summarize dcount(ComputerIP) by bin(TimeGenerated, 1h) 
| render timechart
```
List top 10 VMs with most error events over the past day <sup>MeasureUp</sup>
```kusto
Event
| where (EventLevelName == "Error")
| where (TimeGenerated > ago(1days))
| summarize ErrorCount = count() by Computer
| top 10 by ErrorCount desc
```

Render a SQL query as KQL

```sql
EXPLAIN
SELECT name FROM greeks;
```

Count instances of a value

```
movies | summarize movies_directed = count() by director
```

Create a new column dynamically from others

```js
movies | extend age = 2020 - year | project name, age;
```

Hide secrets from the queries log

```
print h"Hello world!";
.show 
```

Kusto clusters can be provisioned and Kusto databases created and manipulated using both PowerShell and Azure CLI.

The Azure CLI `kusto` module will not be supported after 01/01/2021.

```sh
az extension add -n kusto
```

Create cluster

=== "Azure PowerShell"

    ```powershell
    New-AzKustoCluster -ResourceGroupName testrg -Name testnewkustocluster -Location 'East US' -SkuName Standard_D11_v2 -SkuTier Standard -EnableDoubleEncryption true
    ```
    
=== "Azure CLI"

    ```sh
    az kusto cluster create --name --resource-group --sku
    ```
        
    ```sh
    az kusto database create
    ```

Create table

Connect to database
```
#connect cluster('jasper.eastus').database('test');
```

[Create table](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/management/create-table-command)
```
.create table starships (Name:string, Registry:string, Class:string, Crew:int32)
```


Ingest data
```js
.ingest into table T h'https://raw.githubusercontent.com/jasper-zanjani/dogfood/master/csv/greeks.csv' with (ignoreFirstRecord=true)
```
Alternatively, define a new [`datatable`](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/query/datatableoperator?pivots=azuredataexplorer) inline

```js
let starships = datatable(Name:string,Class:string,Registry:string,Crew:int)
[
  "USS Enterprise", "Constitution","NCC-1701",203,
  "USS Constitution","Constitution","NCC-1700",204,
  "USS Defiant","Defiant","NX-74205",50,
  "USS Voyager","Intrepid","NCC-74656",141,
  "USS Enterprise","Galaxy","NCC-1701-D",6000,
  "USS Reliant","Miranda","NCC-1864",35
];
```
Search for a word

```js
starships | search  "enterprise";
```
```js
search in (SecurityEvent) "Cryptographic"
| take 10;
```

[Datetime <sup>:material-microsoft:</sup>](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/query/scalar-data-types/datetime) values support a menagerie of functions

```js
print datetime(2015-01-01) # 2015-01-01 00:00:00.0000
print format_datetime(datetime(2015-01-01), "yyyy") # 2015
```

Concatenate values from other columns.

```js
StormEvents
| project EpisodeId, where_storm = strcat(EventType, " in ", State);
```

Export data
```js
.export async to sql ['dbo.StormEventTypeTable']
```

Sources

- [Azure Data Explorer documentation <sup>:material-microsoft:</sup>](https://docs.microsoft.com/en-us/azure/data-explorer/)
- [How to start with Microsoft Azure Data Explorer  <sup>:material-play:</sup>](https://app.pluralsight.com/courses/2413d815-291e-4af4-a048-566402102229/table-of-contents)
- [KQL quick reference <sup>:material-microsoft:</sup>](https://docs.microsoft.com/en-us/azure/data-explorer/kql-quick-reference)
- [SQL to Kusto cheat sheet  <sup>:material-microsoft:</sup>](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/query/sqlcheatsheet)
- [Kusto.Explorer <sup>:material-microsoft:</sup>](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/tools/kusto-explorer)
- **Azure Sentinel webinar** parts 1, [2  <sup>:material-play:</sup>](https://www.youtube.com/watch?v=YKD_OFLMpf8&t=883s), 3
- KQL syntax: [`count`](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/query/countoperator), [`take`](https://docs.microsoft.com/en-us/azure/data-explorer/kusto/query/takeoperator)