### `yay`
Display all AUR packages that need to be updated (deprecated)
```sh
yay -Pu
yay --show --upgrades package
```
List all install packages, filtering output to packages that are out-of-date on the local system
```sh
yay -Qu
yay --query --upgrades
```
Install {pkg} from the AUR
```sh
yay -S package
yay --sync package
```
Display information about {package}
```sh
yay -Si package
yay --sync --info package
```
Search for {pkg} in AUR repos
```sh
yay -Ss package
yay --sync --search package
```
Update all packages from AUR and official repos
```sh
yay -Syu
yay --sync --refresh --sysupgrade
```
Remove unwanted dependencies of now-removed installations of AUR repos
```sh
yay -Yc
yay --yay --clean
```
