#include <stdio.h>
#include <string.h>

int main(void) {

    char str[50];

    strcpy(str,"this is a sample for memset");
    puts(str);

    memset(str,'$',7);
    puts(str);

    return 0;
}
