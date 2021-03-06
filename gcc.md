

### Дополнительно:
gcc.gnu.org [offical site](http://gcc.gnu.org/)  
о пакете: [linux.yaroslavl.ru](http://linux.yaroslavl.ru/docs/book/lfsbook/appendixa/gcc.html)  


# AR
```
                                   AR
Программа ar создает, модифицирует и извлекает из архивов.
     Архив - это отдельный файл, содержащий коллекцию других файлов в
     структуре, которая позволяет восстановить первоначальный человек
     файлы (называются членами архива).
   
     Использование: ar [параметры эмуляции] [-]{dmpqrstx}[abcDfilMNoPsSTuvV]
                 [--plugin <имя>] [имя_члена] [счётчик] файл_архива файл…
                 ar -M [<mri-скрипт]
      команды:
     d            - удаление файлов из архива
     m[ab]        - перемещение файлов в архив
     p            - вывод файлов, найденных в архиве
     q[f]         - быстрое добавление файлов в архив
     r[ab][f][u]  - замена существующих или вставка новых файлов в архив
     s          -   действовать как ranlib
     t            - отображение содержимого архива
     x[o]         - извлечение файлов из архива
     особые модификаторы для команд:
     [a]          - размещение файлов после [имени_члена]
     [b]          - размещение файлов до [имени_члена] (то же, что и [i])
     [D]          - use zero for timestamps and uids/gids (default)
     [U]          - use actual timestamps and uids/gids
     [N]          - использование [счета], как варианта имени
     [f]          - обрезание имен вставленных файлов
     [P]          - использование полных путевых имен при сопоставлении
     [o]          - сохранение исходных дат
     [u]          - замена только файлов более новых, чем текущее содержимое архива
     обычные модификаторы:
     [c]          - не предупреждать, если должна быть создана библиотека
     [s]          - создание индекса архива (cf. ranlib)
     [S]          - не создавать таблицу символов
     [T]          - создание полупустого архива
     [v]          - подробный режим
     [V]          - вывод номера версии
     @<файл>      - читать параметры из <файла>
     --target=BFDNAME - назначить форматом объекта назначения BFDNAME
     необязательные:
     --plugin <p> - загрузить указанный модуль
     параметры эмуляции: 
     Нет параметров эмуляции
     ar: поддерживаемые цели: elf64-x86-64 elf32-i386 elf32-iamcu elf32-x86-64 a.out-i386-linux
     pei-i386 pei-x86-64 elf64-l1om elf64-k1om elf64-little elf64-big elf32-little elf32-big
     pe-x86-64 pe-bigobj-x86-64 pe-i386 plugin srec symbolsrec verilog tekhex binary ihex
```

# RANLIB
```
                                  RANLIB
Программа ranlib генерирует индекс содержимого архива для увеличения скорости доступа к нему и
сохраняет его в архиве.
     В индексе перечислены все символы, определенные участником архива, 
     который является перемещаемым файлом объекта.
     Вы можете использовать nm -s или nm --print-armap для отображения 
     этого индекса.
     Архив с таким индексом ускоряет соединение с библиотекой и позволяет
     подпрограммам в библиотеке вызывать друг друга независимо от их 
     размещения в архиве.
     Программа ranlib - это еще одна форма ar; запуск ranlib полностью
     эквивалентен выполнению ar -s.
   
     Использование: ranlib [параметры] архив
     Параметры:
     @<файл>                   читать параметры из <файла>
     --plugin <название>        загрузить указанный модуль
     -D                           Use zero for symbol map timestamp (default)
     -U                           Use an actual symbol map timestamp
     -t                         обновить временные отметки карты символов архива
     -h --help                  показать это справочное сообщение
     -V --version               показать информацию о версии
     ranlib: поддерживаемые цели: elf64-x86-64 elf32-i386 elf32-iamcu elf32-x86-64 a.out-i386-linux
     pei-i386 pei-x86-64 elf64-l1om elf64-k1om elf64-little elf64-big elf32-little elf32-big
     pe-x86-64 pe-bigobj-x86-64 pe-i386 plugin srec symbolsrec verilog tekhex binary ihex
```
