#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2
//FRANCISCO RIPARDO 1906458
//decrarando Registro
typedef struct Login{
  char user[10];
  char senha[10];
}Log;

typedef struct Paciente{
  char nome[10];
  int cpf;
  int telefone; 
  Log log;      
}Pac;

typedef struct Funcionario{
  char nome[10];
  int mat;
  Log log; 
}Fun;

typedef struct Especialidade{
  char nome[10];
  int codigo;
}Esp;

typedef struct Medico{
  int crm;
  Esp esp;
  Fun fun;	
}Med;

//decrarando Procedimentos/Funcoes
void MenuAdm();

void MenuAdmEsp(Esp e[],int t);
void CadEsp(Esp e[],int t);
void AltEsp(Esp e[],int t);
Esp PesqEsp(Esp e[],int t);
void ExcEsp(Esp e[],int t);
void ImpEsp(Esp e[],int t);
void ExibEsp(Esp e);

void MenuAdmFun(Fun f[], int t);
void CadFun(Fun f[], int t);
void AltFun(Fun f[], int t);
Fun PesqFun(Fun f[], int t);
void ExcFun(Fun f[], int t);
void ImpFun(Fun f[], int t);
void ExibFun(Fun f);

void MenuAdmMed(Med med[], int t);
void CadMed(Med med[], int t);
void AltMed(Med med[], int t);
Med PesqMed(Med med[], int t);
void ExcMed(Med med[], int t);
void ImpMed(Med med[], int t);
void ExibMed(Med med);

void MenuFun(Pac p[], int t);
void CadPac(Pac p[], int t);
void AltPac(Pac p[], int t);
Pac PesqPac(Pac p[], int t);
void ExcPac(Pac p[], int t);
void ImpPac(Pac p[], int t);
void ExibPac(Pac p);

main(){
 Log adm;
  Pac pac[MAX];
  Fun fun[MAX];
  Esp esp[MAX];
  Med med[MAX];
  strcpy(adm.user,"adm");
  strcpy(adm.senha,"adm");
  int op, m, achou=0;
  char user[10], sen[10];
  do{
	system("cls");
	printf("Realise Login");
	printf("\nUsuario: ");
	fflush(stdin);
	gets(user);
	printf("\nSenha: ");
	fflush(stdin);
	gets(sen);
	
	if(strcmp(user,adm.user)==0&&strcmp(sen,adm.senha)==0){
	 achou=1;
	 do{
	 MenuAdm();
	 scanf("%i",&m);
	switch(m){
		case 1:
		MenuFun(pac,MAX);	
			break;
		case 2:
		MenuAdmFun(fun,MAX);	
			break;
		case 3:
		MenuAdmEsp(esp,MAX);	
			break;
		case 4:
		MenuAdmMed(med,MAX);	
			break;
		case 0:
		 printf("\nVoltando...\n");
			break;
		default:
		printf("\nOpcao Invalida\n");					
	}   //fim switch case
	 }while(m!=0);
		system("pause");
	}//fim if strcmp adm
	
	for(int i=0;i<MAX;i++){
	if(strcmp(user,fun[i].log.user)==0&&strcmp(sen,fun[i].log.senha)==0&&strcmp(user,"")!=0&&strcmp(sen,"")!=0){
	achou=1;
	 MenuFun(pac,MAX);
	
	}//fim if strcmp func
	}//fim for Func
	
	if(achou==0){
		printf("\nUsuario ou Senha Incorretas\n");
	}
	
	achou=0;
	printf("\nDigite qualquer numero para continuar ou '0' para Sair: ");
	scanf("%i",&op);
  }while(op!=0);
	
system("pause");
	
}//fim main

void MenuAdm(){
	system("cls");
  printf("##Menu ADM##");	
  printf("\n1-CRUD Paciente");	
  printf("\n2-CRUD Funcionario");	
  printf("\n3-CRUD Especialidade");	
  printf("\n4-CRUD Medico");	
  printf("\n0-Voltar\n");
  
}//fim MenuAdm


