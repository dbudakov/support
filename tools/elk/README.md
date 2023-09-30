# elk

https://github.com/widhalmt/ansible-role-elasticsearch

## Cоздание шифрованного подключени elk:  
  https://shiningapples.net/elasticsearch-%D0%B2%D1%8B%D0%BF%D1%83%D1%81%D0%BA-%D1%81%D0%B5%D1%80%D1%82%D0%B8%D1%84%D0%B8%D0%BA%D0%B0%D1%82%D0%B0-%D0%B2-%D1%84%D0%BE%D1%80%D0%BC%D0%B0%D1%82%D0%B5-pkcs12/  
  — https://www.elastic.co/guide/en/elasticsearch/reference/6.8/configuring-tls.html  
  — https://www.elastic.co/guide/en/elasticsearch/reference/6.8/certutil.html  

проверка кластера  
  https://netpoint-dc.com/blog/elasticsearch-cluster-linux/  
  
elk.yml_ssl  
  https://discuss.elastic.co/t/ssl-errors-remaining-after-upgrade-to-7-5-0/212520  
  
openssl  RSA  
  https://www.ibm.com/support/knowledgecenter/SSMNED_5.0.0/com.ibm.apic.cmc.doc/task_apionprem_gernerate_self_signed_openSSL.html  
  https://www.emaro-ssl.ru/blog/convert-ssl-certificate-formats/  
  
keytool import  
  http://blog.qatools.ru/ssl/import-cert-to-java  
  https://www.sslshopper.com/article-most-common-java-keytool-keystore-commands.html  


## GRAYLOG
При подключение если пароль содержить спецсимвол, он не кодируется в URL, а интерпритируется, для кодировки символа используется его кодовое значение:
https://wm-school.ru/html/html_url_acsii.html  

Не умеет создавать индексы с указанием даты

## trouble
[ERROR][o.e.b.Bootstrap][uoIqImq]Exception java.lang.IllegalStateException: failed to load plugin class [org.elasticsearch.xpack.watcher.Watcher]  
https://discuss.elastic.co/t/failed-to-load-plugin-class-org-elasticsearch-xpack-core-xpackplugin/120627  


## Оптимизация ELK
https://github.com/dbudakov?tab=repositories
шардинг - https://community.graylog.org/t/best-practice-for-index-configuration/984

## Backup
можно бэкапить системные индексы, для сохранения настроек систем логирования, оповещения и мониторинга

## Подстановка регулярок
http://grokdebug.herokuapp.com/  
https://regex101.com/  
