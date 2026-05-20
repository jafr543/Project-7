#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"
#include <cctype>
#include <iomanip>

using namespace std;

class clsWithdrawScreen : protected clsScreen
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
        clsWithdrawScreen();
        virtual ~clsWithdrawScreen();

    public:

        static void WithdrawScreen()
        {
            _DrawScreenHeader("\t Withdraw Screen");

           string  AccountNumber = _ReadAccountNumber();
            while(!clsBankClient::isClientExist(AccountNumber))
            {
                cout << "\nAccount Not Found! Pleas Try Again: ";
                AccountNumber = clsinput_Validation::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);
            _Print(Client);

            cout << "\n\nPleas Enter Withdraw Amount: ";
            double Amount;
            Amount = clsinput_Validation::ReadDblNumberBetween(1,Client.GetAccountBalance(), "\nAmount is Exceeds Balance!,Pleas Try Again: ");

            cout << "Are sure to Perform this TransAction? [Y/N]: ";
            char Answr = clsinput_Validation::ReadChar();;


            if(toupper(Answr) == 'Y')
            {
                Client.Withdraw(Amount);
                cout << "\n\nDo Successfully :-)";
                cout << "\n\nThe New Balance is: " << Client.GetAccountBalance();
            }
            else
            {
                cout << "\n\tTransaction Cancel!.";
                return;
            }


        }

};


