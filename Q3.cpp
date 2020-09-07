#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//FRANCISCO RIPARDO 1906458 ADS 4ª PERíODO NOTURNO
typedef struct Municipio{
	char nome[20];
	int quantHab;
}Municipio;//FIM Municipio

typedef struct Estado{
	char nome[20];
	char UF[2];
	int quantHab;
	Municipio mun[5];
}Estado;//FIM Estado

//Declarando variavel Global
Estado est[3];

//Declarando Procedimentos
void CadastrarEst();
void PesquisarUF();
void PesquisarMun();
void ImprimirMenu();

main(){//Inicio main
	ImprimirMenu();
	system("pause");
}//FIM main

void CadastrarEst(){//Inicio CadastrarEst
int i,j;
for(i=0;i<3;i++){//Inicio For i
system("cls");
printf("Cadastrand Estado %i",i+1);
printf("\nDigite Nome do Estado: ");
fflush(stdin);
gets(est[i].nome);
printf("\nDigite a Unidade Federativa: ");
fflush(stdin);
gets(est[i].UF);
est[i].quantHab=0;
for(j=0;j<5;j++){//Inicio For j
printf("\nMunicipio: %i",j+1);
printf("\nDigite Nome do Municipio: ");
fflush(stdin);
gets(est[i].mun[j].nome);
printf("\nDigite a Quantidade de Habitantes do Municipio: ");
scanf("%d",&est[i].mun[j].quantHab);
est[i].quantHab= est[i].quantHab + est[i].mun[j].quantHab;
}//Fim For j
Sleep(1000);
}//Fim For i
}//FIM CadastrarEst

void PesquisarUF(){//Inicio PesquisarUF
	int i,j;
	char uf[2];
system("cls");
printf("\nPesquise o Estado ou a Unidade Federativa: ");
fflush(stdin);
gets(uf);
for(i=0;i<3;i++){//Inicio For i
	if(strcmp(uf,est[i].UF)==0||strcmp(uf,est[i].nome)==0){//Inicio IF
		system("cls");	
		printf("\nNome do Estado: %s",est[i].nome);
		printf("\nUnidade Federativa: %s",est[i].UF);
		for(j=0;j<5;j++){//Inicio For j
			printf("\nMunicipio: %i",j+1);
			printf("\nNome do Municipio: %s",est[i].mun[j].nome);
			printf("\nQuantidade de Habitantes do Municipio: %d",est[i].mun[j].quantHab);
		}//Fim For j
		printf("\nQuantidade de Habitantes do Estado: %d",est[i].quantHab);
		Sleep(5000);
	}//Fim IF
}//Fim For i
}//FIM PesquisarUF

void PesquisarMun(){//Inicio PesquisarMun
	int i,j;
	char MUN[20];
	system("cls");
	printf("\nPesquise o Nome o Municipio: ");
	fflush(stdin);
	gets(MUN);
	for(i=0;i<3;i++){//Inicio For i
		for(j=0;j<5;j++){//Inicio For j	
		if(strcmp(MUN,est[i].mun[j].nome)==0){//Inicio IF
		system("cls");	
		printf("\nNome do Municipio: %s",est[i].mun[j].nome);
		printf("\nQuantidade de Habitantes do Municipio: %d",est[i].mun[j].quantHab);
		printf("\nNome do Estado: %s",est[i].nome);
		printf("\nUnidade Federativa: %s",est[i].UF);
		printf("\nQuantidade de Habitantes do Estado: %d",est[i].quantHab);
		Sleep(5000);	
		}//Fim IF
		}//Fim For j
}//Fim For i
}//FIM PesquisarMun

void ImprimirMenu(){
int m;
do{ //Inicio Do While
system("cls");
	printf("Escolha o que deseja: ");
	printf("\n1-Cadastrar Estado ");
	printf("\n2-Pesquisar por Estado ou UF");
	printf("\n3-Pesquisar por Municipio");
	printf("\n0-Sair\n");
	scanf("%i",&m);

	switch(m){//Inicio Switch Case menu
	case 1: //Inicio Case menu=1
	CadastrarEst();
	break;//Fim Case menu=1
	
	case 2: //Inicio Case menu=2
	PesquisarUF();
	break;//Fim Case menu=2
	
	case 3: //Inicio Case menu=3
	PesquisarMun();
	break;//Fim Case menu=3
	
	case 0: //Inicio Case menu=0
	printf("\nSaindo...");
	break;//Fim Case menu=0
	
	default://Inicio Case menu Default
		printf("\nOpcao Invalda");
		Sleep(2000);//Fim Case menu Default
	}//Fim Switch Case menu
}while(m!=0);//FIM Do While
} //FIM ImprimirMenu
