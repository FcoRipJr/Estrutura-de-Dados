#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(int a, int b);
void Iprimir(int x);

main(){
	int a, b;
	Cadastrar(a,b);
}//fim main

//procedimentos

void Imprimir(int x){
	printf("\nNumero: %i\n",x);
}//fim Imprimir

void Cadastrar(int a, int b){
	printf("Digite o primeiro numero: ");
	scanf("%i",&a);
	printf("\nDigite o segundo numero: ");
	scanf("%i",&b);
	Imprimir(a);
	Imprimir(b);
}//fim Cadastrar
