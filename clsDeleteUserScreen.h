#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsinput_Validation.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
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
clsDeleteUserScreen();
virtual ~clsDeleteUserScreen();

public:
       static void ShowDeleteUserScreen()
{
    _DrawScreenHeader("\t Delete User Screen");

    cout << "Pleas Enter User Name: ";

    string UserName = clsinput_Validation::ReadString();

    while(!clsUser::IsUserExist(UserName))
    {
       cout << "\n\nUser Was Not Found Pleas Try Again!: ";
       UserName = clsinput_Validation::ReadString();
    }

    clsUser User = clsUser::Find(UserName);
    _PrintUser(User);

    cout << "\n\nAre you sure to Delete this User? [Y/N] : ";
    char Answre = clsinput_Validation::ReadChar();

    if(toupper(Answre)=='Y')
     {
        if(User.Delete())
        {
            cout << "\n\nUser Deleted Successfully\n";
            _PrintUser(User);
        }

     }
    else
    {
            cout << "\n\nTransaction Cancel! \n";
    }
}
};


