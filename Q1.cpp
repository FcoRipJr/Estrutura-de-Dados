#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//FRANCISCO RIPARDO 1906458 ADS 4ª PERíODO NOTURNO
typedef struct Estado{
	char nome[20];
	char UF[2];
	int quantHab;
}Estado;//FIM Estado

//Declarando variavel Global
Estado est[3];

//Declarando Procedimentos
void CadastrarEst();
void PesquisarUF();
void ImprimirMenu();

main(){//Inicio main
	ImprimirMenu();
	system("pause");
}//FIM main

void CadastrarEst(){//Inicio CadastrarEst
int i;
for(i=0;i<3;i++){//Inicio For
system("cls");
printf("Cadastrand Estado %i",i+1);
printf("\nDigite Nome do Estado: ");
fflush(stdin);
gets(est[i].nome);
printf("\nDigite a Unidade Federativa: ");
fflush(stdin);
gets(est[i].UF);
printf("\nDigite a Quantidade de Habitantes: ");
scanf("%d",&est[i].quantHab);
Sleep(1000);
}//Fim For
}//FIM CadastrarEst

void PesquisarUF(){//Inicio PesquisarUF
	int i;
	char uf[2];
system("cls");
printf("\nPesquise a Unidade Federativa: ");
fflush(stdin);
gets(uf);
for(i=0;i<3;i++){//Inicio For
	if(strcmp(uf,est[i].UF)==0){//Inicio IF
		system("cls");	
		printf("\nNome do Estado: %s",est[i].nome);
		printf("\nUnidade Federativa: %s",est[i].UF);
		printf("\nQuantidade de Habitantes: %d",est[i].quantHab);
		Sleep(5000);
	}//Fim IF
}//Fim For
}//FIM PesquisarUF

void ImprimirMenu(){
int m;
do{ //Inicio Do While
system("cls");
	printf("Escolha o que deseja: ");
	printf("\n1-Cadastrar Estado ");
	printf("\n2-Pesquisar Unidade Federativa");
	printf("\n0-Sair\n");
	scanf("%i",&m);

	switch(m){//Inicio Switch Case menu
	case 1: //Inicio Case menu=1
	CadastrarEst();
	break;//Fim Case menu=1
	
	case 2: //Inicio Case menu=2
	PesquisarUF();
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
