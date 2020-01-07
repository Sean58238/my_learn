/*definition string*/

#include <stdio.h>

int main(void){

   char def_1[6] = {'H','e','l','l','o','\0'}; 
   printf("def_1 message:%s\n" , def_1);

   char def_2[5] = {'H','e','l','l','o'};
   printf("def_2 message:%s\n" , def_2);

   char def_3[] = "Hello";
   printf("def_3 message:%s\n" , def_3);

   return 0;  
}
