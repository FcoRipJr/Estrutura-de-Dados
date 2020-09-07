#include <stdio.h>
#include <stdlib.h>
main(){
	int a=0, n=1;	
	while(n!=0){
		printf("\n Digite um numero qualquer ou 0 para parar " );
		scanf("%d",&n);
		if((n%2==0)&&(n!=0))
			a++;
	}
printf("\n Foram digitados %d numeros pares ",a);
system("pause");}
