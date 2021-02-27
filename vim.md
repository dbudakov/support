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
