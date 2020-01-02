# vim
Vim 8 supports native loading of plugins (put in `.vim/pack/xx/start/` where `xx` is an arbitrary directory name

Set file format to Unix/DOS [^][1]
```vim
:set fileformat=unix
:set fileformat=dos
```
#### .vimrc
Map `<Alt-j>` and `<Alt-k>` to move lines of text up or down [^][2]
```vimrc
nnoremap <A-j> :m .+1<CR>==
nnoremap <A-k> :m .-2<CR>==
inoremap <A-j> <Esc>:m .+1<CR>==gi
inoremap <A-k> <Esc>:m .-2<CR>==gi
vnoremap <A-j> :m '>+1<CR>gv=gv
vnoremap <A-k> :m '<-2<CR>gv=gv
```

#### Color
\#  | Vim elements
--- | ---
C   | `Comment` `Constant` `Cursor`
F   | `Folded` `Function` 
I   | [`Identifier`](# "Markdown: Bullets in ordered and unordered lists")
K   | `Keyword`
L   | [`LineNr`](# "Line numbers")
N   | `NonText`  [`Normal`](# "Normal, unhighlighted text") `Number` 
P   | `PreProc`
S   | `Special` `SpecialKey` `Statement` `StatusLine` `StatusLineNC` [`String`](# "Code (text enclosed in backticks) in markdown")
T   | [`Title`](# "Markdown: Headings (lines that begin with hashes)") `Todo` `Type`
V   | `VertSplit` `Visual`

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

---

[1]: https://kb.iu.edu/d/acux "kb.iu.edu: \"Convert between Unix and Windows text files\""
[2]: https://vim.fandom.com/wiki/Moving_lines_up_or_down "Vim Tips Wiki: \"Moving lines up or down\""
[3]: # "Oualline, Steve. _The Vim Book_. 2007."
