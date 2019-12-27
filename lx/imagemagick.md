### imagemagick


Command group   | Description
:---            | :---
identify        | describe the format and characteristics of one or more image files
mogrify         | resize, blur, crop, despeckle, dither, draw on, flip, join, resample, etc

#### `identify`
Option                            | Effect
:---                              | :---
`-format {string}`                | display formatted image characteristics; {string} is formatted string using `%[key]` escape sequences<br/> **%w** current width in pixels <br/> **%h** current height in pixels

#### `mogrify`
Option               | Effect
:---                 | :---
`-write $FILENAME`   | save to `filename`
`-resize $Xx$Y`      | resize image to `$X` pixels by `$Y` pixels
`-crop $SIZE$OFFSET` | 
`-gravity $TYPE`     | set current gravity suggestion for various other options <br>possible values `NorthWest`, `North`, `NorthEast`, `West`, `Center`, `East`, `SouthWest`, `South`, or `SouthEast`
  
Argument patterns 
---           | ---
{geometry}    | **{size}{offset}**
{size}        | **{scale}%** height and weight are both scaled by a specified percentage<br/> **{width}x{height}** maximum values of height and width<br/> **{width}x{height}^** minimum values of height and width<br/>
{offset}      | also affected by `-gravity` setting<br/> **`+0+0`** top-left corner
gravity       | 

Resize images (using full syntax)
```sh
magick mogrify -resize 1920x1200 -write mars-bg.jpg pia22511.jpg
```
(using abbreviated syntax)
```sh
magick identify -format "%w x %h" pia22511.jpg
```
Save the output of a command as an image
The `convert` command is from the ImageMagick software suite [^][2]
```sh
cmd | convert label:@- image.png
``` 
View image metadata
The `identify` is from the ImageMagick software suite [^][3]
```sh
identify image.png # => dimensions, color depth, color profile
identify -verbose image.png
```

### Sources
[1]: https://imagemagick.org/script/command-line-processing.php#geometry "imagemagick.org - Geometry"
[2]: ../sources/clkf.md "Cannon, Jason. _Command Line Kung Fu_."
[3]: https://www.ostechnix.com/how-to-view-image-metadata-on-linux/ "ostechnix.com - How to view image metadata on Linux"