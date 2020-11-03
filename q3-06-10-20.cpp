#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(float a, float b, float c);
void Iprimir(float x);
void Comparar(float a, float b, float c);

main(){
	float a, b, c;
	Cadastrar(a,b,c);
}//fim main

//procedimentos

void Imprimir(float x){
	printf("\nMaior: %f\n",x);
}//fim Imprimir

void Comparar(float a, float b, float c){
float x;
if((a>b)&&(a>c)){
	Imprimir(a);
}//fim if a
if((b>a)&&(b>c)){
	Imprimir(b);
}//fim if b
if((c>b)&&(c>a)){
	Imprimir(c);
}//fim if c
}//fim Comparar

void Cadastrar(float a, float b, float c){
	printf("Digite o primeiro numero: ");
	scanf("%f",&a);
	printf("\nDigite o segundo numero: ");
	scanf("%f",&b);
	printf("\nDigite o terceiro numero: ");
	scanf("%f",&c);
	Comparar (a,b,c);
}//fim Cadastrar

