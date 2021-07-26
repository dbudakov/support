# node install

```sh
yum install git -y
cd /opt/
git clone https://github.com/tj/n
cd n/
make
ln -s /usr/local/bin/n /usr/bin/
n --version
n lts
for i in node npm;do ln -s /usr/local/n/versions/node/*/bin/$i /usr/bin;done
```

```sh
yum install git -y
cd /opt/
git clone https://github.com/nvm-sh/nvm.git
cd nvm
git checkout `git describe --abbrev=0 --tags --match "v[0-9]*" $(git rev-list --tags --max-count=1)`
. ./nvm.sh
nvm install node
```

```
nvm install 12 node
