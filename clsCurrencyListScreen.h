#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsinput_Validation.h"
#include "clsScreen.h"
#include "iomanip"

class clsCurrencyListScreen : protected clsScreen
{
        static void _PrintCurrencyinfo(clsCurrency Currency)
        {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
        }


    protected:
clsCurrencyListScreen();
virtual ~clsCurrencyListScreen();
    public:

        static void ShowCurrenciesList()
        {
            string Tital = "\tCurrencies List";
            vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
            string SubTital ="\t(" + to_string(vCurrencies.size()) + ") Currency";

            _DrawScreenHeader(Tital,SubTital);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

            if(vCurrencies.size()==0)
            {
                cout << "\n\n\t\tNo Currencies Available in the System!";
            }
            else
            {
                for(clsCurrency Currency : vCurrencies)
                {
                    _PrintCurrencyinfo(Currency);
                    cout << endl;
                }
            }

        }
};


