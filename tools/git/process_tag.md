Всего два типа тегов - легковесные(lightweight)(указательл на коммит) и снабженные комментарием(annotated)(есть cheksum, есть контакты автора тега, дата, комментарий)
`git tag` - просмотр всех тегов
`git tag -a v1.0 -m 'my version 1.4'` - создание annotated tags
`git tag v0.1` - создание lightweight tags
`git tag v0.1 c7aa519` - создание lightweight tags для определенного коммита
`git push origin <tag_name>` - отправка тега на удаленный репозиторий
`git push origin --tags` - отправка всех тегов

### Генерация номера сборки

Вывод ближайшего тега
`git describe master`
_git tag `git describe master` master_ - проставление тега на мастер

### Присвоени тега стабильной версии с pgp-key

В случае создания тега владельцем версии:
`git tag -s v1.5 -m 'my signed 1.5 tag'`

Для подписания тега может понадобить pgp-ключ, которым можно будет проверять все подписанные автором теги
список имеющихся можно посмотреть:
`gpg --list-keys`

Выбранный ключ можно вставить в базу данных Git проетка:
`git -a --export F21C45A | git hash-object -w --stdin `

Создать тег на содержимое ключа:
`git tag -a maintainer-pgp-pub 659ef797`

Сделать ключ общедоступным:
`git show maintainer-pgp-pub | gpg --import`
