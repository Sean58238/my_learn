#include <stdio.h>
#include <string.h>

int main(void){
   
    int i=0;
    char str[10];
    char *p = str;

    //memset(str, 0 , sizeof(str));
    //memset(str, 0 , 10)
    //memset(p, 0 , sizeof(p));
    memset(p ,0 , sizeof(*p));

    for(i=0; i< 10; ++i){
        printf("%d\x20", str[i]);
    }

    printf("\n");
    return 0;
}
