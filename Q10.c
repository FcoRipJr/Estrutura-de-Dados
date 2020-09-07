#include <stdio.h>
#include <stdlib.h>
main(){
int x=0, n=1000;
while(x<5){
	n++;
	if(n%11==5){
		x=x+1;}
	}
	printf("\n o quinto número maior que 1000, cuja divisão por 11 tenha resto 5 e : %d \n",n);
system("pause");}


