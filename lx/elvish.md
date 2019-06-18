# Elvish shell
## Installation
- __Arch__ Available in the [AUR](https://aur.archlinux.org/packages/elvish/)
- __Debian__ There are packages available on Debian and Ubuntu repositories, but they are out of date. The recommended solution is from source or PPA.
- __Fedora__ Available in the [FZUG repo](https://github.com/FZUG/repo/wiki/Add-FZUG-Repository)
## Syntax
### if/else
```elvish
~> if $true { echo good } else { echo bad }
```
Output:
```
good
```
### for loop iterating over an array
```elvish
~> for x [lorem ipsum] {
     echo $x.pdf
   }
```
Output:
```
lorem.pdf
ipsum.pdf
```

### try/catch block and raising an error
```elvish
~> try {
     fail 'bad error'
   } except e {
     echo error $e
   } else {
     echo ok
   }
```
Output:
```
error ?(fail 'bad error')
```
## Sources
[ItsFOSS](https://itsfoss.com/elvish-shell/)