#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(int *p, int *q);
void Imprimir(int x);

main(){
	int a, b, m;
	do{
	printf("1-Cadastrar\n");
	printf("2-Exibir\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Cadastrar(&a,&b);
		  break;
		case 2:
	Imprimir(a);
	Imprimir(b);		
		  break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");      	
	 }//fim switch case
	}while(m!=0);
}//fim main

//procedimentos

void Imprimir(int x){
	printf("\nNumero: %i\n",x);
}//fim Imprimir

void Cadastrar(int *p, int *q){
	int a,b;
	printf("Digite o primeiro numero: ");
	scanf("%i",&a);
	*p=a;
	printf("\nDigite o segundo numero: ");
	scanf("%i",&b);
	*q=b;
}//fim Cadastrar
