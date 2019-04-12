## CSS
### Browser compatibility
_User agent stylesheets_ are bundled with the browser and contain default CSS rules in the absence of an external stylesheet. Their styles may be removed using a **reset** stylesheet.
### Attribute selectors
Selectors enclosed in square brackets “[” are called attribute selectors, and define selectors by the presence of an attribute
- `a[href]` selects `anchor` tags with an `href` attribute
- `a[href="#"]` selects `anchor` tags with an `href` attribute defined as “#”
- `a[href^="http"]` all `anchors` with `href` attribute that starts with “http”
- `a[href$=".com"]` all `anchors` with `href` attribute that ends with “.com”.
- `a[href*="volusion"]` all `anchors` with `href` attribute that contains the word volusion.
### Miscellaneous properties
`overflow`  
controls how content overflows its container. Three possible values:
- `visible` by default
- `hidden` from view
- `scroll` producing a scroll bar within the container

`visibility`   
allows the **content** of elements to be hidden. The space reserved for the element will still be there.
- `visible` by default
- `hidden`

`display`  
an element to be completely removed from the rendered webpage, unlike Visibility.
- `none`
- `unset` will reset the value, for example in responsive web design

`box-sizing`
defines how width and height of elements are calculated 
- `content-box`  
	by default, width and height properties includes only content
- `border-box`  
	includes content, padding, and border

### BEM naming convention
In the BEM (“block, element, modifier”) naming convention a double hyphen "--" separates an element from its modifier while a double underscore “\_\_” separates an element from its subelement. For example:
- .person 
- .person__hand 
- .person--female 
- .person--female__hand 
- .person__hand--left 

### Pseudo classes
#### Dynamic selectors
- `:link` unvisited link
- `:visited` visited link
- `:hover` mouse hover
- `:active` when a user activates an element (between click and release of mouse button)

#### Structural selectors
- `:first-child` first child of the parent element
- `:last-child` last child
- `:nth-child(an+b)` where `a` represents every second, third element if a was 2 or 3 and `b` represents the first element to start the subset

### Media Queries
`@media only screen and (max-width: 480px) \{ ... \}`
- `@media` begins a media query
- `only screen` instructs the CSS compiler to apply the rules only to display devices (other options are `print` and `handheld`)
- `and (max-width: 480px)` called a **media feature**, CSS compiler is instructed to apply the rules to screens of less than 480 pixels
- CSS rules follow in between curly braces, which will be applied if the media query is satisfied

`@media only screen and (max-width: 480px) and (min-resolution: 300dpi) \{ ...\}`
- `and` can be used to chain multiple conditions together

`@media only screen and (min-width: 480px), (orientation: landscape) \{ ... \}`
- `comma (,)` separates criteria **either of which** may be satisfied for the rules to take effect

### Positioning
Adjusting the position of HTML elements with the following 5 properties:
1. `position` which changes the default position of an element
- `static` by default
- `relative` which places the element **relative to its default static position** by means of the 4 offset properties: `top`, `bottom`, `left`, and `right`
- `absolute` all other elements will ignore the element, and the element will be positioned to its closest parent element, and will scroll with the rest of the page
- `fixed` ignores user scrolling and places the element at a fixed location on the page (useful for navbars, for example). **max-width:100% must be specified**
2. `display` with 3 values:
-  `inline`
- `block`
- `inline-block` Some elements, such as **a**, **strong**, **em**, and **a** are inline by default, and their height and width are defined by their content. And some elements, such as **p** and **h1** are block by default. But these values can be manipulated in CSS. Inline-block combines features of both inline and block. They appear next to each other but their width and height can be manipulated, such as images.
3. `z-index` accepts integer values to control the depth of elements: a higher value will bring the element to the front
4. `float` which will move elements as far `left` or `right` as possible. **Width must be specified**.
5. `clear` specifies how elements behave when they bump into each other on the `left`, `right`, `both`, or `none` sides

### Flexbox
A new tool developed for CSS3 that simplifies the layout and positioning of some elements. the `display` property of the container must be set to : `flex` or `inline-flex`

There are then 10 properties that specify how its children can behave.
1.  `justify-content` (parent) with 5 values: `flex-start`, `flex-end`, `center` , `space-around`, `space-between`
2.  `align-items` (parent) vertical alignment, similar to vertical justification:
- `stretch` by default, child elements will stretch from top to bottom of parent, unless height is defined. `min-height` is permissible
- `flex-start`, `flex-end`, `center`, `baseline`
3.  `flex-grow` (child) allows items to grow. This property takes an integer value: higher values allow the element to grow larger. `max-width` takes precedence 0 by default
4.  `flex-shrink` (child) allows items to shrink, similar to flex-grow. `min-width` takes precedence
- 1 by default
5.  `flex-basis` (child) allows the parent to be sized 
6.  `flex` (child) allows flex-grow, flex-shrink, and flex-basis to be defined in a single line, in that order
7.  `flex-wrap` (parent) similar to text-wrapping, causing child elements to overflow to another line. 3 values: `nowrap` by default, `wrap`, `wrap-reverse`
8.  `align-content` (parent) affects the behavior of child elements while wrapping similar to align-items: `flex-start`, `flex-end`, `center`, `space-between`, `space-around`, `stretch`
9.  `flex-direction` (parent) allows flex containers to define how children are populated and which directions are assigned to the major and cross axes: `row`, `row-reverse`, `column`, `column-reverse`
10. `flex-flow` (parent) allows both flex-wrap and flex-direction properties to be declared on a single line

### Animation
Simple transitions
- `transition-property` specifies the property which is to be animated
- `transition-duration` specifies animation length, in seconds (`s`) or milliseconds (`ms`)
- `transition-delay`

Timing function
Default value is `ease`
- `ease-in` starts slow, accelerates quickly, stops abruptly
- `ease-out` begins abruptly, slows down, and ends slowly
- `ease-in-out` starts slow, gets fast, ends slow
- `linear` constant speed

`Transition` declaration combines multiple declarations for brevity
`transition: transition-property transition-duration transition-timing-function (optional: transition-delay)`

### Accessibility
Accessible Rich Internet Applications (ARIA) describe guidelines to make webpages accessible to a broad audience.
- Use semantic elements: `article`, `aside`, `details`, `figcaption`, `figure`, `footer`, `header`, `main`, `mark`, `nav`, `section`, `summary`, `time`.
- `role="complementary"` attribute and value help a screen reader to understand that the element contains information supporting other text
- `role="presentation"` suppresses a screen reader’s reading of the name of the element when unnecessary (for ordered lists, for example)
- ARIA properties such as `aria-label="..."` identify the significance of ambiguous elements 
- `alt` attributes of some elements is built in (i.e. img). It can be empty but should always be present. Limit of 150 characters.

### Bootstrap
Most popular front-end framework. CSS library used by developers to quickly build responsive websites
- `.navbar` applied to top-level `nav` element
- themes: `.navbar-default`, `.navbar-inverse` (dark), `.navbar-brand` applied to `anchor` element

Positioning: `.navbar-fixed-top`, `.navbar-fixed-bottom`, `.navbar-left`, `.navbar-right`

Jumbotron: showcase area directly beneath header, drawing attention to important site content
- `.jumbotron`, `.jumbotron-fluid`

#### Grid system
All grid content must be wrapped in a `.container` or `.container-fluid` div
- `.row` direct children of the `.container` have 12 columns
- `.col-md-\#` direct children of `.row`, spans # columns; `.col-md-4` 4 columns, `.col-md-6` 6 columns, etc
- `.col-xs-\#` applied to `img`, spans # columns

#### Responsive design
- `.col-xs-x` when viewport is less than 768px
- `.col-sm-x` 768-991px
- `.col-md-x` 992-1199px
- `.col-lg-x` greater than 1199px

#### Buttons
`.btn`

Color schemes: `.btn-primary`, `.btn-secondary`, `.btn-success`, `.btn-info`, `.btn-warning`, `.btn-danger`, `.btn-link`




### Low-Quality Image Placeholders (LQIP) in React
devtips (a-74Zy9EfMQ)


- Wrap the image in a div

```
<div className="imageWrapper">
```

- Use `padding-bottom` to define height in terms of `width`

```
padding-bottom: 150%;
```

- Create logic to replace the placeholder image with the high-quality image upon load

```
const image = {
	original: './path/original.jpg',
	optimized: './path/optimized.jpg',
	svg: './path/svg.svg'
}
```


```
componentDidMount() {
	const img
	img.src = image.original
	img.onload = function() {

		// Query the DOM
		document
			.querySelector('imageWrapper')
			.style['background-image']
			= `url('${img.src}')`
	}
}
```

- Ensure proper scaling

```
background-size: 100%;
```