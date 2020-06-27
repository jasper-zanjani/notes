[https://kb.iu.edu/d/acux]: https://kb.iu.edu/d/acux "kb.iu.edu: \"Convert between Unix and Windows text files\""
[https://vim.fandom.com/wiki/Moving_lines_up_or_down]: https://vim.fandom.com/wiki/Moving_lines_up_or_down "Vim Tips Wiki: \"Moving lines up or down\""
[Oualline]: # "Oualline, Steve. _The Vim Book_. 2007."
[https://youtu.be/wlR5gYd6um0]: https://youtu.be/wlR5gYd6um0 "Mastering the Vim Language"

# vim
Unlike WYSIWYG editors which optimize input for writing text, vim optimizes for editing it.
Vim offers a **composable** language for expressing these editing changes whose syntax can be composed into two elements, **operations** and **text objects**, which are analogous to **verbs** and **nouns** in language.
<sup>[YouTube][https://youtu.be/wlR5gYd6um0]</sup>

The framework of understanding vim's syntax as a language appears to date back to an influential 2011 [stackoverflow](https://stackoverflow.com/questions/1218390/what-is-your-most-productive-shortcut-with-vim/1220118#1220118 "What is your most productive shortcut with Vim?") post.

## Settings
## Plugins
Vim 8 supports native loading of plugins (put in `.vim/pack/xx/start/` where `xx` is an arbitrary directory name

Set file format to Unix/DOS [<sup>ref</sup>][https://kb.iu.edu/d/acux]
```vim
:set fileformat=unix
:set fileformat=dos
```
## Key bindings
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
- [`Identifier`](# "Markdown: Bullets in ordered and unordered lists")
- [`LineNr`](# "Line numbers")
- [`Normal`](#"Normal,unhighlightedtext")
- [`String`](# "Code (text enclosed in backticks) in markdown")
- [`Title`](# "Markdown: Headings (lines that begin with hashes)")
- `Comment` 
- `Constant` 
- `Cursor`
- `Folded`
- `Function`
- `Keyword`
- `NonText`
- `Number`
- `PreProc`
- `Special`
- `SpecialKey`
- `Statement`
- `StatusLine`
- `StatusLineNC`
- `Todo`
- `Type`
- `VertSplit`
- `Visual`

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