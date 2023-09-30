### Удаление файла из всех коммитов
Проверьте размер текущей ветки:
`git count-objects -v`

Сортируем файлы по размеру
`git verify-pack -v .git/objects/pack/pack-29...69.idx |sort -k 3 -n |tail -3`

Находим имя файла по контрольной сумме
`git rev-list --objects --all|grep 82c99a3`
_82c99...af1 git.tgz_

Вывод коммитов которые модифицировали указанный файл
`git log --oneline -- git.tgz`
_dadf725 oops - remover large tarball_
_7b39847 add git tarball_

Для полного исключения файла необходимо удалить файл из всех коммитов начиная с первого:
`git filter-branch --index-fileter 'git rm --cached --ignore-unmatch git.tgz' -- 7b30847^..`

Далее выполните очистку ссылок на старые комиты, удалением текущих ссылок, и созданием новых
`rm -Rf .git/refs/original`
`rm -Rf .git/logs/`
`git gc`

Для удаление объекта из текущего каталога:
`git prune --expire now`
