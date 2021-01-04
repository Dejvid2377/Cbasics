#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"OperacjeLokalne.h"

int konturowanie(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                  /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (j==*wymx-1)
    obraz_pgm[i][j]=fabs(obraz_pgm[i+1][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j]-obraz_pgm[i][j]);
   else if (i==*wymy-1 && j<*wymx-1)
    obraz_pgm[i][j]=fabs(obraz_pgm[i][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j+1]-obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=fabs(obraz_pgm[i+1][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j+1]-obraz_pgm[i][j]);
  }
 }
 return 1;
}

int rozmywanie_poziome(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                  /*iteratory tablic                                       */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli          */
  for (j=0;j<*wymx;j++) {
   if (j==0) /*pierwsza kolumna */
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j]+obraz_pgm[i][j]+obraz_pgm[i+1][j]);
   else if (j==*wymx-1) /*ostatnia kolumna */
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i-1][j]+obraz_pgm[i][j]+obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i-1][j]+obraz_pgm[i][j]+obraz_pgm[i+1][j]);
  }
 }
 return 1;
}

int rozmywanie_pionowe(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                     /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli          */
  for (j=0;j<*wymx;j++) {
   if (i==0)
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j]+obraz_pgm[i][j]+obraz_pgm[i][j+1]);
   else if (i==*wymy-1)
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j-1]+obraz_pgm[i][j]+obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j-1]+obraz_pgm[i][j]+obraz_pgm[i][j+1]);
  }
 }
 return 1;
}

int rozciaganie(int obraz_pgm[][MAX],int *wymx, int *wymy, int *szarosci){
 int i,j;                 /*poczatek sekwencji zmiany wartosci pikseli */                  
 int max=0;               /*inicjalizacja wartosci maksymalnej         */
 int min=*szarosci;       /*inicjalizacja wartosci minimalnej          */

 for(i=0;i<*wymy;i++) {     /*sekwencja przeszukiwania tablicy w celu znalezienia */
  for(j=0;j<*wymx;j++) {    /*minimalnej i maksymalnej wartosci pikseli w pliku   */
	 if(obraz_pgm[i][j]>max)  
    max = obraz_pgm[i][j];
	 if(obraz_pgm[i][j]<min)  
    min = obraz_pgm[i][j];
	}
 }
 for(i=0;i<*wymy;i++) {     /*poczatek sekwencji zmiany wartosci pikseli w pliku */
  for(j=0;j<*wymx;j++) {
	 obraz_pgm[i][j]=(obraz_pgm[i][j]-min)*(*szarosci/(max-min));
  }
 }
  return 1;
} 
