#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"
#include <cctype>
#include <iomanip>

using namespace std;

class clsDepositScreen : protected clsScreen
{
        static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
           cout << "\nPleas Enter AccountNumber: ";
          return AccountNumber = clsinput_Validation::ReadString();
    }

    protected:
        clsDepositScreen();
        virtual ~clsDepositScreen();

    public:

        static void ShowDepositScreen()
        {
           _DrawScreenHeader("\t Deposit Screen");

           string  AccountNumber = _ReadAccountNumber();
            while(!clsBankClient::isClientExist(AccountNumber))
            {
                cout << "\nAccount Not Found! Pleas Try Again: ";
                AccountNumber = clsinput_Validation::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);
            _Print(Client);

            cout << "\n\nPleas Enter Deposit Amount: ";
            double Amount = clsinput_Validation::ReadDblNumberBetween(1,5000, "Amount Exceeds the limit\n\nyou can Deposit up to 5000\n: ");

            cout << "Are sure to Perform this TransAction? [Y/N]: ";
            char Answr;
            cin >> Answr;

            if(toupper(Answr) == 'Y')
            {
                Client.Deposit(Amount);
                cout << "\n\n\tDo Successfully :-)";
                cout << "\n\t" << Client.GetAccountBalance();
            }
            else
            {
                cout << "\n\tTransaction Cancel!.";
                return;
            }

        }
};
