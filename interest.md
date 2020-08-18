```sh
#linkedn
pmatop
pmcollect
netstat -t -a
ss -t -a
sudo tuned-adm list
sudo tuned-adm active
  Current active profile: virtual-guest
sudo tuned-adm profile desktop
sudo tuned-adm active

yum install -y kernl-tools
sudo turbostat
  GFXWatt 

sudo yum install -y sysstat
sudo powertop2tuned powertune
sudo tuned-adm profile powertune
sudo tuned-adm active

tuna

yum install kmod-oracleasm --downloadonly --downloaddir=/tmp/drivers

vi /etc/rsyslog.conf
# Provides TCP syslog recaption
$ModLoad imtcp
$InputTCPServerRun 514
```
