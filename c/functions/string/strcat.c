#include <stdio.h>
#include <string.h>

int main(void){

    char str1[10]="hello";
    char str2[10]="world";
    int len;

    len = strlen(str1);
    printf("str1 len:%d\n", len);

    len = strlen(str2);
    printf("str2 len:%d\n", len); 
 
    strcat( str1 , str2 );
    len = strlen(str1);
    printf("strcat(str2 -> str1): %s\nstr1 len:%d\n", str1 , len);
    
    return 0;
}
