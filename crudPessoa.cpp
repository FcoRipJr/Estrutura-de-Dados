#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

//decrarando Registro
typedef struct Pessoa{
  char nome[10];
  int cpf;
  int rg;       
}Pessoa;

//decrarando Procedimentos
void Cadastrar(Pessoa vet[], int tam, int *p);
void Pesquisar(Pessoa vet[], int tam);
void Alterar(Pessoa vet[], int tam,int *p);
void Excluir(Pessoa vet[], int tam,int *p);
void Exibir(Pessoa vet[], int tam);
void Menu();

main(){
 Pessoa pe[MAX];
 int i=0, cont=0, j, m;   
    do{
     Menu();   
     scanf("%i",&m);  
  
        switch(m){
         case 1:
            Cadastrar(pe,MAX,&cont);
              break;
         case 2:
            Exibir(pe,cont);
              break;
         case 3:
            Alterar(pe,cont,&cont);
              break;
         case 4:
            Excluir(pe,cont,&cont);
              break;
           case 5:
            Pesquisar(pe,cont);
              break;
         case 0:
            exit(0);
              break;  
        default:
            printf("\nOpcao Invalida");
        }//fim switch case
              
    }while(m!=0);
    
    
}//fim main

// Procedimentos
void Cadastrar(Pessoa vet[], int tam,int *p){
  int cont, op;
    cont=*p;
    
do{
if(cont<tam){
  printf("\\nCadastrando Pessoa %i\n",cont+1);
    printf("\nNome: ");
	fflush(stdin);
	gets(vet[cont].nome);
    printf("\nCPF: ");
	scanf("%i",&vet[cont].cpf);
    printf("\nRG: ");
	scanf("%i",&vet[cont].rg);
   
   printf("\nCadastro com Sucesso");                 
   cont++;
   *p=cont;        
   printf("\nDigite qualquer numero para continuar cadastrando ou 0 pra sair: ");
   scanf("%i",&op);         
} //fim if
else{
  printf("Numero maximo de pessoas Cadastradas ");
  op=0;
              }//fim else
}while(op!=0);    
    system("pause");
}//fim Cadastrar

void Exibir(Pessoa vet[], int tam){
    system("cls");
    printf("Lista de Pessoas:\n");
	for(int i=0;i<tam;i++){
    printf("\nPessoa %i",i+1);
    printf("Nome: %s\n",vet[i].nome);
    printf("CPF: %i\n",vet[i].cpf);
    printf("RG: %i\n",vet[i].rg);
	}//fim for
    printf("\nFim da Lista\n");
	system("pause");
}//fim Exibir

void Alterar(Pessoa vet[], int tam,int *p){
 int pesq, achou=0;
 system("cls");
 printf("Pesquise um CPF pa Alterar: ");
 scanf("%i",&pesq);
 for(int i=0;i<tam;i++){
 if(pesq==vet[i].cpf){
  printf("\nAlterando Pessoa %i\n",i+1);
  printf("\nDigite os novos ");
  printf("\nNome: ");
	fflush(stdin);
	gets(vet[i].nome);
    printf("\nCPF: ");
	scanf("%i",&vet[i].cpf);
    printf("\nRG: ");
	scanf("%i",&vet[i].rg);
   achou=1;
   printf("\nAlterado com Sucesso");
 }//fim if
 }//fim for
 if(achou=0){
 	printf("\nCPF nao encontrado\n");
 }//fim if achou
 system("pause");    
}//fim Alterar

void Excluir(Pessoa vet[], int tam,int *p){
     int pesq, cont, op, achou=0;
 cont=*p;
 system("cls");
 
 printf("Pesquise um RG pa Excluir: ");
 scanf("%i",&pesq);
 for(int i=0;i<tam;i++){
 if(pesq==vet[i].rg){
 	 achou=1;
 	printf("\nExcluir Pessoa %i? ",i+1);
 	printf("\n1-SIM");
 	printf("\n2-NAO\n");
 	scanf("%i",&op);
 	 switch(op){
 	 	case 1:
 	 	strcpy(vet[i].nome,"");	
    	vet[i].cpf=0;
    	vet[i].rg=0;
		
		cont=cont-1;
		*p=cont;	 	
   		printf("\nPessoa %i Excluida com Sucesso",i+1);
 	 		break;
 	 	case 2:
		  printf("\nPessoa %i NAO excluida \n",i+1);	
 	 		
 	 		break;
 	 	default:
		  printf("\nopcao invalida\n");	
	  }//fim switch case
 }//fim if
 }//fim for
 if(achou=0){
 	printf("\nRG nao encontrado\n");
 }//fim if achou
 system("pause"); 
}//fim Excluir

void Pesquisar(Pessoa vet[], int tam){
   char pesq[10];
   int achou=0;
 system("cls");
 printf("Pesquise um Nome: ");
 fflush(stdin);
 gets(pesq);
 for(int i=0;i<tam;i++){
   if(strcmp(pesq,vet[i].nome)==0){
    achou=1;
    printf("\nPessoa %i",i+1);
    printf("Nome: %s\n",vet[i].nome);
    printf("CPF: %i\n",vet[i].cpf);
    printf("RG: %i\n",vet[i].rg);
 }//fim if
 
}//fim for

 if(achou=0){
 	printf("\nNome nao encontrado\n");
 }//fim if achou
 
 system("pause");       
}//fim Pesquisar


void Menu(){
  system("cls");
  printf("Escolha o que fazer: \n");
  printf("1-Cadastrar\n");
  printf("2-Exibir\n");
  printf("3-Alterar\n");
  printf("4-Excluir\n");
  printf("5-Pesquisar\n");
  printf("0-Sair\n");
    
}//fim Menu
