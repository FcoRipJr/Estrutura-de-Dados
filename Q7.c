#include <stdio.h>
#include <stdlib.h>
main(){
	int a=0;
	float nota, soma, media;	
	while(nota!=0){
		printf("\n Digite uma nota ou 0 para parar " );
		scanf("%f",&nota);
		soma=soma+nota;
		a++;}
	media=soma/a;
printf("\n A soma das notas e: %f",soma);	
printf("\n A media das notas e: %f \n",media);
system("pause");}
