#include <stdio.h>
#include <stdlib.h>
main(){ 
int ac=150, aj=110, a=0;
while(ac>=aj){
	ac=ac+2;
	aj=aj+3;
	a++;
}
printf("\nForam %d anos para Juca ser maior que Chico\n", a);
system("pause");}
