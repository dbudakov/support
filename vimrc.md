# vim

```conf
".vimrc

" на 80 колонке будет выделять ячейку другим цветом
set colorcolumn=80  

"Цветовая схема
colorscheme pablo
"colorscheme ron
"colorscheme torte                                                               

"Нумерация строк
set nu           

"Определять блоки на основе отступов
set foldmethod=indent                

"Подсвечивание результатов поиска
set incsearch                     

"Отключение результатов поиска(после того как поиск закрыт)
set nohlsearch                                              

"Используется для регулирования ширины отступов в пробелах добавляемых командами >> и <<, отступ может состоять как из символов табуляции так и пробелов, При включении опции - smarttab, оказывает дополнительное влияние
set shiftwidth=4                                                                 

"Количество пробелов, которыми символ символ табуляции отображается при добавлении
set softtabstop=4                                                               

"Количество пробелов которыми символ табуляции отображается в тексте. 
set tabstop=4                                                          

"Копирует отступы с тeкущей строки при добавлении новой
set autoindent                                          

"Делает то же что и autoindent плюс автоматически выставляет отступы в _нужных_ местах. 
set smartindent                                                                 

"Подсветка синтаксиса
syntax on 
```

## colorscheme  

```
:colorscheme ron
:colorscheme pablo

:colorscheme desert
:colorscheme slate
:colorscheme delek
```
## select range
```
command! -range Vis call setpos('.', [0,<line1>,0,0]) |
                    \ exe "normal V" |
                    \ call setpos('.', [0,<line2>,0,0])
```                    

## comments
```vi
" Commenting blocks of code, `,cc` - comment, `,cu` - uncomment
augroup commenting_blocks_of_code
  autocmd!
  autocmd FileType c,cpp,java,scala let b:comment_leader = '// '
  autocmd FileType sh,ruby,python   let b:comment_leader = '# '
  autocmd FileType conf,fstab       let b:comment_leader = '# '
  autocmd FileType tex              let b:comment_leader = '% '
  autocmd FileType mail             let b:comment_leader = '> '
  autocmd FileType vim              let b:comment_leader = '" '
augroup END
noremap <silent> ,cc :<C-B>silent <C-E>s/^/<C-R>=escape(b:comment_leader,'\/')<CR>/<CR>:nohlsearch<CR>
noremap <silent> ,cu :<C-B>silent <C-E>s/^\V<C-R>=escape(b:comment_leader,'\/')<CR>//e<CR>:nohlsearch<CR>
```

## again comments
```
let s:comment_map = { 
    \   "c": '\/\/',
    \   "cpp": '\/\/',
    \   "go": '\/\/',
    \   "java": '\/\/',
    \   "javascript": '\/\/',
    \   "lua": '--',
    \   "scala": '\/\/',
    \   "php": '\/\/',
    \   "python": '#',
    \   "ruby": '#',
    \   "rust": '\/\/',
    \   "sh": '#',
    \   "desktop": '#',
    \   "fstab": '#',
    \   "conf": '#',
    \   "profile": '#',
    \   "bashrc": '#',
    \   "bash_profile": '#',
    \   "mail": '>',
    \   "eml": '>',
    \   "bat": 'REM',
    \   "ahk": ';',
    \   "vim": '"',
    \   "tex": '%',
    \ }

function! ToggleComment()
    if has_key(s:comment_map, &filetype)
        let comment_leader = s:comment_map[&filetype]
        if getline('.') =~ "^\\s*" . comment_leader . " " 
            " Uncomment the line
            execute "silent s/^\\(\\s*\\)" . comment_leader . " /\\1/"
        else 
            if getline('.') =~ "^\\s*" . comment_leader
                " Uncomment the line
                execute "silent s/^\\(\\s*\\)" . comment_leader . "/\\1/"
            else
                " Comment the line
                execute "silent s/^\\(\\s*\\)/\\1" . comment_leader . " /"
            end
        end
    else
        echo "No comment leader found for filetype"
    end
endfunction


nnoremap <leader><Space> :call ToggleComment()<cr>
vnoremap <leader><Space> :call ToggleComment()<cr>
```
