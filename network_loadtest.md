# network test

# loadtest
```
user@192.168.1.1# iperf3 -s
user@192.168.1.2# iperf3 -c 192.168.1.1
```

```sh
user@192.168.1.1# iperf3 -s -p 1000

# test tcp
user@192.168.1.2# iperf3 -c 192.168.1.1 -p 100007

# test udp
user@192.168.1.2# iperf3 -c 192.168.1.1 -p 10000 -u
```

## How to check UDP/10000 connectivity

<https://community.jitsi.org/t/tip-how-to-check-udp-10000-connectivity/73031>  

### ngrep  

On the **server** side: install `ngrep` and check traffic  

```ssh
apt-get install ngrep
ngrep -q 'is accessable' udp port 10000
```

On the **client** side: install `netcat`, and send a messaget to the server through UDP/10000  

```sh
apt-get install netcat
echo 'yes, it is accessable' | nc -u your.server.com 10000

# and again
for i in (seq 1 20); do sleep 3; nc -z -v -u your.domain.com 1 10000; done

#and service for send message in request
curl "http://checkmyport.emrah.com?proto=udp&port=10000&text=is%20accessable"

# WRONG! or so, without server part, only client
nc -z -v -u YOUR-HOST-ADDRESS 10000
```

ON THE SERVER COME MESSAGE: _"yes, it is accessable"_  

### tcpdump

listen traffic:  

```sh
sudo tcpdump -ni en0 port 10000
```

block traffic:  

```sh
echo "block drop quick on en0 proto udp from any to any port = 10000" | sudo pfctl -ef -
```

enable traffic:  

```sh
echo "block drop quick on en0 proto udp from any to any port = 10000" | sudo pfctl -d
```
