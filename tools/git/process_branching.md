При фиксации очередного сострояния Git сохнраняет объект-коммит, содержфщий укаатель на снимок индексированного содержимого.
Репозиторий как массив двоичных данныхgit

`blob` - один массив двоичных данных для трех файлов(blob: _5b13d_ _911e7_ _cba0a_)
`tree` - одно дерево, отображающее содержимое папки\* и указывающее, какие имена файлов сохранены как массивы двоичных данных(_91ec2_)
`commit` - один коммит с указателем на корень дерева и все свои метаданные(_98ca9_)

### list

`git branch` - список веток
`git branch -v` - последний коммит для каждой ветки
`git branch -vv` - информация об актульности веток, необходимо предварительно выполнить `git fetch --all`
`git branch --<merged:no-merges>` - вывести список веток, слитых с текущей

`git branch <branch_name>` - создание новой ветки для текущего коммита
`git branch <branch_name> <commit_cache>` - создание ветки для предыдущего коммита
`git chekout <branch_name>` - переместиться в указанную ветку
`git checkout -b <branch_name>` - создать ветку и сразу перейти в нее
`git checkout -b <branch_name> <remote_branch>` - создание ветки с указателем на удаленную
`git branch -D <branch_name>` - удаление(delete/remove) локальной ветки
`git push origin --delete <remote_branch>` - удаление удаленной ветки

`git branch -m <new_name>` - переименовать(rename) ветку  

`git log --oneline --decorate` - показывает действующую ветку(параметр "HEADgit")
`git log --oneline --decorate --graph -all` - показать разветвления всего репозитория в _graph_

`git merg <branch>` - слияние ветки в текущую

_Fast-forward_ - перемотка при слиянии

#### конфликт

`git merge <branch_name>`
`git status` - вывод информации о конфликте слияния

#### best practice

При создании доп веток используют: `master`, `develop`, `next`, `porposed/pu`(proposed updates)

`topic branch` - тематическая ветка

#### tracking branch

Ветка наблюдения
`git checkout -b <new_local_branch> <remote_branch> --track` - создание ветки наблюдения для альтернативных(не master) веток
`git branch [-u/--set-upstream-to] origin/serverfix` - задание отслеживаемой ветки

#### remote branch

remote branch - представляют собой ссылки на состояния веток в удаленных репозиториях

`git fetch <remote_repo>` - синхронизация с удаленным репозиториемма

#### filter-branch

Удалить файл _password.txt_ из всех коммитов, добавленый по ошибке:
`git filter-branch --tree-filter 'rm -f passwords.txt' HEAD` - перемещает _HEAD_ к каждой ветке и удаляет файл
`git filter-branch --tree-filter --all 'rm -f passwords.txt' HEAD` - работа со всеми ветками

Переназначить корневую ветку на ветку с именем _trunk_:
`git filter-branch --subdirectory-filter trunk HEAD`

Изменить электронную почту автора во всей истории, где она фигурирует:

```sh
git filter-branch --commit-filter '
  if [ "$GIT_AUTHOR_EMAIL" = "shacon@localhost" ];
  then
        GIT_AUTHOR_NAME="Scott Chacon";
        GIT_AUTHOR_EMAIL="schacon@example.com";
        git commit-tree "$@";
  else
        git commit-tree "$@";
  fi' HEAD
```
