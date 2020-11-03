#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//FRANCISCO RIPARDO 1906458

//declarando procedimetos
void Cadastrar(int *p);
void Pesquisar(int *p, int *q, int *r);
void Exibir(int x);
void Alterar(int *p);
void Excluir(int *p);
main(){
int a, b, c,op;

	do{
	
	printf("1-Cadastrar\n");
	printf("2-Pesquisar\n");
	printf("0-Sair\n");
	
	scanf("%i",&op);
	switch(op){
		case 1:
	Cadastrar(&a);
	Cadastrar(&b);
	Cadastrar(&c);
			break;
		case 2:
			Pesquisar(&a,&b,&c);
			break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");			
	}//fim
	}while(op!=0);
	
}//fim main

void Pesquisar(int *p, int *q, int *r){
int n, m;
 printf("\nProcure um Numero: ");
 scanf("%i",&n);
 if(*p==n){
 	do{
 	printf("1-Exibir\n");
	printf("2-Alterar\n");
	printf("3-Excluir\n");
	printf("0-Sair\n");
 	 scanf("%i",&m);
	switch(m){
		case 1:
		Exibir(*p);
			break;
		case 2:
		Alterar(p);
			break;
		case 3:
		Excluir(p);
			break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");			
	}//fim switch case 
	}while(m!=0);
 }//fim if p
 
 if(*q==n){
 	do{
 	printf("1-Exibir\n");
	printf("2-Alterar\n");
	printf("3-Excluir\n");
	printf("0-Sair\n");
 	 scanf("%i",&m);
	switch(m){
		case 1:
		Exibir(*q);
			break;
		case 2:
		Alterar(q);
			break;
		case 3:
		Excluir(q);
			break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");			
	}//fim switch case 
	}while(m!=0);
 }//fim if q
 
 if(*r==n){
 	do{
 	printf("1-Exibir\n");
	printf("2-Alterar\n");
	printf("3-Excluir\n");
	printf("0-Sair\n");
 	 scanf("%i",&m);
	switch(m){
		case 1:
		Exibir(*r);
			break;
		case 2:
		Alterar(r);
			break;
		case 3:
		Excluir(r);
			break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");			
	}//fim switch case 
	}while(m!=0);
 }//fim if r
 
}//fim Pesquisar

void Exibir(int x){
	printf("Valor:%i \n",x);
}

void Alterar(int *p){
int aux;

printf("Digite O novo valor: ");
scanf("%i",&aux);	
*p=aux;	
}//fim Alterar

void Excluir(int *p){
*p=0;
printf("Valor Excluido");	
}//fim Excluir;

void Cadastrar(int *p){
int x ;

printf("\nDigite o valor: ");
scanf("%i",&x);	
*p=x;	
}//fim Cadastrar
