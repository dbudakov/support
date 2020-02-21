[root@localhost otus2]# cat hw.c
#include <stdio.h>

int main(int argc, char *argv[]) {
        printf("hello, %s", "world");
        return 0;
}

[root@localhost otus2]# gcc -g -o hw hw.c

[root@localhost otus2]# strace ./hw
## запуск дочернего процесса в unix осуществляется через fork() - клонирование процесса, после чего происходит "подмена образа" через execve()
execve("./hw", ["./hw"], [/* 28 vars */]) = 0 ## = 0 - это возвращаемое значение. В данном случае "всё хорошо", хотя возвращать это значение уже некому, родительского форка уже нет
brk(NULL)                               = 0x13fb000 ## Эй, ядро, а где у меня память кончается? Сейчас себе malloc() настраивать буду, надо знать
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd0ae5c8000 # Выделяем себе немножко памяти, видимо под буфер
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory) ## Есть ли такой файл?
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3 ## Открываем файл на чтение, возвращаемое значение - номер файлового дескриптора. Первые 3 стандартные: 0 = STDIN, 1 = STDOUT, 2 = STDERR
fstat(3, {st_mode=S_IFREG|0644, st_size=29023, ...}) = 0 ## Так, а что мы открыли? Это оказывается обычный файл с доступами 644. 3 - номер дескриптора, второй параметр - ссылка на структуру, которую заполнит fstat. Возвращаемое значение 0 - "всё хорошо". И вообще man 2 fstat. А, да, для этого надо доставить man-pages
mmap(NULL, 29023, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd0ae5c0000 ## "Отображаем файл в память".
## Еще раз про mmap
## Это syscall, которая выделяет область памяти, за которой следит ядро. Оно туда загружает часть файла.
## В случае попытки прочитать за пределами выделенной памяти, ядро обработает ошибку доступа к памяти 
## и подгрузит еще кусок файла. Если свободной памяти будет недостаточно, ядро будет освобождать блоки памяти.
## В данном случае нам важно, что все процессы, "заммапившие" один и тот-же файл получат один и тот-же указатель.
## Это используется в механизме разделяемых библиотек.
## mmap без указания дескриптора еще используется для выделения общей ("shared") памяти
close(3)                                = 0 ## Теперь мы (на самом деле glibc) будем работать с памятью, а не с файлом, дескриптор больше не нужем, закрываем файл.
## Дальше мы подгрузим разделяемую часть glibc (до этого работала статическая часть вкомпиленная в нашу программу
## (еще разок - это GNU C Standard Library)
open("/lib64/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\20\35\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2127336, ...}) = 0
mmap(NULL, 3940800, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fd0adfe5000
mprotect(0x7fd0ae19d000, 2097152, PROT_NONE) = 0
mmap(0x7fd0ae39d000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b8000) = 0x7fd0ae39d000
mmap(0x7fd0ae3a3000, 16832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fd0ae3a3000
close(3)                                = 0
## Успешно загрузили
## Теперь выделим себе еще немного памяти. Судя по размерам - для для разных буферов glibc
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd0ae5bf000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd0ae5bd000
## Тут немного платформоспецифичного, нам не сильно интересно. Но если интересно - man 2 mprotect. man-pages поставили?
arch_prctl(ARCH_SET_FS, 0x7fd0ae5bd740) = 0
mprotect(0x7fd0ae39d000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7fd0ae5c9000, 4096, PROT_READ) = 0
## Мы закончили работать с разделяемыми библиотеками в целом и /etc/ld.so.cache в частности (см выше), можно разммапить память (освободить память, отвязать от файла)
munmap(0x7fd0ae5c0000, 29023)           = 0
## Куда мы писать-то будем?
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 4), ...}) = 0 ## Ага, STDOUT - это терминал (character device)
## И еще немного буферов
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd0ae5c7000
## Наконец ми дошли до главного!
## write(1, "hello, world", 12)            = 12 ## Мы написали в STDOUT (1) строку. Целых 12 байт. Ядро нам вернуло 12 - т.е. "мне удалось записать 12 байт" 
exit_group(0)                           = ? ## Ну и всё, заканчиваем.
+++ exited with 0 +++

[root@localhost otus2]#
