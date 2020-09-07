#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcpy
#include<windows.h>//Sleep
//FRANCISCO RIPARDO 1906458 ADS 4ª PERíODO NOTURNO
typedef struct Endereco{//dados do endereço:bairro, rua e casa
	char bairro[20];
	char rua[20];
	char casa[6];
}Endereco;

typedef struct Contato{//dados de contato nome, e-mail e telefone 
	char nome[20];
	char email[50];
	char telefone[20];
}Contato;

typedef struct Carro{
	char placa[8];
	char cor[10];
	char modelo[20];
	int quantidade;
	char status[1]; //Disponivel: D; Alugado: A 
	float valorDiaria;
}Carro;

typedef struct Funcionario{
	int matricula;
	char senha[3];
	Contato contato;
	Endereco endereco;
}Funcionario;

typedef struct Cliente{
	char CNH[10];
	Contato contato;
	Endereco endereco;
}Cliente;

void imprimirMenu(){//funçao para imprimir os itens do menu
	printf("\nESCOLHA O QU DESEJA FAZER\n\n");
	printf("\n1-CADASTRAR CARRO");
	printf("\n2-CADASTRAR FUNCIONARIO");
	printf("\n3-CADASTRAR CLIENTE");
	printf("\n4-REALIZAR ALUGUEL");
	printf("\n5-REALIZAR DEVOLUCAO DO CARRO");
	printf("\n6-EXIBIR CARROS CADASTRADOS");
	printf("\n7-EXIBIR CARROS ALUGADOS");
	printf("\n0-SAIR\n");			
}

