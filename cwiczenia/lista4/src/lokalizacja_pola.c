#include <stdio.h>
#include <stdlib.h>
#include "lokalizacja_pola.h"

wspolrzedne z1d_n2d (int indeks){
 wspolrzedne pole;
 pole.x = indeks/(MAX) + 1;
 if (indeks==0)
  pole.y = 1;
 else if (indeks%MAX==MAX-1)
  pole.y = MAX;
 else
  pole.y = indeks%(MAX)+1;
 return pole; 
}

int z2d_n1d(wspolrzedne pole){
 int indeks = (pole.x-1) * (MAX) + (pole.y-1);
 return indeks;
}

int znajdz_puste(int *tablica){
 int i=0;
 while (tablica[i]!=0) {
  i++;
 }
 return i;
}

wspolrzedne ruch (wspolrzedne puste, char kierunek[]){
 switch(kierunek[0]){
  case '1': if (puste.x==1) {fprintf(stderr,"Operacja niedozwolona\n");}
            else { puste.x--; }
            break;
  case '2': if (puste.y==MAX) {fprintf(stderr,"Operacja niedozwolona\n");}
            else { puste.y++; }
            break;
  case '4': if (puste.x==MAX) {fprintf(stderr,"Operacja niedozwolona\n");}
            else { puste.x++; }
            break;
  case '8': if (puste.y==1) {fprintf(stderr,"Operacja niedozwolona\n");}
            else { puste.y--; }
            break;
  default : break;
 }
 return puste;
}

void zamien(int *tablica,int indeks_przed,int indeks_po){
 int temp;
 temp=tablica[indeks_po];
 tablica[indeks_po]=tablica[indeks_przed];
 tablica[indeks_przed]=temp;
}

void pomieszaj (int indeks,wspolrzedne puste,int *tablica){
 int liczba;
 if (MAX<6)
  liczba=500;
 else if (MAX<11)
  liczba=1000;
 else
  liczba=10000;

 for (int i=0;i < liczba; i++){
  switch (rand() % 4){
   case 0: if (puste.x!=1) {
              tablica[indeks]=tablica[indeks-1];
              tablica[indeks-1]=0;
              puste.x--;
              indeks--;
             }
             break;
   case 1: if (puste.x!=MAX) {
              tablica[indeks]=tablica[indeks+1];
              tablica[indeks+1]=0;
              puste.x++;
              indeks++;
             }
             break;
   case 2: if (puste.y!=1 && puste.x!=1) {
              tablica[indeks]=tablica[indeks-MAX];
              tablica[indeks-MAX]=0;
              puste.y--;
              indeks-=MAX;
             }
             break;
   case 3: if (puste.y!=MAX) { 
              tablica[indeks]=tablica[indeks+MAX];
              tablica[indeks+MAX]=0;
              puste.y++;
              indeks+=MAX;
             }
              break;
   default :  break;
  }
 }
}