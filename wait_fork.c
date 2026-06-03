#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define f_printf(str){printf("pid: %d: %s", getpid(), str);}

// Just show how work WAIT when pid forks
int main(){
    pid_t pid;
    f_printf("befor fork\n");

    pid=fork();

    f_printf("befor if\n");

    if (pid == -1){
        // error create fork
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // it is fork process
        f_printf("FORK PROCESS!\n");
        sleep(10);
        // return 1;
    } else {
        f_printf("WAIT ON\n");
        // wait(NULL); //wait fort process
        f_printf("WAIT OFF\n");

    }
    f_printf("after if\n");
    return 0;
}
