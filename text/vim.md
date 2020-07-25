[https://kb.iu.edu/d/acux]: https://kb.iu.edu/d/acux "kb.iu.edu: \"Convert between Unix and Windows text files\""
[https://vim.fandom.com/wiki/Moving_lines_up_or_down]: https://vim.fandom.com/wiki/Moving_lines_up_or_down "Vim Tips Wiki: \"Moving lines up or down\""
[Oualline]: http://sci.notbc.org/~weiss/resources/vim/Vim-course/others/vim-1.0.pdf "Oualline, Steve. _The Vim Book_. 2007."
[https://youtu.be/wlR5gYd6um0]: https://youtu.be/wlR5gYd6um0 "Mastering the Vim Language"

# vim
Unlike WYSIWYG editors which optimize input for writing text, vim optimizes for editing it.
Vim offers a **composable** language for expressing these editing changes whose syntax can be composed into two elements, **operations** and **text objects**, which are analogous to **verbs** and **nouns** in language.
<sup>[YouTube][https://youtu.be/wlR5gYd6um0]</sup>

The framework of understanding vim's syntax as a language appears to date back to an influential 2011 Stack Overflow [post](https://stackoverflow.com/questions/1218390/what-is-your-most-productive-shortcut-with-vim/1220118#1220118 "What is your most productive shortcut with Vim?").
#### Settings
[relativenumber]: #settings '```&#10;:set relativenumber&#10;:set rnu&#10;```&#10;Turn on relative line numbers'
[expandtab]: #settings '```&#10;:set expandtab&#10;:set et&#10;```&#10;Turn on soft tabs'
[conceallevel]: #settings '```&#10;:set conceallevel=2&#10;:set cole=2&#10;```&#10;Determine how text with the `conceal` syntax attribute is shown'
[termguicolors]: #settings '```&#10;:set termguicolors&#10;:set tgc&#10;```&#10;Enable 24-bit color support'
[splitright]: #settings '```&#10;:set splitright&#10;:set sr&#10;```&#10;When on, splitting a window will put the new window right of the current one.'
[splitbelow]: #settings '```&#10;:set splitbelow&#10;:set sb&#10;```&#10;When on, splitting a window will put the new window below the current one.'

[vim:relativenumber]: https://vimhelp.org/options.txt.html#'relativenumber' "relativenumber documentation"
[vim:expandtab]: https://vimhelp.org/options.txt.html#'expandtab' "expandtab documentation"
[vim:conceallevel]: https://vimhelp.org/options.txt.html#'conceallevel' "conceallevel documentation"
[vim:termguicolors]: https://vimhelp.org/options.txt.html#'termguicolors' "termguicolors documentation"
[vim:splitright]: https://vimhelp.org/options.txt.html#'splitright' "splitright documentation"
[vim:splitbelow]: https://vimhelp.org/options.txt.html#'splitbelow' "splitbelow documentation"

[`conceallevel`][conceallevel]<sup>[?][vim:conceallevel]</sup>
[`expandtab`][expandtab]<sup>[?][vim:expandtab]</sup>
[`relativenumber`][relativenumber]<sup>[?][vim:relativenumber]</sup>
[`splitright`][splitright]<sup>[?][vim:splitright]</sup>
[`splitbelow`][splitbelow]<sup>[?][vim:splitbelow]</sup>
[`termguicolors`][termguicolors]<sup>[?][vim:termguicolors]</sup>

#### Key bindings
Map `<Alt-j>` and `<Alt-k>` to move lines of text up or down 
<sup>[vim.fandom.com][https://vim.fandom.com/wiki/Moving_lines_up_or_down]</sup>

```vimrc
nnoremap <A-j> :m .+1<CR>==
nnoremap <A-k> :m .-2<CR>==
inoremap <A-j> <Esc>:m .+1<CR>==gi
inoremap <A-k> <Esc>:m .-2<CR>==gi
vnoremap <A-j> :m '>+1<CR>gv=gv
vnoremap <A-k> :m '<-2<CR>gv=gv
```
#### Elements
[`Directory`](#elements "Directories in NERDTree sidebar")
[`Identifier`](# "Markdown: Bullets in ordered and unordered lists")
[`LineNr`](# "Line numbers")
[`NonText`](#elements "Characters that do not really exist in the text")
[`Normal`](#"Normal,unhighlightedtext")
[`String`](# "Code (text enclosed in backticks) in markdown")
[`Title`](# "Markdown: Headings (lines that begin with hashes)")
[`VertSplit`](#elements "Bar separating two windows")

`Comment` 
`Constant` 
`Cursor`
`Folded`
`Function`
`Keyword`
`Number`
`PreProc`
`SpecialKey`
`Special`
`Statement`
`StatusLineNC`
`StatusLine`
`Todo`
`Type`
`Visual`

#### Color
Select alternative colorschemes
```vim
:colo[rscheme] <tab>
```
Display all available colorschemes
```vim
:colo <C-d>
```
Clear custom color commands
```vim
:highlight clear
:hi clear
```
Set `ELEMENT` to `COLOR`
```vim
:hi ELEMENT ctermfg=COLOR ctermbg=COLOR
```
Hexadecimal color codes
```vim
:hi ELEMENT guifg=#abc123 guibg=#abc123
```
# vim plugins
Vim 8 supports native loading of plugins (put in `.vim/pack/xx/start/` where `xx` is an arbitrary directory name

Set file format to Unix/DOS [<sup>ref</sup>][https://kb.iu.edu/d/acux]
```vim
:set fileformat=unix
:set fileformat=dos
```
#### NERDTree

