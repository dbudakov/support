Команда _git branch 'custom-name'_ узнает хеш коммита из файла _.git/HEAD_
Файл _.git/HEAD_ представляет собой символическую ссылку на вышу текущую ветку:

`cat .git/HEAD`
`ref: refs/heads/master`

По команде _git checkout test_ Git обновит файл и его вывод покажет:
`cat .git/HEAD`
`ref: refs/heads/test`

Для работы с файлом _.git/HEAD_, существует специальная команда:
`git symbolic-ref HEAD` - узнать значение указателя _HEAD_
`git symbolic-ref HEAD refs/heads/test` - задать значение _HEAD_

**Примечание:** невозможно создать ссылку за пределы папки _refs_:
`git symbolic-ref HEAD test`
`fatal: Refusing to point HEAD outside of refs/`
