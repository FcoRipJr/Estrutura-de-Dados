#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//FRANCISCO RIPARDO 1906458

//declarando Registro
typedef struct Pessoa{
 char nome[10];
 int cpf;
 int nasc;
 float alt;
 float peso;
 float imc;
}Pessoa;

//declarando procedimetos
void Cadastrar(Pessoa *p);
void Iprimir(Pessoa x);
void Pesquisar(Pessoa p, Pessoa q, Pessoa r);

main(){
	Pessoa a;
	Pessoa b; 
	Pessoa c;
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

void Imprimir(Pessoa x){
	printf("\nNome: %s\n",x.nome);
	printf("\nCPF: %i\n",x.cpf);
	printf("\nAno Nascimento: %i\n",x.nasc);
	printf("\nPeso: %.1f\n",x.peso);
	printf("\nAltura: %.2f\n",x.alt);
	printf("\nIMC: %.2f\n",x.imc);
}//fim Imprimir

void Pesquisar(Pessoa p, Pessoa q, Pessoa r){
int cpf;
printf("\nPesquise um CPF: ");
scanf("%i",&cpf);
if(cpf==p.cpf){
	Imprimir(p);
}//fim if p
if(cpf==q.cpf){
	Imprimir(q);
}//fim if q

if(cpf==r.cpf){
	Imprimir(r);
}//fim if r
}//fim Pesquisar

void Cadastrar(Pessoa *p){
Pessoa a;	
	printf("\n##Pessoa ##\n ");
	 printf("\nNome: ");
	 fflush(stdin);
	 gets(a.nome);
	 printf("\nCPF: ");
	 scanf("%i",&a.cpf);
	 printf("\nAno Nascimento: ");
	 scanf("%i",&a.nasc);
	 printf("\nPeso: ");
	 scanf("%f",&a.peso);
	 printf("\nAltura: ");
	 scanf("%f",&a.alt);
	 a.imc=a.peso/(a.alt*a.alt);
strcpy(p->nome,a.nome);
p->cpf=a.cpf;
p->nasc=a.nasc;	 
p->alt=a.alt;
p->peso=a.peso;
p->imc=a.imc;	
	
	}//fim Cadastrar

