#include"OperacjeLokalne.h"
#include"OperacjePunktowe.h"
#include"PrzygotowanieProgramu.h"
/**********************************************************************************************************
* PROJEKT:  PRZETWARZANIE OBRAZOW CZESC PIERWSZA                                                          *
* AUTOR:    DAWID KREKORA                                                                                 *
* DATA:     10.12.2020                                                                                    *
* OPIS:     Program zawarty w tym pliku sluzy do operowania na obrazach monochromatycznych w formacie PGM.*
*           Zaimplementowane w nim funkcje pozwalaja na przeprowadzenie podstawowych operacji na pikselach* 
*           zapisujac calosc modyfikacji w nowym pliku o wybranej przez uzytkownika nazwie.               *
**********************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main() {
 do {
  printf("Program operujacy na obrazach PGM.\n"); 
   /*sekwencja pobrania danych obrazu wejsciowego */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  plik=fopen(nazwa,"r");
  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
  fclose(plik);
   /* jezeli funkcja odczytano zadzialala prawidlowo wyswietl menu: */
  if (odczytano!=0){
   menu_glowne();
   scanf("%1s", menu);
  /* menu oparte na funkcji switch, przypisanie zmiennej koniec wartosci !=0 
    (jako wartosci zwracanej przy poprawnym wykonaniu funkcji) jest kluczowe 
    dla dalszego dzialania programu */
   switch(menu[0]){
    case 'w': wyswietl(nazwa);
              koniec = 1;
              break;
    case '0': koniec = negatyw(obraz,&wymx,&wymy,&odcieni);
              break;
    case '1': koniec = progowanie(obraz,&wymx,&wymy,&odcieni);
              break;
    case '2': koniec = polprogowanie_czerni(obraz,&wymx,&wymy,&odcieni);
              break;
    case '3': koniec = polprogowanie_bieli(obraz,&wymx,&wymy,&odcieni);
              break;
    case '4': koniec = korekcja_gamma(obraz,&wymx,&wymy,&odcieni);
              break;
    case '5': koniec = zmiana_poziomow(obraz,&wymx,&wymy,&odcieni);
              break;
    case '6': koniec = konturowanie(obraz,&wymx,&wymy);
              break;
    case '7': koniec = rozmywanie_poziome(obraz,&wymx,&wymy);
              break; 
    case '8': koniec = rozmywanie_pionowe(obraz,&wymx,&wymy);
              break; 
    case '9': koniec = rozciaganie(obraz,&wymx,&wymy,&odcieni);
              break; 
    case 'k': printf("Koniec dzialania programu.\n");
              break;
    default:  printf("Nierozpoznane, sprobuj ponownie.\n");  
   }
   /* jezeli wpisano prawidlowe wartosci w etapie menu..sekwencja zapisu do nowego pliku */
   if (dobry_stan(menu) && koniec){
    printf("Podaj nazwe pliku do zapisu: ");
    scanf("%s", nazwa2);
     
    plik2=fopen(nazwa2,"w");
    if (plik2 != NULL){
     zapisano = zapis(plik,obraz,&wymx,&wymy,&odcieni);
     fclose(plik2);  }
   }
  }
 } while (menu[0]!='k' && koniec);
 return zapisano;
}




