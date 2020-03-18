#include "cal.h"
#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}


int main(){
    int result = 0;

    struct cal_t myCal;
    myCal.a = 12;
    myCal.b = 4;
    myCal.p = add;

    result = calculator(&myCal);
    printf("result=%d\n",result);
    return 0;
}
