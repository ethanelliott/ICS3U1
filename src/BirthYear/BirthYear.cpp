//*****//  Birth Year Source  //*****//
//Contains functions for calculating birth year.
//(C) Ethan Elliott 2015

#include "../EthanLib.h"

BirthYear * BirthYear::instance = NULL;

BirthYear::BirthYear()
{
    eby = new Ethan();
}

BirthYear::~BirthYear()
{
    delete instance;
}

BirthYear * BirthYear::GetInstance()
{
    if (instance == NULL)
    {
        instance = new BirthYear;
    }
    return instance;
}

void BirthYear::main()
{

}
