#pragma once
#include <iostream>
#include "clsinput_Validation.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsAddNewClient : protected clsScreen
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

   static void ReadNewClient(clsBankClient &Client)
{
    cout << "\nFirst Name: ";
    Client.setFirstName(clsinput_Validation::ReadString());
    cout << "\nLast Name: ";
    Client.setLastName(clsinput_Validation::ReadString());
    cout << "\nEmail: ";
    Client.setEmail(clsinput_Validation::ReadString());
    cout << "\nPhone: ";
    Client.setPhone(clsinput_Validation::ReadString());
    cout << "\nPinCode: ";
    Client.SetPinCode(clsinput_Validation::ReadString());
    cout << "\nAccount Balance: ";
    Client.SetAccountBalance(clsinput_Validation::ReadFloatNumber());
}

protected:
        clsAddNewClient();
        virtual ~clsAddNewClient();

public:

static void AddNewClient()
{

   if(!CheckPermission(clsUser::enPermissions::pAddNewClient))
    {
        return;
    }

    _DrawScreenHeader("\t Add New Client Screen");

   cout << "Pleas Enter Account Number: ";
   string AccountNumber = clsinput_Validation::ReadString();

   while(clsBankClient::isClientExist(AccountNumber))
   {
       cout << "\nthis Account Number already Exist \n Pleas Try Again: ";
       AccountNumber = clsinput_Validation::ReadString();
   }

   clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

   ReadNewClient(Client);

   clsBankClient::enSaveResult SaveResult;
   SaveResult = Client.Save();

   switch(SaveResult)
   {
    case clsBankClient::enSaveResult::enSvSucceeded:

        cout << "\n\nAccount Added Successfully :-)\n";
        _Print(Client);
        break;

    case clsBankClient::enSaveResult::enSvFaildeEmptyObject:

        cout << "\n\nError Account Was Not Save Because it`s Empty!. ";
        break;

        case clsBankClient::enSaveResult::svFaildAccountNumberExists:

        cout << "\n\nError Account Was Not Save Because it`s already Exist!. ";
   }
}
};
