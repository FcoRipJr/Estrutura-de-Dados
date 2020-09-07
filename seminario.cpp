#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcpy
#include<windows.h>//Sleep
//FRANCISCO RIPARDO 1906458
typedef struct filme{
	char titulo[50];
	int anoLancamento;
	int duracao;
	char produtora[50];
	int* pont;
};

void imprimirMenu(){
	printf("\nESCOLHA O QU DESEJA FAZER\n\n");
	printf("\n1-CADASTRAR FILME");
	printf("\n2-EXIBIR FILMES CADASTRADOS");
	printf("\n3-EXIBIR PRECOS DE LOCACAO");
	printf("\n4-SOLICITAR LOCACAO");
	printf("\n5-REALIZAR BACKUP DE TITULOS");
	printf("\n0-SAIR\n");			
}

void imprimirPrecos(){
	printf("\nO PRECO DO ALUGUEL CUSTA:\n");
	printf("\nAte 3 dias:R$5.00 por dia  ");
	printf("\nAte 5 dias:R$4.50 por dia  ");
	printf("\nAte 7 dias:R$4.00 por dia  ");
	printf("\nAte 10 dias:R$3.50 por dia  ");
	printf("\nAte 15 dias:R$3.00 por dia  ");
	printf("\nAte 30 dias:R$2.50 por dia  ");
	printf("\nMais de 30 dias:R$2.00 por dia  \n");
}

float calcularValorAlugel( int quant){
	float  precoLocacao, valor;	
	
	if(quant<=3){
		valor=5;}
	else if(quant<=5){
		valor=4,5;}		
	else if(quant<=7){
		valor=4;}
	else if(quant<=10){
		valor=3,5;}
	else if(quant<=15){
		valor=3;}
	else if(quant<=30){
		valor=2,5;}	
	else{
		valor=2;}							
	
	precoLocacao=quant*valor;
	printf("\nPRECO DE LOCACAO: $%.2f\n",precoLocacao);
	return precoLocacao;
	}

struct filme filme[3];
	
main(){
	int quantDias, i, j=1, cont=0, menu;
	char vetorTitulo[50][3];
	printf("\nBEM VINDO A LOCADORA\n\n");
	Sleep(2000);
	do{
		system("cls");
		i=0;
		imprimirMenu();
		scanf("%d",&menu);
		Sleep(2000);
	switch(menu){
		case 1:  
			while(j!=0){
			system("cls");
				printf("\nCADASTRANDO...\n\n");
				printf("\nDIGITE O TITULO DO FILME:");
				scanf("%s",&filme[i].titulo);
				printf("\nDIGITE O ANO DE LANCAMENTO DO FILME:");
				scanf("%d",&filme[i].anoLancamento);
				printf("\nDIGITE A DURACAO DO FILME(EM MINUTOS):");
				scanf("%d",&filme[i].duracao);
				printf("\nDIGITE A PRODUTORA DO FILME:");
				scanf("%s",&filme[i].produtora);
				filme[i].pont=&filme[i].anoLancamento;
			i++;
				printf("\n\nCADASTRO COM SUCESSO");	
			cont++;
			Sleep(1500);
				printf("\nDIGITE 0 PARA PARAR ");
				scanf("%d",&j);
			Sleep(2000);	
		}
		break;
		
		case 2:  
		system("cls");
			for(i=0;i<cont;i++){
				printf("\n\nNUMERO %d",i+1);
				printf("\nTITULO: %s",filme[i].titulo);
				printf("\nANO DE LANCAMENTO: %d",filme[i].anoLancamento);
				printf("\nDURACAO: %d",filme[i].duracao);
				printf("\nPRODUTORA: %s",filme[i].produtora);
				printf("\nENDRECO: %p",filme[i].pont);	
			}
		printf("\n\nFIM DA LISTA\n");
		Sleep(5000);
		break;
		
		case 3:
		system("cls");
		imprimirPrecos();
		Sleep(5000);
		break;
			
		case 4: 
		system("cls"); 
			printf("\nDIGITE QUANTOS DIAS DESEJA ALUGAR: ");
			scanf("%d",&quantDias);
				calcularValorAlugel(quantDias);
		Sleep(5000);
		break;
		
		case 5:  
		system("cls");
			printf("\nREALIZANDO BACKUP DOS TITULOS... ");
			for(i=0;i<cont;i++){
			strcpy(vetorTitulo[i],filme[i].titulo);
			}
		Sleep(3000);	
		system("cls");
			printf("\n..BACKUP REALIZADO COM SUCESSO...\n");
		Sleep(5000);	
		break;
	
		case 0: printf("SAINDO...");
		break;
		
		default: printf("\nOPCAO INVALIDA");		
		}
		
	}while(menu!=0);
	
}	
