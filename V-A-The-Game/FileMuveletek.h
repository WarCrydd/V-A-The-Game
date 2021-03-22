#pragma once
#include <fstream>
#include <list>
#include <string>
#include <array>

#include "ElemiFizikObj.h"

using namespace std;
namespace FileMuveletek
{
    static void fizikObjektumokBeOlvas(list<BaseFizikObj*>* lista, string file)
    {
        ifstream myfile;
        myfile.open(file, ios::binary);

    };
}
