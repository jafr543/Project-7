#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include <iomanip>

using namespace std;

class clsTransferScreen : protected clsScreen
{
    static void Printinfo(clsBankClient Client)
    {
        cout << "\nClient Card: \n\n";
        cout << "_________________________________\n\n";
        cout << "Full Name   : " << Client.GetFullName();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n\n__________________________________\n\n";
    }

    static string _ReadAccountNumber()
{
    string Account = clsinput_Validation::ReadString();

    while(!clsBankClient::isClientExist(Account))
    {
        cout << "\n\nAccount Number Not Found Pleas Try Again: ";
        Account = clsinput_Validation::ReadString();
    }
    return Account;
}
    static double _ReadAmount(clsBankClient SoursClient)
    {
    return clsinput_Validation::ReadDblNumberBetween
    (1,SoursClient.GetAccountBalance(), "Amount Exceeds Balance Please Try Again: ");

    }

    protected:
        clsTransferScreen();
        virtual ~clsTransferScreen();

    public:



        static void ShowTransferScreen()
        {
            _DrawScreenHeader("\t Transfer Screen");

            cout << "Pleas Enter Account Number to Transfer From: ";

            clsBankClient SoursClient = clsBankClient::Find(_ReadAccountNumber());
            Printinfo(SoursClient);

            cout << "Pleas Enter Account Number to Transfer to: ";

            clsBankClient DestinClient = clsBankClient::Find(_ReadAccountNumber());
            Printinfo(DestinClient);

            cout << "\n\nEnter Transfer Amount: ";
            double Amount = _ReadAmount(SoursClient);

            cout << "Are you sure to preform this Transaction? [Y/N]? ";
            char Answr = clsinput_Validation::ReadChar();

            if(toupper(Answr) == 'Y')
            {
            if(SoursClient.Transfer(Amount,DestinClient))
            {
                cout << "\n\n\tDone Successfully :-).\n\n";
                Printinfo(SoursClient);
                Printinfo(DestinClient);
            }
            else
            {
                cout << "\n\n\tError Amount Exceeds Balance!";
            }
            }
            else
            {
                cout << "\n\n\tTransaction was Cancel";
            }
        }
};
