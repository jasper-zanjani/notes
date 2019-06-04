# vim

## Converting between DOS and Unix formats


Syntax        | Effect
:---          | :---
`:set fileformat=unix` | set file format to unix
`:set fileformat=dos` | set file format to dos

## Color

Syntax        | Effect
:---          | :---
`$HOME/.vim/colors` | directory where custom colorschemes can be placed. There are "light", "dark", and unmodified versions of colors red, green, yellow, blue, magenta, cyan, as well as white and black

Syntax        | Effect
:---          | :---
`:colo[rscheme] <tab>` | select alternative colorschemes
`:colo <C-d>` | display all available colorschemes
`:hi clear` | clear custom color commands
`:hi[ghlight] Element ctermfg=color ctermbg=color` | set {Element} to {color}
`:hi[ghlight] Element guifg=#abc123 guibg=#abc123` | hexadecimal color codes

Elements | Effect
:---     | :---
`LineNr` | line numbers
`Normal` | normal, unhighlighted text
`Title`  | headings in markdown
`String` | code (text between backticks) in markdown
`Identifier` | bullets for ordered and unordered lists in markdown
`NonText` | 
`Cursor` | 
`StatusLine` | 
`StatusLineNC` | 
`VertSplit` | 
`Folded` | 
`Visual` | 
`SpecialKey` | 
`Comment` | 
`Todo` | 
`Constant` | 
`Function` | 
`Type` | 
`Statement` | 
`Keyword` | 
`PreProc` | 
`Number` | 
`Special` | 


## Plugins
Vim 8 supports native loading of plugins (put in `.vim/pack/xx/start/` where `xx` is an arbitrary directory name

## .vimrc
`.vimrc` configuration file (`/home/user/.vimrc`)
`"` comments

## Vim-like shortcuts in Firefox

Shortcut  | Effect
:---      | :---
`o` | open URL
`h` `j` `k` `l` | scroll left, down, up, right
`gg` `G` | top and bottom of page
`f` | trigger hint mode for clickable elements
`r` `R` | reload, hard reload
`H` `L` | go back, forward in history
`t` `x` `X` | open, close, restore tab
`?` | show help

### VimFx, Vimium

Shortcut  | Effect
:---      | :---
`yy` | copy URL
`yy` | copy URL
`/` | search
`n` `N` | next, previous match
`J` `K` | switch between tabs
`space` `shift+space` | page up, down
`?` | see all shortcuts
`i` | "ignore" mode

### Vimium

Shortcut  | Effect
:---      | :---
`f` `F` | open link in current tab, new tab, 
`i` | insert mode
`alt+m` | mute tab

### Vim Vixen

Shortcut  | Effect
:---      | :---
`:` | open console
`o` `t` `w` | open page in current tab, new tab, new window
`O` `T` `W`
`a` | bookmark page
`zi` `zo` `zz` | zoom in, out, neutral
`[[` `]]` | find previous, next link and open it
`y` | copy URL of current tab

### Tridactyl

Shortcut  | Effect
:---      | :---
`:` | activate command line
`ctrl+g` `ctrl+G` | next, previous result 

## Sources
  - "Convert between Unix and Windows text files" [kb.iu.edu](https://kb.iu.edu/d/acux)
