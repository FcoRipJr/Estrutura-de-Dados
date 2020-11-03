#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//FRANCISCO RIPARDO 1906458

//declarando Registro
typedef struct Pessoa{
 char nome[10];
 int cpf;
 int nasc;
 int idade;
}Pessoa;

//declarando procedimetos
void Cadastrar(Pessoa *p);
void Iprimir(Pessoa x);
void Pesquisar(Pessoa *p);
void Alterar(Pessoa *p);
void Excluir(Pessoa *p);

main(){
	Pessoa a;
int m;
	do{
	printf("1-Cadastrar\n");
	printf("2-Pesquisar\n");
	printf("0-Sair\n");		
		scanf("%i",&m);
	 switch(m){
		case 1:
	Cadastrar(&a);
		  break;
		case 2:
	Pesquisar (&a);		
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

void Pesquisar(Pessoa *p){
int n, m;
 printf("\nProcure um CPF: ");
 scanf("%i",&n);
 if(n==*p.cpf){
 	do{
 	printf("1-Exibir\n");
	printf("2-Alterar\n");
	printf("3-Excluir\n");
	printf("0-Sair\n");
 	 scanf("%i",&m);
	switch(m){
		case 1:
		Imprimir(*p);
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
 }//fim if 
 
}//fim Pesquisar

void Imprimir(Pessoa x){
	printf("\nNome: %s\n",x.nome);
	printf("\nCPF: %i\n",x.cpf);
	printf("\nAno Nascimento: %i\n",x.nasc);
	printf("\nIdade: %i\n",x.idade);
}//fim Imprimir

void Cadastrar(Pessoa *p){
Pessoa a;
int ano;	
	printf("\n##Pessoa ##\n ");
	 printf("\nNome: ");
	 fflush(stdin);
	 gets(a.nome);
	 printf("\nCPF: ");
	 scanf("%i",&a.cpf);
	 printf("\nAno Nascimento: ");
	 scanf("%i",&a.nasc);
	 printf("\nAno atual: ");
	 scanf("%i",&ano);
	 a.idade=ano-a.nasc
strcpy(*p.nome,a.nome);
*p.cpf=a.cpf;
*p.nasc=a.nasc;	 
*p.idade=a.idade;
	
}//fim Cadastrar

void Alterar(Pessoa *p){
Pessoa a;	
	printf("\n##Informe os novos: ##\n ");
	 printf("\nNome: ");
	 fflush(stdin);
	 gets(a.nome);
	 printf("\nCPF: ");
	 scanf("%i",&a.cpf);
	 printf("\nAno Nascimento: ");
	 scanf("%i",&a.nasc);
strcpy(*p.nome,a.nome);
*p.cpf=a.cpf;
*p.nasc=a.nasc;	 
}//fim Alterar

void Excluir(Pessoa *p){
strcpy(*p.nome,"");
*p.cpf=0;
*p.nasc=0;
*p.idade=0;
printf("Pessoa Excluido");	
}//fim Excluir;
