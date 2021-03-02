Run MongoDB service in the background on port 80
```sh
mongod --dbpath $HOME/db --port 80 --fork --logpath /var/tmp/mongodb
```
