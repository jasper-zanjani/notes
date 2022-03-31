# Asyncio


The asyncio module offers an implementation of **coroutines** which allow tasks to control context switching to implement [**concurrency**](Concurrency).

The **await** keyword is a checkpoint that indicates where it is safe for the process to go to another coroutine, allowing total control over **context switching**.

```py
import asyncio
import time

counter = 0

async def func1():
    global counter

    while True:
        counter += 1
        counter -= 1
        await asyncio.sleep(0)

async def func2():
    global counter

    while True:
        counter += 1
        counter -= 1
        await asyncio.sleep(0)

asyncio.gather(func1(), func2())
asyncio.get_event_loop().run_forever()
```


```py
async def get_users():
    users = await client.do_query('select * from users')
    return users

async def main():
    task = asyncio.create_task(get_users())
    # ...
    await task

asyncio.run(main())
```

Allows the joining of multiple threads.
```py
async def get_users():
    users = await client.do_query('select * from users')
    return users

async def main():
    await asyncio.gather(
        get_users(),
        get_users(),
    )

asyncio.run(main())
```
```py
async def get_users():
    users = await client.do_query('select * from users')
    return users

asyncio.run(get_users())
```

```py
async def main():
    users = await get_users()
    print(users)

asyncio.run(main())
```

Sources:

- [Demistifying Python's Async and Await keywords](https://youtu.be/F19R_M4Nay4)
