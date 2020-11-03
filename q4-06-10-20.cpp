#include<stdio.h>
#include<stdlib.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Iprimir(float x);
void Somar(float a, float b);
void Subtrair(float a, float b);
void Dividir(float a, float b);
void Multiplicar(float a, float b);
void Potencia(float a, float b);

main(){
	float a, b;
int m;
	do{
	printf("1-Somar\n");
	printf("2-Subtrair\n");
	printf("3-Dividir\n");
	printf("4-Multiplicar\n");
	printf("5-Potencia\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Somar(a,b);
		  break;
		case 2:
	Subtrair(a,b);
		  break;
		case 3:
	Dividir(a,b);
		  break;
		case 4:
	Multiplicar(a,b);
		  break;
		case 5:
	Potencia(a,b);
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
	printf("\nResultado: %f\n",x);
}//fim Imprimir

void Potencia(float a, float b){
	float r;
	printf("\ndigite o numero base: ");
	scanf("%f",&a);
	printf("\ndigite a potencia: ");
	scanf("%f",&b);
	r=a;
	for(int i=1;i<b;i++){
	 r=r*a;
	}//fim for
	Imprimir(r);
}//fim Potencia

void Somar(float a, float b){
	float r;
	printf("\ndigite o primeiro numero: ");
	scanf("%f",&a);
	printf("\ndigite o segundo numero: ");
	scanf("%f",&b);
	r=a+b;
	Imprimir(r);
}//fim Somar

void Subtrair(float a, float b){
	float r;
	printf("\ndigite o primeiro numero: ");
	scanf("%f",&a);
	printf("\ndigite o segundo numero: ");
	scanf("%f",&b);
	r=a-b;
	Imprimir(r);
}//fim Subtrair


void Dividir(float a, float b){
	float r;
	printf("\ndigite o primeiro numero: ");
	scanf("%f",&a);
	printf("\ndigite o segundo numero: ");
	scanf("%f",&b);
	r=a/b;
	Imprimir(r);
}//fim Dividir


void Multiplicar(float a, float b){
	float r;
	printf("\ndigite o primeiro numero: ");
	scanf("%f",&a);
	printf("\ndigite o segundo numero: ");
	scanf("%f",&b);
	r=a*b;
	Imprimir(r);
}//fim Multiplicar
