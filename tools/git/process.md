#### Инициализация репозитория

```sh
git init
git init -bare # инициализация репозитория без рабочего каталога
```

#### Клонирование репозитория

```sh
# клонирование в текущий каталог
git clone https://github.com/libgit2/libgit2
# клонирование в указаный каталог mylibgit
git clone https://github.com/libgit2/libgit2 mylibgit
```

#### Варианты протоколов

- https://
- git://
- user@server:path/to/repo.git

#### Рабочие команды

`git chekout <file>` - to discard changes in working directory
`git restore [<file>|"./"]` - restore file or all repo
`git restore --staged <file>` - откат индексации файла
`git rm --cached <file>` - удалить файл из отслеживаемых
`git add <file> `- проиндексировать файл или добавить в отслеживаемым, а также пометить файл с конфликтом как разрешенный для слияния
`git add [-p, --patch]` - индексация указанных строк в файле
`git add [-i, --interactive]` - перевод оболочки в интерактивный режим индексации, для разделения большого коммита по выполненным операциям(модулям)
`git commit <file>` - зафиксировать файл
`git commit -a ` - commit without staged, tracked files
`git status` - состояние файлов в репозитории
`git status -s [ --short ]`
`git reset HEAD` - to unstage
`git diff` - change list
`git diff --staged` - staged changes with last commit version
`git diff --cached` - also `-- staged`
`git clean` - очистка рабочего каталога
`git clean -d -f` - очистить репозиторий от неотслеживаемых файлов
`git clean -x -i` - предыдущая команда, игнорируя файл _.gitignore_, в интерактивном режиме
`git clean -d -n` - имитация очистки и вывод результата на экран, без изменения каталога

#### git log

`git log` - просмотр истории
`git log -g master`
`git log -p -2` - выводит два последних коммита и показывает разницу внесенную каждым коммитом
`git log -p --cc` - показывает каким образом был разрешен конфликт
`git log --stat` - краткая статистика по каждой версии
`git log --pretty=oneline` - изменяет формат вывода, доступные варианты(`short`, `full`, `fuller`)
`git log --pretty=format: "%h - %an, %ar : %s"` - форматируемый вывод лога
`git log --pretty=format: "%h %s" --graph` - графическое ветвление
`git log --since=2.weeks` - вывод логов за последние две недели
`git log S<string>` - вывод лога только по опр. строке
`git log --author` - выборка по автору, для одновременного использования параметров выбоки `--all-match`
`git log --grep` - выборка по слову, для одновременного использования параметров выбоки `--all-match`
`git log --pretty="%h - %s" --author=gitster --since="2008-10-01" --before="2008-11-01" --no-merges -- t/` - пример запроса для выборки коммита Junio Hamano, не попавшие в слияние за октябрь 2008
`git log --abbrev-commit --pretty=oneline` - вывод уникльных имет коммитов
`git log branch2.HEAD` = `git log branch2..` - выводит разницу в коммитах
`git log refA..refB` = `git log ^refA refB` = `git log refB --not refA` - также выводит разницу в коммитах, позволяет строить конструкции вида `git log refA refB --not refC`
`git log refA...refB` - вывод всех отличающихся точек в коммитах
`git log --left-right refA...refB` - как и предыдущая но с принадлежностью коммитов
`git log --oneline --left-right --merge` - выведет информаци лдя разрешения конфликта
`git log --show-signature` - проверка подписи коммитов
`git log --pretty="format:%h %G? %aN %s"` - указание в выводе указать подписи
`git log -S ZLIB_BUF_MAX --oneline` - поиск выражения _ZLIB-BUF-MAX_ в истории коммитов
`git log -G ZLIB_BUF_MAX --oneline` - аналогично предыдущей команде, но _-G_ позволяет искать по регулярдному выражению
`git log -L :git_deflate_bound:zlib.c` - вывод всех изменений функции _git-deflate-bound_ в файле _zlib.c_
`git log -L '/unsigned long git_deflate_bound/',/^}/:zlib.c'` - аналогично предыдущему, но через регулярное выражение, можно использовать интервал строк или номер строки

#### git amend

Добавляет область индексации в предыдущий коммит. В итоге следующей операции останется единственный коммит - второй заменит результат первого, изменяет контрольную сумму:
`git commit --amend`

```sh
git commit -m 'изначальный коммит'
git add forgotten_file
git commit --amend
```

#### git reset

`git reset HEAD <file>` - удаляет индексацию для указанного файла
`git reset HEAD <file --hard>` - может затронуть рабочую область, без `hard` идет работа только с областью индексации

#### git stash

`git stash` - добавить модификации файлов в буфер, это очистит статус репозитория от требования индексации при переходе в другую ветку
`git stash list` - список буферов
`git stash apply` - вставить последни буфер(по умолчанию)
`git stash apply stash@{2}` - вставить второй буфер
`git stash apply --index` - вставить и значение индекса
`git stash drop stash@{0}` - удаление указанного буфера
`git stash pop` - вставка и удаление буфера
`git stash --keep-index` - не скрывать данные, прошедшие _git add_, для индексации только части изменения
`git stash [-u, --include-untracked]` - вставить буфер все файлы включая неотслеживаемые
`git stash --patch` - выбор файлов для скрытия
`git stash show - stash@{0} | git apply -R` - отменить внесенные из буфера изменения, даже после модификации
`git stash branch` - создать ветку на основе скрытого фрагмента
`git stash --all` - удаляет содержимое лишних файлов, но с последующим сохранением их в буфере

#### git reset

`git cat-file -p HEAD` - вывод списка содержимого папки ветки HEAD
`git ls-tree -r HEAD` - вывод контрольных сумм для каждого файла в снимке HEAD
`git ls-files -s` - вывод содержимого индекса
`git ls-files -u` - вывод конфликтующих файлов с их предшествующими конфликту версиями

`git reset --soft` - перемещение ветки HEAD на родительский коммит
`git reset --mixed` - (используется по умолчанию) перемещение HEAD и перезапись содержимого индекса к состоянию предка
`git reset --hard` - переход HEAD, перезапись index и возврат содержимого рабочего каталога, если следующего(текущего) индекска нет, а были только модификации, то их не вернуть
`git reset eb43bf file.txt` - откат файла до состояния из указанного коммита
`git reset file.txt --patch` - откат файлов построчно

`git reset --soft HEAD~2 && git commit` - перемещение ко второму по глубине коммиту и объединение его с текущим, без промежуточного, в ветке будет 2-a коммита вместо 3-х
