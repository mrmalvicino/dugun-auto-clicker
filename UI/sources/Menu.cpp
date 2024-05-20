#include "../headers/Menu.h"

void Menu::display()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("DUGUN AUTO CLICKER");
        std::cout << "(1) Iniciar\n";
        std::cout << "(2) Secuencia\n";
        std::cout << "(3) Capturadora\n";
        std::cout << "(4) Ayuda\n";
        _terminal.displayMenuFooter("Salir");

        selection = _validation.cinIntBetween(0, 4);

        switch (selection)
        {
            case 1:
                run();
                break;
            case 2:
                sequence();
                break;
            case 3:
                
                break;
            case 4:
                help();
                break;
        }
    }
    while (selection != 0);
}

void Menu::run()
{

}

void Menu::sequence()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("Secuencia");
        std::cout << "    ID: 0\n";
        std::cout << "(1) Nombre: Default\n";
        std::cout << "(2) Archivo\n";
        _terminal.printLine();
        std::cout << "(3) Repeticiones: infinitas\n";
        std::cout << "(4) Tiempo aleatorio: 0 ms\n";
        std::cout << "(5) Posición aleatoria: 0 px\n";
        _terminal.printLine();
        std::cout << "(6) Agregar acción\n";
        std::cout << "(7) Editar acciones creadas\n";
        std::cout << "(8) Iniciar secuencia\n";
        _terminal.displayMenuFooter();

        selection = _validation.cinIntBetween(0, 9);

        switch (selection)
        {
            case 1:
                
                break;
            case 2:
                file();
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
        }
    }
    while (selection != 0);
}

void Menu::file()
{
    int selection = 1;

    do
    {
        _terminal.clear();
        _terminal.displayMenuHeader("Archivo");
        std::cout << "(1) Nuevo\n";
        std::cout << "(2) Abrir\n";
        std::cout << "(3) Guardar\n";
        std::cout << "(4) Eliminar\n";
        _terminal.displayMenuFooter();

        selection = _validation.cinIntBetween(0, 4);

        switch (selection)
        {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
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
        _terminal.displayMenuHeader("Ayuda");
        std::cout << "(1) Atajos del teclado\n";
        std::cout << "(2) Lenguajes\n";
        std::cout << "(3) Acerca de\n";
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
        _terminal.displayMenuHeader("Atajos del teclado");
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
        _terminal.displayMenuHeader("Lenguajes");
        std::cout << "(1) Inglés\n";
        std::cout << "(2) Español\n";
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