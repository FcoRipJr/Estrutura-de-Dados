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
}Carro;

//declarando procedimetos
void Cadastrar(Carro a, Carro b,Carro c);
void Iprimir(Carro x);
void Pesquisar(Carro x, Carro y, Carro z);

main(){
	Carro a;
	Carro b; 
	Carro c;
	Cadastrar(a,b,c);
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
void Cadastrar(Carro a,Carro b,Carro c){
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
	
	printf("\n##Carro 2##\n ");
     printf("\nModelo: ");
	 fflush(stdin);
	 gets(b.modelo);
	 printf("\nMarca: ");
	 fflush(stdin);
	 gets(b.marca);
	 printf("\nPlaca: ");
	 fflush(stdin);
	 gets(b.placa);
	 printf("\nCor: ");
	 fflush(stdin);
	 gets(b.cor);
	 printf("\nValor: ");
	 scanf("%f",&b.valor);
	 b.ipva=b.valor*0.03;
	
	printf("\n##Carro 3##\n ");
	 printf("\nModelo: ");
	 fflush(stdin);
	 gets(c.modelo);
	 printf("\nMarca: ");
	 fflush(stdin);
	 gets(c.marca);
	 printf("\nPlaca: ");
	 fflush(stdin);
	 gets(c.placa);
	 printf("\nCor: ");
	 fflush(stdin);
	 gets(c.cor);
	 printf("\nValor: ");
	 scanf("%f",&c.valor);
	 c.ipva=c.valor*0.03;

	Pesquisar(a,b,c);
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

