#include "MyObj.h"

MyObj::MyObj(BaseFizikObj* _body, GrafikObj* _megjelenes)
{
    body = _body;
    megjelenes = _megjelenes;
}

MyObj::~MyObj()
{
  
}

BaseFizikObj* MyObj::getBody()
{
    return body;
}

GrafikObj* MyObj::getMegjelenes()
{
    return megjelenes;
}