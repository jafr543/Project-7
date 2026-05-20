#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include <iostream>
#include <clsinput_Validation.h>
#include "Global.h"
#include "clsLoginRegister.h"
#include <cstdalign>

using namespace std;
class clsLoginScreen : protected clsScreen
{
    static bool Login()
    {
        bool LoginFailed = false;
        short LoginAttempts = 3;

        string UserName,Password;

        do
        {

            if(LoginFailed)
            {
                LoginAttempts --;

                if(LoginAttempts==0)
                {
                    cout << "\n\nYou have Exceeds the Trials of Login today!\n\n";
                    return false;
                }
                cout << "\nError Invalid Username/Password! Pleas Try Again:\n";
                cout << "You have [" << LoginAttempts << "] Trials left\n";

            }

            cout << "\nPleas Enter UserName: ";
            UserName = clsinput_Validation::ReadString();
            cout << "\nPleas Enter Password: ";
            Password = clsinput_Validation::ReadString();

            CurrentUser = clsUser::Find(UserName,Password);
            LoginFailed = CurrentUser.IsEmpty();

        }while(LoginFailed);

        clsUser::LoginRegister(CurrentUser);

        clsMainScreen::ShowMainMenue();
        return true;
    }


    protected:
clsLoginScreen();
virtual ~clsLoginScreen();

    public:
        static bool ShowLoginMenue()
        {
            system("cls");
            _DrawScreenHeader("\t Login Screen");
               return Login();
        }
};


