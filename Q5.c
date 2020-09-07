#include <stdio.h>
#include <stdlib.h>
main(){ 
int n;
for(n=1;n<=100;n++){
	if((n%2!=0)&&(n%3==0)){
		printf("\n %d \n",n);}
	}
system("pause");}
