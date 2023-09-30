### Global
*GIT_EXEC_PATH* - указывает где находятся программы(git-commit,git diff a.t.c), вывод по команде `git --exec-path`
*HOME* - используется для поиска глобального файла конфигураций
*PREFIX* - интерпретируется в _$PREFIX/etc/gitconfig_
*GIT_XONFIG_NOSYSTEM* - отключает использование общесистемного конфигурационного файла, в случает отсутствия доступа к файлу для редактирования
*GIT_PAGER/PAGER* - управляет программой, выполняемой многостаничный вывод в оболчке
*GIT_EDITOR/EDITOR* - задает редактор

### Repository
*GIT_DIR* - указывает местоположение папки *.git*
*GIT_CEILING_DIRECTORIES* - управляет поиском *.git*
*GIT_WORK_TREE* - указывает местоположение корневой рабочей папки, в случае обысного а не голого репозитория
*GIT_INDEX_FILE* - содержит путь к индексномуфайлу
*GIT_OBJECT_DIRECTORY* - позволяет задать *.git/objects*
*GIT_ALTERNATE_OBJECT_DIRECTORIES* - список альтернатив для каталога *.git/objects*, имеет вид */dir/one:/dir/two:dir/...*

### Access way
*GIT_GLOB_PATHSPECS/GIT_COGLOB_PATHSPECS* - управляют поведением групповых символов в путях доступа(трактовка символа *)
*GIT_LITERAL_PATHSPECS* - отключает оба вышеприведенных варианта поведения, отключат как групповые, так и специальные префиксы
*GIT_ICASE_PATHSPECS* - делает пути независимыми от региста символов

### Фиксация изменений
*GIT_AUTHOR_NAME* - имя в поле *author*
*GIT_AUTHOR_EMAIL* - почта в поле *author*
*GIT_AUTHOR_DATE* - временная метка для поля *author*
*GIT_COMMITTER_NAME* - задает имя для поля *commiter*
*GIT_COMMITTER_EMAIL* - задает почту для поля *commiter*
*GIT_COMMITTER_DATE* - задает временную метку для поля *commiter*

### Работа в сети
используется библиотека _curl_
*GIT_CURL_VERBOSE* - вывод подробной информации(curl -v)
*GIT_SSL_NO_VERIFY* - отключает проверку ssl-сертификатов
*GIT_HTTP_LOW_SPEED_LIMIT* - нижиний порог соединения (_http.lowSpeedLimit_)
*GIT_HTTP_LOW_SPEED_TIME* - нижний порог времени низкой скорости соединения(_http.lowSpeedTime_)
*GIT_HTTP_USER_AGENT* - задает строку _user-agent_

### Определение изменений и слияние
*GIT_DIFF_OPTS* - кол-во строк в выводе `git diff`; `-u<n>` и `--unified=<n>`
*GIT_EXTERNAL_DIFF* - замещение конфигурационного _diff.external_, вызываемая программа на запрос `git diff`
*GIT_DIFF_PATH_COUNTER*/*GIT_DIFF_PATH_TOTAL* - работает внутри программы указанной  в _diff.external_
*GIT_MERGE_VERBOSITY* - уровень детализации вывода при рекурсивном слиянии(0-5, default 2)

### Отладка
*GIT_TRACE* - контролирует протоколирование действий, не поподающих в другие категории
*GIT_TRACE_PACK_ACCESS* - регистрирует доступ к pack-файлам, первое поле - файл, второе поле - смещение
*GIT_TRACE_PACKET* - активирует регистрацию сетевых операций на уровне пакетов
*GIT_TRACE_PRFORMANCE* - отвечает за регистрацию сведений о производительности. Вывод времени выполнения.
*GIT_STACE_SETUP* - вывод информации, собранной Git о репозитории и среде.

### Разное
*GIT_SSH* - служит для подключения: `$GIT_SSH [user]@host -p <port> <command>`, не поддерживается в сценарии
*GIT_ASKPASS* - переопределяет `core.askpass`,запрос учетных данных
*GIT_NAMESPACE* - доступ к ссылкам, внутри пространства имен, эквивалентна флагу *--namespace*
*GIT_FLUSH* - буферезация вывода, при инкрементрой записи(0-1)
*GIT_REFLOG_ACTION* - позволяет задать описание в журнале ссылок
