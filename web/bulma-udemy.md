# Bulma Udemy course
## Mixins
Elements that occur within modifier class names
- responsive mixins (4)
  - `mobile`
  - `tablet-only`
  - `desktop-only`
  - `widescreen-only`
  - `touch`
  - `tablet`
  - `desktop`
  - `widescreen`
  - `fullhd`
- color mixins
  - `primary` (`$turquoise`)
  - `info`    (`$cyan`)
  - `warning` (`$yellow`)
  - `danger`  (`$red`)
  - `light`   (`$white-ter`)
  - `dark`    (`$grey-darker`)
  - `success` (`$green`)
  - `link`    (`$blue`)
  - `white`   (`$white`)
  - `black`   (`$black`)
- display mixins (10)
  - `flex`
  - `block`
  - `inline`
  - `inline-block`
  - `inline-flex`
  - `hidden`
- text size mixins (11)
  - numbers from 1-7 correspond to decreasing text sizes, from 3 rem to 0.75 rem
- size mixins
  -`large`
  -`medium`
  -`small`
- image size mixins
  - `64x64`
- column size mixins (12)
  - `three-quarters`
  - `two-thirds`
  - `half`
  - `one-third`
  - `one-quarter`
  - `full`
- text justification mixins
  - `centered`
  - `justified`
  - `left`
  - `right`
## Icons (7)
icons mostly appear within a `span` class
  - structure
    `span.icon`
      `i.{icon style mixin}.{font-size mixin}.fa-{name}`
  - size: `fa-xs` | `fa-sm` | `fa-lg` | `fa-2x` | ... | `fa-10x`
  - fixed-width: `fa-fw`
  - icon style mixins
    - `fas` solid (free) 
    - `far` regular (Pro)
    - `fal` light (Pro)
    - `fab` brands (free)
  - color: inline CSS, e.g. `(style="color: tomato;")`
  - e.g. `i.fas.fa-lg.fa-stroopwaffel`
### Layering
requires SVG + JS framework
  - `(data-fa-transform={modifications})` shrink icons
    - `shrink-{x}` where `x` is a positive number
    - `up-{x}` | `down-{x}`
    - `rotate--{d}` where `d` is the number of degrees
  - `span.fa-layers-counter` put text in top-right corner
  - `span.fa-layers-text` put text in middle
#### Structure
span.fa-layers.fa-fw
  i.fas.fa-square
  i.fa-inverse.fas.fa-circle
## Styling
### Helper classes (9)
`is-clearfix` enclose ("clear") the entirety of floating children
`is-pulled-left` | `is-pulled-right` float to either side
`is-marginless` remove all margin
`is-paddingless` remove padding
`is-radiusless` sharp corners
`is-shadowless` no drop shadow
`is-unselectable` prevent text from being selected
`is-invisible` invisible but space is still taken up
### Typography helpers (11-12)
change size and color of text for one or multiple viewport widths
`.is-size-{size mixin}-{responsive mixin}` sizes
  - e.g. `.is-size-1-touch`
`.has-text-{color mixin}` color
  - e.g. `has-text-danger`
`.has-text-{alignment mixin}-{responsive mixin}`
## Layout
### Containers
`.container` main container class
### Columns (12)
  - structure:
    `.columns` container, "row of columns"
      `.column` up to 12 columns that automatically manage space
  - modifiers:
    - `.is-{column-size mixin}` across all display sizes
    - `.is-{column-size mixin}-{responsive mixin}` for a particular display size
### Hero sections (14)
  - structure:
    `section.hero` main container class
      `.hero-head` (optional)
      `.hero-body` immediate descendant
      `.hero-foot` (optional)
  - modifiers:
    - `.is-bold` adds a dark gradient
    - `.is-{color mixin}` color of background
    - `.is-{size}` | `.is-fullheight`
### Other elements
`.section` add padding (16)
`.footer` add padding and a background color (17)
`.level` horizontally align multiple buttons, but then vertically stack them in mobile (by default)
`.level` > `.level-item` | `.level-left` > `.level-item`
  - display-size `.is-{display size mixin}` e.g. `is-mobile`
### Media Object
looks like a social media or forum post: image or avater next to text content; can be nested up to 3 levels deep
  - structure:
    `article.media`
      `figure.media-left`
        `image`
      `.media-content` 
        `.content` formatted text...
      `.media-right` 
        `button.delete`
  - `figure` can be modified:
    - position: `.media-left` | `.media-content` | `.media-right`
  - `image` can be modified:
    - size: `is-64x64`...
### Tile
  - `.tile.is-ancestor` > `.tile.is-parent` > `.tile.is-child` (20)
  - stacking: `is-vertical`
## Input
### Forms (21)
All form controls are placed in a `.control` container
`input.input` textbox
- dropdown menu
.select
  select
    option
- textbox
textarea.textarea
`input` (22)
  - `type` attribute values: `text` | `password` hides input | `email`
### Checkboxes and radio buttons (24)
`label.checkbox`
`label.checkbox(disabled)`
`label.checkbox(checked)`
`label.radio`
  `input(type="radio", name="rsvpNormal")`
## Complex components
### Breadcrumb (38)
directory-like navigation of a large website
  - structure: 
    `nav.breadcrumb`
      `ul`
        `li.is-active`
          `a`
  - modifiers:
    - justification: `.is-right` | `.is-centered` | `.is-left`
    - size: `.is-{size mixin}`
    - divider appearance: `has-arrow-separator` | `has-bullet-separator` | `has-dot-separator` | `has-succeeds-separator`
