#### Подготовка устойчивой версии

Создать последний снимок состояния проекта в _...tar.gz/project_
`git archive master --prefix='project/' | gzip > `git describe master`.tar.gz`
`git archive master --prefix='project/' --format=zip | gzip > `git describe master`.zip`
