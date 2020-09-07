#include <stdio.h>//
#include <stdlib.h>
main(){
	int c, cp=0, ci=0, somap=0, somag=0, n;
	float mediap=0, mediag=0;	
	while((n!=0)&&(n>0)){
		printf("\n Digite um numero qualquer ou 0 para parar " );
		scanf("%d",&n);
		c++;
		somag=somag+n;
		if((n%2==0)&&(n!=0)){
			somap=somap+n;
			cp++;}
		else if(n%2!=0) {
		ci++;}
	}
	mediap=somap/cp;
	mediag=somag/c;
	printf("\n Foram informados %d numeros pares ",cp);
	printf("\n Foram informados %d numeros impares ",ci);
	printf("\n A media dos numeros pares informados e: %f",mediap);
	printf("\n A media dos numeros gerais informados e: %f",mediag);
system("pause");}

