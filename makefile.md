source: [habr.com](https://habr.com/ru/post/211751/)  

#### Основная структура make:
```
# Индентация осуществляется исключительно при помощи символов табуляции,
# каждой команде должен предшествовать отступ
<цели>: <реквизиты>
	<команда #1>
	...
	<команда #n>
```

#### Основные шаги
```
{Из чего делаем? (реквизиты)} ---> [Как делаем? (команды)] ---> {Что делаем? (цели)}

# Компиляция
{исходные файлы} ---> [трансляция] ---> {объектные файлы}
{объектные файлы} ---> [линковка] ---> {исполнимые файлы}
```

#### Пример с одной программой `main.c`:
```C
/*
 * main.c
 */
#include <stdio.h>
int main()
{
	printf("Hello World!\n");
	return 0;
}
```

Makefile:
```sh
hello: main.c
	gcc -o hello main.c
```

#### Пимер с двумя программами `main.c` `hello.c`:
```C
/*
 * main.c
 */
int main()
{
	hello();
	return 0;
}
```
```C
/*
 * hello.c
 */
#include <stdio.h>
void hello()
{
	printf("Hello World!\n");
}
```

Makefile:
```sh
hello: main.c hello.c
        gcc -o hello main.c hello.c
```

#### Инкрементная компиляция
```sh
main.o: main.c
        gcc -c -o main.o main.c
hello.o: hello.c
        gcc -c -o hello.o hello.c
hello: main.o hello.o
        gcc -o hello main.o hello.o
```

#### Фиктивные цели `all`, `clean`, `install`, `uninstall`:
```sh
.PHONY: all clean install uninstall
	
all: hello
	
clean:
			rm -rf hello *.o
main.o: main.c
			gcc -c -o main.o main.c
hello.o: hello.c
			gcc -c -o hello.o hello.c
hello: main.o hello.o
			gcc -o hello main.o hello.o
install:
			install ./hello /usr/local/bin
uninstall:
			rm -rf /usr/local/bin/hello
```

#### Переменные
```sh
TARGET = hello
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)
	
clean:
			rm -rf $(TARGET) *.o
main.o: main.c
			gcc -c -o main.o main.c
hello.o: hello.c
			gcc -c -o hello.o hello.c
$(TARGET): main.o hello.o
			gcc -o $(TARGET) main.o hello.o
install:
			install $(TARGET) $(PREFIX)
uninstall:
			rm -rf $(PREFIX)/$(TARGET)
```

#### Также имеются автоматические переменный
```
$@ Имя цели обрабатываемого правила
$< Имя первой зависимости обрабатываемого правила
$^ Список всех зависимостей обрабатываемого правила
```

### Дополнительно
книга про gcc:  
[twirpx](https://www.twirpx.org/file/2101475/grant/)    

сайты:  
[dimaru.github.io](https://dimaru.github.io/make-doc/make.html)  
[rus-linux.net](http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC101)  

спец переменные:   
[www.gnu.org](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)  

Linux Makefiles:  
[linoxide.com](https://linoxide.com/how-tos/learn-linux-makefiles/)  
