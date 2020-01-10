### `chown`
Change a file or directory's ownership. To change the user and group owner of a file to {user} and {group}, `chown`'s syntax is of the format `user:group` [[32](sources.md)].
```sh
chown susan:delta file          # Assign {file} to user `susan` and group `delta`
chown alan file                 # Assign {file} to user `alan`
chown alan: file                # Assign {file} to user and group `alan`
chown :gamma file               # Assign {file} to the group `gamma`
```
Recursively grant {user} ownership to {path}
```sh
chown -R user path
```
Assign {path} to `susan` and group `delta`, recursively and with verbose output
```sh
chown --verbose --recursive susan:delta path 
chown -vR susan:delta path
```
```sh
chown -vR --reference=. path    # Use a `reference` file to match the configuration of a particular file
chown -cfR --preserve-root alan # `preserve-root` prevents changes to files in the root directory, but has no effect when not used with `recursive`
```