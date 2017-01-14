//*****//  Ticket Price Source  //*****//
//Source file for Ticket Price
//(C) Ethan Elliott 2015

#include "../EthanLib.h"

Tickets * Tickets::instance = NULL;

struct Receipt
{
    int blue;
    int green;
    int white;
    int red;
    int purple;
    float blueC = 35.000;
    float greenC = 31.500;
    float whiteC = 28.000;
    float redC = 23.750;
    float purpleC = 19.950;
};

struct Receipt R;

Tickets::Tickets()
{
    Tickets::et = new Ethan();
}

Tickets::~Tickets()
{
    delete instance;
}

Tickets * Tickets::GetInstance()
{
    if (instance == NULL)
    {
        instance = new Tickets();
    }
    return instance;
}

void Tickets::main()
{
    ShowTicketInformation();
}

void Tickets::ShowTicketInformation()
{
    bool isDone = false;
    while (!isDone)
    {
        et->Cls();
        cout << "=======================================================================" << endl;
        cout << " _  ____  _______  _________ ____  _____   _____   _____  _  _   __  _ " << endl;
        cout << "| ||  __||  ___  )|______  /|  __||  _  \\ |  _  \\ |  ___|| || | |  \\| |" << endl;
        cout << "| || |__ | |  / /       / / | |__ | |_)  )| |_)  )| |___ | || | |     |" << endl;
        cout << "| ||  __|| | / /       / /  |  __||  ___/ |  ___/ |  ___|| || | | |\\  |" << endl;
        cout << "| || |__ | |/ / ____  / /   | |__ | |     | |     | |    | || | | | \\ |" << endl;
        cout << "| ||____||   / /___/ / /    |____|| |     | |     | |    | ||_| | | | |" << endl;
        cout << "| |_____ |  /       / /__________ | |     | |     | |___ | |___ | | | |" << endl;
        cout << "|       || /       /             || |     | |     |     ||     || | | |" << endl;
        cout << "|_______||/       /______________||_|     |_|     |_____||_____||_| | |" << endl;
        cout << "                                                                    | |" << endl;
        cout << "                                                                   /__|" << endl;
        cout << "=======================================================================" << endl;
        cout << "                     Purchase Concert Tickets                          " << endl;
        cout << "=======================================================================" << endl;
        cout << "                   Seat Colour    |    Seat Cost                       " << endl;
        cout << "                ------------------|----------------                    " << endl;
        cout << "                      Blue        |     $35.00                         " << endl;
        cout << "                     Green        |     $31.50                         " << endl;
        cout << "                     White        |     $28.00                         " << endl;
        cout << "                       Red        |     $23.75                         " << endl;
        cout << "                    Purple        |     $19.95                         " << endl;
        cout << "=======================================================================" << endl;
        cout << "Note! If you dont want any of a certain ticket, put 0!\n\n";
        for (int x = 0; x < 5; x++)
        {
            int tickets = 0;
            cout << "\nHow many " << tChoices[x] << " tickets would you like?";
            while (!(cin >> tickets))
            {
                cerr << "WHOA! That's not a number!\nTry Again: ";
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            }
            switch (x)
            {
            case 0:
                R.blue = tickets;
                break;
            case 1:
                R.green = tickets;
                break;
            case 2:
                R.white = tickets;
                break;
            case 3:
                R.red = tickets;
                break;
            case 4:
                R.purple = tickets;
                break;
            }
        }
        et->Cls();
        PrintReceipt();
        cout << "\nDo you want to make a change? [y / n]";
        switch (getch())
        {
        case 'y':
            isDone = false;
            break;
        case 'n':
            isDone = true;
            break;
        default:
            isDone = true;
            break;
        }
    }
    et->Cls();
    PrintReceipt();
    cout << "\nDo you want to save your receipt? [y / n]";
    switch (getch())
    {
    case 'y':
        SaveReceipt();
        break;
    case 'n':
        break;
    default:
        break;
    }
    et->Pause("Pause");
    et->Cls();
}

