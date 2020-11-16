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
//declarando Variaaveis globais
FILE *pe;//ponteiro arquivo Especialidade.txt
FILE *pf;//ponteiro arquivo Funcionario.txt
FILE *pm;//ponteiro arquivo Medico.txt
FILE *pp;//ponteiro arquivo Paciente.txt

//decrarando Procedimentos/Funcoes
void MenuAdm();

void MenuAdmEsp(Esp e[],int t);
bool VerEsp();
void CadEsp(Esp e[],int t);
void AltEsp(Esp e[],int t);
Esp PesqEsp(Esp e[],int t);
void ExcEsp(Esp e[],int t);
void ImpEsp(Esp e[],int t);
void ExibEsp(Esp e);
void ListEsp();

void MenuAdmFun(Fun f[], int t);
bool VerFun();
void CadFun(Fun f[], int t);
void AltFun(Fun f[], int t);
Fun PesqFun(Fun f[], int t);
void ExcFun(Fun f[], int t);
void ImpFun(Fun f[], int t);
void ExibFun(Fun f);
void ListFun();

void MenuAdmMed(Med med[], int t);
bool VerMed();
void CadMed(Med med[], int t);
void AltMed(Med med[], int t);
Med PesqMed(Med med[], int t);
void ExcMed(Med med[], int t);
void ImpMed(Med med[], int t);
void ExibMed(Med med);
void ListMed();

void MenuFun(Pac p[], int t);
bool VerPac();
void CadPac(Pac p[], int t);
void AltPac(Pac p[], int t);
Pac PesqPac(Pac p[], int t);
void ExcPac(Pac p[], int t);
void ImpPac(Pac p[], int t);
void ExibPac(Pac p);
void ListPac();

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
  printf("\n6-Listar Arquivo");
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
		case 6:
		 ListEsp();
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

bool VerEsp(){
	pe=fopen("Especialidade.txt","a+");	
	if(pe!=NULL){
	return true;	
	}else{
	return false;	
	}
	
	fclose(pe);
}//fim VerEsp

void CadEsp(Esp e[],int t){
system("cls");
if(VerEsp()){
printf("Cadastrando \n");
for(int i=0;i<t;i++){
	printf("\nEspecialidade: %i",i+1);
	printf("\nNome: ");
	fflush(stdin);
	gets(e[i].nome);
	printf("\nCodigo: ");
	scanf("%i",&e[i].codigo);
	
	pe=fopen("Especialidade.txt","a");
	fwrite(&e[i],sizeof(Esp),1,pe);
	fclose(pe);
	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim comparação
else{
	printf("Arquivo Especialidade nao encontrado\n");
	system("pause");
}//fim else

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

void ListEsp(){
Esp esp;
system("cls");
		//abrir arquivo
		pe=fopen("Especialidade.txt","r");
		rewind(pe);//comando para localizar o ponteiro do arquivo, para inicio
		while(!feof(pe)){
		fread(&esp,sizeof(Esp),1,pe);	
		if(!feof(pe)){
	printf("\nNome: %s",esp.nome);
	printf("\nCodigo: %i\n\n",esp.codigo);
		printf("\n\n");
		}
	 }		
		fclose(pe);
	
system("pause");

}//fim listEsp

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
  printf("\n6-Listar Arquivo");	
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
		case 6:
		 ListFun();	
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

bool VerFun(){
	pf=fopen("Funcionario.txt","a+");	
	if(pf!=NULL){
	return true;	
	}else{
	return false;	
	}
	
	fclose(pf);
}//fim VerFun

void CadFun(Fun f[], int t){
system("cls");
if(VerFun()){
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

	pf=fopen("Funcionario.txt","a");
	fwrite(&f[i],sizeof(Fun),1,pf);
	fclose(pf);
	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim comparação

else{
	printf("Arquivo Funcionario nao encontrado\n");
	system("pause");
}//fim else

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

void ListFun(){
Fun fun;
system("cls");
		//abrir arquivo
		pf=fopen("Funcionario.txt","r");
		rewind(pf);//comando para localizar o ponteiro do arquivo, para inicio
		while(!feof(pf)){
		fread(&fun,sizeof(Fun),1,pf);	
		if(!feof(pf)){
	printf("\nNome: %s",fun.nome);
	printf("\nMatricula: %i",fun.mat);
	printf("\nUsuario: %s",fun.log.user);	
	printf("\nSenha: %s\n\n",fun.log.senha);	
		printf("\n\n");
		}
	 }		
		fclose(pf);
	
system("pause");

}//fim listFun

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
  printf("\n6-Listar Arquivo");
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
		case 6:
		  ListMed();
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

bool VerMed(){
	pm=fopen("Medico.txt","a+");	
	if(pm!=NULL){
	return true;	
	}else{
	return false;	
	}
	
	fclose(pm);
}//fim VerMed

void CadMed(Med med[], int t){
	system("cls");
	
	if(VerMed()){

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

	pm=fopen("Medico.txt","a");
	fwrite(&med[i],sizeof(Med),1,pm);
	fclose(pm);
	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim comparação

else{
	printf("Arquivo Medico nao encontrado\n");
	system("pause");
}//fim else

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

void ListMed(){
Med med;
system("cls");
		//abrir arquivo
		pm=fopen("Medico.txt","r");
		rewind(pm);//comando para localizar o ponteiro do arquivo, para inicio
		while(!feof(pm)){
		fread(&med,sizeof(Med),1,pm);	
		if(!feof(pm)){
	printf("\nNome: %s",med.fun.nome);
	printf("\nCRM: %i",med.crm);
	printf("\nEspecialdade: %s",med.esp.nome);
	printf("\nUsuario: %s",med.fun.log.user);	
	printf("\nSenha: %s\n\n",med.fun.log.senha);	
		printf("\n\n");
		}
	 }		
		fclose(pm);
	
system("pause");

}//fim listMed

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
  printf("\n6-Listar Arquivo");	
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
		case 6:
		 ListPac();		
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

bool VerPac(){
	pp=fopen("Paciente.txt","a+");	
	if(pp!=NULL){
	return true;	
	}else{
	return false;	
	}
	
	fclose(pp);
}//fim VerPac

void CadPac(Pac p[], int t){
system("cls");

if(VerPac()){

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


	pm=fopen("Paciente.txt","a");
	fwrite(&p[i],sizeof(Pac),1,pp);
	fclose(pp);
	
}//fim for
printf("\nFinalizando Cadastro\n");
system("pause");
}//fim comparação

else{
	printf("Arquivo Paciente nao encontrado\n");
	system("pause");
}//fim else

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

void ListPac(){
Pac pac;
system("cls");
		//abrir arquivo
		pp=fopen("Paciente.txt","r");
		rewind(pp);//comando para localizar o ponteiro do arquivo, para inicio
		while(!feof(pp)){
		fread(&pac,sizeof(Pac),1,pp);	
		if(!feof(pp)){
	printf("\nNome: %s",pac.nome);
	printf("\nCPF: %i",pac.cpf);
	printf("\nTelefone: %i",pac.telefone);
	printf("\nUsuario: %s",pac.log.user);	
	printf("\nSenha: %s\n\n",pac.log.senha);
		printf("\n\n");
		}
	 }		
		fclose(pp);
	
system("pause");

}//fim listPac

//FIM CRUD PASCIENTE
