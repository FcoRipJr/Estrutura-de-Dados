#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(float a, float b, float c);
void Imprimir(float x);
void Pesquisar(float a, float b, float c);

main(){
	float a, b, c;
	Cadastrar(a,b,c);
	
}//fim main

//procedimentos

void Imprimir(float x){
	printf("\nEncontrou: %f\n",x);
}//fim Imprimir

void Pesquisar(float a, float b, float c){
float x;
printf("\nPesquise um numero: ");
scanf("%f",&x);
if(x==a){
	Imprimir(a);
}//fim if a
if(x==b){
	Imprimir(b);
}//fim if b
if(x==c){
	Imprimir(c);
}//fim if c
}//fim Pesquisar

void Cadastrar(float a, float b, float c){
	printf("Digite o primeiro numero: ");
	scanf("%f",&a);
	printf("\nDigite o segundo numero: ");
	scanf("%f",&b);
	printf("\nDigite o terceiro numero: ");
	scanf("%f",&c);
	Pesquisar (a,b,c);		
}//fim Cadastrar

