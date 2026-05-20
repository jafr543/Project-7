#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsinput_Validation.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
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

    cout << "\nMange Users? [Y/N]? ";
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
clsUpdateUserScreen();
virtual ~clsUpdateUserScreen();

    public:
        static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsinput_Validation::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, Try Again: ";
            UserName = clsinput_Validation::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = clsinput_Validation::ReadChar();

        if (toupper(Answer) == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};


