#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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

   static void ReadClientNewinfo(clsBankClient &Client)
{
    clsinput_Validation input;

    cout << "First Name: ";
    Client.setFirstName(input.ReadString());
    cout << "\nLast Name: ";
    Client.setLastName(input.ReadString());
    cout << "\nEmail: ";
    Client.setEmail(input.ReadString());
    cout << "\nPhone: ";
    Client.setPhone(input.ReadString());
}

    protected:
        clsUpdateClientScreen();
        virtual ~clsUpdateClientScreen();

public:

static void UpdataClient()
{
       if(!CheckPermission(clsUser::enPermissions::pUpdateClients))
    {
        return;
    }


    _DrawScreenHeader("\t Update Client Screen");

    string AccountNumber;

    cout << "Pleas Enter Client Account Number: ";

    AccountNumber = clsinput_Validation::ReadString();

    while(clsBankClient::isClientExist(AccountNumber)==false)
    {
       cout << "Client Not Found Pleas Try Again!.\n\n";
       AccountNumber = clsinput_Validation::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    _Print(Client);

    char Answr = 'n';
    cout << "\nAre sure you want to Update this Client? [Y/N]: ";
    cin >> Answr;

    if(Answr == 'Y' || Answr == 'y')
    {
    cout << "\nEnter The New Info: \n\n============================\n\n";

    ReadClientNewinfo(Client);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = Client.Save();

    switch(SaveResult)
    {
    case clsBankClient::enSaveResult::enSvSucceeded:

        cout << "\n\nUpdate Save Successfully :-)\n";
        _Print(Client);
        break;

    case clsBankClient::enSaveResult::enSvFaildeEmptyObject:

        cout << "\n\nError Update Was Not Save Because it`s Empty!. ";
        break;
    }
    }
}

};


