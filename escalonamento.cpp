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
	
/* Escalonamento de alto n�vel (longo prazo): Chamado tamb�m de escalonamento de tarefas, 
determina quais tarefas passar�o a competir pelos recursos do sistema
Neste caso o sistema optou por iniciar a tarefa: 
EMISS�O DE SENHAS e posteriormente ATENDIMENTO
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
Escalonamento n�vel intermedi�rio (m�dio prazo): 
Corresponde � determina��o de quais processos existentes competir�o pelo uso 
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
 Escalonamento de baixo n�vel (curto prazo): 
 Estas tarefas s�o executadas pelo 'dispatcher', 
 usualmente uma rotina escrita diretamente em linguagem de m�quina 
 que se encontra permanentemente na mem�ria principal. 
*/
		printf("Nome do cliente: %s\n", cli[i].nome);
		printf("CPF do cliente: %i", cli[i].CPF);
		Sleep(2000);
		printf("\n\n\nATENDIMENTO FINALIZADO!");
		Sleep(2000);
	}		
}
/*   8) Escolha 3 Objetivos de escalonamento, fa�a um algoritmo que os represente.
No programa acima podemos visualizar:
	
	justo-> todos os clientes seriam atendidoss
	Ser previs�vel-> pois seria algo padr�o
	Balancear o uso de recursos-> pq ele trabalharia tanto com prioridade quanto comum!
*/
