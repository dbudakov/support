## Централизованная работа

Начало работы c проектом:
`git clone`
`git commit`
`git push`

Если после коммита выдается сообщение что ветка изменена, то необходимо скачать все изменения и выполнить слияние с origin/master своей master(local)
`git push`
`git fetch origin`
`git merge origin/master`
`git push origin master`

Отфильтровать коммиты удаленной ветке не входящие в локальную ветку:
Фильтр для команды `git log` для отображения только тех коммитов из `origin/master`, которых нет в `issue54`
`git log --no-merges issue54..origin/master`

## Оператор интеграции

Для обновления информации о репозитории
`git fetch`

Для слияния определенной ветки в случае ее измения
`git checkout featureB`
`git merge origin/featureBee`

Посмотреть что именно изменилось:
`git log featureA..origin/featureA`

Привязать локальную ветку к уленной:
`git push -u origin featureA` - _`-u/--set-upstream`_ облегчает дальнейгую отправку данных на сервер и скачивание из оттуда
`git push -u origin featureB:featureBee`

## Открытый проект, ветвления

Склонируй репозиторий проекта:
`git clone (origin/master_url)`

Выполни _fork_ репозитория:
`(выполнение fork для repo)`

Создай удаленный репозиторий для _fork'a_
`git remote add myfork (my_fork_url)`

Синхонизацию выполняй с _master'ом_ репозитория команды:
`git fetch origin/master`

Отправляй коммиты в fork:
`git commit -u myfork featureA`

После чего запрашивай разрешение на слияние:
`git request-pull origin/master myfork` - вывод этой команды можешь отправить на слияние

## Открытый проект, электронная почта

Представление коммитов в формате электронного письма
`git format -patch -M origin/master` -- параметр _-M_ заставляет git следить за перемиенованиями файлов

Следующий текст исчезнет при добавление в _origin/master_:

```
---
(...)
diff --git
```

Настройка отправки через почту:

```conf
[imap]
  folder = "[Gmail]/Drafts"
  host = imaps://imap.gmail.com
  user = user@gmail.com
  pass = P@ssw0rd
  port = 993
  sslverify = false
```

Создания письма в черновиках
`git send-email *.patch`

### shortlog

Краткое описание изменений репозитория для отправки по почте начиная с версии v1.0.1
`git shortlog --no-merges master --not v1.0.1`
