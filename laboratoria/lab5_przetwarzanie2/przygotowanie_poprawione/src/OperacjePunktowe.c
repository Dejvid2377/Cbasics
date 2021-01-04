#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"OperacjePunktowe.h"


int negatyw (int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){
 int i,j;                    /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {  /* zmiana wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   obraz_pgm[i][j] = *szarosci-(obraz_pgm[i][j]); 
  }
 }
 return 1;
}

int progowanie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){                
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */     

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){  
  fprintf(stderr,"To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))  
    obraz_pgm[i][j] = 0;
   else
    obraz_pgm[i][j] = *szarosci;
  } 
 } 
 return 1; 
}

int polprogowanie_czerni(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){               
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */  

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){
  fprintf(stderr,"Błąd. To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {    /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))
    obraz_pgm[i][j] = 0;
   else
    obraz_pgm[i][j] = obraz_pgm[i][j];
  } 
 } 
 return 1; 
}

int polprogowanie_bieli(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){               
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */  

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){
  fprintf(stderr,"Blad. To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Blad. Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))
    obraz_pgm[i][j] = obraz_pgm[i][j];
   else
    obraz_pgm[i][j] = *szarosci;
  } 
 } 
  return 1; 
}

int korekcja_gamma(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci) {              
 int i,j;                  /*iteratory tablic                                    */
 float gamma;              /*zmienna pomocnicza przy przypisaniu wartosci progu  */ 

 printf("Podaj wartosc parametru gamma (wieksze od 0): ");
 if (scanf("%f",&gamma) != 1){
  fprintf(stderr,"Błąd. To nie jest liczba.\n");
  return 0; }
 if (gamma <= 0){
  fprintf(stderr,"Bledna wartosc parametru. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {   /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   obraz_pgm[i][j]= pow(obraz_pgm[i][j],1/gamma) / pow(*szarosci,(1-gamma)/gamma);
  } 
 } 
 return 1;
}

int zmiana_poziomow(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){              
 int i,j;                  /*iteratory tablic                                    */
 float biel,czern;         /*zmienna pomocnicza przy ustalaniu wartosci progow   */
 float prog_czerni, prog_bieli; /* zmienna pomocnicza przy ustalaniu wartosci z ich */
 
 printf("Podaj nowe wartosci dla parametrow czerni i bieli (w %%).\n");
 printf("(Uwaga, pierwszy parametr nie moze miec wiekszej wartosci od drugiego): ");
 
 if (scanf("%f%f",&czern,&biel) != 2){
  fprintf(stderr,"Blad. Bledna wartosc parametrow\n");
  return 0; }
 if (biel-czern<=0){
  fprintf(stderr,"Blad. Parametr czerni nie moze byc wiekszy od bieli\n");
  return 0; }
 if (czern<0 || biel<0 || czern>100 || biel>100){
  fprintf(stderr,"Blad. Wartosci parametrow musza miescic sie w zakresie od 0%% do 100%%\n");
  return 0; }

 prog_bieli = biel/100 * *szarosci;     /* wyznaczanie wartosci progow */
 prog_czerni = czern/100 * *szarosci;

 for (i=0;i<*wymy;i++) {                /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= prog_czerni)
    obraz_pgm[i][j] = 0;
   else if (obraz_pgm[i][j]>prog_czerni && obraz_pgm[i][j]<prog_bieli)
    obraz_pgm[i][j] = (obraz_pgm[i][j]-prog_czerni) * *szarosci/(prog_bieli-prog_czerni);
   else if (obraz_pgm[i][j]>=prog_bieli)
    obraz_pgm[i][j] = *szarosci;
  } 
 }
 return 1;
}

