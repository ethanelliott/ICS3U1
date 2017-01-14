//*****//  Basic Functions Header  //*****//
//Header file for Ethan's basic commands
//(C) Ethan Elliott 2015

#ifndef ETHAN_H
#define ETHAN_H
using namespace std;

class Ethan
{
public:
    Ethan();
    ~Ethan();

    void Test();//Test
    void Cls();//Cls
    void Printe(string out);
    string Gete(string prompt);
    void Pause(string text = "");
    void Exit();
    void ShowAbout();

private:
};

#endif // ETHAN_H
