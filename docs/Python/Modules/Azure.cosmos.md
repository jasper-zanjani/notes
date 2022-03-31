# Azure.cosmos

```py
import azure.cosmos
from azure.cosmos.partition_key import PartitionKey

database = cosmos_client.create_database('RetailDemo')
container = database.create_container(id='WebsiteData', partition_key=PartitionKey(path='/CartID'))
print('Container WebsiteData created')
```
