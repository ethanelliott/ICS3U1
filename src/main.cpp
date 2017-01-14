#include "EthanLib.h"
//*****//  Main C++ File  //*****//
//Contains base commands and int main()
//(C) Ethan Elliott 2015

class EEMain
{
private:
    Ethan * E;
    Menu * eMenu;
    Age * ageCalc;
    OddEven * oddOrEven;
    BirthYear * birthYear;
    Tickets * ticketPrice;
    static EEMain* instance;
    bool done;
    //Private Variable Declerations

    //End Declerations
public:
    //Public Variable Decleration

    //End Declerations
    EEMain(void)
    {
        E = new Ethan();
        eMenu = Menu::GetInstance();
        ageCalc = new Age();
        oddOrEven = OddEven::GetInstance();
        birthYear = BirthYear::GetInstance();
        ticketPrice = Tickets::GetInstance();
        system("Title Ethan's Project");
        done = false;
    }//Contructor
    ~EEMain(void)
    {
        delete instance;
    }//Deconstructor
    static EEMain* GetInstance()
    {
        if (instance == NULL)
        {
            instance = new EEMain();
        }
        return instance;
    }//GetInstance
    bool isDone()
    {
        return done;   //isDone
    }
    //**********//  Main Functions   //**********//
    void MainInit()
    //Called once
    {
        while (true)
        {
            eMenu->ShowMenu();
            eMenu->MenuChoice();
            E->Cls();
            eMenu->ShowChoice();

            switch(eMenu->GetChoice())
            {
            case '\033':
                E->Exit();
                break;
            case '0':
                E->Exit();
                break;
            case '1':
                E->ShowAbout();
                break;
            case '2':
                ageCalc->main();
                break;
            case '3':
                oddOrEven->main();
                break;
            case '4':
                birthYear->main();
                break;
            case '5':
                ticketPrice->main();
                break;
            default:
                cout << "Invalid Selection!\n";
                break;
            }
        }
    }//MainInit

    //**********// End Main Functions    //**********//

};

EEMain* EEMain::instance = NULL;

int main()
{
    EEMain * codeBase;
    codeBase = EEMain::GetInstance();
    try
    {
        codeBase->MainInit();
    }
    catch (int e)
    {
        cout << "An exception occurred." << e << '\n';
    }
    return DEFAULT_RETURN_VAL;
}//main

//*****//  End Main C++ File  //*****//
