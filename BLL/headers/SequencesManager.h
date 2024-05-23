#pragma once
#include <iostream>
#include "../../UI/headers/Terminal.h"
#include "../../UI/headers/Validation.h"
#include "../../DML/headers/Sequence.h"
#include "../../DAL/headers/SequencesArchive.h"

class SequencesManager
{
    public:

    bool create();

    bool update();

    int search();

    int searchById();

    int searchByName();

    void list(bool list_actives = true, bool list_inactives = true);

    void load(int index);

    int generateId();

    private:

    Terminal _terminal;

    Validation _validation;

    Sequence _sequence;

    SequencesArchive _sequencesArchive;
};