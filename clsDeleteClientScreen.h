#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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
        clsDeleteClientScreen();
        virtual ~clsDeleteClientScreen();

    public:


       static void DeleteClient()
{
       if(!CheckPermission(clsUser::enPermissions::pDeleteClient))
    {
        return;
    }

    string Title = "\t Delete Client Screen";

    _DrawScreenHeader(Title);

    string AccountNumber;

    cout << "Pleas Enter Client Account Number: ";

    AccountNumber = clsinput_Validation::ReadString();

    while(!clsBankClient::isClientExist(AccountNumber))
    {
       cout << "Client Was Not Found Pleas Try Again!.\n\n";
       AccountNumber = clsinput_Validation::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    _Print(Client);

    cout << "\n\nAre you sure to Delete this Account? [Y/N] : ";
    char Answre = 'n';
    cin >> Answre;

    if(toupper(Answre)=='Y')
    {
        if(Client.Delete())
        {
            cout << "\n\nAccount Deleted Successfully\n";
            _Print(Client);
        }
        else
        {
            cout << "\n\nError Client Was Not Deleted! \n";
        }
    }
}

};
