/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <stdio.h>
#include <windows.h>

#include "Ustawienia_konsoli.h"
#include "Menu.h"

int main()
{
    SetConsoleOutputCP(1250);

    rozmiar_konsoli();
    menu();

    return 0;
}
