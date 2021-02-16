#include "FizEngine.h"

FizEngine::FizEngine()
{
    entitasok = new list<FizikObj*>();
}

FizEngine::~FizEngine()
{
    delete[] entitasok;
    delete entitasok;
}

void FizEngine::addEntitas(FizikObj* _entiti)
{
    entitasok->push_back(_entiti);
}

bool FizEngine::removEntitas(FizikObj* _entiti)
{
    entitasok->remove(_entiti);
    return true;
}
