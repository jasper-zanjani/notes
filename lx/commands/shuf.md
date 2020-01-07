### `shuf`

Option  | Effect
:---    | :---
`-e`    | shuffle items separated by a space


Randomly permute input
```sh
shuf 
```
Shuffle `$ITEMS` separated by a space [[10](sources.md)]
```sh
shuf -e $ITEMS
```
Print random selection of integers from {x} to {y} (inclusive) without replacement
```sh
shuf -i x-y
```
Print random selection of integers from {x} to {y} (inclusive), with replacement
```sh
shuf -i x-y -r
```
Shuffle items separated by newline in file `cards.txt`, displaying only one [[10](sources.md)]
```sh
shuf -n 1 items.txt
```
