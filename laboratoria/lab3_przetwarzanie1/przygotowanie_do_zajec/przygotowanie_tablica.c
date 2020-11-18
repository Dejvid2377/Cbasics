#include <stdio.h>
#define MAX 10

int tablica[MAX][MAX];
void wypelnij (int a, int b);
void wypisz (int a, int b);
void zamien_znaki (int a, int b);

int main()
{
    int wiersze, kolumny;
    

    printf ("Podaj ile wierszy tablicy kwadratowej o wymiarach %dx%d potrzebujesz: ", MAX, MAX);
    scanf("%d", &wiersze);
    printf ("Podaj ile kolumn tablicy kwadratowej o wymiarach %dx%d potrzebujesz: ", MAX, MAX);
    scanf("%d", &kolumny);

    wypelnij(wiersze,kolumny);
    printf("Zawartosc oryginalna: \n");
    wypisz(wiersze,kolumny);
    zamien_znaki(wiersze,kolumny);
    printf("Zawartosc po zmianie znakow: \n");
    wypisz(wiersze,kolumny);

    return 0;
}

void wypelnij (int a, int b)
{
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            tablica[i][j] = i * j;
        }
    }
}

void wypisz (int a, int b)
{
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            printf("%3d", tablica[i][j]);
        }
        printf("\n");
    }
}

void zamien_znaki (int a, int b)
{
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            tablica[i][j] = -i*j;
        }
    }
}