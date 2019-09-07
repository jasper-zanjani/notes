# Databases
The historical motivation for the invention of relational databases was minimizing the cost of storage by eliminating duplication. At the turn of the century, as storage cost fell, other database paradigms emerged, producing **7 fundamental categories of data** [[1](#sources)]:
  - **Relational** data
  - **Key-value** data: divided into **key-to-blob** storage and **key-to-document** storage
  - **In-memory** storage: i.e. Redis, MemCacheD
  - **Graph** storage
  - **Search**: introspection into natural-language queries, i.e. **Managed Elastic Search**
  - **Time-series**
  - **Ledger**

NoSQL databases are read-optimized, not storage-optimized. They can't be used like traditional relational databases, which explains why many teams trying to implement NoSQL find unsatisfactory results. **Normalized** data (deduplicated) is not used by NoSQL which uses **hierarchical** data. Instantiated views are implemented in NoSQL whereas queries are computed ad-hoc in relational databases.[[2](#sources)\
NoSQL databases are made of tables which are populated with **items** with varying **attributes**. One of these attributes is considered the **partition key**, which uniquely identifies the item and determines the data distribution. An additional attribute, optionally, can be the **sort key** which orders items.[[2](#sources)\
"Hot keys" are an indication of bad NoSQL design and an anti-pattern, where a single storage node is being accessed much more frequently than others. A fully distributed database, where requests are distributed uniformly, is the ideal situation.[[2](#sources)
NoSQL is most efficiently used with **composite keys** which combine more than one attribute in order to create hierarchical structures.
## Glossary
Term      | Description
:---      | :---
cursor    | control structure that enables traversal over the records in a database by pointing to one individual record at a time [[3](#sources)]
## MongoDB
#### Creating a new database
Databases are implicitly created by switching to them, then inserting documents.
```mongo
use collection
db.artists.insert({ artistname: "Picasso" })
```
## Sources
  1. "Choosing a Database Platform". [AWS Podcast 329](sources/README.md#aws-329).
  2. "AWS re:Invent 2018: Amazon DynamoDB Deep Dive: Advanced Design Patterns for DynamoDB (DAT401)". [YouTube](https://youtu.be/HaEPXoXVf2k).
  3. "Cursor (databases)". [Wikipedia](https://en.wikipedia.org/wiki/Cursor_(databases).