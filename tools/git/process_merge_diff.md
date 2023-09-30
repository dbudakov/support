Слияние указанной ветки в текущую
`git merge <branch>`

`git merge --no-commit` - отменяет автоматическую запись коммита при слиянии.
`git merge --squash` - превращает все содержимое сливаемой ветки в один коммит, не являющийся коммитом слияния и помещает его на вершину текущей ветки.
`git merge --verify-signatures non-verify` - проверка на подпись и разрешение слияния только подписанного коммита
`git merge --verify-signatures -S signed-branch` - подпись коммита слияния

#### Conflict

Игнорирование пробелов:
`git merge -Xignore-all-space <branch>` - игнорирует изменение символов пробела в любом количестве
`git merge -Xignore-space-change <branch>` - игнорирует все связанные с пробелами изменения в совокупности

Версии файла при _merge_
При слиянии в области индексирования хранятся три версии файлов: 1. общий предок, 2 - ваша версия, 3 - версия в процессе слияния, берется из _MERGE-HEAD_
`git show :1:hello.rb > hello.common.rb`
`git show :2:hello.rb > hello.ours.rb`
`git show :3:hello.rb > hello.theirs.rb`
`git ls-files -u`
`git merge-rile -p hello.ours.rb hello.common.rb hello.theirs.rb > hello.rb` - сборка слияния из файлов
`git diff --ours` - вывести к чему привело слияние
`git diff --theirs -w` - чем результат слияния отличается от содержимого ветки, в которую сливались данные
`git diff --base -w` - изменение файла относительно двух веток

`git merge <branch>`
`git checkout --conflict=diff3 <file>` - вывод конфликта в файле, с указанием базовой части
`git checkout --conflict=merge <file>` - позволяет вернуть файл в состояние конфликта
`git config --global merge.conflictstyle diff3` - сделать такой вывод по умолчанию
