# SSL

## Генерация сертификата
<https://www.leaderssl.ru/articles/207-vse-pro-openssl-za-5-minut>  
<https://itproffi.ru/generatsiya-i-ispolzovanie-ssl-sertifikatov-v-linux/>  
<https://itproffi.ru/ustanovka-ssl-sertifikata-na-nginx/>  


Прочитать сертификат

```sh
openssl x509 -in  certificate.crt -text -noout
```

cгенерировал для serv.domain2.domain1  

```sh
openssl req -batch -new -newkey rsa:2048 -nodes -keyout cert.key -subj '/C=RU/O=org/OU=ou/CN=rc.home.org' -out cert.csr
```

## Снять пароль с ключа сертификата

<http://gtalex.ru/kak-ubrat-vvod-parolya-enter-pem-pass-phrase-pri-perezapuske-nginx>  

```sh
cp server.key server.key.org
openssl rsa -in server.key.org -out server.key
```

## Дополнительно по созданию сертификата

Создаём ключи: `openssl ecparam -genkey -name prime256v1 | openssl ec -out private.key`  
Создаём сертификат по ключу: `openssl req -new -x509 -days 3650 -key private.key -out public.crt`  

## Генерация `.pem` файла

```sh
#Генерируем:
openssl req -new -x509 -nodes -out server.crt -keyout server.key
openssl req -newkey rsa:2048 -new -nodes -x509 -days 3650 -keyout mongo.key -out mongo.crt

# Записываем в один файл:
cat server.key > /etc/ssl/mytest.loc.pem
cat server.crt >> /etc/ssl/mytest.loc.pem
```
