[https://kb.iu.edu/d/acux]: https://kb.iu.edu/d/acux "kb.iu.edu: \"Convert between Unix and Windows text files\""
[https://vim.fandom.com/wiki/Moving_lines_up_or_down]: https://vim.fandom.com/wiki/Moving_lines_up_or_down "Vim Tips Wiki: \"Moving lines up or down\""
[Oualline]: http://sci.notbc.org/~weiss/resources/vim/Vim-course/others/vim-1.0.pdf "Oualline, Steve. _The Vim Book_. 2007."
[https://youtu.be/wlR5gYd6um0]: https://youtu.be/wlR5gYd6um0 "Mastering the Vim Language"

# vim

<!-- 

It would be nice to develop a course about various vim configs and language definitions.
Maybe I could extend the markdown language plugin to incorporate mkdocs and pymdownx syntax.

-->


Unlike WYSIWYG editors which optimize input for writing text, vim optimizes for editing it.
Vim offers a **composable** language for expressing these editing changes whose syntax can be composed into two elements, **operations** and **text objects**, which are analogous to **verbs** and **nouns** in language.
<sup>[YouTube][https://youtu.be/wlR5gYd6um0]</sup>

The framework of understanding vim's syntax as a language appears to date back to an influential 2011 Stack Overflow [post](https://stackoverflow.com/questions/1218390/what-is-your-most-productive-shortcut-with-vim/1220118#1220118 "What is your most productive shortcut with Vim?").

On Unix-derived operating systems the main config file for Vim is placed at **$HOME/.vimrc**.
On Windows it is placed at **$HOME/\_vimrc**.

## Syntax

#### normal
:   
    Use **`:normal`** to define a series of normal-mode commands
    
    ```vim title="Select all lines of a buffer"
    :normal ggVG
    ```

#### Keybindings

There are two kinds of keybindings in Vim

- **Recursive** using command words `map`, `nmap`, `vmap`, etc. In these keybindings, the mapping itself is interpreted.
- **Nonrecursive** 

There are two types of keycodes:

- [**Vim keycodes**](https://vim.fandom.com/wiki/Mapping_fast_keycodes_in_terminal_Vim) which are identifiable as being in angle brackets: `<Space>`, `<Return>`, etc
- [**Terminal keycodes**](https://wiki.archlinux.org/index.php/Keyboard_input#Identifying_keycodes_in_Xorg) that appear similar to `^[[1;2A`. These may or may not be identifiable with the **keycodes** which the Linux kernel maps to raw keyboard **scancodes**. <sup>[ref][archwiki:Keyboard_input]</sup>

The **leader** key is used to create more complicated keybindings using any arbitrary keypress, for example using `,` or `<Space>`.

```vim
let mapleader = ' '
```


#### Autocommands
:   
Autocommands expose an API that allows handling editor events like `BufNewFile`, `BufReadPost`, `BufWritePost`, `BufWinLeave`, and especially to implement functionality specific to filetypes.


Highlight added lines in green and removed lines in red in .diff files [<sup>:material-play:</sup>](https://youtu.be/aHm36-na4-4?t=690 "Damian Conway, \"More Instantly Better Vim\" - OSCON 2013")
```vimscript
filetype on

augroup PatchDiffHighlight
  autocmd!
  autocmd FileType diff syntax enable
augroup END
```

Turn syntax highlighting on only for certain filetypes [<sup>:material-play:</sup>](https://youtu.be/aHm36-na4-4?t=690 "Damian Conway, \"More Instantly Better Vim\" - OSCON 2013")
```vimscript
augroup PatchDiffHighlight
  autocmd!
  autocmd BufEnter *.patch,*.rej,*.diff syntax enable
augroup END
```

#### Color

```vimscript
; Change the color of ELEMENT
highlight ELEMENT ctermfg=COLOR ctermbg=COLOR guifg=#abc123 guibg=#abc123

; Select alternative colorschemes
:colo[rscheme] <tab>

; Display all available colorschemes
:colo <C-d>
```

Clear custom color commands
```vim
:highlight clear
:hi clear
```
[Set file format to Unix/DOS][https://kb.iu.edu/d/acux]
```vim
:set fileformat=unix
:set fileformat=dos
```


#### Completion

- [Context-aware completion](https://youtu.be/3TX3kV3TICU?t=1005)
- [++ctrl+x++ ++ctrl+l++](https://youtu.be/3TX3kV3TICU?t=1260)
- [Omni completion ++ctrl+x++ ++ctrl+o++](https://youtu.be/3TX3kV3TICU?t=1350)

## Tasks

#### Invoking to a specific line number
:   
    ```sh
    # Open with cursor at line 13
    vim .bashrc +13
    ```

#### Configuration
:   
    ```vimscript title="Configuration"
    " Prevent vim from creating backups files
    set nobackup

    " Set relative line numbers
    set rnu
    ```

#### [Search and replace](https://vim.fandom.com/wiki/Search_and_replace)
:   

    ```vimscript
    " Replace foo with bar across all lines, wherever they occur
    %s/foo/bar/g
    ```

#### Mapping keys
:   
    Map ++alt+j++ and ++alt+k++ to move lines of text up or down
    ```vimrc
    nnoremap <A-j> :m .+1<CR>==
    nnoremap <A-k> :m .-2<CR>==
    inoremap <A-j> <Esc>:m .+1<CR>==gi
    inoremap <A-k> <Esc>:m .-2<CR>==gi
    vnoremap <A-j> :m '>+1<CR>gv=gv
    vnoremap <A-k> :m '<-2<CR>gv=gv
    ```


#### Yanking STDOUT 
:   
    To run a shell command from the normal mode command line, you simply run the `!` (["bang"](https://learnvimscriptthehardway.stevelosh.com/chapters/52.html)) command in normal mode.
    ```vim
    :!env
    ```

    However to [store the output of that command into a register](https://stackoverflow.com/questions/1694392/vim-store-output-of-external-command-into-a-register), you must run a command like the following, which stores the output of the shell command into the **a** register.
    ```vim
    :let @a = system('env')
    ```
    The register signified by **`@"`** will be placed into the buffer by the **put** command (**`p`**).
    ```vim
    :let @" = system('env')
    ```

    Alternatively
    ```vim
    :put =system('env')
    ```

#### Filetype-associated settings
:   
    ```vimscript title="Set indentation behavior specific to YAML"
    autocmd FileType yaml setlocal ai ts=2 sw=2 et
    ```
    
#### Plugins
:   
    Vim 8 supports native loading of plugins (put in **$HOME/.vim/pack/start/**

    [vim-plug](https://github.com/junegunn/vim-plug) is a popular plugin manager.


    Install a plugin to provide [Rust language support](https://github.com/rust-lang/rust.vim)
    ```vimscript
    Plug 'rust-lang/rust.vim'
    ```

#### Mouse support
:   
    From [here](https://vimtricks.com/)
    ```vim
    set mouse=a
    ```

#### Language definition
:   
    Syntax highlighting for various languages are stored in **syntax files**, stored in **/usr/share/vim/vim82/syntax**.

    Defining highlighting for pymdownx [snippets](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/?h=snippet#snippets)

    ```vim
    syn match markdownPymdownxSnippet '^-\{2,}8<-\{2,} .*' " (1)
    hi def link markdownPymdownxSnippet Error
    ```

    1. Note that the quantifier specifying at least two instances of the preceding hyphen requires the initial brace to be escaped.
    However, the open angle bracket does not.
