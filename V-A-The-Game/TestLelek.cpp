#include "TestLelek.h"

TestLelek::TestLelek(BaseFizikObj* _b) : ElemiLelek(_b)
{
}

void TestLelek::mozgasIgeny(MyPoint* vector)
{
    MyPoint* gyorsulas = test->getMozgasAllapot()->getSebesseg();

    *gyorsulas += *vector;
}