void Tickets::PrintReceipt()
{
    cout << "=======================================================================" << endl;
    cout << " _  ____  _______  _________ ____  _____   _____   _____  _  _   __  _ " << endl;
    cout << "| ||  __||  ___  )|______  /|  __||  _  \\ |  _  \\ |  ___|| || | |  \\| |" << endl;
    cout << "| || |__ | |  / /       / / | |__ | |_)  )| |_)  )| |___ | || | |     |" << endl;
    cout << "| ||  __|| | / /       / /  |  __||  ___/ |  ___/ |  ___|| || | | |\\  |" << endl;
    cout << "| || |__ | |/ / ____  / /   | |__ | |     | |     | |    | || | | | \\ |" << endl;
    cout << "| ||____||   / /___/ / /    |____|| |     | |     | |    | ||_| | | | |" << endl;
    cout << "| |_____ |  /       / /__________ | |     | |     | |___ | |___ | | | |" << endl;
    cout << "|       || /       /             || |     | |     |     ||     || | | |" << endl;
    cout << "|_______||/       /______________||_|     |_|     |_____||_____||_| | |" << endl;
    cout << "                                                                    | |" << endl;
    cout << "                                                                   /__|" << endl;
    cout << "=======================================================================" << endl;
    cout << "       QTY      |                 ITEM                  |     TOTAL    " << endl;
    cout << "----------------|---------------------------------------|--------------" << endl;
    if (R.blue != 0)
    {
        cout << "      " << R.blue << (R.blue < 10 ? "\t" : "") << "\t|\t" << "Blue Tickets @ $35.00" << "\t\t|   $" <<  roundCost((R.blue*R.blueC),2) << endl;
    }
    if (R.green != 0)
    {
        cout << "      " << R.green << (R.green < 10 ? "\t" : "") << "\t|\t" << "Green Tickets @ $31.50" << "\t\t|   $" <<  roundCost((R.green*R.greenC),2) << endl;
    }
    if (R.white != 0)
    {
        cout << "      " << R.white << (R.white < 10 ? "\t" : "") << "\t|\t" << "White Tickets @ $28.00" << "\t\t|   $" <<  roundCost((R.white*R.whiteC),2) << endl;
    }
    if (R.red != 0)
    {
        cout << "      " << R.red << (R.red < 10 ? "\t" : "") << "\t|\t" << "Red Tickets @ $23.75" << "\t\t|   $" <<  roundCost((R.red*R.redC),2) << endl;
    }
    if (R.purple != 0)
    {
        cout << "      " << R.purple << (R.purple < 10 ? "\t" : "") << "\t|\t" << "Purple Tickets @ $19.95" << "\t\t|   $" <<  roundCost((R.purple*R.purpleC),2) << endl;
    }
    cout << "=======================================================================" << endl;
    cout << "SUBTOTAL\t\t\t\t\t\t    $" << roundCost(((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC)),2) << endl;
    cout << "TAX 13%\t\t\t\t\t\t\t    $" << roundCost((((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC))*0.13),2) << endl;
    cout << "=======================================================================" << endl;
    cout << "GRAND TOTAL\t\t\t\t\t\t    $" << roundCost((((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC))*1.13),2) << endl;
}

void Tickets::SaveReceipt()
{
    ofstream receipt ("receipt.txt");
    if (receipt.is_open())
    {
        receipt << "=======================================================================" << endl;
        receipt << " _  ____  _______  _________ ____  _____   _____   _____  _  _   __  _ " << endl;
        receipt << "| ||  __||  ___  )|______  /|  __||  _  \\ |  _  \\ |  ___|| || | |  \\| |" << endl;
        receipt << "| || |__ | |  / /       / / | |__ | |_)  )| |_)  )| |___ | || | |     |" << endl;
        receipt << "| ||  __|| | / /       / /  |  __||  ___/ |  ___/ |  ___|| || | | |\\  |" << endl;
        receipt << "| || |__ | |/ / ____  / /   | |__ | |     | |     | |    | || | | | \\ |" << endl;
        receipt << "| ||____||   / /___/ / /    |____|| |     | |     | |    | ||_| | | | |" << endl;
        receipt << "| |_____ |  /       / /__________ | |     | |     | |___ | |___ | | | |" << endl;
        receipt << "|       || /       /             || |     | |     |     ||     || | | |" << endl;
        receipt << "|_______||/       /______________||_|     |_|     |_____||_____||_| | |" << endl;
        receipt << "                                                                    | |" << endl;
        receipt << "                                                                   /__|" << endl;
        receipt << "=======================================================================" << endl;
        receipt << "       QTY      |                 ITEM                  |     TOTAL    " << endl;
        receipt << "----------------|---------------------------------------|--------------" << endl;
        if (R.blue != 0)
        {
            receipt << "      " << R.blue << (R.blue < 10 ? "\t" : "") << "\t|\t" << "Blue Tickets @ $35.00" << "\t\t|   $" <<  roundCost((R.blue*R.blueC),2) << endl;
        }
        if (R.green != 0)
        {
            receipt << "      " << R.green << (R.green < 10 ? "\t" : "") << "\t|\t" << "Green Tickets @ $31.50" << "\t\t|   $" <<  roundCost((R.green*R.greenC),2) << endl;
        }
        if (R.white != 0)
        {
            receipt << "      " << R.white << (R.white < 10 ? "\t" : "") << "\t|\t" << "White Tickets @ $28.00" << "\t\t|   $" <<  roundCost((R.white*R.whiteC),2) << endl;
        }
        if (R.red != 0)
        {
            receipt << "      " << R.red << (R.red < 10 ? "\t" : "") << "\t|\t" << "Red Tickets @ $23.75" << "\t\t|   $" <<  roundCost((R.red*R.redC),2) << endl;
        }
        if (R.purple != 0)
        {
            receipt << "      " << R.purple << (R.purple < 10 ? "\t" : "") << "\t|\t" << "Purple Tickets @ $19.95" << "\t\t|   $" <<  roundCost((R.purple*R.purpleC),2) << endl;
        }
        receipt << "=======================================================================" << endl;
        receipt << "SUBTOTAL\t\t\t\t\t\t    $" << roundCost(((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC)),2) << endl;
        receipt << "TAX 13%\t\t\t\t\t\t\t    $" << roundCost((((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC))*0.13),2) << endl;
        receipt << "=======================================================================" << endl;
        receipt << "GRAND TOTAL\t\t\t\t\t\t    $" << roundCost((((R.blue*R.blueC)+(R.green*R.greenC)+(R.white*R.whiteC)+(R.red*R.redC)+(R.purple*R.purpleC))*1.13),2) << endl;
        receipt.close();
    }
    else
    {
        cout << "Unable to save.";
    }
}

string Tickets::roundCost(const double x, const int decDigits)
{
    stringstream ss;
    ss << fixed;
    ss.precision(decDigits);
    ss << x;
    return ss.str();
}