### Card (39)
  - structure: 
    `.card` container
      `header.card-header` 
        `p.card-header-title`
        `.card-image` > `figure.image.is-4by3` > `img`
      `.card-content`
### Dropdown (40)
  - structure: 
    `.dropdown` container for the button and menu
      `.dropdown-trigger` container for button
        `button.button`
      `.dropdown-menu` menu itself, hidden by default
        `.dropdown-content` 
          `a.dropdown-item` | `a.dropdown-item` | etc.
  - `dropdown.is-active`
  - `dropdown.is-hoverable`
  - `dropdown.is-up` dropdown expands up
  - `dropdown.is-right` right-aligned dropdown
  - `dropdown-item` can be used with `a` or `div`, inserting any type of content
### Menu (41)
  - structure:
    `aside.menu` container
      `p.menu-label` label to group menu items
      `ul.menu-list` list that __appears__ to be child to `menu-label` but is actually sibling
        `li`
        `ul` child lists are unmarked
### Message (42): colorful message blocks
  - structure:
    `article.message`
      `.message-header` (optional)
        `p`
        `button.delete` "X" button
      `.message-body`
  - modifiers:
    - `article.message.is-{color}`
    - `article.message.is-{size}`
### Modal (43)
requires JavaScript implementation
  - structure:
    `.modal`
      `.modal-background` obscures the page
      `.modal-content` actual modal, centered within viewport
      `.modal-close` "X" button
### Navbars (15, 44)
  - structure:
    `nav.navbar`
      `.navbar-brand`
        `a.navbar-item`
        `button.button.navbar-burger`
      `.navbar-menu` hidden on touch devices by default
        `.navbar-start` | `.navbar-end` will appear at left|right on desktops
        `a.navbar-item.is-active`
        `a.navbar-item` , `a.navbar-item`, `a.navbar-item` ...
  - modifiers:
    - background: `nav.navbar.is-{color mixin}` | `.is-transparent`
### Pagination (45)
  - structure:
    `nav.pagination`
      `a.pagination-previous`
      `a.pagination-next`
      `ul.pagination-list`
        `li`
          `a.pagination-link.is-current` current page
          `a.pagination-link`
  - modifiers:
    - size: `.is-{size}`
### Panel (46)
container for compact controls
  - structure:
    `nav.panel` 
      `p.panel-heading` title at top
      `.panel-block` this panel block holds a small search bar and is a div
        `p.control.has-icons-left`
          `input.input.is-small`
          `span.icon.is-small.is-left`
            `i.fas.fa-search`
      `.panel-tabs` for navigation
        `a` , `a` , `a` ...
      `a.panel-block` individual item with an icon
        `span.panel-icon`
          `i.fas.fa-book`
        | text
### Tables
  - structure:
    `table.table`
      `thead` (optional)
      `tbody`
        `tr` rows
          `th` headings
          `td` cells
      `tfoot` (optional)
  - modifiers
    - `.is-bordered` borders
    - `.is-striped` alternating stripes
    - `.is-hoverable`
    - `.is-fullwidth` | `.is-narrow`
## Usage examples
### Card > Media (bulma-card-1.pug)
.card
  .card-image
    figure.image.is-4by3
      img(src='https://bulma.io/images/placeholders/1280x960.png', alt='Placeholder image')
  .card-content
    .media
      .media-left
        figure.image.is-48x48
          img(src='https://bulma.io/images/placeholders/96x96.png', alt='Placeholder image')
      .media-content
        p.title.is-4 John Smith
        p.subtitle.is-6 @johnsmith
    .content
      | Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus nec iaculis mauris.
      a @bulmaio
      | .
      a(href='#') #css
      a(href='#') #responsive
      br
      time(datetime='2016-1-1') 11:09 PM - 1 Jan 2016
### Media > Level (bulma-media-2.pug) Social media post
article.media
  figure.media-left
    p.image.is-64x64
      img(src='https://bulma.io/images/placeholders/128x128.png')
  .media-content
    .field
      p.control
        textarea.textarea(placeholder='Add a comment...')
    nav.level
      .level-left
        .level-item
          a.button.is-info Submit
      .level-right
        .level-item
          label.checkbox
            input(type='checkbox')
            |  Press enter to submit
### Media > Level (51) Resume job listing
article.media
  figure.media-left.icon.is-large.has-text-info
    img(src="resume/adrem-logo.png")
  .media-content
    h3.is-marginless Senior Quality Control Linguist
    .level
      span.level-left
        a(href="#") AdRem Systems Corporation
      small.level-right.is-uppercase.has-text-weight-bold.has-text-gray
        time(datetime="2016-07") July 2016
        | &ndash;
        time(datetime="2018-02") February 2018
#### Media > Font Awesome Icon Layering
.media
  .media-left.icon.is-medium.fa-layers.fa-fw.fa-2x
    i.fas.fa-circle.has-text-primary
    i.fas.fa-male.has-text-white(data-fa-transform="shrink-5")
  .media-content Jasper Zanjani
#### Font Awesome Icon Layering (fa-layering.pug) Bookmark with a heart on top
span.fa-layers.fa-fw(style='background:#efe5c3')
  i.fas.fa-bookmark
  i.fa-inverse.fas.fa-heart(data-fa-transform='shrink-10 up-2', style='color:Tomato')