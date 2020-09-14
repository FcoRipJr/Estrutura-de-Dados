#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//FRANCISCO RIPARDO 1906458 ADS 4ª PERíODO NOTURNO

typedef struct Funcionario{
	char nome[10];
	int mat;
}Funcionario;

typedef struct Produto{
	char nome[10];
	char status[2];
	int quant;
	int quantVend;
	float valor;
}Produto;

//Declarando variavel Global
int senhaDono=123;
Funcionario func[2];
Produto prod[2];

//Declarando Procedimentos
void Login();
void MenuDono();
void MenuFunc();
void CadFunc();
void CadProd();
void Vender();
void GerarRelatorio();

main(){
	Login();
}//Fim da main

void Login(){
int senha;
int log;

do{
	system("cls");
	log=0;
	printf("Digite a senha ou sua matricula: ");
	scanf("%i",&senha);
	
	if(senha==senhaDono){
		log=1;
		MenuDono();
	}//fim comparação senhaDono
    
    for(int p=0;p<2;p++){
	 if(senha==func[p].mat){
	 	log=1;
		MenuFunc();
	 }//fim comparacao matricula
	}//fim for p
}while(log!=0);//fim do while
printf("senha ou matricula Inexistente ");
printf("\nEncerrando sistema... ");
	
	
}// fim Login

void MenuDono(){
int m;
system("cls");
printf("Bem vindo Dono ");
Sleep(1000);	
do{ //Inicio Do While
  system("cls");
  printf("Escolha o que deseja: ");
  printf("\n1-Cadastrar Funcionario ");
  printf("\n2-Cadastrar Produto ");
  printf("\n3-Gerar Relatorio ");
  printf("\n0-Sair\n");
  scanf("%i",&m);

  switch(m){//Inicio Switch Case menu
	case 1: //Inicio Case menu=1
		CadFunc();
	break;//Fim Case menu=1
	
	case 2: //Inicio Case menu=2
		CadProd();
	break;//Fim Case menu=2
	
	case 3: //Inicio Case menu=3
		GerarRelatorio();
	break;//Fim Case menu=3
	
	case 0: //Inicio Case menu=0
	printf("\nSaindo...");
	break;//Fim Case menu=0
	
	default://Inicio Case menu Default
		printf("\nOpcao Invalda");
		Sleep(2000);//Fim Case menu Default
	}//Fim Switch Case menu
  }while(m!=0);//FIM Do While
} //FIM MenuDono

void MenuFunc(){
int m;
system("cls");
printf("Bem vindo Funcionario ");
Sleep(1000);	
do{ //Inicio Do While
  system("cls");
  printf("Escolha o que deseja: ");
  printf("\n1-Realizar Venda ");
  printf("\n0-Sair\n");
  scanf("%i",&m);

  switch(m){//Inicio Switch Case menu
	case 1: //Inicio Case menu=1
		Vender();
	break;//Fim Case menu=1
	
	case 0: //Inicio Case menu=0
	printf("\nSaindo...");
	break;//Fim Case menu=0
	
	default://Inicio Case menu Default
		printf("\nOpcao Invalda");
		Sleep(2000);//Fim Case menu Default
	}//Fim Switch Case menu
  }while(m!=0);//FIM Do While
} //FIM MenuFunc

void CadFunc(){
	system("cls");
	printf("cadastrando funcionario...\n\n");
	Sleep(1000);
	for(int f=0;f<2;f++){
	  system("cls");
	  printf("Funcionario %i",f+1);
	  printf("\nDigite o nome: ");
	  fflush(stdin);
	  gets(func[f].nome);
	  printf("\nDigite a matricula: ");
	  scanf("%i",&func[f].mat);
	  printf("\n\nCadastro com sucesso");
	  Sleep(1000);
	}//fim for f
	system("cls");
	printf("Finalizando cadastro de funcionarios...\n\n");
	Sleep(1000);
}//fim CadFunc;

void CadProd(){
	system("cls");
	printf("cadastrando produto...\n\n");
	Sleep(1000);
	for(int p=0;p<2;p++){
	  system("cls");
	  printf("Produto %i",p+1);
	  printf("\nDigite o nome: ");
	  fflush(stdin);
	  gets(prod[p].nome);
	  printf("\nDigite o valor: ");
	  scanf("%f",&prod[p].valor);
	  printf("\nDigite a quantidade: ");
	  scanf("%i",&prod[p].quant);
	  strcpy(prod[p].status,"D");
	}//fim for p
	system("cls");
	printf("Finalizando cadastro de produtos...\n\n");
	Sleep(1000);
}//fim CadProd;

void Vender(){
  int p, s, quant;
  float precoT, recebido, troco;
  system("cls");
  printf("Iniciando Venda...");
  Sleep(1000);
  do{
	printf("lista de produtos:\n");
	  for(p=0;p<2;p++){
		printf("\nProduto %i",p+1);
	    printf("\nNome: %s",prod[p].nome);
	    printf("\nValor: R$%.2f",prod[p].valor);
	    printf("\nQuantidade: %i\n",prod[p].quant);
	}//fim for p	
	printf("\nInforme o numero do produto que deseja ou 0 para Sair: ");
	scanf("%i",&s);
	p=s-1;
	printf("\nInforme a quantidade que deseja: ");
	scanf("%i",&quant);
	prod[p].quant= prod[p].quant-quant;
	prod[p].quantVend=prod[p].quantVend+quant;
	strcpy(prod[p].status,"V");
	precoT=quant*prod[p].valor;
	printf("\nPreco Total: $%.2f",precoT);
	printf("\nInforme o valor recebido: ");
	scanf("%f",&recebido);
	troco=recebido-precoT;
	printf("\nValor do troco: $%.2f",troco);
	Sleep(2000);
	system("cls");
	printf("Venda concluida...");
	Sleep(2000);
}while(s!=0);

}//fim Vender

void GerarRelatorio(){
	system("cls");
	printf("Gerando relatorio de produtos vendidos...");
	Sleep(1000);
	for(int p=0;p<2;p++){
	  if(strcmp(prod[p].status,"D")!=0){
	  	system("cls");
		printf("Produto %i",p+1);
	    printf("\nNome: %s",prod[p].nome);
	    printf("\nValor: R$%.2f",prod[p].valor);
	    printf("\nQuantidade: %i",prod[p].quant);
	    printf("\nQuantidade Vendida: %i",prod[p].quantVend);
	    Sleep(5000);
	  }//fim comparacao de status
	}//fim for p
	system("cls");
	printf("Finalizando Relatorio...\n\n");
	Sleep(1000);

}//fim GerarRelatorio
