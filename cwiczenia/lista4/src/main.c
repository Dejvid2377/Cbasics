/**********************************************************************************
 * \param[Autor projektu]: Dawid Krekora                                          *
 * \param[Nazwa projektu]: Gra interaktywna znana pod nazwa "Ukladanka" polegajaca*
 *      na ulozeniu liczb w kolejnosci rosnacej. Numerowanie rozpoczynamy od      *
 *      lewego gornego pola idac w kierunku prawym, stosujac ta zasade rowniez w  *
 *      kolejnych wierszach. Gra konczy sie gdy wszystkie pola zostana ulozone w  *  
 *      kolejnosci rosnacej (rozpoczynajac od liczby 1), a ostatnim polem w       *
 *      ukladance bedzie puste pole.                                              *
 *      Wazna informacja: Budowa programu zostala dostosowana do dowolnego        *
 *      rozmiaru pola gry (MAKSYMALNIE 31x31) - w celu zwiekszenia nalezy zmienic *
 *      wartosc MAX w pliku: "ZmiennePomocnicze.h".                               *
 * \param[Zasady gry] Poruszamy sie za pomoca lokalizacji pustego pola. Ruch      *
 *        wykonujemy poprzez zamiane pustego pola z polem do niego sasiadujacym.  *
 *        Ruch prowadzacy do wyjscia pustego pola poza obszar gry jest traktowany *
 *        jako operacja niedozwolona.                                             * 
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "przygotowanie_gry.h"
#include "lokalizacja_pola.h"
#include "zmienne_pomocnicze.h"

int main (){
 char menu[2] = " ";
 wspolrzedne polozenie_przed, polozenie_po;
 int *pole_gry;
 int indeks, wielkosc_pola;

 wielkosc_pola = (MAX*MAX)-1;

//rezerwacja pamieci dla dynamicznej tablicy symulujacej pole gry 
 pole_gry = malloc(wielkosc_pola * sizeof(int *));
 if (pole_gry==NULL)
  fprintf(stderr,"Błąd przydzielania pamięci.\n");
 
 //wypelnienie pola gry i pomieszanie ustawienia poczatkowego
 wypelnij(pole_gry);
 indeks = znajdz_puste(pole_gry);
 polozenie_przed = z1d_n2d(indeks);
 pomieszaj(indeks,polozenie_przed,pole_gry);
 
 //sekwencja wczytania POPRAWNEGO wyboru uzytkownika
 //powtarzaj do momentu spelnienia warunkow wygranych lub wyjscia z gry
 do{
  wyswietl(pole_gry);
  menu_glowne();
  scanf("%1s",menu);
  system("clear");
  printf("\n");
  while (dobry_stan(menu)!=1){
   system("clear");
   printf("Wybor nierozpoznany, sprobuj ponownie.\n");
   wyswietl(pole_gry);
   menu_glowne();
   scanf("%1s",menu);
   printf("\n");
  }

  //sekwencja zamiany pol w grze
  indeks = znajdz_puste(pole_gry);
  polozenie_przed = z1d_n2d(indeks);
  polozenie_po = ruch(polozenie_przed,menu);
  zamien(pole_gry,z2d_n1d(polozenie_przed),z2d_n1d(polozenie_po));
 } while (wygrana(pole_gry,menu)!=1);
 
 if (menu[0]=='k')
  printf("Poddales sie, koniec dzialania programu.\n");
 else {
  wyswietl(pole_gry);
  printf("Gratulacje, wygrales!!!\n");
 }

 free(pole_gry);
 return 0;
}
