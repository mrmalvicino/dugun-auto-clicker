#include "../headers/SequencesManager.h"

bool SequencesManager::create()
{
    bool successful_write;
    bool user_wants_to_save;

    //_terminal.clear();
    //_terminal.displayMenuHeader("AGREGAR SEQUENCEE");

    _sequence.setId(generateId());
    //setear atributos name, loops, random, etc
    //setear atributos
    //setear atributos
    //setear atributos

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _validation.cinBool();

    if (user_wants_to_save == true)
    {
        successful_write = _sequencesArchive.write(_sequence);

        if (successful_write == true)
        {
            std::cout << "Registro guardado correctamente.\n";
        }
        else
        {
            std::cout << "Error de escritura.\n";
        }
    }
    else
    {
        successful_write = false;
        std::cout << "Registro descartado por usuario.\n";
    }

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

bool SequencesManager::update()
{
    _terminal.clear();

    int search_rtn = search();

    if (search_rtn == -1)
    {
        return false;
    }

    int selection = 1;

    do
    {
        //display menu

        selection = _validation.cinIntBetween(0, 7);

        switch (selection)
        {
            case 1:
                // menu
                break;
            case 2:
                // menu
                break;
        }
    }
    while (selection != 0);

    int index = _sequencesArchive.getIndex(_sequence.getId());
    bool successful_write = _sequencesArchive.overWrite(_sequence, index);

    return successful_write;
}

int SequencesManager::search()
{
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    // menu buscar por

    selection = _validation.cinIntBetween(0, 2);

    switch (selection)
    {
        case 0:
            search_rtn = -1;
            _terminal.clear();
            break;
        case 1:
            search_rtn = searchById();
            break;
        case 2:
            search_rtn = searchByName();
            break;
    }

    return search_rtn;
}

int SequencesManager::searchById()
{
    int search_rtn = 0;
    int index;
    int id;
    int max_id;

    max_id = _sequencesArchive.getRegistersAmount();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _validation.cinIntBetween(0, max_id);

    if (0 < id)
    {
        index = _sequencesArchive.getIndex(id);
        load(index);
        //print
    }
    else
    {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int SequencesManager::searchByName()
{
    int search_rtn = 0;
    int index;
    std::string description;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, description);

    index = _sequencesArchive.getIndex(description);

    while (index == -1)
    {
        std::cout << "No se encontró el registro " << description << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, description);

        if (description == "0")
        {
            index = -2;
        }
        else
        {
            index = _sequencesArchive.getIndex(description); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index)
    {
        load(index);
        //print
    }
    else
    {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void SequencesManager::list(bool list_actives, bool list_inactives)
{
    _terminal.clear();

    int amount_of_sequences = _sequencesArchive.getRegistersAmount();

    _terminal.displayMenuHeader("LISTADO DE SEQUENCEES");

    for (int i = 0; i < amount_of_sequences; i ++)
    {
        load(i);

        if ((_sequence.getStatus() == true && list_actives == true) || (_sequence.getStatus() == false && list_inactives == true))
        {
            //print();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void SequencesManager::load(int index)
{
    _sequence = _sequencesArchive.read(index);
}

int SequencesManager::generateId()
{
    int id = 1;

    if(_sequencesArchive.getRegistersAmount() != 0)
    {
        id = _sequencesArchive.getRegistersAmount() + 1;
    }

    return id;
}