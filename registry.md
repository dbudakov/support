# registry

## show runlike container

```bash
docker inspect \
  --format "$(curl -s https://gist.githubusercontent.com/efrecon/8ce9c75d518b6eb863f667442d7bc679/raw/run.tpl)" \
  name_or_id_of_your_running_container
```


```bash
PATH_REGISTRY=/home/dbudakov/registry
mkdir ${PATH_REGISTRY} ${PATH_REGISTRY}/auth ${PATH_REGISTRY}/certs
docker run --rm --entrypoint htpasswd httpd:2 -Bbn "docker" "P@ssw0rd" > ${PATH_REGISTRY}/auth/htpasswd

# set default name for crt
openssl req \
    -newkey rsa:4096 \
    -nodes \
    -sha256 \
    -keyout ${PATH_REGISTRY}/certs/domain.key \
    -addext "subjectAltName = DNS:192.168.0.104" \
    -x509 \
    -days 365 \
    -out ${PATH_REGISTRY}/certs/domain.crt

# cat ${PATH_REGISTRY}/certs/domain.crt | openssl x509 -text

mkdir /mnt/registry

docker run -d\
  --name "registry" \
  --volume "${PATH_REGISTRY}/certs:/certs" \
  --volume "/mnt/registry:/var/lib/registry" \
  --volume "${PATH_REGISTRY}/auth:/auth" \
  --log-driver "json-file" \
  --restart "always" \
  --publish "0.0.0.0:443:443/tcp" \
  --network "bridge" \
  --expose "443/tcp" \
  --expose "5000/tcp" \
  --env "REGISTRY_HTTP_TLS_KEY=/certs/domain.key" \
  --env "REGISTRY_AUTH=htpasswd" \
  --env "REGISTRY_AUTH_HTPASSWD_REALM=Registry Realm" \
  --env "REGISTRY_AUTH_HTPASSWD_PATH=/auth/htpasswd" \
  --env "REGISTRY_HTTP_ADDR=0.0.0.0:443" \
  --env "REGISTRY_HTTP_TLS_CERTIFICATE=/certs/domain.crt" \
  --env "REGISTRY_STORAGE_DELETE_ENABLED"="true" \
  --entrypoint "/entrypoint.sh" \
  "registry:2.8.2" \
  "/etc/docker/registry/config.yml" 

openssl s_client -connect 192.168.0.104:443 -showcerts 2>/dev/null </dev/null | openssl x509 -text
curl --cert certs/domain.crt --key certs/domain.key --cacert /etc/ssl/certs/ca-certificates.crt  -u docker:P@ssw0rd https://192.168.0.104/v2/_catalog
curl -k -u docker:P@ssw0rd https://192.168.0.104/v2/_catalog 

# get crt for registry
# openssl s_client -connect 192.168.0.104:443 -showcerts 2>/dev/null </dev/null | openssl x509 -pem >192.168.0.104.crt
# OR: keytool -printcert -sslserver 192.168.0.104:443 -rfc >192.168.0.104.crt

# add crt for linux
# sudo cp 192.168.0.104.crt /usr/local/share/ca-certificates/192.168.0.104.crt 
# sudo update-ca-certificates 
# systemctl restart docker

# add crt for macos
# sudo security add-trusted-cert -d -r trustRoot -k /Library/Keychains/System.keychain 192.168.0.104.crt 
# killall Docker && open /Applications/Docker.app
```

## delete manifest from registry
```bash
curl -u docker:P@ssw0rd https://192.168.0.104/v2/_catalog 
curl -u docker:P@ssw0rd https://192.168.0.104/v2/custom/postgres/tags/list # repo: custom/postgres
curl -sS -u docker:P@ssw0rd -v -X HEAD -H 'Accept: application/vnd.docker.distribution.manifest.v2+json' https://192.168.0.104/v2/"custom/postgres"/manifests/15.3 2>&1 |  awk '/docker-content-digest/ {print $3}'
curl -su docker:P@ssw0rd  -X DELETE https://192.168.0.104/v2/custom/postgres/manifests/sha256:cf82e31f4f0b610a9bd0b3031adeb3b1729e849f803f32d06f97101afa7a593e
docker exec -it registry sh -c "registry garbage-collect /etc/docker/registry/config.yml"
```