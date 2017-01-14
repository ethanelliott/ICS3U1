//*****//  Ticket Price Header  //*****//
//Header file for Ticket Price Source
//(C) Ethan Elliott 2015

#ifndef TICKETS_H
#define TICKETS_H

using namespace std;

class Tickets
{
public:

    Tickets(void);
    ~Tickets(void);
    static Tickets * instance;
    static Tickets * GetInstance();

    struct Receipt;

    string tChoices[5] = {
            "Blue",
            "Green",
            "White",
            "Red",
            "Purple"
    };

    void main();
    void ShowTicketInformation();
    void PrintReceipt();
    void SaveReceipt();

    string roundCost(const double x, const int decDigits);

private:
    Ethan * et;
};

#endif // TICKETS_H
