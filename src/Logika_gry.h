/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef LOGIKA_GRY_H_
#define LOGIKA_GRY_H_

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40

void idz_do_x_y(int x, int y);
void logika_gry(int szybkosc, int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC],
	int* wspolrzedna_x_weza, int* wspolrzedna_y_weza, int* wspolrzedna_x_jedzenia, int* wspolrzedna_y_jedzenia,
	struct FILE* zapis_najlepszego_wyniku, int dlugosc_weza_z_pliku);

#endif
