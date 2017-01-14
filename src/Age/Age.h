//*****//  Age Calculator Header  //*****//
//Header file for Age Calculator
//(C) Ethan Elliott 2015

#ifndef AGE_H
#define AGE_H
#define AGE_MENU_SIZE 9

using namespace std;

class Age
{
public:
    Age(void);      //Constructor
    ~Age(void);     //Deconstructor
    static Age * instance;  //Instance
    static Age * GetInstance();     //Get Instance

    struct Person;      //Person
    struct aChoice;     //aChoice

    int main();
    void GetAge();
    void CalcAge();
    int ShowAge();

    bool GetBirthYear(int year);
    bool GetBirthMonth(int month);
    bool GetBirthDay(int day);

    void CalcYear();
    void CalcWeek();
    void CalcMonth();
    void CalcDay();
    void CalcHour();
    void CalcMinute();
    void CalcSecond();
    void CalcExact();

    int FormatDate(int year, int month, int date);
    bool LeapYear(int year);
    int MonthLength(int month, int year);

    void ShowAgeMenu();
    void AgeMenuChoose();
    char GetAgeMenuChoice();

    string amChoices[AGE_MENU_SIZE]=
    {
        "Back",
        "Age in years",
        "Age in weeks",
        "Age in months",
        "Age in days",
        "Age in hours",
        "Age in minutes",
        "Age in seconds",
        "Exact Age"
    };//Menu Strings


private:
    Ethan * ea;
};

#endif // AGE_H
