### user
```sh
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# user specific environment
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;94m\]\u$\[\033[00m\] '

```
### root
```sh
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# root specific environment
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;94m\]\u$\[\033[00m\] '
```
