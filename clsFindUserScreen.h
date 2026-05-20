#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsinput_Validation.h"

using namespace std;


class clsFindUserScreen : protected clsScreen
{
        static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

    protected:
        clsFindUserScreen();
        virtual ~clsFindUserScreen();

    public:

    static void ShowFindUserScreen()
{
    _DrawScreenHeader("\tFind User Screen");

    cout << "Pleas Enter User Name: ";

    string UserName = clsinput_Validation::ReadString();

    while(!clsUser::IsUserExist(UserName))
    {
       cout << "\n\nUser Was Not Found Pleas Try Again!: ";
       UserName = clsinput_Validation::ReadString();
    }

    clsUser User = clsUser::Find(UserName);

    if(User.IsEmpty())
    {
        cout << "\nUser Not Found :-(";
    }
    else
    {
        cout << "\nUser Found :-)\n";
    }
    _PrintUser(User);
}

};
