#include "../headers/Menu.h"

void Menu::display()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("DUGUN AUTO CLICKER");
        std::cout << "(1) INICIAR AUTO CLICKER\n";
        std::cout << "(2) SECUENCIA...\n";
        std::cout << "(3) AYUDA\n";
        _terminal.printLine();
        std::cout << "(0) SALIR\n";

        selection = _validation.cinIntBetween(0, 3);

        switch (selection)
        {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                help();
                break;
        }
    }
    while (selection != 0);
}

void Menu::help()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("AYUDA");
        std::cout << "(1) ATAJOS DEL TECLADO\n";
        std::cout << "(2) LENGUAJES\n";
        std::cout << "(3) ACERCA DE\n";
        _terminal.displayMenuFooter();

        selection = _validation.cinIntBetween(0, 3);

        switch (selection)
        {
            case 1:
                hotkeys();
                break;
            case 2:
                language();
                break;
            case 3:
                about();
                break;
        }
    }
    while (selection != 0);
}

void Menu::hotkeys()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("ATAJOS DEL TECLADO");
        std::cout << "Iniciar auto clicker: CTRL + A\n";
        std::cout << "Iniciar grabación de mouse: CTRL + R\n";
        std::cout << "Detener ejecución: CTRL + S\n";
        std::cout << "Obtener coordenadas: CTRL + C\n";
        _terminal.displayMenuFooter();

        selection = _validation.cinIntBetween(0, 0);
    }
    while (selection != 0);
}

void Menu::language()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("LENGUAJES");
        std::cout << "(1) INGLÉS\n";
        std::cout << "(2) ESPAÑOL\n";
        _terminal.displayMenuFooter();

        selection = _validation.cinIntBetween(0, 2);

        switch (selection)
        {
            case 1:
                
                break;
            case 2:
                
                break;
        }
    }
    while (selection != 0);
}

void Menu::about()
{
    const char * url = "https://github.com/mrmalvicino/dugun-auto-clicker";

    #ifdef _WIN64
        system(("start " + std::string(url)).c_str());
    #endif

    #ifdef __linux__
        system(("xdg-open " + std::string(url)).c_str());
    #endif

    #ifdef __APPLE__
        system(("open " + std::string(url)).c_str());
    #endif
}