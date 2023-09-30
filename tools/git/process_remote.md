`git remote` - отображение имени удаленного репозитория
`git remonte -v` - имя репозитория и его адрес
`git remote add pb https://github.com/paulbenne/ticgit` - добавление удаленного репозитория
`git fetch <remote_repo>` - скачивает отсутствующую информацию,только обновляет информацию о репозитории, но не соединяет файлы
`git fetch --all`
`git pull test2 main` - скачивает недостающие файлы
`git push origin master` - отправляет данные, если были изменения необходимо предварительно их синхронизировать
`git pull (url)` - однократное скачивание репозитория, без добавления его в _remote_

`git remote show origin` - полная информация о удаленной ветке

`git remote rename <old_name> <new_name>` - переименование
`git remote rm <name_branch>` - удаление

`git push <remote_server> <branch>` - отправка локального репозитория на удаленный сервер
`git push <remote_server> <local_branch>:<remote_branch>` - аналогично
`git push <local_branch> --delete` - удаление веток с удаленного репозитория
`git push <remote_repo> --delete <other_branch>` - удаление ветки "_other_" с удаленного репозитория
