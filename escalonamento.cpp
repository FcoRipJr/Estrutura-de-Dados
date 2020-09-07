#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct cliente{
	char nome[10];
	int CPF;
};

struct cliente cli[4];

main(){
	int senhaUnica[4],i, vez, p=0;
	
/* Escalonamento de alto nível (longo prazo): Chamado também de escalonamento de tarefas, 
determina quais tarefas passarão a competir pelos recursos do sistema
Neste caso o sistema optou por iniciar a tarefa: 
EMISSÃO DE SENHAS e posteriormente ATENDIMENTO
*/
	
	printf("\n\n###################################\n\n\n\n\n");
	printf("     I N I C I A L I Z A N D O\n\n\n");
	printf("     P R O G R A M A\n\n\n");
	printf("     ...\n\n\n\n\n");
	printf("#################################");
	Sleep(2000);
	
		for(i=0;i<4;i++){
			system("cls");
			printf("\n\n##################################\n\n");
			printf("    E M I T I N D O\n");
			printf("    S E N H A\n\n");
			printf("#############################");
			printf("\n\nINFORME O TIPO DE CLIENTE:\n\n");
			printf(" 1 - PREFERENCIAL\n");
			printf(" 2 - COMUM\n");
			scanf("%i",&vez);
			printf("Nome do cliente: \n");
			scanf("%s", &cli[i].nome);
			printf("CPF do cliente: \n");
			scanf("%i", &cli[i].CPF);
						
			switch(vez){
				case 1: 
					senhaUnica[i]=1;
				break;
				case 2:
					senhaUnica[i]=2;
				break;
			}
			
			printf("\n\nSENHA EMITIDA COM SUCESSO!");
			Sleep(1500);
		}
	
	/*
Escalonamento nível intermediário (médio prazo): 
Corresponde à determinação de quais processos existentes competirão pelo uso 
do processador
Neste caso o sistema escolheu utilizar por ordem de chegada!
	*/
	
	for (i=0;i<4;i++){
		system("cls");
		printf("\n\n###########################################\n\n");
		printf("   I N I C I A N D O\n");
		printf("   A T E N D I M E N T O \n\n");
		printf("########################################");
		printf("\n\nSENHA: 00%i\n\n", i+1);
		if (senhaUnica[i] == 1){
			printf("Senha Preferencial\n");
		} else{
			printf("Senha Comum\n");
		}
		
/*
 Escalonamento de baixo nível (curto prazo): 
 Estas tarefas são executadas pelo 'dispatcher', 
 usualmente uma rotina escrita diretamente em linguagem de máquina 
 que se encontra permanentemente na memória principal. 
*/
		printf("Nome do cliente: %s\n", cli[i].nome);
		printf("CPF do cliente: %i", cli[i].CPF);
		Sleep(2000);
		printf("\n\n\nATENDIMENTO FINALIZADO!");
		Sleep(2000);
	}		
}
/*   8) Escolha 3 Objetivos de escalonamento, faça um algoritmo que os represente.
No programa acima podemos visualizar:
	
	justo-> todos os clientes seriam atendidoss
	Ser previsível-> pois seria algo padrão
	Balancear o uso de recursos-> pq ele trabalharia tanto com prioridade quanto comum!
*/
