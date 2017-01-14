//*****//  Basic Functions Source  //*****//
//Contains basic commands and other cool stuff
//(C) Ethan Elliott 2015

#include "..\EthanLib.h"

Ethan::Ethan()
//Constructor
{

}//Ethan

Ethan::~Ethan()
//Deconstructor
{
}//~Ethan

void Ethan::Test()
{
    cout << "Hello World\n";
}//Test

void Ethan::Cls()
{
    system("cls");
}//cls

void Ethan::Printe(string out)
{
    cout << out << "\n";
}//Printe

string Ethan::Gete(string prompt)
{
    string x;
    cout << "\n" << prompt;
    x = "";
    cin >> x;
    return x;
}//Gete

void Ethan::Pause(string text)
{
    cout << "\n" << text;
    getch();
}//Pause

void Ethan::Exit()
{
    char x;
    cout << "\nAre you sure? [y/n]";
    x = getch();
    if(x == 'y')
    {
        cout << "\n\nClosing Program!\n\n";
        exit(0);
    }
    else
    {
        cout <<"\nNot Closing.\n";
    }
}

void Ethan::ShowAbout()
{

}
