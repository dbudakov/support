#!/bin/bash

cat<<EOF>/home/$USER/.bashrc
if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;94m\]\u$\[\033[00m\] '
EOF

source /home/dbudakov/.bashrc
