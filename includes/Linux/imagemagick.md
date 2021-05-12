# imagemagick

[imagemagick identify]: #imagemagick-identify                   'Describe the format and characteristics of one or more image files'
[imagemagick mogrify]: #imagemagick-mogrify                    'Resize, blur, crop, despeckle, dither, draw on, flip, join, resample, etc'

[`identify`][imagemagick identify] 
[`mogrify`][imagemagick mogrify] 

### identify

| Option             | Effect                                                                                                                                                                          |
| :----------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `-format {string}` | display formatted image characteristics; {string} is formatted string using `%[key]` escape sequences<br/> **%w** current width in pixels <br/> **%h** current height in pixels |

### mogrify
| Option               | Effect                                                                                                                                                                         |
| :------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `-write $FILENAME`   | save to `filename`                                                                                                                                                             |
| `-resize $Xx$Y`      | resize image to `$X` pixels by `$Y` pixels                                                                                                                                     |
| `-crop $SIZE$OFFSET` |
| `-gravity $TYPE`     | set current gravity suggestion for various other options <br>possible values `NorthWest`, `North`, `NorthEast`, `West`, `Center`, `East`, `SouthWest`, `South`, or `SouthEast` |
  
| Argument patterns | bla                                                                                                                                                                                                      |
| ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| {geometry}        | **{size}{offset}**                                                                                                                                                                                       |
| {size}            | **{scale}%** height and weight are both scaled by a specified percentage<br/> **{width}x{height}** maximum values of height and width<br/> **{width}x{height}^** minimum values of height and width<br/> |
| {offset}          | also affected by `-gravity` setting<br/> **`+0+0`** top-left corner                                                                                                                                      |
| gravity           |

Resize images
```sh
magick mogrify -resize 1920x1200 -write mars-bg.jpg pia22511.jpg
magick identify -format "%w x %h" pia22511.jpg
```
Save the output of a command as an image (`convert` is from the ImageMagick software suite) [ref][CLKF]
```sh
cmd | convert label:@- image.png
``` 
View image metadata (`identify` is from the ImageMagick software suite) [ostechnix.com](https://www.ostechnix.com/how-to-view-image-metadata-on-linux/ "How to view image metadata")
```sh
identify image.png # => dimensions, color depth, color profile
identify -verbose image.png
```