#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"

using namespace std;


class clsFindClientScreen : protected clsScreen
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

    protected:
        clsFindClientScreen();
        virtual ~clsFindClientScreen();

    public:

    static void FindClientScreen()
    {
           if(!CheckPermission(clsUser::enPermissions::pFindClient))
    {
        return;
    }

        _DrawScreenHeader("\t Find Client Screen");

   cout << "Pleas Enter Account Number: ";
   string AccountNumber = clsinput_Validation::ReadString();

   while(!clsBankClient::isClientExist(AccountNumber))
   {
       cout << "\nAccount Number Was Not Found, Pleas Try Again: ";
       AccountNumber = clsinput_Validation::ReadString();
   }

   clsBankClient Client = clsBankClient::Find(AccountNumber);

   if(!Client.isEmpty())
        {
        cout << "\n\nClient Found :-)\n";
        _Print(Client);
        }
    else
    {
        cout << "\n\nClient Was Not Found :-(";
    }

   }

};
