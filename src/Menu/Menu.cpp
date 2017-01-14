//*****//  Menu Source  //*****//
//Contains functions for displaying and retreiving information from the menu
//(C) Ethan Elliott 2015

#include "..\EthanLib.h"

Menu * Menu::instance = NULL;

struct Selection
{
    char choice;
};

struct Selection u;

Menu::Menu()
{

}//Constructor

Menu::~Menu()
{
    delete instance;
}//Deconstructor

Menu * Menu::GetInstance()
{
    if(instance == NULL)
    {
        instance = new Menu();
    }
    return instance;
}

void Menu::ShowMenu()
{
    time_t mnow = time(0);
    tm * mtm = localtime(&mnow);
    cout << "\n\n";
    cout << "========================================================" << endl;
    cout << "=                                                      =" << endl;
    cout << "=         _____     _        _____                     =" << endl;
    cout << "=        |     |___|_|___   |     |___ ___ _ _         =" << endl;
    cout << "=        | | | | .'| |   |  | | | | -_|   | | |        =" << endl;
    cout << "=        |_|_|_|__,|_|_|_|  |_|_|_|___|_|_|___|        =" << endl;
    cout << "=                                                      =" << endl;
    cout << "========================================================" << endl;
    cout << "  Time: " << mtm->tm_hour << ":" << mtm->tm_min << ":" << mtm->tm_sec << "                      Date: " << mtm->tm_mday << "/" << (mtm->tm_mon+1) << "/" << (mtm->tm_year+1900) <<   endl;
    cout << "========================================================" << endl;
    for (int i = 0; i<MENU_SIZE; i++)
    {
        cout << "   " << i << ") " << mChoices[i] << "\n";
    }
    cout << "=========================================================" << endl;
}
void Menu::MenuChoice()
{
    cout << "Make a Selection: ";
    u.choice = getch();
}

void Menu::ShowChoice()
{
    cout << "\nChoice: " << u.choice <<"\n";
}

char Menu::GetChoice()
{
    switch (u.choice)
    {

    }
    return u.choice;
}
