Для того чтобы не обращаться к комиту по хешу, нужно создать ссылку на коммит(по хешу),
Ссылки хранятся в каталоге _.git/refs/_

Для работы с сылками используются команды:
`git update-ref refs/heads/master <hash>`
`git update-ref refs/heads/test cac0ca`

Принцп действия такой:
`echo 6ed2a44e60064ce7816b8def596a7151b85f638e > .git/refs/heads/master`

Далее можно обращаться к комиту через _master_
`git cat-file -p master`

Операция _update-ref_ является мета командой для _git brach 'branch-name'_ когда хеш последнего коммита записывается в указанную ссылку
