#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(float *p, float *q, float *r);
void Imprimir(float x);
void Pesquisar(float *p, float *q, float *r);

main(){
	float a, b, c;
	int m;
	do{
	printf("1-Cadastrar\n");
	printf("2-Pesquisar\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Cadastrar(&a,&b,&c);
		  break;
		case 2:
	Pesquisar (&a,&b,&c);		
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
	printf("\nEncontrou: %f\n",x);
}//fim Imprimir

void Pesquisar(float *p, float *q, float *r){
float x;
printf("\nPesquise um numero: ");
scanf("%f",&x);
if(x==*p){
	Imprimir(*p);
}//fim if p
if(x==*q){
	Imprimir(*q);
}//fim if q
if(x==*r){
	Imprimir(*r);
}//fim if r
else{
	printf("\nnumero na econtrado\n");
}//fim else
}//fim Pesquisar

void Cadastrar(float *p, float *q, float *r){
float a, b,c;	
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

