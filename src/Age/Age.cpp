//*****//  Age Calculator Source  //*****//
//Contains commands for calculating age
//(C) Ethan Elliott 2015

#include "..\EthanLib.h"

Age * Age::instance = NULL;

struct Person
{
    string name;

    int birthY;
    int birthM;
    int birthD;

    int birthDate;

    int ageY;
    int ageW;
    int ageM;
    int ageD;
    int ageH;
    int ageMi;
    int ageS;
    string ageT;

    string ERROR_STRING;

};//Person

struct aChoice
{
    char choice;
};//aChoice

struct Person user;
struct aChoice ac;

Age::Age()
{
    Age::ea = new Ethan();

    user.ageD = 0;
    user.ageH = 0;
    user.ageM = 0;
    user.ageMi = 0;
    user.ageS = 0;
    user.ageW = 0;
    user.ageY = 0;
    user.birthD = 0;
    user.birthDate = 0;
    user.birthM = 0;
    user.birthY = 0;
    user.name = "";
    user.ERROR_STRING = "";
}//Constructor

Age::~Age()
{
    delete instance;
}//Deconstructor

Age * Age::GetInstance()
{
    if (instance == NULL)
    {
        instance = new Age();
    }
    return instance;
}//GetInstance

int Age::main()
{
    GetAge();

    CalcAge();

    if(ShowAge()==0)
    {
        return 0;
    }
    return 0;
}//CalcMain

