#ifndef PRZYGOTOWANIEPROGRAMU_H
#define PRZYGOTOWANIEPROGRAMU_H
#include "ZmiennePomocnicze.h"

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										                                            *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM  	                *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz                 *
 * \param[out] wymx szerokosc obrazka						                        *
 * \param[out] wymy wysokosc obrazka						                        *
 * \param[out] szarosci liczba odcieni szarosci					                    *
 * \return liczba wczytanych pikseli						                        *
 ************************************************************************************/
int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci); 

/************************************************************************************
 * Funkcja zapisuje obraz PGM do nowego pliku         	       	       	       	    *
 *										                                            *
 * \param[in] plik_wy uchwyt do wybranego pliku                  		            *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                            *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] plik_wy obraz pgm               					                    *
 * \return liczba wczytanych pikseli						                        *
 ************************************************************************************/
int zapis (FILE *plik_wy,int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/************************************************************************************
 * Funkcja wyswietla rządany obraz poprzez ingerencje w polecenia systemowe    	    *
 *										                                            *
 * \param[in] n_pliku nazwa pliku ktory chcemy wyswietlic                           * 
 * \param[out] wyswietlony obraz               					                    *
 ************************************************************************************/
void wyswietl(char *n_pliku);

/************************************************************************************
 * Funkcja wyswietla dostepne opcje w programie                                     *
 ************************************************************************************/
void menu_glowne(void);

/************************************************************************************
 * Funkcja kontrolujaca poprawnosc wpisanych danych                                 *
 *                                                                                  *
 * \param[in] menu[] wartosc zmiennej char zapisanej w tablicy menu                 *
 * \param[out] wartosc logiczna potrzebna do uruchomienia petli sterujacej          *
 ************************************************************************************/
_Bool dobry_stan (char *);

#endif
