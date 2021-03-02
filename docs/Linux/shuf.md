Print random selection of integers from {x} to {y} (inclusive) without replacement
```sh
shuf -i x-y
```
Print random selection of integers from {x} to {y} (inclusive), with replacement
```sh
shuf -i x-y -r
```
Shuffle items separated by newline in file `cards.txt`, displaying only one 
```sh
shuf -n 1 items.txt
```