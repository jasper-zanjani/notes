# Bulma
## Customizing variables
Requires compiling CSS from SASS or SCSS
4 types of variables that can be used to customize styling
  1. initial variables: global variables with literal values
  2. derived variables: global variables that reference other variables or are computed
  3. generic variables: for HTML elements with no CSS class
  4. element/component variables: specific to a Bulma element or component
### Headers
`.title`
`.subtitle`
## Variables
### Color
- `$white`
- `$black`
- `$light`
- `$dark`
- `$pimary`
- `$info`
- `$success`
- `$warning`
- `$danger`
- `$red`
- `$yellow`
- `$green`
- `$cyan`
- `$blue`
- `$turquoise`
- `$white-ter`
- `$grey-darker`
## Components
### Hero
`.hero > .hero-body`
`.hero > hero-head,.hero-body,.hero-foot` full-height
## Input and forms
`.field` container for one or more `.control` containers
`.control` container for single form controls
'''
.field
  label.label
    input.input(type="text", placeholder="Text input")
  p.help This is help text
'''
### Checkbox
`label.checkbox > input(type="checkbox")`

'''
label.checkbox
	input(type="checkbox" value="marketing")
	| Send me special offers
'''
- `type` attribute values in Syntax spreadsheet
- `disabled` and `checked` flags
### Radio button
`label.radio > input(type="radio")`
'''
label.radio
	input(type="radio", value="yes") Yes
label.radio
	input(type="radio", value="no") No
label.radio
	input(type="radio", value="maybe') Maybe
'''
- also `disabled` and `checked` flags
### File upload input
- structure:
  `div.file`          main container
    `.label.file-label` actual interactive and clickable part of element
      `input.file-input`  native file input, hidden
      `span.file-cta`     upload call-to-action
        `span.file-icon`
          `i.fas.fa-upload` upload icon
        `span.file-label` Choose a file
