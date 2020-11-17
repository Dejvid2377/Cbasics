/*  Niniejszy program sluzy do okreslenia pulsu pacjenta na podstawie danych wejciowych. Program pobiera dane ze standardowego wejscia do momentu, aż nie napotka wartości krytycznej.
    Nastepnie sprawdza czy pobrana wartosc nalezy do zakresu liczbowego oraz czy pomiedzy dwoma sasiednimi wartosciami wystepuje 0 (tylko dla prawidlowych liczb). Po kazdej wczytanej
    sekwencji liczb przedstawia rezultat w postaci komunikatu o wartosci pulsu - czyli liczbie wystapien przeciecia zera. */

#include <stdio.h>

#define MIN_VALUE -10       //minimalna wartosc liczb wliczanych do zakresu                 ***************************************************
#define MAX_VALUE  10       //maksymalna wartosc liczb wliczanych do zakresu                *****                                         *****
#define MIN_FREQ    8       //minimalna, prawidlowa czestotliwosc pulsu                     *****       INSTRUKCJE DLA PREPROCESORA       *****
#define MAX_FREQ   14       //maksymalna, prawidlowa czestotliwosc pulsu                    *****     DEKLARACJA STALYCH SYMBOLICZNYCH     *****
#define CRIT_VALUE 99       //liczba oznaczajaca koniec wczytywania ze strumienia danych    *****                                         *****
#define DATA_VALUE 99       //maksumalna liczba pobranych danych w jednej sekwencji         ***************************************************

int main ()
{                           //deklaracja zmiennych i nadanie im wartosci poczatkowych:
    float a = 0.0;          //zmienna do ktorej wczytujemy dane wejsciowe
    float b = 0.0;          //zmienna pomocnicza do przechowywania poprzedniej wartosci
    int cross_0 = 0;        //licznik wystapienia przeciecia zera
    int counter = 0;        //licznik wczytanych liczb w sekwencji

    while (a != CRIT_VALUE) {   //petla sprawdzajaca kiedy zakonczyc dzialanie programu
     scanf("%f", &a);
      counter++;

        if (a>MIN_VALUE && a<MAX_VALUE && a!=0) {               //instrukcja warunkowa sprawdzajaca czy liczba miesci sie w poprawnym zakresie
            if (a*b < 0){
                cross_0++;
            }
            b = a;
            if (!(counter % DATA_VALUE) || b==CRIT_VALUE) {     //instrukacja warunkowa sprawdzajaca kiedy zakonczyc pojedyncza sekwencje liczb i przystapic do interpretacji wynikow 
                if (cross_0<MIN_FREQ || cross_0>MAX_FREQ){      //instrukcja warunkowa interpretujaca wartosc tetna
                    printf("Niepoprawny puls (%d)\n",cross_0);
                }
                else {
                    printf("Puls w normie. Wartosc pulsu: %d\n", cross_0);
                }
                a = b = 0.0;                                    //wyzerowanie wartosci poczatkowych zmiennych dla kolejnej sekwencji liczb
                cross_0 = counter = 0;               
            }
        }
    }

    return 0;
}