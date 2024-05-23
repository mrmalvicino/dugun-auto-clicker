#include "../headers/SequencesArchive.h"

SequencesArchive::SequencesArchive()
{
    setPath("registers/Sequences.dat");
}

SequencesArchive::SequencesArchive(std::string path)
{
    setPath(path);
}

void SequencesArchive::setPath(std::string path)
{
    _path = path;
}

std::string SequencesArchive::getPath()
{
    return _path;
}

bool SequencesArchive::write(Sequence & reg)
{
    FILE * filePointer = fopen(getPath().c_str(), "ab");

    if (filePointer == NULL) {
        std::cerr << "Error de archivo. No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successfulWrite = fwrite(& reg, sizeof(Sequence), 1, filePointer);
    fclose(filePointer);

    return successfulWrite;
}

bool SequencesArchive::overWrite(Sequence & reg, int index)
{
    FILE * filePointer = fopen(getPath().c_str(), "rb+");

    if (filePointer == NULL) {
        std::cerr << "Error de archivo. No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(filePointer, sizeof(Sequence) * index, 0);
    bool successfulWrite = fwrite(& reg, sizeof(Sequence), 1, filePointer);
    fclose(filePointer);

    return successfulWrite;
}

Sequence SequencesArchive::read(int index)
{
    Sequence reg;
    FILE * filePointer = fopen(getPath().c_str(), "rb");

    if (filePointer == NULL) {
        std::cerr << "Error de archivo. No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(filePointer, sizeof(Sequence) * index, 0);
    fread(& reg, sizeof(Sequence), 1, filePointer);
    fclose(filePointer);

    return reg;
}

int SequencesArchive::getIndex(int id)
{
    int i = 0;
    Sequence reg;
    reg = read(i);

    while (reg.getId() != id && i < getRegistersAmount()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int SequencesArchive::getIndex(std::string & name)
{
    int i = 0;
    Sequence reg;
    reg = read(i);

    while (reg.getName() != name && i < getRegistersAmount()) {
        i ++;
        reg = read(i);
    }

    if (i == getRegistersAmount()) {
        i = -1;
    }

    return i;
}

int SequencesArchive::getRegistersAmount()
{
    FILE * filePointer = fopen(getPath().c_str(), "rb");

    if (filePointer == NULL) {
        return 0;
    }

    fseek(filePointer, 0, SEEK_END);
    int bytes = ftell(filePointer);
    fclose(filePointer);
    int totalSequences = bytes / sizeof(Sequence);

    return totalSequences;
}

void SequencesArchive::createEmptyArchive()
{
    FILE * filePointer = fopen(getPath().c_str(), "wb");

    if (filePointer == NULL) {
        std::cerr << "Error de archivo. No se pudo abrir el archivo.\n";
    } else {
        fclose(filePointer);
    }
}