#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsinput_Validation.h"
#include "clsScreen.h"
#include "iomanip"

class clsFindCurrencyScreen : protected clsScreen
{

    static void _PrintCurrencyinfo(clsCurrency Currency)
    {
        cout << "Currency Card:\n";
        cout << "\n________________________________________\n";
        cout << "\nCountry : " << Currency.Country();
        cout << "\nCode    : " << Currency.CurrencyCode();
        cout << "\nName    : " << Currency.CurrencyName();
        cout << "\nRate(1$): " << Currency.Rate();
        cout << "\n\n________________________________________\n\n";
    }

    static void _ShowResult(clsCurrency Currency)
    {
        if(!Currency.IsEmpty())
        {
          cout << "\nCurrency Found :-) \n\n";
          _PrintCurrencyinfo(Currency);

        }
       else
        {
          cout << "\n\nCurrency Not Found :-(\n\n";
        }

    }

    protected:
clsFindCurrencyScreen();
virtual ~clsFindCurrencyScreen();
    public:

      static void ShowFindCurrencyScreen()
      {
          _DrawScreenHeader("\t Find Currency Screen");

          cout << "Find By: [1] Code or [2] Country? ";
          short Answr = clsinput_Validation::ReadShortNumberBetween(1,2,"\nPleas Select Between 1 or 2: ");

          if(Answr == 1)
          {
              cout << "\n\nPlease Enter CurrencyCode: ";
              string CurrencyCode = clsinput_Validation::ReadString();
              clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
              _ShowResult(Currency);
          }
          else
          {
              cout << "\n\nPlease Enter Country Name: ";
              string CountryName = clsinput_Validation::ReadString();
              clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
              _ShowResult(Currency);

          }

      }

};


