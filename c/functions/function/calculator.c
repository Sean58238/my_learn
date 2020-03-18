#include <stdio.h>

int add(int a , int b);
int multiply(int a , int b);

typedef int (*pFunc)(int , int);

int main(){

    pFunc p1 = NULL;
    int a = 3, b = 7, result = 0; 
    p1 = add;
    result = p1(a,b);
    printf("result=%d\n" , result);

    p1 = multiply;
    result = p1(a,b);
    printf("result=%d\n", result);
}

int add(int a , int b){
    printf("-->add operation\n");
    return a + b;
}

int multiply(int a , int b){
    printf("-->multiply operation\n");
    return a * b;
}
