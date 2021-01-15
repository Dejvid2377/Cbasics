#include <stdio.h>
#include <stdlib.h>
#include "przygotowanie_gry.h"

void wyswietl(int *tablica){
 int szerokosc;
 if (MAX<10)
  szerokosc=3;
 else
  szerokosc=4;

 int temp = 0;
 for(int i=0;i<MAX;i++){
  for(int j=0;j<MAX;j++){
    if (tablica[temp]==0) {
     printf("%*c",szerokosc,' ');
     temp++; }
    else {
     printf("%*d",szerokosc,tablica[temp]);
     temp++; }
  }
 printf("\n");
 }
}

void wypelnij(int *tablica){
 int temp = 1;
 for(int i=0;i<MAX*MAX;i++){
    tablica[i]=temp++;
 }
 tablica[MAX*MAX-1]=0;
}

int wygrana (int *tablica,char menu[]){
 int zwyciestwo = MAX*MAX-2;
 int i=0;
 while (tablica[i]<tablica[i+1] && tablica[0]!=0){
  i++;
  zwyciestwo--;
 }
 if (zwyciestwo==0 || menu[0]=='k')
  return 1;
 else
  return 0;
}

void menu_glowne(){
 printf(" Dostepne mozliwosci ruchu:\n");
 printf(" 1 - gora\n");
 printf(" 2 - prawo\n");
 printf(" 4 - dol\n");
 printf(" 8 - lewo\n");
 printf(" k - poddaje sie :(\n");
 printf(" Twoj wybor: ");
}

_Bool dobry_stan(char menu[]){
 _Bool sukces = 1;
 if (menu[0]=='1' || menu[0]=='2' || menu[0]=='4' || menu[0]=='8' || menu[0]=='k');
 else sukces = 0;
 return sukces;
}
