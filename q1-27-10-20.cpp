#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2
//FRANCISCO RIPARDO 1906458
//decrarando Registro
typedef struct Carro{
  char placa[8];
  char modelo[10];
  char cor[10];
}Car;

//decrarando Procedimentos/Funcoes
void Cadastrar(Car vet[], int tam);
Car Pesquisar(Car vet[], int tam);
void Alterar(Car vet[], int tam);
void Exibir(Car vet[], int t);
void Imprimir(Car vet);

main(){
  Car c[MAX];
  int op;
  
  do{
  	system("cls");
  	printf("1-Cadastrar\n");
  	printf("2-Pesquisar\n");
  	printf("3-Alterar\n");
  	printf("0-Sair\n");
  	scanf("%i",&op);
  	
  	switch(op){
  	  case 1:
  	  	Cadastrar(c,MAX);
		break;
	
	  case 2:
	  	Imprimir(Pesquisar(c,MAX));
		break;
	
	  case 3:
	  	Alterar(c,MAX);
		break;
	
	  case 0:
	  	exit(0);
		break;
	
	  default:
	    printf("\nOpcao Invalida\n");					
	  }//fim switch case
  	
  	system("pause");
  }while(op!=0);

}//fim main

// Procedimentos/Funcoes
void Cadastrar(Car vet[], int tam){
  system("cls");
  printf("##Cadastrando Carros##");
  
  for(int i=0; i<tam; i++){
    printf("\nCarro %i",i+1);
    printf("\nPlaca: ");
    fflush(stdin);
    gets(vet[i].placa);
    printf("\nModelo: ");
    fflush(stdin);
    gets(vet[i].modelo);
    printf("\nCor: ");
    fflush(stdin);
    gets(vet[i].cor);
  
  }//fim for
  system("pause");
}//fim Cadastrar

Car Pesquisar(Car vet[], int tam){
  int achou=0;
  char pesq[8];
  system("cls");
  printf("Pesquise uma Placa: ");
  fflush(stdin);
  gets(pesq);
  
  for(int i=0; i<tam; i++){
  	if(strcmp(pesq,vet[i].placa)==0){
	  achou=1;
	  return vet[i];
	  }//fim if pesq

  }//fim for
  
  if(achou=0){
  	printf("\nPlaca Nao Encontrada\n");
  }//fim if achou
  
  system("pause");
}//fim Pesquisar

void Exibir(Car vet[], int t){
  printf("\nPlaca: %s\n",vet[t].placa);
  printf("Modelo: %s\n",vet[t].modelo);
  printf("Cor: %s\n",vet[t].cor);
}//fim Exibir

void Imprimir(Car vet){
  printf("\nPlaca: %s\n",vet.placa);
  printf("Modelo: %s\n",vet.modelo);
  printf("Cor: %s\n",vet.cor);
}//fim Imprimir

void Alterar(Car vet[], int tam){
  int op, achou=0;
  char pesq[8];
  
  system("cls");
  printf("Pesquise uma Placa: ");
  fflush(stdin);
  gets(pesq);
  
  for(int i=0; i<tam; i++){
  	if(strcmp(pesq,vet[i].placa)==0){
	  achou=1;
	  do{
  	system("cls");
  	printf("Alterar Carro %i\n",i+1);
  	printf("1-Placa\n");
  	printf("2-Modelo\n");
  	printf("3-Cor\n");
  	printf("0-Voltar\n");
  	scanf("%i",&op);
  	
  	switch(op){
  	  case 1:
  	  	printf("\nDigite nova Placa: ");
  	  	fflush(stdin);
  	  	gets(vet[i].placa);
		break;
	
	  case 2:
  	  	printf("\nDigite novo Modelo: ");
  	  	fflush(stdin);
  	  	gets(vet[i].modelo);
		break;
	
	  case 3:
  	  	printf("\nDigite nova Cor: ");
  	  	fflush(stdin);
  	  	gets(vet[i].cor);
		break;
	
	  case 0:
	  	printf("\nValtando ao Menu Inicial\n");
		break;
	
	  default:
	    printf("\nOpcao Invalida\n");					
	  }//fim switch case
  	
  	system("pause");
  }while(op!=0);
	  
	  }//fim if pesq

  }//fim for
  
  if(achou=0){
  	printf("\nPlaca Nao Encontrada\n");
  }//fim if achou
  else{
    system("cls");
  	printf("\nAlteracao Concluida\n");
    system("pause");
  	
  }//fim else
  system("pause");
}//fim Alterar
