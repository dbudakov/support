# Создание снепшота индексов текущего движка
  - создание снепшотов системных индексов для сохранения конфигурации сервиса  
# Резервное копирование:

Указание каталога в файле elasticsearch.yml для хранения снепшотов, можно локальную дирректорию  
```
path.repo: ["/mount/es_backups"]
```

Назначение подключенной(указанной в конфиге) папки под репозиторий
```
curl -XPUT 'http://localhost:9200/_snapshot/backups' -H
'Content-Type: application/json' -d '{
    "type": "fs",
    "settings": {
        "location": "/mount/es_backups/backups",
        "compress": true
    }
}'
```

Назначение облака под репозиторий
```
curl -XPUT 'http://localhost:9200/_snapshot/backups' -H 'Content-Type:
application/json' -d '{
    "type": "s3",
    "settings": {
        "bucket": "bucket_name",
        "region": "us-west",
        ...
    }
}'
```

Создание снепшота в назначенный репозиторий
```
curl -XPUT
'http://localhost:9200/_snapshot/backups/backup_201710101930?pretty' -H
'Content-Type: application/json' -d'
{
    "indices": "bigginsight,logstash-*",
    "ignore_unavailable": true,
    "include_global_state": false
}'
```
Список всех снепшотов
```
curl -XGET 'http://localhost:9200/_snapshot/backups/_all?pretty'
```

Восстановление из снепшота  
```
curl –XPOST 'http://localhost:9200/_snapshot/backups/backup_201710101930/_restore'
```
