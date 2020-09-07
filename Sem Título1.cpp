#include <conio.h>

#include <stdio.h>

main(){

     int A[] = {9,3,7,6,21,50,45,36,2,8,7,9,42,32,18};
int j ,i;
     int Aux;

     for(int j=0;j <= 14;j++)

         printf(""\nA[%d] = %d"",j,A[j]);

     for(int j=0;j <= 13;j++)

        for(int i=0;i <= 13;i++)

           if (A[i] > A[i+1]){

               Aux = A[i];

               A[i] = A[i+1];

               A[i+1] = Aux;};

     printf(""\n\nValores Ordenados"");      

     for(int j=0;j <= 14;j++)

         printf(""\nA[%d] = %d"",j,A[j]);

      printf(""\n\n\\n.................FIM.................."");

      getch();   // esperar uma tecla

}
