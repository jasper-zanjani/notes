# vim
## Converting between DOS and Unix formats
Syntax        | Effect
:---          | :---
`:set fileformat=unix` | set file format to unix
`:set fileformat=dos` | set file format to dos
[[1](#sources)]
## Motion keys
Key sequence  | Effect
:---          | :---
`aw`          | word and the space after it
`iw`          | word
`iW`          | sequence of non-whitespace characters
`aW`          | sequence of non-whitespace characters and the space after it
`is`          | sentence
`as`          | sentence and spaces after it
`ip`          | paragraph
`ap`          | paragraph and the following space
`i(`          | phrase enclosed in parentheses
`a(`          | phrase enclosed in parentheses, including parentheses
`i&lt;`       | phrase enclosed in angle brackets
`a&lt;`       | phrase enclosed in angle brackets, including enclosing angle brackets
`i[`          | phrase enclosed in square brackets
`a[`          | phrase enclosed in square brackets, including enclosing brackets
`i{`          | phrase enclosed in braces
`a{`          | phrase enclosed in braces, including enclosing braces
`i"`          | phrase enclosed in double quotes
`a"`          | phrase enclosed in double quotes, including enclosing quotes
`i'`          | phrase enclosed in single quotes
`a'`          | phrase enclosed in single quotes, including enclosing quotes
`i&#96;`      | phrase enclosed in backticks
`a&#96;`      | phrase enclosed in backticks, including enclosing backticks

## Color
Syntax        | Effect
:---          | :---
`$HOME/.vim/colors` | directory where custom colorschemes can be placed. There are "light", "dark", and unmodified versions of colors red, green, yellow, blue, magenta, cyan, as well as white and black

Syntax        | Effect
:---          | :---
`:colo[rscheme] <tab>` | select alternative colorschemes
`:colo <C-d>` | display all available colorschemes
`:hi clear` | clear custom color commands
`:hi[ghlight] ELEMENT ctermfg=COLOR ctermbg=COLOR` | set {ELEMENT} to {COLOR}
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
3. _The Vim Book_. Oualline, Steve. 2007.
