#include<stdio.h>
#include<stdlib.h>
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
void Cadastrar(Pessoa a, Pessoa b, Pessoa c);
void Iprimir(Pessoa x);
void Pesquisar(Pessoa x,Pessoa y,Pessoa z);

main(){
	Pessoa a;
	Pessoa b; 
	Pessoa c;
	Cadastrar(a,b,c);
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

void Pesquisar(Pessoa x,Pessoa y,Pessoa z){
int cpf;
printf("\nPesquise um CPF: ");
scanf("%i",&cpf);
if(cpf==x.cpf){
	Imprimir(x);
}//fim if x
if(cpf==y.cpf){
	Imprimir(y);
}//fim if y

if(cpf==z.cpf){
	Imprimir(z);
}//fim if z
else{
	printf("\nCPF nao encontrado");
}
}//fim Pesquisar

void Cadastrar(Pessoa a, Pessoa b, Pessoa c){
	printf("\n##Pessoa 1##\n ");
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
	
	printf("\n##Pessoa 2##\n ");
     printf("\nNome: ");
	 fflush(stdin);
	 gets(b.nome);
	 printf("\nCPF: ");
	 scanf("%i",&b.cpf);
	 printf("\nAno Nascimento: ");
 	 scanf("%i",&b.nasc);
	 printf("\nPeso: ");
	 scanf("%f",&b.peso);
	 printf("\nAltura: ");
	 scanf("%f",&b.alt);
	 b.imc=b.peso/(b.alt*b.alt);
	
	printf("\n##Pessoa 3##\n ");
	 printf("\nNome: ");
	 fflush(stdin);
	 gets(c.nome);
	 printf("\nCPF: ");
	 scanf("%i",&c.cpf);
	 printf("\nAno Nascimento: ");
	 scanf("%i",&c.nasc);
	 printf("\nPeso: ");
	 scanf("%f",&c.peso);
	 printf("\nAltura: ");
	 scanf("%f",&c.alt);
	 c.imc=c.peso/(c.alt*c.alt);

	Pesquisar(a,b,c);
	}//fim Cadastrar

