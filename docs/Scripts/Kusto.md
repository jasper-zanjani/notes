If you're serious about learning Azure, you've gotta learn Kusto. 

Kusto is Microsoft's custom-built relational database query language, combining the functionality of SQL with the syntax of a shell language. 

It is a deep topic, but it's worth mastering if you're planning on doing data science or security in Azure. 

But like a lot of things worth mastering, getting started is a pain. That's where I'm going to help you.

### Setup
The first thing you need to get started is an Azure account. If this is your first time signing up for an account, you'll be able to receive a $200 credit that will last 30 days.

<strike>One of the main complications learning Kusto is that, as far as I know, there isn't a local client like sqlite that you can just download and start playing around with. There is the Kusto Explorer which is available for Windows only, but I'm not a big fan of it. </strike>

[Azure Data Studio](https://docs.microsoft.com/en-us/sql/azure-data-studio/download-azure-data-studio?view=sql-server-ver15) has a [Kusto extension](https://docs.microsoft.com/en-us/sql/azure-data-studio/extensions/kusto-extension?view=sql-server-ver15). After installing it, you can connect to an ADX cluster.

Now, what they do have is a Web UI at [dataexplorer.azure.com](https://dataexplorer.azure.com) which you.. don't even need an Azure account for! It's more or less publicly accessible as long as you login with a Microsoft account.

Now you would think this would be the perfect place to play around with Kusto to start learning it, but if you go straight here you won't have any available data to run queries against.

This layout is modeled on similar graphical applications put out by Microsoft like SQL Server Manager Studio where your data sources or connections are listed on the left sidebar, top pane is where you would compose your queries, and then the results would be displayed on the bottom pane.

As we can see, there are no data connections available at the present time. So the first thing I'm going to show you, even though I'm not going to use it, is how to add the default "Samples" database that is used in every other tutorial and video you're going to find on this topic.


Add connection > help.kusto.windows.net, and it's available to the public so you should immediately see the connection show up and you can begin running queries, even though like I said I'm not going to use it for this video.

This dataset includes tables on Covid19, US geospatial data, and of course the legendary StormEvents table which you will see everywhere somebody is trying to teach Kusto.

But we're not going to go with the canned data that Microsoft provides because, frankly, it's boring and I can't learn with it. Unless you've already done a lot of data analysis, which I haven't, the results will probably seem frankly meaningless.

We want to make our own data, or rather I'm going to give you some simple data to play with that you will be able to play with and engage with better. But to do that, we have to get into Azure and create our own Kusto cluster.


The first thing we need to do is [create a free Azure account](https://azure.microsoft.com/en-us/free/). Now even though it says it's free, if you're signing in for the first time you will be expected to produce credit card information, so be ready for that.

There are a couple of different ways that Kusto is used in Azure, for example Log Analytics workspaces. But this video is going to focus on just learning the syntax of the language itself, and for that we're going to be using Azure Data Explorer.

There are many ways of going about this. Even though I typically opt for using a command-line interface, of which there are two available for Azure, Azure PowerShell and Azure CLI, today for the sake of simplicity I'm going to stick to the Azure website which is referred to as the Portal.

![](img/Kusto-1.png)

It will take a few minutes for the cluster to deploy. But once it does, we will be able to connect to it using the Data Explorer web ui by adding it as a source just like we did.

Now that the database is up let's add some tables. 

![](img/Kusto-2.png)

```
.create table starships (name:string, class:string, registry:string, series:string);
```
Ingest data
```
.ingest into table starships 'https://raw.githubusercontent.com/jasper-zanjani/kusto/main/starships.csv' with (ignoreFirstRecord=true);
```
If you make a mistake
```
.drop table starships;
```

### Joining other tables
```
.create table classes (class:string, crew: int32);
.ingest into table classes 'https://raw.githubusercontent.com/jasper-zanjani/kusto/main/classes.csv' with (ignoreFirstRecord=true);

.create tables series (series:string, description:string);
.ingest into table series 'https://raw.githubusercontent.com/jasper-zanjani/kusto/main/series.csv' with (ignoreFirstRecord=true);
```

There are a lot of different join flavors: leftouter, rightouter, fullouter, leftsemi, rightsemi, leftanti, rightanti...

Joining with classes
```
starships | join kind = inner (classes) on $left.class==$right.class
| project name, crew;
```


### Sqlbolt
I love interactive tutorials, and one of my favorite tutorials has been sqlbolt.com.

It is a very well-thought out site that takes you from topic to topic with interactive exercises in the browser to challenge what you learn every step of the way. 

Best of all, it's totally free, with no need even to sign up. 

In fact, I'm such a big fan when I decided to make this video I decided simply to adapt SQLbolt's lessons to Kusto.

If you're interested in learning SQL, I can't recommend sqlbolt highly enough. 