void Age::GetAge()
{
    //Reset all values
    user.ageD = 0;
    user.ageH = 0;
    user.ageM = 0;
    user.ageMi = 0;
    user.ageS = 0;
    user.ageW = 0;
    user.ageY = 0;
    user.birthD = 0;
    user.birthDate = 0;
    user.birthM = 0;
    user.birthY = 0;
    user.name = "";
    user.ERROR_STRING = "WHOA! That's not the value I'm looking for...";

    //Get info from user
    cout << "\n\nLet's get some information from you first.\n\n";
    cout << "\nEnter your name:  ";
    cin >> user.name;
    cout << "\nHello " << user.name << "\n";

    while(!GetBirthYear(user.birthY))
    {
        cout <<"\nEnter your Birth Year (YYYY):  ";
        while (!(cin >> user.birthY))
        {
            cerr << "WHOA! That's not a number!\nTry Again: ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        if(GetBirthYear(user.birthY)!=true)
        {
            cerr << user.ERROR_STRING << "\nTry Again: ";
        }
    }

    while(!GetBirthMonth(user.birthM))
    {
        cout <<"\nEnter your Birth Month (MM):  ";
        while (!(cin >> user.birthM))
        {
            cerr << "WHOA! That's not a number!\nTry Again: ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        if(GetBirthMonth(user.birthM)!=true)
        {
            cerr << user.ERROR_STRING << "\nTry Again: ";
        }
    }
    while(!GetBirthDay(user.birthD))
    {
        cout <<"\nEnter your Birth Day (DD):  ";
        while (!(cin >> user.birthD))
        {
            cerr << "WHOA! That's not a number!\nTry Again: ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        if(GetBirthDay(user.birthD)!=true)
        {
            cerr << user.ERROR_STRING << "\nTry Again: ";
        }
    }

    //format birthdate
    user.birthDate = FormatDate(user.birthY,user.birthM,user.birthD);
    cout << "\n" << user.birthDate << endl << endl;
    cout << "\n";
}//GetAge

void Age::CalcAge()
{
    //Calculate Year
    CalcYear();
    //Calculate Month
    CalcMonth();
    //Calculate Days
    CalcDay();
    //Calcuate Weeks
    CalcWeek();
    //Calculate Hours
    CalcHour();
    //Calculate Minutes
    CalcMinute();
    //Calculate Seconds
    CalcSecond();

    //Calculate Current Exact Age
    CalcExact();


    ea->Pause("\nEverything Seems Good! \nPress any key to continue.");
    ea->Cls();
}//CalcAge

int Age::ShowAge()
{
    while (true)
    {
        ShowAgeMenu();
        AgeMenuChoose();
        switch(GetAgeMenuChoice())
        {
        case '0':
            ea->Cls();
            return 0;
            break;
        case '1':
            ea->Cls();
            cout << "\n\nYou are " << user.ageY << " years old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '2':
            ea->Cls();
            cout << "\n\nYou are " << user.ageW << " weeks old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '3':
            ea->Cls();
            cout << "\n\nYou are " << user.ageM << " months old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '4':
            ea->Cls();
            cout << "\n\nYou are " << user.ageD << " days old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '5':
            ea->Cls();
            cout << "\n\nYou are " << user.ageH << " hours old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '6':
            ea->Cls();
            cout << "\n\nYou are " << user.ageMi << " minutes old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '7':
            ea->Cls();
            cout << "\n\nYou are " << user.ageS << " seconds old!\n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        case '8':
            ea->Cls();
            cout << "\n\n" << user.ageT << " \n\n";
            ea->Pause("Press any key to return to the menu.");
            ea->Cls();
            break;
        default:
            ea->Cls();
            cout << "Invalid Selection!\n";

            break;
        }
    }
}//ShowAge

bool Age::GetBirthYear(int year)
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    if (year == 0)
    {
        return false;
    }
    else
    {
        if ((year >= 1900) && (year < (ltm->tm_year)+1900))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}//GetBirthYear

bool Age::GetBirthMonth(int month)
{
    if (month == 0)
    {
        return false;
    }
    else
    {
        if (month <=12 && month >=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}//GetBirthMonth

bool Age::GetBirthDay(int day)
{
    if (day == 0)
    {
        return false;
    }
    else
    {
        if(day > 0 && day < MonthLength(user.birthM,user.birthY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}//GetBirthDay

void Age::CalcYear()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    if((user.birthM)-(ltm->tm_mon+1) <= 0)
    {
        user.ageY = (((ltm->tm_year + 1900) - (user.birthY)));
    }
    else if((user.birthM)-(ltm->tm_mon+1) > 0)
    {
        user.ageY = (((ltm->tm_year + 1900) - (user.birthY+1)));
    }
}//CalcYear

void Age::CalcWeek()
{
    user.ageW = ((user.ageD - (user.ageD%7))/7);
}//CalcWeek

void Age::CalcMonth()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    if((user.birthM)-(ltm->tm_mon+1) <= 0)
    {
        user.ageM = ((((ltm->tm_year + 1900) - (user.birthY))*12)+ (abs((user.birthM)-(ltm->tm_mon+1))));
    }
    else if((user.birthM)-(ltm->tm_mon+1) > 0)
    {
        if (ltm->tm_mday > user.birthD)
        {
            user.ageM = ((((ltm->tm_year + 1900) - (user.birthY))*12) - (abs((user.birthM+1)-(ltm->tm_mon+2))));
        }
        else
        {
            user.ageM = ((((ltm->tm_year + 1900) - (user.birthY))*12) - (abs((user.birthM+1)-(ltm->tm_mon+1))));
        }
    }
}//CalcMonth

void Age::CalcDay()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    for (int year = user.birthY; year <= (ltm->tm_year + 1900); year++)
    {
        if (year == user.birthY)
        {
            for (int month = (user.birthM); month <= 12; month++)
            {
                if (month == user.birthM)
                {
                    user.ageD += (MonthLength(month,year) - user.birthD);
                }
                else
                {
                    user.ageD += MonthLength(month,year);
                }
            }
        }
        else if (year == (ltm->tm_year + 1900))
        {
            for (int month = 1; month <= (ltm->tm_mon+1); month++)
            {
                if (month == (ltm->tm_mon+1))
                {
                    if (user.birthD < ltm->tm_mday)
                    {
                        user.ageD +=  ltm->tm_mday;
                    }
                    else if (user.birthD > ltm->tm_mday)
                    {
                        user.ageD += ltm->tm_mday;
                    }
                }
                else
                {
                    user.ageD += MonthLength(month,year);
                }
            }
        }
        else
        {
            for (int month = 1; month <= 12; month++)
            {
                user.ageD += MonthLength(month,year);
            }
        }
    }
}//CalcDay

void Age::CalcHour()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    user.ageH = (user.ageD * 24) + ltm->tm_hour;
}//CalcHour

void Age::CalcMinute()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    user.ageMi = (user.ageD * 1440) + (ltm->tm_hour * 60) + ltm->tm_min;
}//CalcMinute

void Age::CalcSecond()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    user.ageS = (user.ageD *86400) + (ltm->tm_hour * 3600) + (ltm->tm_min * 60) + ltm->tm_sec;
}//CalcSecond

void Age::CalcExact()
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    stringstream sstm;
    if (((MonthLength((ltm->tm_mon+1),(ltm->tm_year+1900)) - user.birthD) + ltm->tm_mday) > MonthLength((ltm->tm_mon+1),(ltm->tm_year+1900)))
    {
        sstm << "You are: " << user.ageY << " years, " << ((user.ageM+1)-(user.ageY*12)) << " months, " << (ltm->tm_mday) << " days, " << ltm->tm_hour << " hours, " << ltm->tm_min << " minutes and " << ltm->tm_sec << " seconds Old";
    }
    else
    {
        sstm << "You are: " << user.ageY << " years, " << (user.ageM-(user.ageY*12)) << " months, " << ((MonthLength((ltm->tm_mon+1),(ltm->tm_year+1900)) - user.birthD) + ltm->tm_mday) << " days, " << ltm->tm_hour << " hours, " << ltm->tm_min << " minutes and " << ltm->tm_sec << " seconds Old";
    }

    user.ageT = sstm.str();
}//CalcExact

int Age::FormatDate(int year, int month, int date)
{
    return (date*1000000) + (month*10000) + (year);
}//Format Date

bool Age::LeapYear(int year)
{
    if(year%4 == 0)
    {
        if ((year%100 == 0) && (year%400 != 0))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}//LeapYear

int Age::MonthLength(int month, int year)
{
    if ((month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10)||(month == 12))
    {
        return 31;
    }
    else
    {
        if (month == 2)
        {
            if(LeapYear(year) == true)
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else
        {
            return 30;
        }
    }
}//MonthLength

void Age::ShowAgeMenu()
{
    cout << "\n\n";
    cout << "============================================================" << endl;
    cout << "=  _____            _____     _         _     _            =" << endl;
    cout << "= |  _  |___ ___   |     |___| |___ _ _| |___| |_ ___ ___  =" << endl;
    cout << "= |     | . | -_|  |   --| .'| |  _| | | | .'|  _| . |  _| =" << endl;
    cout << "= |__|__|_  |___|  |_____|__,|_|___|___|_|__,|_| |___|_|   =" << endl;
    cout << "=       |___|                                              =" << endl;
    cout << "============================================================" << endl;
    for (int i = 0; i<AGE_MENU_SIZE; i++)
    {
        cout << "   " << i << ") " << amChoices[i] << "\n";
    }
    cout << "=========================================================" << endl;

}//ShowAgeMenu

void Age::AgeMenuChoose()
{
    cout << "Make a Selection: ";
    ac.choice = getch();
}//AgeMenuChoose

char Age::GetAgeMenuChoice()
{
    return ac.choice;
}//GetMenuChoice

//*****//  End Ethan's Age Calculator  //*****//
