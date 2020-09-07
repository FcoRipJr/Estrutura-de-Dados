#include <stdio.h>
#include <stdlib.h>
main(){ 
int x=0, h=0, f=0, altura, somat, somaf, maior=0, menor=10000, sexo;
float mediap, mediaf, percenth;
while(x<50){
	x++;
	printf("\n digite a altura: ");
	scanf("%d",&altura);
	somat=somat+altura;
	if(maior<altura){maior=altura;}
	if(menor>altura){menor=altura;}
	printf("\n selecione o sexo digitando 0 para MASCULINO ou 1 para FEMININO ");
	scanf("%d",&sexo);
	if(sexo=0){h++;}
	if(sexo=1){
		somaf=somaf+altura;
		f++;}
}
mediaf=somaf/f;
mediap=somat/x;
percenth=(100*h)/x;
printf("\nA maior altura encontrada foi: %d \n",maior);
printf("\nA menor altura encontrada foi: %d \n",menor);
printf("\n A media de altura entre mulheres e: %f \n",mediaf);	
printf("\n A media de altura da populacao e: %f \n",mediap);
printf("\n O percentual de homens na populacao e %f % \n",percenth);
system("pause");}
