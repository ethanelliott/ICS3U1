//*****//  Odd / Even Source  //*****//
//Contains functions for calculating whether a number is odd or even
//(C) Ethan Elliott 2015

#include "../EthanLib.h"

OddEven * OddEven::instance = NULL;

OddEven::OddEven()
{
    OddEven::eeo = new Ethan();
}//Constructor

OddEven::~OddEven()
{
    delete instance;
}

OddEven * OddEven::GetInstance()
{
    if(instance == NULL)
    {
        instance = new OddEven();
    }
    return instance;
}

void OddEven::main()
{
    bool isDone = false;
    int x = 0;
    while (!isDone)
    {
        cout << "\nCheck to see if a number is Odd or Even!\n";
        cout << "Enter a number: ";
        while (!(cin >> x))
        {
            cerr << "WHOA! That's not a number!\nTry Again: ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        switch (IsEven(x))
        {
        case true:
            cout << "\n\n" << x << " is an even number!\n\n";
            break;
        case false:
            cout << "\n\n" << x << " is an odd number!\n\n";
            break;
        default:
            break;
        }
        cout << "Do you want to calculate another? [y / n]\n";
        switch (getch())
        {
        case 'n':
            isDone = true;
            eeo->Cls();
            break;
        case 'y':
            isDone = false;
            eeo->Cls();
            break;
        default:
            isDone = false;
            eeo->Cls();
            break;
        }
    }


}

bool OddEven::IsEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
