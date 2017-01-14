//*****//  Birth Year Header  //*****//
//Header file for Birth Year Source
//(C) Ethan Elliott 2015

#ifndef BIRTHYEAR_H
#define BIRTHYEAR_H
using namespace std;

class BirthYear
{
public:
    BirthYear(void);
    ~BirthYear(void);
    static BirthYear * instance;
    static BirthYear * GetInstance();

    void main();

private:
    Ethan * eby;
};

#endif // BIRTHYEAR_H
