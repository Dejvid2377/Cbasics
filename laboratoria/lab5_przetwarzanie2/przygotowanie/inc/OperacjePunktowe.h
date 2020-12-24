#ifndef OPERACJEPUNKTOWE_H
#define OPERACJEPUNKTOWE_H
#include"ZmiennePomocnicze.h"

int negatyw (int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int progowanie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int polprogowanie_czerni(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int polprogowanie_bieli(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int korekcja_gamma(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int zmiana_poziomow(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
#endif
