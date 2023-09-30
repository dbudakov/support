# Установка из исходников

```bash
yum install -y
epel-release

yum install -y \
gcc    \
wget    \
xmlto    \
asciidoc  \
autoconf   \
curl-devel  \
docbook2X    \
exapt-devel   \
gettext-devel  \
openssl-devel   \
zlib-devel

wget https://github.com/git/git/archive/v2.29.2.tar.gz
tar -zxf v2.29.2.tar.gz
cd git-2.29.2
make configure
./configure --prefix=/usr
make all doc info
sed -i 's/docbook2x-texi/db2x_docbook2texi/' ./Documentation/Makefile
sudo make install install-doc instal-html install-info
```