main(){
	int  i, a, cont=0, menu;//i=indice do vetor, a=carro escolhio pel cliente, menu controla o menu
	char placaDevolvida[8];//placa que o clente informara para a devolucao
	int mat;// matricula para login
	char sen[3];//senha para login
	char cnh[10];//para cusca do cliente
	Carro carro[3];
	Funcionario funcionario[3];
	Cliente cliente[3];
	
	printf("\nBEM VINDO A LOCADORA\n\n");
	Sleep(2000);//esra o tempo inserido antes do programa avançar
	do{
		system("cls");// limpa a tela
		i=0;
		imprimirMenu();
		scanf("%i",&menu);//sala o valor inserido para variavel menu 
		Sleep(2000);
	switch(menu){// direciona o valor inserido no menu para a opção correspondente
		case 1://CADASTRAR CARRO 
		system("cls");
		printf("\nCADASTRANDO CARRO...\n\n");
		Sleep(1500);
		for(i=0;i<3;i++){
			system("cls");
			printf("\n\nCARRO: %i\n",i+1);
			printf("\nDIGITE O MODELO: ");
				fflush(stdin);
				gets(carro[i].modelo);
			printf("\nDIGITE A COR: ");
				fflush(stdin);
				gets(carro[i].cor);
			printf("DIGITE A PLACA: ");
				fflush(stdin);
				gets(carro[i].placa);
			printf("\nDIGITE A QUANTIDADE: ");
				scanf("%i",&carro[i].quantidade);
			printf("\nDIGITE O VALOR DA DIARIA: ");
				scanf("%f",&carro[i].valorDiaria);
			strcpy(carro[i].status, "D");
		 	printf("\n\nCADASTRO COM SUCESSO");
			 Sleep(1500);
			} 	
			break;
			
		case 2:// CADASTRO FUNCIONARIO
		system("cls"); 	
				printf("\nCADASTRANDO FUNCIONARIO...\n\n");
			for(i=0;i<3;i++){
				printf("\n\nFUNCIONARIO: %i\n",i+1);
				printf("\nDIGITE O NOME: ");
					fflush(stdin);
					gets(funcionario[i].contato.nome);
				printf("DIGITE A MATRICULA: ");
					scanf("%i",&funcionario[i].matricula);
				printf("DIGITE A SENHA: ");
					fflush(stdin);
					gets(funcionario[i].senha);
				printf("\nDIGITE O TELEFONE: ");
					fflush(stdin);
					gets(funcionario[i].contato.telefone);
				printf("\nDIGITE O E-MAIL: ");
					fflush(stdin);
					gets(funcionario[i].contato.email);
				printf("\nENDERECO: ");
				printf("\nDIGITE O BAIRRO: ");
					fflush(stdin);
					gets(funcionario[i].endereco.bairro);
				printf("\nDIGITE A RUA: ");
					fflush(stdin);
					gets(funcionario[i].endereco.rua);
				printf("\nDIGITE O NUMERO: ");
					fflush(stdin);
					gets(funcionario[i].endereco.rua);		
			printf("\n\nCADASTRO COM SUCESSO");	
			Sleep(1500);
			}
		break;
		
		case 3: // CADASTRO CLIENTE
		system("cls"); 	
			printf("\nCADASTRANDO CLIENTE...\n\n");
			for(i=0;i<3;i++){
				printf("\n\nCLIENTE: %i\n",i+1);
				printf("\nDIGITE O NOME: ");
					fflush(stdin);
					gets(cliente[i].contato.nome);
				printf("\nDIGITE O CNH: ");
					fflush(stdin);
					gets(cliente[i].CNH);
				printf("\nDIGITE O TELEFONE: ");
					fflush(stdin);
					gets(cliente[i].contato.telefone);
				printf("\nDIGITE O E-MAIL: ");
					fflush(stdin);
					gets(cliente[i].contato.email);
				printf("\nENDERECO: ");
				printf("\nDIGITE O BAIRRO: ");
					fflush(stdin);
					gets(cliente[i].endereco.bairro);
				printf("\nDIGITE A RUA: ");
					fflush(stdin);
					gets(cliente[i].endereco.rua);
				printf("\nDIGITE O NUMERO: ");
					fflush(stdin);
					gets(cliente[i].endereco.rua);		
			printf("\n\nCADASTRO COM SUCESSO");	
			Sleep(1500);
			}
		break;

		case 4:// REALIZAR ALUGUEL
		system("cls");
		printf("INFORME O NUMERO DA MATRICULA: ");
		scanf("%i",&mat);
		printf("\n INFORME A SENHA: ");
		fflush(stdin);
		gets(sen);
		for(i=0;i<3;i++){//login do funcionario
			if((mat=funcionario[i].matricula)&&(strcmp(sen,funcionario[i].senha)==0)){	
				system("cls");
				printf("\nLOGIN REALIZADO COM SUCESSO");
				Sleep(2000);
			}
		}
		system("cls");
		printf("INFORME O CNH DO CLIENTE: ");
		fflush(stdin);
		gets(cnh);
		Sleep(2000);
		for(i=0;i<3;i++){
			if(strcmp(cnh,cliente[i].CNH)==0){//busca o ciente pelo CNH
			system("cls");	
			printf("CLIENTE ENCONTRADO");
			Sleep(2000);
			}
		}
			printf("CARROS DISPONIVEIS\n");
			for(i=0;i<3;i++){
				if(strcmp(carro[i].status, "D")==0){
				printf("\n\n CARRO: %i\n",i+1);	
				printf("MODELO: %s \n",carro[i].modelo);
				printf("COR: %s \n",carro[i].cor);
				printf("PLACA: %s \n",carro[i].placa);
				printf("QUANTIDADE: %i \n",carro[i].quantidade);
				printf("VALOR DA DIARIA: R$%.2f \n",carro[i].valorDiaria);
				printf("STATUS: %s\n\n",carro[i].status);
				}			
			} 	
		printf("\n\nFIM DA LISTA\n");
		printf("DIGITE O NUMERO D CARRO QUE DESEJA ALUGAR: ");
		scanf("%i",&a);
			switch(a){//submenu para escolha do carro para aluguel
				case 1:
					strcpy(carro[0].status,"A");
					Sleep(3000);
				break;
				case 2:
					strcpy(carro[1].status,"A");
					Sleep(3000);
				break;
				case 3:
					strcpy(carro[2].status,"A");
					Sleep(3000);				
				break;
				defaut: printf("\nOPCAO INVALIDA");		
				Sleep(2000);
			}
		Sleep(3000);	
		system("cls");
			printf("\n..ALUGUEL REALIZADO COM SUCESSO...\n");
		Sleep(5000);
		break;
		
		case 5:// REALIZAR DEVOLUCAO DO CARRO
		system("cls"); 
		printf("DIGITE A PLACA DO CARRO QUE DESEJA DEVOLVER: ");
		fflush(stdin);
		gets(placaDevolvida);
			for(i=0;i<3;i++){
				if(strcmp(placaDevolvida,carro[i].placa)==0){
				strcpy(carro[i].status,"D");
				}		
			}
		Sleep(3000);	
		system("cls");
			printf("\n..DEVOLUCAO REALIZADA COM SUCESSO...\n");
		Sleep(5000);
		break;
		
		case 6: //EXIBIR CARROS CADASTRADOS
		system("cls");
		printf("CARROS CADASTRADOS\n");
			for(i=0;i<3;i++){
				printf("\n MODELO: %s \n",carro[i].modelo);
				printf("COR: %s \n",carro[i].cor);
				printf("PLACA: %s \n",carro[i].placa);
				printf("QUANTIDADE: %i \n",carro[i].quantidade);
				printf("VALOR DA DIARIA: R$%.2f \n",carro[i].valorDiaria);
				printf("STATUS: %s\n\n",carro[i].status);
			} 	
		printf("\n\nFIM DA LISTA\n");
		Sleep(5000);
		break;
		
		case 7: //EXIBIR CARROS ALUGADOS
		system("cls");
		printf("CARROS ALUGADOS\n");
			for(i=0;i<3;i++){
				if(strcmp(carro[i].status,"A")==0){
				printf("\nMODELO: %s \n",carro[i].modelo);
				printf("COR: %s \n",carro[i].cor);
				printf("PLACA: %s \n",carro[i].placa);
				printf("QUANTIDADE: %i \n",carro[i].quantidade);
				printf("VALOR DA DIARIA: R$%.2f \n",carro[i].valorDiaria);
				printf("STATUS: %s\n\n",carro[i].status);
				}			
			} 	
		printf("\n\nFIM DA LISTA\n");
		Sleep(5000);
		break;
		
		case 0: printf("SAINDO...");//ao inserir 0 no menu se enserará o processo de repetiçao do menu
		break;
		
		default: printf("\nOPCAO INVALIDA");		
		Sleep(2000);
		}
	}while(menu!=0);
	system("pause");	
}
