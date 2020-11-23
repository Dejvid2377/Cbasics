/*  Program wylicza i wyswietla kolejne wiersze Piramidy Pascala. Calosc projektu opiera sie na implementacji dwoch funkcji: silnia oraz dwumian. 
    "silnia" wylicza wartosc silni liczby ktora zostanie podana jako argument funkcji.
    "dwumian" implementuje Dwumian Newtona (wylicza wartosci rozkladow sumy dwoch liczb podniesionych do dowolnej potegi naturalnej).
    Jako argumentu przyjmuje gorna (gora) i  dolna (dol) wartosc zapisu Dwumianu Newtona.
    Z racji konstrukcji programu maksymalny wiersz ktory jest w stanie wyswietlic to wiersz 12. Wynika to z estetyki wyswietlania liczb
    (brak duzych odstepow miedzy liczbami). W celu mozliwosci wyswietlania wiekszej ilosci wierszy nalezy zmienic szerokosc pola w ktorym wyswietlamy
    liczby (26 linijka kodu). */

#include <stdio.h>

int silnia (int liczba);            //Deklaracja dwoch funkcji uzywanych w programie (definicja pod funkcja glowna)
int dwumian (int gora, int dol);

int main()
{
    int wiersz;
    
    printf("Ktory wiersz Piramidy Pascala (max 12) wyswietlic? ");
    scanf("%d", &wiersz);

    int tablica[wiersz];
    
    for (int i=0; i <= wiersz; i++)
    {            
        tablica[i] = dwumian(wiersz,i);
        printf("%4d", tablica[i]);
    }
    printf("\n");

    return 0;
}

int silnia (int liczba)         //funkcja obliczajaca wartosc silni z podanego argumentu (liczba)
{
    int wartosc = 1;

    for (int i=0; i< liczba;)
    {
        wartosc *= ++i;
    }
    return wartosc;
}

int dwumian (int gora, int dol)     //  funkcja wylicza wartosc wybranego elementu rozkladu Dwumianu Newtona 
{                                   //  (argumenty gora i dol oznaczaja wartosci analogiczne jak w zapisie naukowym)  
    int wartosc;
    wartosc = silnia(gora) / (silnia(gora-dol) * silnia(dol));
    return wartosc;
}