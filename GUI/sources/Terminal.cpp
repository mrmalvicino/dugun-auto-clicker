#include "../headers/Terminal.h"

Terminal::Terminal()
{
    _lineWidth = 100;
    _lineCharacter = '-';
    setBackCaption("ATRÁS");
}

void Terminal::setLineWidth(int lineLenght)
{
    _lineWidth = lineLenght;
}

int Terminal::getLineWidth()
{
    return _lineWidth;
}

void Terminal::setLineCharacter(char lineCharacter)
{
    _lineCharacter = lineCharacter;
}

int Terminal::getLineCharacter()
{
    return _lineCharacter;
}

void Terminal::setBackCaption(std::string back_caption)
{
    strcpy(_backCaption, back_caption.c_str());
}

std::string Terminal::getBackCaption()
{
    return _backCaption;
}

void Terminal::clear()
{
    #ifdef _WIN64
        system("cls");
    #endif

    #ifdef __linux__
        system("clear");
    #endif

    #ifdef __APPLE__
        system("clear");
    #endif
}

void Terminal::pause()
{
    #ifdef _WIN64
        system("pause");
    #endif

    #ifdef __linux__
        int aux = 1;

        do{
            std::cout << "Ingresar 0 para continuar.\n";
            std::cin >> aux;
        } while (aux != 0);
    #endif

    #ifdef __APPLE__
        int aux = 1;
        std::cout << "\nIngresar 0 para continuar.\n";

        while (true) {
            if (std::cin >> aux && aux == 0) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Ingresar 0 para continuar.\n";
            }
        }
    #endif
}

void Terminal::printLine()
{
    for (int i = 0; i < _lineWidth; i ++) {
        std::cout << "-";
    }

    std::cout << "\n";
}

void Terminal::printCentered(std::string text)
{
    int blanks = (_lineWidth - text.length()) / 2;
    
    for (int i = 0; i < blanks; i ++) {
        std::cout << " ";
    }

    std::cout << text;

    for (int i = 0; i < blanks; i ++) {
        std::cout << " ";
    }

    std::cout << "\n";
}

void Terminal::printBackOption()
{
    std::cout << "(0) " << getBackCaption() << "\n";
}

void Terminal::displayMenuHeader(std::string title)
{
    printLine();
    printCentered(title);
    printLine();
}

void Terminal::displayMenuFooter()
{
    printLine();
    printBackOption();
}

void Terminal::configureUTF8()
{
    #ifdef _WIN64
        system("chcp 65001");
        system("Set-Culture es-ES");
    #endif
}

void Terminal::cleanBuffer()
{
    int aux;
    while ((aux = std::cin.get()) != '\n' && aux != EOF) {}
}