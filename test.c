#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>


int main(void)
{
    pid_t pid;
    int i=0;
    for(i=0;i<1024;i++){
        pid=fork();
        if(0==pid)
            break;
    }
    if(i==1024){
        return 0;
    }
    else {
        execlp("nc","nc","127.0.0.1","8000",NULL);
        perror("exec error");
        exit(1);
    }
    else {
        perror("fork error");
        exit(1);
    }
}
    


