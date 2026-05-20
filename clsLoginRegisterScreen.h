#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

 static void PrintLoginRegisterRecordLine(clsUser::stLoginRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.Date;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permission;
    }

    protected:
clsLoginRegisterScreen();
virtual ~clsLoginRegisterScreen();

    public:

    static void ShowLoginRegisterScreen()
    {
        if(!CheckPermission(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRecord> vLoginRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle =  "\t\t(" + to_string(vLoginRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRecord Record : vLoginRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};


