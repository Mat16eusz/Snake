/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef RYSOWANIE_PLANSZY_I_USTAWIANIE_WARTOSCI_H_
#define RYSOWANIE_PLANSZY_I_USTAWIANIE_WARTOSCI_H_

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40

void poczatkowe_ustawianie_pol(int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC], int* wspolrzedna_x_weza,
	int* wspolrzedna_y_weza, int* wspolrzedna_x_jedzenia, int* wspolrzedna_y_jedzenia);
void kolor_jedzenia(void);
void rysowanie_planszy(int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC]);

#endif
