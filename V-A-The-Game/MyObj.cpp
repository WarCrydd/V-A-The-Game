#include "MyObj.h"

MyObj::MyObj(FizikObj* _body, GrafikObj* _megjelenes)
{
    body = _body;
    megjelenes = _megjelenes;
}

MyObj::~MyObj()
{
  
}

FizikObj* MyObj::getBody()
{
    return body;
}

GrafikObj* MyObj::getMegjelenes()
{
    return megjelenes;
}