//CRUD ESPECIALIDADE
void MenuAdmEsp(Esp e[],int t){
  int m;
  do{
  system("cls");
  printf("##CRUD Especialidade##");	
  printf("\n1-Cadastrar Especialidade");	
  printf("\n2-Alterar Especialidade");	
  printf("\n3-Pesquisar Especialidade");	
  printf("\n4-Excluir Especialidade");	
    printf("\n5-Listar Especialidades");
  printf("\n0-Voltar\n");
  scanf("%i",&m);
	switch(m){
		case 1:
	     CadEsp(e,t);
			break;
		case 2:
		  AltEsp(e, t);
			break;
		case 3:
		 ExibEsp(PesqEsp(e,t));
			break;
		case 4:
		  ExcEsp(e, t);
			break;
		case 5:
		  ImpEsp(e, t);
			break;
		case 0:
		 printf("\nVoltando...\n");
			system("pause");	
			break;
		default:
		printf("\nOpcao Invalida\n");					
	}   //fim switch case	
  }while(m!=0);
  	system("pause");
}//fim MenuAdmEsp

void CadEsp(Esp e[],int t){
system("cls");
printf("Cadastrando \n");
for(int i=0;i<t;i++){
	printf("\nEspecialidade: %i",i+1);
	printf("\nNome: ");
	fflush(stdin);
	gets(e[i].nome);
	printf("\nCodigo: ");
	scanf("%i",&e[i].codigo);
	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim CadEsp

Esp PesqEsp(Esp e[],int t){
int cod, achou=0;
system("cls");
printf("Busque um Codigo: ");
scanf("%i",&cod);
for(int i=0;i<t;i++){
if(cod==e[i].codigo){
achou=1;
return e[i];
}//fim if cod
}//fim for


if(achou==0){
	printf("\nCodigo Nao Encontrado\n");
}//fim if Achou
achou=0;
system("pause");
}//fim PesqEsp

void ExibEsp(Esp e){
	printf("\nNome: %s",e.nome);
	printf("\nCodigo: %i\n\n",e.codigo);
system("pause");
}//fim ExibEsp

void AltEsp(Esp e[],int t){
int cod, op, achou=0;
system("cls");
printf("Busque um Codigo: ");
scanf("%i",&cod);
for(int i=0;i<t;i++){
if(cod==e[i].codigo){
achou=1;
 system("cls");
 printf("Alterar? ");
 printf("\n1-Nome"); 
 printf("\n2-Codigo"); 
 printf("\n0-Voltar\n");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	  printf("\nNovo Nome: ");
	fflush(stdin);
	gets(e[i].nome);
		break;
	 case 2:	
	printf("\nNovo Codigo: ");
	scanf("%i",&e[i].codigo);
   	  break;
   	case 0:
   		printf("\nVoltando...");
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case


}//fim if cod
}//fim for


if(achou==0){
	printf("\nCodigo Nao Encontrado\n");
}//fim if Achou
achou=0;
system("pause");

}//fim AltEsp

void ExcEsp(Esp e[],int t){
int cod, op, achou=0;
system("cls");
printf("Busque um Codigo: ");
scanf("%i",&cod);
for(int i=0;i<t;i++){
if(cod==e[i].codigo){
achou=1;
 system("cls");
 printf("Deseja Excluir Especialidade %i? ",i+1);
 printf("\n1-Sim"); 
 printf("\n0-Nao");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	    e[i].codigo=0;
		strcpy(e[i].nome,"");
   		printf("\nEspecialidade %i Excluido",i+1);
   	  break;
   	case 0:
   		printf("\nEspecialidade %i NAO Excluido",i+1);
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case


}//fim if cod
}//fim for


if(achou==0){
	printf("\nCodigo Nao Encontrado\n");
}//fim if Achou
achou=0;
system("pause");

}//fim ExcEsp

void ImpEsp(Esp e[],int t){
system("cls");
printf("Listando Especialidades \n");
for(int i=0;i<t;i++){
	printf("\nEspecialidade: %i",i+1);
	printf("\nNome: %s",e[i].nome);
	printf("\nCodigo: %i\n\n",e[i].codigo);
	
}//fim for
printf("\nFim da Lista\n");
system("pause");

}//fim ImpEsp

//FIM CRUD ESPECIALIDADE

//CRUD FUNCIONARIO
void MenuAdmFun(Fun f[], int t){
 int m;
 do{
 system("cls");
  printf("##CRUD Funcionario##");	
  printf("\n1-Cadastrar Funcionario");	
  printf("\n2-Alterar Funcionario");	
  printf("\n3-Pesquisar Funcionario");	
  printf("\n4-Excluir Funcionario");
    printf("\n5-Listar Funcionarios");	
  printf("\n0-Voltar\n");	
	scanf("%i",&m);
	switch(m){
		case 1:
			 CadFun( f, t);
			break;
		case 2:
		AltFun(f,  t);
			break;
		case 3:
		ExibFun(PesqFun(f,t));
			break;
		case 4:
		ExcFun(f,t);
			break;
        case 5:
		ImpFun(f, t);
			break;
		case 0:
		 printf("\nVoltando...\n");
			system("pause");
			break;
		default:
		printf("\nOpcao Invalida\n");					
	}   //fim switch case
 }while(m!=0);
 	system("pause");
}//fim MenuAdmFun

void CadFun(Fun f[], int t){
system("cls");
printf("Cadastrando \n");
for(int i=0;i<t;i++){
	printf("\nFuncionario: %i",i+1);
	printf("\nNome: ");
	fflush(stdin);
	gets(f[i].nome);
	printf("\nMatricula: ");
	scanf("%i",&f[i].mat);
	printf("\nUsuario: ");
	fflush(stdin);
	gets(f[i].log.user);	
	printf("\nSenha: ");
	fflush(stdin);
	gets(f[i].log.senha);	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim CadFun

Fun PesqFun(Fun f[], int t){
int mat, achou=0;
system("cls");
printf("Busque uma Matricula: ");
scanf("%i",&mat);
for(int i=0;i<t;i++){
 if(mat==f[i].mat){
 achou=1;
 return f[i];
 }//fim if

}//fim for


if(achou==0){
printf("\nMatricula Nao Encontrada\n");
}//fim if achou
achou=0;
system("pause");
}//fim PesqFun

void ExibFun(Fun f){
	printf("\nNome: %s",f.nome);
	printf("\nMatricula: %i",f.mat);
	printf("\nUsuario: %s",f.log.user);	
	printf("\nSenha: %s\n\n",f.log.senha);
system("pause");
}//fim ExibFun

void AltFun(Fun f[], int t){
int mat, op, achou=0;
system("cls");
printf("Busque uma Matricula: ");
scanf("%i",&mat);
for(int i=0;i<t;i++){
 if(mat==f[i].mat){
 achou=1;
 system("cls");
 printf("Alterar? ");
 printf("\n1-Nome"); 
 printf("\n2-Matricula"); 
 printf("\n3-Usuario"); 
 printf("\n4-Senha"); 
 printf("\n0-Voltar\n");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	printf("\nNovo Nome: ");
	fflush(stdin);
	gets(f[i].nome);
		break;
	 case 2:	
	printf("\nNova Matricula: ");
	scanf("%i",&f[i].mat);
		break;
	 case 3:	
	printf("\nNovo Usuario: ");
	fflush(stdin);
	gets(f[i].log.user);	
		break;
	 case 4:	
	printf("\nNova Senha: ");
	fflush(stdin);
	gets(f[i].log.senha);	
   	  break;
   	case 0:
   		printf("\nVoltando");
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case

 }//fim if

}//fim for


if(achou==0){
printf("\nMatricula Nao Encontrada\n");
}//fim if achou
achou=0;
system("pause");
}//fim AltFun

void ExcFun(Fun f[], int t){
int mat, op, achou=0;
system("cls");
printf("Busque uma Matricula: ");
scanf("%i",&mat);
for(int i=0;i<t;i++){
 if(mat==f[i].mat){
 achou=1;
 system("cls");
 printf("Deseja Excluir Funcionario %i? ",i+1);
 printf("\n1-Sim"); 
 printf("\n0-Nao");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	    f[i].mat=0;
		strcpy(f[i].nome,"");
		strcpy(f[i].log.user,"");
	 	strcpy(f[i].log.senha,"");	
   		printf("\nFuncionario %i Excluido",i+1);
   	  break;
   	case 0:
   		printf("\nFuncionario %i NAO Excluido",i+1);
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case

 }//fim if

}//fim for


if(achou==0){
printf("\nMatricula Nao Encontrada\n");
}//fim if achou
achou=0;
system("pause");

}//fim ExcFun

void ImpFun(Fun f[], int t){
system("cls");
printf("Listando Funcionarios \n");
for(int i=0;i<t;i++){
	printf("\nFuncionario: %i",i+1);
	printf("\nNome: %s",f[i].nome);
	printf("\nMatricula: %i",f[i].mat);
	printf("\nUsuario: %s",f[i].log.user);	
	printf("\nSenha: %s\n\n",f[i].log.senha);	
}//fim for
printf("\nFim da Lista\n");
system("pause");
}//fim ImpFun

//FIM CRUD FUNCIONARIO

//CRUD MEDICO
void MenuAdmMed(Med med[], int t){
	int m; 
	do{
	system("cls");
  printf("##CRUD Medico##");	
  printf("\n1-Cadastrar Medico");	
  printf("\n2-Alterar Medico");	
  printf("\n3-Pesquisar Medico");	
  printf("\n4-Excluir Medico");	
  printf("\n5-Listar Medicos");
  printf("\n0-Voltar\n");	
	scanf("%i",&m);
	switch(m){
		case 1:
			CadMed(med, t);
			break;
		case 2:
			AltMed(med,t);
			break;
		case 3:
			ExibMed(PesqMed( med,  t));
			break;
		case 4:
			ExcMed(med,t);
			break;
		case 5:
		  ImpMed(med, t);
			break;
		case 0:
		 printf("\nVoltando...\n");
			system("pause");	
			break;
		default:
		printf("\nOpcao Invalida\n");					
	}   //fim switch case
	}while(m!=0);
		system("pause");
}//fim MenuAdmMed

void CadMed(Med med[], int t){
	system("cls");
printf("Cadastrando \n");
for(int i=0;i<t;i++){
	printf("\nMedico: %i",i+1);
	printf("\nNome: ");
	fflush(stdin);
	gets(med[i].fun.nome);
	printf("\nCRM: ");
	scanf("%i",&med[i].crm);
	printf("\nEspecialdade: ");
	fflush(stdin);
	gets(med[i].esp.nome);
	printf("\nUsuario: ");
	fflush(stdin);
	gets(med[i].fun.log.user);	
	printf("\nSenha: ");
	fflush(stdin);
	gets(med[i].fun.log.senha);	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim CadMed

Med PesqMed(Med med[], int t){
int crm, achou=0;
system("cls");
printf("Busque CRM: ");
scanf("%i",&crm);
for(int i=0;i<t;i++){
if(crm==med[i].crm){
achou=1;
return med[i];
}//fim if

}//fim for

if(achou==0){
	printf("\nCRM Nao Encontrado\n");
}//fim if achou
achou=0;
system("pause");
}//fim PesqMed

void ExibMed(Med med){
printf("\nNome: %s",med.fun.nome);
	printf("\nCRM: %i",med.crm);
	printf("\nEspecialdade: %s",med.esp.nome);
	printf("\nUsuario: %s",med.fun.log.user);	
	printf("\nSenha: %s\n\n",med.fun.log.senha);	
system("pause");
}//fim ExibMed

void AltMed(Med med[], int t){
int crm, op, achou=0;
system("cls");
printf("Busque CRM: ");
scanf("%i",&crm);
for(int i=0;i<t;i++){
if(crm==med[i].crm){
achou=1;
system("cls");
 printf("Alterar? ");
 printf("\n1-Nome"); 
 printf("\n2-CRM"); 
 printf("\n3-Especialidade"); 
 printf("\n4-Usuario"); 
 printf("\n1-Senha"); 
 printf("\n0-Voltar\n");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	printf("\nNovo Nome: ");
	fflush(stdin);
	gets(med[i].fun.nome);
	  break;
	  case 2:
	  printf("\nNovo CRM: ");
	scanf("%i",&med[i].crm);
	break;
	case 3: 
	printf("\nNova Especialdade: ");
	fflush(stdin);
	gets(med[i].esp.nome);
		break;
	case 4:
	printf("\nNovo Usuario: ");
	fflush(stdin);
	gets(med[i].fun.log.user);	
		break;
	case 5: 
	printf("\nNova Senha: ");
	fflush(stdin);
	gets(med[i].fun.log.senha);	
   	  break;
   	case 0:
   		printf("\nVoltando");
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case

}//fim if

}//fim for

if(achou==0){
	printf("\nCRM Nao Encontrado\n");
}//fim if achou
achou=0;
system("pause");
}//fim AltMed

void ExcMed(Med med[], int t){
int crm, op, achou=0;
system("cls");
printf("Busque CRM: ");
scanf("%i",&crm);
for(int i=0;i<t;i++){
if(crm==med[i].crm){
achou=1;
system("cls");
 printf("Deseja Excluir Medico %i? ",i+1);
 printf("\n1-Sim"); 
 printf("\n0-Nao");
 scanf("%i",&op);
   switch(op){
   	case 1: 
	    med[i].crm=0;
		strcpy(med[i].fun.nome,"");
		strcpy(med[i].esp.nome,"");
	 	strcpy(med[i].fun.log.user,"");	
		strcpy(med[i].fun.log.senha,"");
   		printf("\nMedico %i Excluido",i+1);
   	  break;
   	case 0:
   		printf("\nMedico %i NAO Excluido",i+1);
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case

}//fim if

}//fim for

if(achou==0){
	printf("\nCRM Nao Encontrado\n");
}//fim if achou
achou=0;
system("pause");


}//fim ExcMed

void ImpMed(Med med[], int t){
system("cls");
printf("Listando Medicos \n");
for(int i=0;i<t;i++){
	printf("\nMedico: %i",i+1);
	printf("\nNome: %s",med[i].fun.nome);
	printf("\nCRM: %i",med[i].crm);
	printf("\nEspecialdade: %s",med[i].esp.nome);
	printf("\nUsuario: %s",med[i].fun.log.user);	
	printf("\nSenha: %s\n\n",med[i].fun.log.senha);	
}//fim for
printf("\nFim de Lista\n");
system("pause");

}//fim ImpMed

//FIM CRUD MEDICO

//CRUD PACIENTE
void MenuFun(Pac p[], int t){
  int m;
  do{
  system("cls");
  printf("##CRUD Paciente##");	
  printf("\n1-Cadastrar Paciente");	
  printf("\n2-Alterar Paciente");	
  printf("\n3-Pesquisar Paciente");	
  printf("\n4-Excluir Paciente");	
  printf("\n5-Listar Pacientes");	
  printf("\n0-Voltar\n");	
	
	scanf("%i",&m);
	switch(m){
		case 1:
			CadPac(p, t);
			break;
		case 2:
			AltPac(p,t);
			break;
		case 3:
			ExibPac(PesqPac(p,t));
			break;
		case 4:
			ExcPac(p,t);
			break;
		case 5:
		  ImpPac(p, t);
			break;	
		case 0:
		 printf("\nVoltando...\n");
			system("pause");		
			break;
		default:
		printf("\nOpcao Invalida\n");					
	}   //fim switch case
  }while(m!=0);
	system("pause");
}//fim MenuFun

void CadPac(Pac p[], int t){
system("cls");
printf("Cadastrando \n");
for(int i=0;i<t;i++){
	printf("\nPaciente: %i",i+1);
	printf("\nNome: ");
	fflush(stdin);
	gets(p[i].nome);
	printf("\nCPF: ");
	scanf("%i",&p[i].cpf);
	printf("\nTelefone: ");
	scanf("%i",&p[i].telefone);
	printf("\nUsuario: ");
	fflush(stdin);
	gets(p[i].log.user);	
	printf("\nSenha: ");
	fflush(stdin);
	gets(p[i].log.senha);	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");

}//fim CadPac

Pac PesqPac(Pac p[], int t){
int cpf, achou=0;
system("cls");
printf("Busque um CPF: ");
scanf("%i",&cpf);
for(int i=0;i<t;i++){
 if(cpf==p[i].cpf){
 	achou=1; 
 return p[i]; 
 }
}//fim for

if(achou==0){
printf("\nCPF Nao Encontrado\n ");
}//fim if achou
achou=0;
system("pause");
}//fim PesqPac

void ExibPac(Pac p){
	printf("\nNome: %s",p.nome);
	printf("\nCPF: %i",p.cpf);
	printf("\nTelefone: %i",p.telefone);
	printf("\nUsuario: %s",p.log.user);	
	printf("\nSenha: %s\n\n",p.log.senha);
	system("pause");	
}//fim ExibPac

void AltPac(Pac p[], int t){
int cpf, op, achou=0;
system("cls");
printf("Busque um CPF: ");
scanf("%i",&cpf);
for(int i=0;i<t;i++){
 if(cpf==p[i].cpf){
 	achou=1; 
 	system("cls");
 printf("Deseja Alterar? ");
 printf("\n1-Nome"); 
 printf("\n2-CPF"); 
 printf("\n3-Telefone");
 printf("\n4-Usuario");
 printf("\n5-Senha");
 printf("\n0-Voltar\n");
 scanf("%i",&op);
   switch(op){
   	case 1: 
printf("\nNovo Nome: ");
	fflush(stdin);
	gets(p[i].nome);
   	  break;
   	case 2: 
	printf("\nNovo CPF: ");
	scanf("%i",&p[i].cpf);
   	  break;
   	case 3: 
	printf("\nNovo Telefone: ");
	scanf("%i",&p[i].telefone);

   	  break;
   	case 4: 
	printf("\nNovo Usuario: ");
	fflush(stdin);
	gets(p[i].log.user);	

   	  break;
   	case 5: 
	printf("\nNova Senha: ");
	fflush(stdin);
	gets(p[i].log.senha);	

   	  break;
   	case 6: 

   	  break;		 		 		    	  
   	case 0:
   		printf("\nVoltando");
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case
 }//fim if cpf
}//fim for

if(achou==0){
printf("\nCPF Nao Encontrado\n ");
}//fim if achou
achou=0;
system("pause");

}//fim AltPac

void ExcPac(Pac p[], int t){
int cpf, op, achou=0;
system("cls");
printf("Busque um CPF: ");
scanf("%i",&cpf);
for(int i=0;i<t;i++){
 if(cpf==p[i].cpf){
 	achou=1; 
 	system("cls");
 printf("Deseja Excluir Paciente %i? ",i+1);
 printf("\n1-Sim"); 
 printf("\n0-Nao");
 scanf("%i",&op);
   switch(op){
   	case 1: 
		strcpy(p[i].nome," ");
		p[i].cpf=0;
	    p[i].telefone=0;
	 	strcpy(p[i].log.user,"");	
		strcpy(p[i].log.senha,"");
   		printf("\nPaciente %i Excluido",i+1);
   	  break;
   	case 0:
   		printf("\nPaciente %i NAO Excluido",i+1);
	   break;
	default:
	  printf("\nOpcao Invalida\n");     
   }//fim switch case
 }//fim if cpf
}//fim for

if(achou==0){
printf("\nCPF Nao Encontrado\n ");
}//fim if achou
achou=0;
system("pause");

}//fim ExcPac

void ImpPac(Pac p[], int t){
printf("Listando Pacientes\n");
for(int i=0;i<t;i++){
	printf("\nPaciente: %i",i+1);
	printf("\nNome: %s",p[i].nome);
	printf("\nCPF: %i",p[i].cpf);
	printf("\nTelefone: %i",p[i].telefone);
	printf("\nUsuario: %s",p[i].log.user);	
	printf("\nSenha: %s\n\n",p[i].log.senha);	
}//fim for
printf("\nFim de Lista\n");
system("pause");

}//fim ImpPac
//FIM CRUD PASCIENTE
