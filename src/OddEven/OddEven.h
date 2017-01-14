//*****//  Odd / Even Header  //*****//
//Header file for Odd / Even Source
//(C) Ethan Elliott 2015

#ifndef ODDEVEN_H
#define ODDEVEN_H
using namespace std;

class OddEven
{
public:
    OddEven(void);
    ~OddEven(void);
    static OddEven * instance;
    static OddEven * GetInstance();

    void main();
    bool IsEven(int num);

private:
    Ethan * eeo;
};


#endif // ODDEVEN_H
