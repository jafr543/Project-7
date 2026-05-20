#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
#include <ctime>
#include <iomanip>

using namespace std;
class clsScreen
{
    static void GetSystemTime()
    {
       {
               time_t t = time(0);
                 tm* now = localtime(&t);

        cout << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900 ;

       }
    }

       protected :
clsScreen();
virtual ~clsScreen();

    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t\t__________________________________________";
        cout << "\n\n\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t  " << SubTitle;
        }
        cout << "\n\t\t__________________________________________\n\n";

        cout << "\t\t\tUser:" << CurrentUser.GetUserName();
        cout << "\n\t\t\tDate:" << clsDate::DateToString(1) << "\n\n" << endl;

    }


    static bool CheckPermission(clsUser::enPermissions Permission)
    {
        if(!CurrentUser.CheckAccessPermission(Permission))
        {
        cout << "\t\t__________________________________________";
        cout << "\n\n\t\tAccess Denied Pleas contact your Admen ";
        cout << "\n\t\t__________________________________________\n\n";

        return false;
        }
        else
        {
            return true;
        }
    }

};


