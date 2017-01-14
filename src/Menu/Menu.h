//*****//  Menu Header  //*****//
//Header file for Menu Source
//(C) Ethan Elliott 2015

#ifndef MENU_H
#define MENU_H
#define MENU_SIZE 6
using namespace std;

class Menu
{
public:
    Menu(void);
    ~Menu(void);
    static Menu * instance;
    static Menu * GetInstance();

    struct Selection;

    string mChoices[MENU_SIZE]=
    {
        "Exit",
        "About",
        "Calculate your age!",
        "Odd or Even?",
        "Age Assignment",
        "Ticket Prices"
    };

    void ShowMenu();
    void MenuChoice();
    char GetChoice();
    void ShowChoice();


private:
};

#endif // MENU_H
