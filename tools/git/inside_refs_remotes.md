При клонировании или отправки данных на репозитозиторий, Git записывает хеш последнего состояния удаленного репозитория в файл _.git/refs/remotes/*_
например:
`cat .git/refs/remotes/origin/master`
_ca82a6dff817ec66f44342007202690a93763949_

Этот хеш является последним состоянием удаленной ветки, и доступен только для чтения, как закладка, не получится переместить на нее _HEAD_ указатель, и создать в ней _commit_

Для работы с удаленными ветками а именно для синхронизации и отправки используются следующие инструменты:

#### Извлечение через ссылки:
Общий вид для ссылок: `<источник>:<цель>`, где `<источник>` шиблон для ссылок на сервере, a `<цель>` - место, куда эти ссылки будут записываться локально, `+`(опционально) заставляет Git обновлять ссылки, даже если речь идет не о перемотке.

Выполнение команды:
`git remote add origin https://github.com/schacon/simplegit-progit`

Создает запись в файле _.git/config_, следующего вида:

```conf
[remote origin]
  url = https://github.com/schacon/simplegit-progit
  fetch = +refs/heads/*:refs/remotes/origin/*
```

Можно добавить в описание удаленного репозитория и отдельные ветки например _master_,_experement_
  _fetch = +refs/heads/master:refs/remotes/origin/mymaster_
  _fetch = +refs/heads/exprtiment:refs/remotes/origin/experement_

Запись следующего вида некорректна, так как не поддерживаются общие маски:
  _fetch = +refs/heads/qa*:refs/remotes/origin/qa*_
только:
  _fetch = +refs/heads/qa/*:refs/remotes/origin/qa/*_

#### Отправка через ссылки

Для выполнение _push_ с применением ссылок, нужно привести описание ветки к следующему виду:

```conf
[remote origin]
  url = https://github.com/schacon/simplegit-progit
  fetch = +refs/heads/*:refs/remotes/origin/*
  push = refs/heads/master:refs/heads/qa/master
```

В результате по команде `git push origin`, по умолчанию отправляться локальная ветка `master` в ветку `qa/master` на  удаленном сервере

#### Ликвидация ссылок

Для очистки ветки на удаленном сервере, delete remote branch:
`git push origin :topic`

Так как формат имеет вид `<источник>:<цель>`, опуская _источник_, команда интерпретируется как приведение тематичесткой ветки на удаленном сервере, к пустому состоянию
