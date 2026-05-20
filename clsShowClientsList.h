#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

class clsShowClientsList : protected clsScreen
{
    static void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(20) << left << Client.GetFullName();
    cout << "| " << setw(12) << left << Client.GetPhone();
    cout << "| " << setw(20) << left << Client.GetEmail();
    cout << "| " << setw(10) << left << Client.GetPinCode();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();

}

    protected:
clsShowClientsList();
virtual ~clsShowClientsList();


    public:



static void ShowClientsList()
{
       if(!CheckPermission(clsUser::enPermissions::pListClients))
    {
        return;
    }


    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    string Title = "\t  ClientsList";

    string SubTitle = "\n\t\tClient List (" + to_string(vClients.size()) + ") Client(s).";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}
};
