### user
```sh
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Импорт алиасов или переменных
# if [ -f ~/.bash_aliases ];then
#    source ~/.bash_aliases
# fi


# user specific environment
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;94m\]\u$\[\033[00m\] '

```
### root
```sh
alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'

if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi
PATH="$HOME/.local/bin:$HOME/bin:$PATH:/usr/bin:/usr/sbin"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;91m\]\u>\[\033[00m\] '
```
