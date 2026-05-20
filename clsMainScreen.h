#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsShowClientsList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersMenue.h"
#include "clsLoginRegister.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"
#include "clsUser.h"
#include "Global.h"
#include <iomanip>


using namespace std;


class clsMainScreen : protected clsScreen
{

        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8, eCurrencyMenu = 9
            , eExit = 10
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(18) << left << ""<< "Choose what do you want to do? [1 to 10]? ";
            short Choice = clsinput_Validation::ReadShortNumberBetween(1,10,"Enter Number between 1 to 10? ");
            return Choice;
        }

       static  void _GoBackToMainMenue()
        {
            cout << setw(20) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";

            system("pause>0");
            ShowMainMenue();
        }

       static void _ShowAllClientsScreen()
       {
           clsShowClientsList::ShowClientsList();
       }

       static void _ShowAddNewClientsScreen()
       {
           clsAddNewClient::AddNewClient();
       }

       static void _ShowDeleteClientScreen()
       {
           clsDeleteClientScreen::DeleteClient();

       }

       static void _ShowUpdateClientScreen()
       {
           clsUpdateClientScreen::UpdataClient();
       }

       static void _ShowFindClientScreen()
       {
           clsFindClientScreen::FindClientScreen();

       }

       static void _ShowTransactionsMenue()
       {
           clsTransactionsScreen::ShowTransactionsMenue();
       }

       static void _ShowManageUsersMenue()
       {
           clsManageUsersMenue::ShowManageUsersMenue();

       }

       static void _ShowLoginRegisterScreen()
       {
           clsLoginRegisterScreen::ShowLoginRegisterScreen();
       }

       static void _ShowCurrencyMenue()
       {
           clsCurrencyMainScreen::ShowCurrencyMainMenu();
       }

       static void _Login()
       {
           return;
       }

       static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                system("cls");
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                system("cls");
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                system("cls");
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eLoginRegister:
                system("cls");
                _ShowLoginRegisterScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eCurrencyMenu:
                system("cls");
                _ShowCurrencyMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eExit:
                system("cls");
                _Login();
                break;
            }

        }



public:

clsMainScreen();
virtual ~clsMainScreen();

       static void ShowMainMenue()
        {

            system("cls");
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(16) << left <<""<< "===========================================\n";
            cout << setw(20) << left << "" << "\t\tMain Menue\n";
            cout << setw(16) << left << "" << "===========================================\n";
            cout << setw(20) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(20) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(20) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(20) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(20) << left << "" << "\t[5] Find Client.\n";
            cout << setw(20) << left << "" << "\t[6] Transactions.\n";
            cout << setw(20) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(20) << left << "" << "\t[8] LoginRegisters.\n";
            cout << setw(20) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(20) << left << "" << "\t[10] Logout.\n";
            cout << setw(16) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }

};
