#include <iostream>
#include <regex>
#include <fstream>
#include "register.h"
using namespace std;

int main()
{
    char choice;
    bool IsOk=true;
    user employee;

	display_menu();

    while(IsOk){
        cout<<"Choose form the above table: ";
        cout<<"--> ";
        cin>>choice;

        switch(choice){
            case '1':{
                //user register data.
                employee.set_data();
                break;
            }
            case '2':{
                //checking user login data.
                employee.login_data();
                break;
            }
            case '3':{
                //changing the user password.
                employee.change_password();
                changeFilesNames();
                break;
                }
            case '4':{
                cout<<"Thanks for using our login application program!!\n";
                IsOk=false;
                break;
            }
            default:
                cout<<"enter a valid option please!!"<<endl;
                break;
        }
    }
}
