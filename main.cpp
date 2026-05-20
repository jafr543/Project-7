#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsinput_Validation.h"
#include "Utility.h"
#include "clsLoginScreen.h"
#include <ctime>
using namespace std;

int main()

{
    while(true)
    {
       if(!clsLoginScreen::ShowLoginMenue())
       {
           break;
       }
    }

    return 0;
}
