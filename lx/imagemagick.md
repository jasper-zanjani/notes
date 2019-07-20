### Image Magick

Syntax | Effect
:--- | :---
`mogrify` - resize, blur, crop, despeckle, dither, draw on, flip, join, resample, etc
`identify`- describes the format and characteristics of one or more image files

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
  
#### Argument patterns
### {geometry}
[Image Geometry](https://imagemagick.org/script/command-line-processing.php#geometry) have several patterns
  - `{size}{offset}`

### {size}
  - `{scale}%` height and weight are both scaled by a specified percentage
  - `{width}x{height}` maximum values of height and width
  - `{width}x{height}^` minimum values of height and width
  - 
### {offset}
also affected by `-gravity` setting
`+0+0`
  top-left corner
### gravity
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

Syntax | Effect
:--- | :---
`magick mogrify -resize 1920x1200 -write mars-bg.jpg pia22511.jpg` |
`magick identify -format "%w x %h" pia22511.jpg` | 

### Sources
  - "Geometry" [imagemagick.org](https://imagemagick.org/script/command-line-processing.php#geometry)
