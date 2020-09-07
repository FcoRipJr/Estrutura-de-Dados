#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//FRANCISCO RIPARDO 1906458 ADS 4ª PERíODO NOTURNO
typedef struct Municipio{
	char nome[20];
	char estado[20];
	char UF[2];
	int quantHab;
}Municipio;//FIM Municipio

//Declarando variavel Global
Municipio mun[3];

//Declarando Procedimentos
void CadastrarMun();
void PesquisarMun();
void ImprimirMenu();

main(){
	ImprimirMenu();
	system("pause");
}//FIM main

void CadastrarMun(){//Inicio CadastrarMun
int i;
for(i=0;i<3;i++){//Inicio For
system("cls");
printf("Cadastrand Municipio %i",i+1);
printf("\nDigite Nome do Municipio: ");
fflush(stdin);
gets(mun[i].nome);
printf("\nDigite o Estado: ");
fflush(stdin);
gets(mun[i].estado);
printf("\nDigite a Unidade Federativa: ");
fflush(stdin);
gets(mun[i].UF);
printf("\nDigite a Quantidade de Habitantes: ");
scanf("%d",&mun[i].quantHab);
Sleep(3000);
}//Fim For
}//FIM CadastrarMun

void PesquisarMun(){//Inicio PesquisarMun
	int i;
	char MUN[20];
system("cls");
printf("\nPesquise o Nome o Municipio: ");
fflush(stdin);
gets(MUN);
for(i=0;i<3;i++){//Inicio For
	if(strcmp(MUN,mun[i].nome)==0){//Inicio IF
		system("cls");	
		printf("\nNome do Municipio: %s",mun[i].nome);
		printf("\nEstado: %s",mun[i].estado);
		printf("\nUnidade Federativa: %s",mun[i].UF);
		printf("\nQuantidade de Habitantes: %d",mun[i].quantHab);
		Sleep(5000);
	}//Fim IF
}//Fim For
}//FIM PesquisarMun

void ImprimirMenu(){
int m;
do{ //Inicio Do While
system("cls");
	printf("Escolha o que deseja: ");
	printf("\n1-Cadastrar Municipio ");
	printf("\n2-Pesquisar Municipio");
	printf("\n0-Sair\n");
	scanf("%i",&m);

	switch(m){//Inicio Switch Case menu
	case 1: //Inicio Case menu=1
	CadastrarMun();
	break;//Fim Case menu=1
	
	case 2: //Inicio Case menu=2
	PesquisarMun();
	break;//Fim Case menu=2
	
	case 0: //Inicio Case menu=0
	printf("\nSaindo...");
	break;//Fim Case menu=0
	
	default://Inicio Case menu Default
		printf("\nOpcao Invalda");
		Sleep(2000);//Fim Case menu Default
	}//Fim Switch Case menu
}while(m!=0);//FIM Do While
} //FIM ImprimirMenu
