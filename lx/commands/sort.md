### sort

Option  | Effect
:---    | :---
`-k $N` | sort by column number `$N`
`-r`    | reverse sort order
`-t $X` | set delimiter to character `$X`


Sort by space-delimited columns. Processes consuming the most memory will be at the bottom [[23](sources.md)]
```sh
ps aux | sort -nk 4
```
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```
