#ifndef OPERACJEPUNKTOWE_H
#define OPERACJEPUNKTOWE_H
#include "ZmiennePomocnicze.h"

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu negatywu	       	    *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej	                        *
 ************************************************************************************/
int negatyw (int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/****************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu progowania      	        *
 * (im wyzszy poziom progu tym wiecej pikseli klasyfikujemy jako punkty koloru czarnego)*
 *                                                                                      *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                        *
 * \param[in] wymx szerokosc obrazka						                                        *
 * \param[in] wymy wysokosc obrazka						                                          *   
 * \param[in] szarosci liczba odcieni szarosci                                          *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                           *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                              *
 ****************************************************************************************/
int progowanie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu polprogowania czerni *
 * (wszystkim pikselom ponizej wartosci progu przypisuje wartosc 0)                 *
 *                                                                                  *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int polprogowanie_czerni(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/*************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu polprogowania bieli   *
 * (wszystkim pikselom powyzej wartosci progu przypisuje maksymalna wartosc szarosci)*
 *                                                                                   *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                     *
 * \param[in] wymx szerokosc obrazka						                                     *
 * \param[in] wymy wysokosc obrazka						                                       *   
 * \param[in] szarosci liczba odcieni szarosci                                       *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                        *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                           *
 *************************************************************************************/
int polprogowanie_bieli(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu korekcji gamma       *
 * (parametr ponizej wartosci 1 przyciemni obraz, natomiast powyzej go rozjasni)									                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int korekcja_gamma(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania zmiany poziomow             *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int zmiana_poziomow(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
#endif
