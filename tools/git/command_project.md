Список ссылок и тегов репозитория, _refs/heads/master_ - ветки, _refs/pull/1/head_ - запросы, _refs/pull/1/merge_ - будущий коммит в результате слияния
`git ls-remote origin`

Извлечь и слить данные из *ссылки* в репозитории(в файл *.git/FETCH-HEAD* ):
`git fetch origin refs/pull/958/head`
`git merge FETCH_HEAD`

Чтобы добавить извлечение ссылок в стандартую процедуру _fetch_ необходими в описание ветки в файле _.git/config_ добавить следующую строку для ветки
`fetch = +refs/pull/*/head:refs/remotes/origin/pr/*`

После слияния можно перейти в запрос на включения и протестировать код:
`git checkout pr/2`
