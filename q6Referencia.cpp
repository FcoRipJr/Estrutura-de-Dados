#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//FRANCISCO RIPARDO 1906458

//declarando Registro
typedef struct Carro{
 char modelo[10];
 char marca[10];
 char placa[8];
 char cor[10];
 float valor;
 float ipva;
 Carro *car;
}Carro;

//declarando procedimetos
void Cadastrar(Carro *p);
void Iprimir(Carro x);
void Pesquisar(Carro x, Carro y, Carro z);

main(){
	Carro a;
	Carro b; 
	Carro c;
int m;
	do{
	printf("1-Cadastrar\n");
	printf("2-Pesquisar\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Cadastrar(&a);
	Cadastrar(&b);
	Cadastrar(&c);
		  break;
		case 2:
	Pesquisar (a,b,c);		
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

void Imprimir(Carro x){
	printf("\nModelo: %s\n",x.modelo);
	printf("\nMarca: %s\n",x.marca);
	printf("\nPlaca: %s\n",x.placa);
	printf("\nCor: %s\n",x.cor);
	printf("\nValor: R$%.2f\n",x.valor);
	printf("\nIPVA: R$%.2f\n",x.ipva);
}//fim Imprimir

void Cadastrar(Carro *p){
Carro a;
	printf("\n##Carro 1##\n ");
	 printf("\nModelo: ");
	 fflush(stdin);
	 gets(a.modelo);
	 printf("\nMarca: ");
	 fflush(stdin);
	 gets(a.marca);
	 printf("\nPlaca: ");
	 fflush(stdin);
	 gets(a.placa);
	 printf("\nCor: ");
	 fflush(stdin);
	 gets(a.cor);
	 printf("\nValor: ");
	 scanf("%f",&a.valor);
	 a.ipva=a.valor*0.03;
strcpy(*p.cor,a.cor);
strcpy(*p.marca,a.marca);
strcpy(*p.modelo,a.modelo);
strcpy(*p.placa,a.placa);
*p.valor=a.valor;
*p.ipva=a.ipva;
	
}//fim Cadastrar


void Pesquisar(Carro x, Carro y,Carro z){
char placa[8];
printf("\nPesquise uma Placa: ");
fflush(stdin);
gets(placa);
if(strcmp(placa, x.placa)==0){
	Imprimir(x);
}//fim if x

if(strcmp(placa, y.placa)==0){
	Imprimir(y);
}//fim if y

if(strcmp(placa, z.placa)==0){
	Imprimir(z);
}//fim if z
else{
	printf("\nPlaca nao encontrada\n");
}
}//fim Pesquisar

