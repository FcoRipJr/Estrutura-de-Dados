#include <stdio.h>
#include <stdlib.h>
main(){ 
int n,  soma=0;
for(n=15;n<=250;n++){
	if((n%2!=0)&&(n%6==0)){
		soma=soma+n;
	}
}
	printf("\nA soma de numeros impares multiplos de 6 entre 15 e 250 e: %d \n",soma);
system("pause");}

