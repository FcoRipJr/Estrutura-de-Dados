#include <stdio.h>
#include <stdlib.h>
main(){
	int soma, produto, n=1;	
	while((n!=0)&&(n>0)){
		printf("\n Digite um numero qualquer ou 0 para parar " );
		scanf("%d",&n);
		if(n%2!=0){
			produto=produto*n;
		}
		if(n%2==0){
			soma=soma+n;
		}
	}
	printf("\n O produto dos numeros impares e: %d",produto);
	printf("\n A soma dos numeros pares e: %d \n",soma);
	system("pause");}
