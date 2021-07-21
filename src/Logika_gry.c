/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "Logika_gry.h"
#include <stdio.h>
#include <windows.h>
#include <math.h>

#include "Sterowanie.h"
#include "Rysowanie_planszy_i_ustawianie_wartosci.h"

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40
#define SZEROKOSC_PLANSZY 69
#define WYSOKOSC_PLANSZY 39
#define PRAWO 301

/**
 * Kursor jest ustawiany na podane koordynaty w konsoli.
 *
 * @param int x: koordynat X na planszy.
 * @param int y: koordynat Y na planszy.
 */
void idz_do_x_y(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

/**
 * Funkcja odpowiadaj¹ca za mechanikê gry.
 *
 * @param int szybkosc: szybkoœæ poruszania siê wê¿a.
 * @param int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC]: logiczna plansza po której porusza siê w¹¿.
 *                                                                          Wartoœæ 0 odpowiada pustemu polu, 1 odpowiada polu z wê¿em,
 *                                                                          2 odpowiada polu z jedzeniem.
 * @param int* wspolrzedna_x_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu X z pozycj¹ wê¿a.
 * @param int* wspolrzedna_y_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu Y z pozycj¹ wê¿a.
 * @param int* wspolrzedna_x_jedzenia: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu X jedzenia.
 * @param int* wspolrzedna_y_jedzenia: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu Y jedzenia.
 * @param struct FILE* zapis_najlepszego_wyniku: wartoœæ spod zmiennej zostaje zapisana do pliku, która przechowuje najd³u¿sz¹ d³ugoœæ wê¿a.
 * @param int dlugosc_weza_z_pliku: przechowuje odczytan¹ wartoœæ z pliku odnosz¹c¹ siê do aktualnego rekordu d³ugoœci wê¿a.
 */
void logika_gry(int szybkosc, int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC],
    int* wspolrzedna_x_weza, int* wspolrzedna_y_weza, int* wspolrzedna_x_jedzenia, int* wspolrzedna_y_jedzenia,
    struct FILE* zapis_najlepszego_wyniku, int dlugosc_weza_z_pliku)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int ile_ruchow = 0;
    int kierunek = PRAWO;
    int dlugosc_weza = 4;
    int historia_wspolrzenej_x[100000] = { 0 }, historia_wspolrzenej_y[100000] = { 0 };

    for (;;)
    {
        idz_do_x_y(0, 0);
        SetConsoleOutputCP(1250);
        printf("Aktualna d³ugoœæ wê¿a wynosi %d", dlugosc_weza);
        SetConsoleOutputCP(852);

        historia_wspolrzenej_x[ile_ruchow] = *wspolrzedna_x_weza;
        historia_wspolrzenej_y[ile_ruchow] = *wspolrzedna_y_weza;

        Sleep(1000 / szybkosc);

        ustawienia_sterowania(&kierunek);
        sterowanie(&kierunek, wspolrzedna_x_weza, wspolrzedna_y_weza);

        if (*wspolrzedna_x_weza == SZEROKOSC_PLANSZY)
        {
            *wspolrzedna_x_weza = 0;
        }
        if (*wspolrzedna_x_weza == -1)
        {
            *wspolrzedna_x_weza = SZEROKOSC_PLANSZY - 1;
        }
        if (*wspolrzedna_y_weza == WYSOKOSC_PLANSZY)
        {
            *wspolrzedna_y_weza = 0;
        }
        if (*wspolrzedna_y_weza == -1)
        {
            *wspolrzedna_y_weza = WYSOKOSC_PLANSZY - 1;
        }

        if (plansza[*wspolrzedna_x_weza][*wspolrzedna_y_weza] == 1)
        {
            SetConsoleOutputCP(1250);

            idz_do_x_y(0, WYSOKOSC_PLANSZY + 3);

            printf("\n\aKoniec gry\n");
            printf("D³ugoœæ wê¿a to %d.\n", dlugosc_weza);

            zapis_najlepszego_wyniku = fopen("save.bin", "wb");

            if (zapis_najlepszego_wyniku == NULL)
            {
                printf("Nie mo¿na otworzyæ pliku aby zapisaæ rekord\n");
                return 1;

                fprintf(zapis_najlepszego_wyniku, "%d\n", dlugosc_weza);
            }

            if (dlugosc_weza >= dlugosc_weza_z_pliku)
            {
                if (zapis_najlepszego_wyniku == NULL)
                {
                    printf("Nie mo¿na otworzyæ pliku aby zapisaæ rekord\n");
                    return 1;
                }

                fprintf(zapis_najlepszego_wyniku, "%d\n", dlugosc_weza);
            }
            else
            {
                if (zapis_najlepszego_wyniku == NULL)
                {
                    printf("Nie mo¿na otworzyæ pliku aby zapisaæ rekord\n");
                    return 1;
                }

                fprintf(zapis_najlepszego_wyniku, "%d\n", dlugosc_weza_z_pliku);
            }
            fclose(zapis_najlepszego_wyniku);

            printf("Naciœnij dowolny klawisz aby zakonczyæ gre.");
            system("pause>nul");

            break;
        }

        if (plansza[*wspolrzedna_x_weza][*wspolrzedna_y_weza] == 2)
        {
            dlugosc_weza++;

            do
            {
                *wspolrzedna_x_jedzenia = rand() % SZEROKOSC_PLANSZY;
                *wspolrzedna_y_jedzenia = rand() % WYSOKOSC_PLANSZY;
            } while (plansza[*wspolrzedna_x_jedzenia][*wspolrzedna_y_jedzenia] != 0);

            plansza[*wspolrzedna_x_jedzenia][*wspolrzedna_y_jedzenia] = 2;

            idz_do_x_y((*wspolrzedna_x_jedzenia) * 2 + 1, (*wspolrzedna_y_jedzenia) + 2);

            kolor_jedzenia();
        }
        else
        {
            plansza[historia_wspolrzenej_x[abs(ile_ruchow - dlugosc_weza + 1)]][historia_wspolrzenej_y[abs(ile_ruchow - dlugosc_weza + 1)]] = 0;

            idz_do_x_y(historia_wspolrzenej_x[abs(ile_ruchow - dlugosc_weza + 1)] * 2 + 1, historia_wspolrzenej_y[abs(ile_ruchow - dlugosc_weza + 1)] + 2);
            printf("  ");
        }

        plansza[*wspolrzedna_x_weza][*wspolrzedna_y_weza] = 1;

        idz_do_x_y((*wspolrzedna_x_weza) * 2 + 1, (*wspolrzedna_y_weza) + 2);
        
        SetConsoleTextAttribute(h, 0xFF);
        printf("  ");
        SetConsoleTextAttribute(h, 0x07);

        ile_ruchow++;
    }
}
