#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsBankClient.h"
#include "Utility.h"
#include <cctype>
#include <iomanip>

using namespace std;


class clsTotalBalancesScreen : protected clsScreen
{
   static void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(20) << left << Client.GetFullName();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();

}
    protected:
clsTotalBalancesScreen();
virtual ~clsTotalBalancesScreen();
    public:

      static void ShowTotalBalancesScreen()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    string Title = "\t  ClientsList";

    string SubTitle = "\n\t\tClient List (" + to_string(vClients.size()) + ") Client(s).";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n_______________________________________________________" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\n\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double Balance = clsBankClient::GetClientsTotalBalance();
    cout << "\t\t\tTotal Balance = " << Balance << endl;

    cout << "\t\t\t" << clsUtility::NumberToText(Balance);
}
};
