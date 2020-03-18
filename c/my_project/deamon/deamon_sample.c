#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void init_deamon();

int main(){
    FILE *fp;
    time_t t;
    
    init_deamon();

    while(1){
        sleep(2);
        if((fp=fopen("test.log","a")) >= 0){
             t=time(0);
             fprintf(fp,"I'm here at %s\n", asctime(localtime(&t)));
             fclose(fp);
        }
    }
}

void init_deamon(){
    int pid;
    int i;

    if(pid=fork()){
        exit(0);
    }
    else if(pid<0){
       exit(1);
    }

    setsid();
    
    if(pid=fork()){
        exit(0);
    }else if(pid<0){
        exit(1);
    }
     
    for(i=0;i<NOFILE;++i){
        close(i);
    }
    chdir("/tmp");
    umask(0);
}
