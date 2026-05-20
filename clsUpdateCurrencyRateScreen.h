#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsinput_Validation.h"
#include "clsScreen.h"
#include "iomanip"


class clsUpdateCurrencyRateScreen : protected clsScreen
{
    static void _UpdateRate(clsCurrency Currency)
    {
        cout << "\n\nUpdate Currency Rate: \n";
        cout << "\n______________________________________\n";
        cout << "\nEnter New Rate: ";

        float NewRate = clsinput_Validation::ReadFloatNumber();

        Currency.UpdateRate(NewRate);

      cout << "\n\nCurrency Rate Update Successfully :-)";
     _PrintCurrencyinfo(Currency);
    }

    static void _PrintCurrencyinfo(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "\n________________________________________\n";
        cout << "\nCountry : " << Currency.Country();
        cout << "\nCode    : " << Currency.CurrencyCode();
        cout << "\nName    : " << Currency.CurrencyName();
        cout << "\nRate(1$): " << Currency.Rate();
        cout << "\n\n________________________________________\n\n";
    }


    protected:
clsUpdateCurrencyRateScreen();
virtual ~clsUpdateCurrencyRateScreen();
    public:

        static void ShowUpdateCurrencyRateScreen()
        {
            _DrawScreenHeader("\t Update Currency Rate Screen");

            cout << "Please Enter Currency Code: ";
            string CurrencyCode = clsinput_Validation::ReadString();

            while(!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                cout << "\n\nCurrency Not Found Please Try Again: ";
                CurrencyCode = clsinput_Validation::ReadString();
            }


              clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
              _PrintCurrencyinfo(Currency);

            cout << "Are you sure you want to Update the Rate of this Currency? [Y/N] ";
            char Answer = clsinput_Validation::ReadChar();

            if(toupper(Answer) == 'Y')
            {
                _UpdateRate(Currency);

            }
            else
            {
                cout << "\n\nTransaction was cancel \n\n";
            }

        }
};


