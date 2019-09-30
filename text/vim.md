# vim
## Converting between DOS and Unix formats
Syntax        | Effect
:---          | :---
`:set fileformat=unix` | set file format to unix
`:set fileformat=dos` | set file format to dos
[[1](#sources)]
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
`"` comments
#### Keymappings
Map &lt;Alt-j&gt; and &lt;Alt-k&gt; to move lines of text up or down
```vimrc
nnoremap <A-j> :m .+1<CR>==
nnoremap <A-k> :m .-2<CR>==
inoremap <A-j> <Esc>:m .+1<CR>==gi
inoremap <A-k> <Esc>:m .-2<CR>==gi
vnoremap <A-j> :m '>+1<CR>gv=gv
vnoremap <A-k> :m '<-2<CR>gv=gv
```
[[2](#sources)]
## Sources
1. "Convert between Unix and Windows text files" [kb.iu.edu](https://kb.iu.edu/d/acux)
2. "Moving lines up or down". [Vim Tips Wiki](https://vim.fandom.com/wiki/Moving_lines_up_or_down)
