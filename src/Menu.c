/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Rysowanie_planszy_i_ustawianie_wartosci.h"
#include "Ustawienia_konsoli.h"
#include "Logika_gry.h"

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40

 /**
  * Pod menu. Funkcja odpowiedzialna za powrót do g³ównego menu lub wyjœcia z aplikacji.
  * -Wróæ do g³ównego menu
  * -Wyjœcie
  */
void pod_menu(void)
{
    char wybor = '0';

    printf("1. Wróæ\n");
    printf("2. Wyjœcie\n");
    printf("Wybierz opcjê: ");

    while (wybor != '1' && wybor != '2')
    {
        scanf("%c", &wybor);
        while (getchar() != '\n');

        if (wybor != '1' && wybor != '2')
        {
            printf("Nieprawid³owy wybór!\n");
            printf("Wybierz ponownie opcjê: ");
        }
    }

    switch (wybor)
    {
    case '1':
        system("cls");
        menu();
        break;

    case '2':
        exit(0);
        break;

    default:
        break;
    }
}

/**
 * Menu gry. Wyœwietla menu i umo¿liwia wyœwietlanie poszczególnych opcji takich jak:
 * -Rozpocznij grê
 * -Sterowanie
 * -O autorze
 * -Wyjœcie
 */
void menu(void)
{
    char wybor = '0';
    int szybkosc = 15;
    int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC] = { 0 };
    int wspolrzedna_x_weza = 0;
    int wspolrzedna_y_weza = 0;
    int wspolrzedna_x_jedzenia = 0;
    int wspolrzedna_y_jedzenia = 0;
    FILE* zapis_najlepszego_wyniku;
    int dlugosc_weza_z_pliku = 0;

    zapis_najlepszego_wyniku = fopen("save.bin", "rb");

    if (zapis_najlepszego_wyniku == NULL)
    {
        printf("Rekord d³ugoœci wê¿a wynosi 0\n");
    }
    else
    {
        if (zapis_najlepszego_wyniku == NULL)
        {
            printf("Nie mo¿na otworzyæ pliku aby odczytaæ zapis\n");
            return 1;
        }

        fscanf(zapis_najlepszego_wyniku, "%d", &dlugosc_weza_z_pliku);
        printf("Rekord d³ugoœci wê¿a wynosi %d\n", dlugosc_weza_z_pliku);

        fclose(zapis_najlepszego_wyniku);
    }

    printf("MENU\n\n");
    printf("Wybierz opcjê\n");
    printf("1. Rozpocznij grê\n");
    printf("2. Sterowanie\n");
    printf("3. O autorze\n");
    printf("4. Wyjœcie\n");
    printf("Wybierz opcjê: ");

    while (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4')
    {
        scanf("%c", &wybor);
        while (getchar() != '\n');

        if (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4')
        {
            printf("Nieprawid³owy wybór!\n");
            printf("Wybierz ponownie opcjê: ");
        }
    }

    switch (wybor)
    {
    case '1': /*Rozpocznij gre*/
        poczatkowe_ustawianie_pol(plansza, &wspolrzedna_x_weza, &wspolrzedna_y_weza, &wspolrzedna_x_jedzenia, &wspolrzedna_y_jedzenia);
        pokaz_kursor_na_ekranie(false);
        rysowanie_planszy(plansza);
        logika_gry(szybkosc, plansza, &wspolrzedna_x_weza, &wspolrzedna_y_weza, &wspolrzedna_x_jedzenia, &wspolrzedna_y_jedzenia, &zapis_najlepszego_wyniku, dlugosc_weza_z_pliku);

        break;

    case '2': /*Sterowanie*/
        wybor = '0';
        
        system("cls");
        printf("STEROWANIE\n\n");
        printf("Góra:  Strza³ka w górê\n");
        printf("Dó³:   Strza³ka w dó³\n");
        printf("Lewo:  Strza³ka w lewo\n");
        printf("Prawo: Strza³ka w prawo\n\n");

        pod_menu();

        break;

    case '3': /*O autorze*/
        wybor = '0';

        system("cls");
        printf("Nazywam siê Mateusz Jasiak.\n\n");
        printf("Dane kontaktowe: mateusz.jasiak.dev@gmail.com\n");
        printf("Rekord autora wynosi 151.\n\n");
        printf("Podziêkowania dla beta testerów:\n");
        printf("Pawe³ Pi¹tek\n");
        printf("Adrian Ciochoñ\n");
        printf("Grzegorz Kosman\n");
        printf("Daniel £azarek\n\n");

        pod_menu();

        break;

    case '4': /*Wyjœcie z aplikacji*/
        exit(0);
        break;

    default:
        break;
    }
}
