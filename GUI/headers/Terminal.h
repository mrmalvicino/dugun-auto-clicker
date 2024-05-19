#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

class Terminal {
    public:

    Terminal();

    void setLineWidth(int lineLenght);

    int getLineWidth();

    void setLineCharacter(char lineCharacter);

    int getLineCharacter();

    void setBackCaption(std::string backCaption);

    std::string getBackCaption();

    void clear();

    void pause();

    void printLine();

    void printCentered(std::string text);

    void printBackOption();

    void displayMenuHeader(std::string title);

    void displayMenuFooter();

    void configureUTF8();

    void cleanBuffer();

    private:

    int _lineWidth;

    char _lineCharacter;

    char _backCaption[30];
};