#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsinput_Validation.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

     static bool AnswerPermission()
{
  char Answer = clsinput_Validation::ReadChar();

  return (toupper(Answer)=='Y');
}

static int _ReadPermissionsToSet()
{

    int Permission = 0;
    cout << "\nDo you Want to Give Full Permissions?[Y/N]: ";
    if(AnswerPermission())
    {
       return Permission = -1;

    }

    cout << "\nDo you want to give Access to: \n\n";

    cout << "Client List? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission = (clsUser::enPermissions::pListClients);
    }

    cout << "\nAdd New Client? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pAddNewClient);
    }

    cout << "\nDelete Client? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pDeleteClient);
    }

    cout << "\nUpdate Client? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pUpdateClients);
    }

    cout << "\nFind Client? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pFindClient);
    }

    cout << "\nTransaction? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pTranactions);
    }

    cout << "\nMange Users? [Y/N]";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pManageUsers);
    }

    cout << "\nLoginRegister Screen? [Y/N]? ";
    if(AnswerPermission())
    {
        Permission += (clsUser::enPermissions::pLoginRegister);
    }

    return Permission;

}

      static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.setFirstName(clsinput_Validation::ReadString());

        cout << "\nEnter LastName: ";
        User.setLastName(clsinput_Validation::ReadString());

        cout << "\nEnter Email: ";
        User.setEmail(clsinput_Validation::ReadString());

        cout << "\nEnter Phone: ";
        User.setPhone(clsinput_Validation::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsinput_Validation::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

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
        clsAddNewUserScreen();
        virtual ~clsAddNewUserScreen();

    public:

       static void ShowAddNewUserScreen()
        {
            _DrawScreenHeader("\t Add New User Screen ");
              cout << "\nEnter User Name? ";

    string UserName = clsinput_Validation::ReadString();

    while(clsUser::IsUserExist(UserName))
    {
        cout << "\nUserName already Exist! Pleas Try another one: ";
        UserName = clsinput_Validation::ReadString();
    }

    clsUser User = clsUser::GetAddNewUserObject(UserName);

    _ReadUserInfo(User);

     clsUser::enSaveResults SaveResults;
     SaveResults = User.Save();

     switch(SaveResults)
     {
     case clsUser::enSaveResults::svSucceeded:
        cout << "\n\nNew User Added Successfully :-)";
        _PrintUser(User);
        break;

     case clsUser::enSaveResults::svFaildEmptyObject:
        cout << "\n\nError User was Not Save Because it`s Empty! ";
        break;

     case clsUser::enSaveResults::svFaildUserExists:
        cout << "\n\nError User was Not Save Because it`s already Exist!";
        break;
     }
}
};
