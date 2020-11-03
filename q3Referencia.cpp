#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(float *p, float *q, float *r);
void Iprimir(float x);
void Comparar(float a, float b, float c);

main(){
	float a, b, c;
	int m;
	do{
	printf("1-Cadastrar\n");
	printf("2-Comparar\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Cadastrar(&a,&b,&c);
		  break;
		case 2:
	Comparar (a,b,c);		
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

void Cadastrar(float *p, float *q, float *r){
	float a,b,c;
	printf("Digite o primeiro numero: ");
	scanf("%f",&a);
	*p=a;
	printf("\nDigite o segundo numero: ");
	scanf("%f",&b);
	*q=b;
	printf("\nDigite o terceiro numero: ");
	scanf("%f",&c);
	*r=c;
}//fim Cadastrar

