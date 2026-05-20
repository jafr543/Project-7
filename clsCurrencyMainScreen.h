#pragma once
#include <iostream>
#include "clsString.h"
#include <iomanip>
#include "clsinput_Validation.h"
#include "clsScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyMainScreen : protected clsScreen
{
     enum enCurrencyMenueOptions {
            eCurrencyList = 1, eFindCurrency = 2, eCurrencyUpdateRate = 3,
            eCurrencyCalculator = 4, MainMenue = 5
        };

       static short _ReadCurrencyMenueOption()
        {
            cout << setw(18) << left << ""<< "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsinput_Validation::ReadShortNumberBetween(1,5,"Enter Number between 1 to 5? ");
            return Choice;
        }

       static  void _GoBackToCurrencyMenue()
        {
            cout << setw(20) << left << "" <<"\n\tPress any key to go back to Currency Menue...\n";

            system("pause>0");
            ShowCurrencyMainMenu();
        }

        static void _ShowCurrencyListScreen()
        {
            clsCurrencyListScreen::ShowCurrenciesList();
        }

        static void _ShowCurrencyFindScreen()
        {
            clsFindCurrencyScreen::ShowFindCurrencyScreen();
        }

        static void _ShowUpDateCurrencyRateScreen()
        {
            clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
        }

        static void _ShowCurrencyCalculatorScreen()
        {
           clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
        }


    static void PerformCurrencyMenuOption(enCurrencyMenueOptions CurrencyMenueOptions)
      {
          switch(CurrencyMenueOptions){

       case enCurrencyMenueOptions::eCurrencyList:
        {
           system("cls");
           _ShowCurrencyListScreen();
           _GoBackToCurrencyMenue();
           break;
        }

       case enCurrencyMenueOptions::eFindCurrency:
        {
         system("cls");
        _ShowCurrencyFindScreen();
        _GoBackToCurrencyMenue();
        break;
        }

       case enCurrencyMenueOptions::eCurrencyUpdateRate:
        {
            system("cls");
            _ShowUpDateCurrencyRateScreen();
            _GoBackToCurrencyMenue();
            break;
        }

       case enCurrencyMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMenue();
        break;
        }

       case enCurrencyMenueOptions::MainMenue:
        {
            //Main Menu Will Handle it :-)
        }
        }
        }


    protected:
clsCurrencyMainScreen();
virtual ~clsCurrencyMainScreen();

public:

    static void ShowCurrencyMainMenu()
    {
        system("cls");

            _DrawScreenHeader("\t Currency Main Menue");

            cout << setw(16) << left << "" << "===========================================\n";
            cout << setw(20) << left << "" << "\t\tMain Menue\n";
            cout << setw(16) << left << "" << "===========================================\n";
            cout << setw(20) << left << "" << "\t[1] List Currency.\n";
            cout << setw(20) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(20) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(20) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(20) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(16) << left << "" << "===========================================\n";

            PerformCurrencyMenuOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
    }
};
