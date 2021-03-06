Ежедневные задачи  
* Оценка показаний датчиков аппаратного контроля  
* Проверка результатов выполнения резервного копирования  
* Проверка журналов серверов  
* Проверка свободного пространства на носителях  
* Проверка функционирования основных служб  
* Проверка обновлений программного обеспечения  
* Проверка антивирусных баз  
* Оценка внешних факторов

Еженедельные задачи
* Проверка системы охлаждения серверов
* Проверка системы кондиционирования
* Проверка производительности серверов
* Формирования отчета

Прочие плановые операции
* Очистка оборудования от пыли
* Удаление старых объектов службы каталогов
* Планирование развития
* Актуализация организационно-распорядительной документации


## Ежедневные задачи
Основная ежедневная задача = это мониторинг, контроль текущего состояния информационной системы. Задача мониторинга состоит из серии операций, которые предстоит выполнять каждый день.

- **Оценка показаний датчиков аппаратного контроля** - нет ничего хуже жесткого диска, который вышел из строя, а если еще учесть, что он предупреждал за месяц до этого...
Современное оборудование позволяет контролировать температурный режим, скорость вращения вентиляторов, параметры электропитания и
даже предсказывать скорый выход из строя жестких дисков на основе технологии S.M.A.R.T(Self-Monitoring, Analysis and Reporting technology)

- **Проверка результатов выполнения резервного копирования** - практически все утилиты резервного копирования предоставляют отчет о выполнении резервного копирования.
Мало просто настроить резервное копирование по определенному сценарию и забыть о нем — нужно ежедневно проверять, создалась ли резервная копия? Мог выйти из строя жесткий диск сетевого хранилища используемого для РК. Во время РК могло произойти отключение электричества, обрыв сетевого соединения...
В результате резервная копия не была создана, а вы об этом узнаете только тогда, когда она понадобится.

- **Проверка журналов серверов** - администратору нужно регулярно проверять журналы работы серверов(особенно если у вас их несколько), обращая особое внимание на журналы безопасности и ошибок. В них можно найти много интересного — например, сведения о неудачных попытках входа в систему. Если таких попыток одна-две, пользователь просто ошибся с паролем, а вот если их много, то, возможно, кто-то пытался подобрать пароль.

- **Проверка свободного пространства на носителях** - правильнее всего настроить автоматический мониторинг дискового пространство.
Типичный пример: на сетевом хранилище осталось 5 Гбайт свободного пространства.
Вы еще не получили сообщения о том, что свободное пространство закончилось, но если вы знаете, что резервная копия, которая будет создана вечером, занимает,
скажем, 7 Гбайт, то не стоит дожидаться того самого сообщения, - нужно принять меры по ликвидации дефицита дискового пространства. Муры могут быть самыми разными:
от удаления неактуальной информации до приобретения еще одного жесткого диска.

- **Проверка функционирования основных служб** - следует регулярно проверять работоспособность основных служб системы: соединения с Интернетом службы каталогов, службы электронной почты и пр.

- **Проверка обновлений программного обеспечения** - возможно, вышли обновления используемого ПО. Администратору нужно ознакомиться с сутью каждого обновления, а не слепо устанавливать все полученные обновления.

- **Проверка антивирусных баз** - обычно антивирусные базы обновляются автоматически. Но администратор должен убедиться, что обновление произошло

- **Оценка внешних факторов** - администратор должен контролировать температуру вокруг серверов, проверять отсутствие внешних факторов вскрытия корпусов серверов и АРМ.


## Еженедельные задачи
Некоторые задачи администратору нужно выполнять каждую неделю или каждые две недели -- все зависит от специфики предприятия
- **Проверка системы охлаждения серверов** - система охлаждения серверов имеет свойство забиваться пылью, и ее надо периодически чистить, но раз в неделю нужно хотя бы внешне оценивать несходимость такой чистки. Следует также контролировать состояние вентиляторов — иногда они выходят из строя. Если вентиляторы гудят, замените их. Если замена по тем или иным причинам, в том числе финансовым, невозможно, смажьте подшипники гудящих вентиляторов

- **Проверка системы кондиционирования** - серьезные серверные комнаты оснащаются системами кондиционирования и фильтрации воздуха. Хотя бы раз в две недели нежно оценивать состояние фильтров системы кондиционирования и при необходимости производить их чистку или замену.

- **Проверка производительности серверов** - необходимо производить проверку производительности серверов и анализировать изменения в ней по сравнению с прошлыми периодами. Если производительность понизилась следовать принять меры по поддержанию привычного уровня обслуживания пользователей.

- **Формирования отчета** - В конце каждой недели администратору желательно составлять отчет о проделанной работе. Это дисциплинирует самого администратора и позволяет держать руководителя предприятия в курсе всего происходящего в информационной системе.

## Прочие плановые операции
Никоторые операции администратору нужно производить относительно редко, но о них не стоит забывать. Следующие операции можно выполнять раз в квартал.
- **Очистка оборудования от пыли** - речь идет о компьютерном парке и прочей технике, рабочий станции не работают на полную мощность и перегрев и отказ одной станции не страшен, поэтому ТО раз в квартал.

- **Удаление старых объектов службы каталогов** - состав объектов в службе каталогов часто не соответствует реальному положению дел. Поэтому нужно периодически чистить AD(УЗ уволенных сотрудников, замененных компьютеров и т.п.)

- **Учебное восстановление системы** - следует производить ежеквартально — администратор должен в случае сбоя оперативно восстановить работу системы, для этого нужны периодические тренировки. Администратор должен знать, как произвести замену вышедшего из строя накопителя в составе RAID? Как восстановить работу сети, как в случае необходимости восстановить всю "упавшую" систему. Если у вас нет сервера для экспериментов, тренируйтесь в виртуальных машинах

- **Планирование развития** - администратор должен оценивать текущее положение дел информационной системы. Вряд ли руководителю понравиться если администратор вдруг заявит что нужен новый сервер, хотя вчера еще и старый всех устраивал. Поэтому нужно составлять план развития на следующий квартал, в котором предусматривать необходимость покупки/модернизации оборудования. В план развития также надо включать и прочие расходы, связанные с выполнением обязанностей ИТ-отдела: оплату услуг хостинга и регистрации доменного имени, стоимость обновления программного обеспечения или продления лицензий. Руководитель предприятия или финансовый директор должны быть в курсе требуемых расходов.

- **Актуализация организационно-распорядительной документации** - раз в год нужно актуализировать схемы сетей, помещений или пересматривать руководящие документы, касающиеся работы ИТ-отдела(например, должностные инструкции его сотрудников, политику безопасности и резервного копирования и т.п.)
