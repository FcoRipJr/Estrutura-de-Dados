#include <stdio.h>  //[0-25], [26-50], [51-75] e [76-100]. 
#include <stdlib.h>
main(){
	int c1=0, c2=0, c3=0, c4=0,n;	
	while(n>=0){
		printf("\n Digite um numero qualquer ou um numero negativo  para parar " );
		scanf("%d",&n);
		if((n>=0)&&(n<=25)){
		   c1++;}
		if((n>=26)&&(n<=50)){
		   c2++;}	
		if((n>=51)&&(n<=75)){
		   c3++;}
		if((n>=76)&&(n<=100)){
		   c4++;}   
    }
    printf("\n Foram digitados %d numeros  no intervalo de 0-25 \n",c1);
    printf("\n Foram digitados %d numeros  no intervalo de 26-50 \n",c2);
    printf("\n Foram digitados %d numeros  no intervalo de 51-75 \n",c3);
    printf("\n Foram digitados %d numeros  no intervalo de 76-100 \n",c4);
    system("pause");}
