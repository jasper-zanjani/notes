### zip
Archive files in InfoZIP format
```sh
zip zipfile *files
```

### unzip
Extract compressed files in a zip archive

### zipcloak
Encrypt a zip {archive}
```sh
zipcloak archive
```

### zipdetails
Produce a detailed list of information about a zip {archive}
```sh
zipdetails archive
```

### zipgrep
Search for {string} within all files of a zip {archive}
```sh
zipgrep string archive
```

### zipinfo
Print information about ZIP format archives
```sh
zipinfo *zipfiles
```
### zipnote
Annotate a zip {archive} by creating a {comments} file, which can then be edited and rewritten with `-w` flag
```sh
zipnote archive > comments
```

### zipsplit
Split `zipfile` into segments of size `size`
```sh
zipsplit -n size zipfile
```