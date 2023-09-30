Можно задать в config псевдонимы. в результате нужно будет вводить `git ci` вместо `git commit`

#### Псевдонимы

`git config --global alias.co checkout`
`git config --global alias.br branch`
`git config --global alias.ci commit`
`git config --global alias.st status`

#### Cоставные псевдонимы

`git config --global alias.unstage 'reset HEAD --'` - делает эквивалентным `git unstage <file_name>` и `git reset HEAD <file_name>`
`git config --global alias.last 'log -1 HEAD '` - `git last` для просмотра последнего коммита

#### Внешние команды

`git config --global alias.visual "!gitk"` - `git visual` для запуска gitk

#### Системные псевдоними

`@{u},@{upstream}` - _tracking branch_
