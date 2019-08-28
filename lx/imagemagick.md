### imagemagick

Command groups  | Effect
:---            | :---
identify        | describes the format and characteristics of one or more image files
mogrify         | resize, blur, crop, despeckle, dither, draw on, flip, join, resample, etc

#### `identify` Options
`-format {string}` 
  - display formatted image characteristics
  - `{string}` is formatted string using `%[key]` escape sequences
    - `%w` current width in pixels
    - `%h` current height in pixels
    - lots more: https://imagemagick.org/script/escape.php

#### `mogrify` Options
`-write {filename}`
  save to `filename`
`-resize XxY`
  resize image to `X` pixels by `Y` pixels
`-crop {geometry}`
  
Argument patterns 
:---          | 
{geometry}    | **{size}{offset}**
{size}        | **{scale}%** height and weight are both scaled by a specified percentage<br/> **{width}x{height}** maximum values of height and width<br/> **{width}x{height}^** minimum values of height and width<br/>
{offset}      | also affected by `-gravity` setting<br/> **`+0+0`** top-left corner
gravity       | 
`-gravity {type}`
  set current gravity suggestion for various other options
  {type} can have following values
  - `NorthWest`
  - `North`
  - `NorthEast`
  - `West`
  - `Center`
  - `East`
  - `SouthWest`
  - `South`
  - `SouthEast`

## Examples
#### Resize images
```sh
# Using full syntax
magick mogrify -resize 1920x1200 -write mars-bg.jpg pia22511.jpg

# Using abbreviated syntax
magick identify -format "%w x %h" pia22511.jpg
```
#### Save the output of a command as an image
The `convert` command is from the ImageMagick software suite [[2](#sources)]
```sh
cmd | convert label:@- image.png
``` 
#### View metadata
The `identify` is from the ImageMagick software suite [[3](#sources)]
```sh
identify image.png # => dimensions, color depth, color profile
identify -verbose image.png
```

### Sources
  1. "Geometry" [imagemagick.org](https://imagemagick.org/script/command-line-processing.php#geometry) 
  2. Cannon, Jason. [*Command Line Kung Fu*](../sources/clkf.md)
  3. "How to view image metadata on Linux". [OSTechNix](https://www.ostechnix.com/how-to-view-image-metadata-on-linux/): 2019/08/26.