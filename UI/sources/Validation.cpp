#include "../headers/Validation.h"

int Validation::cinIntBetween(int min, int max)
{
    int rtn;

    while (true)
    {
        if (std::cin >> rtn && min <= rtn && rtn <= max)
        {
            break;
        }
        else
        {
            std::cin.clear();
            _terminal.cleanBuffer();

            if (min < max)
            {
                std::cout << "Error de validación. Ingrese un número entre " << min << " y " << max << ".\n";
            }
            else if (min == max)
            {
                std::cout << "Error de validación. Ingrese " << min << " para continuar.\n";
            }
            else
            {
                std::cout << "Error de validación. No es posible validar el número ingresado.\n";
            }
        }
    }

    return rtn;
}

bool Validation::cinBool()
{
    char input;
    bool rtn;

    while (true)
    {
        if (std::cin >> input && (input == 'y' || input == 'Y' || input == 's' || input == 'S' || input == 'n' || input == 'N'))
        {
            break;
        }
        else
        {
            std::cin.clear();
            _terminal.cleanBuffer();
            std::cout << "Error de validación: Ingresar 'S' para confirmar o 'N' para denegar.\n";
        }
    }

    if (input == 'y' || input == 'Y' || input == 's' || input == 'S')
    {
        rtn = true;
    }
    else
    {
        rtn = false;
    }

    return rtn;
}