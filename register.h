#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED
#include<string>
using namespace std;


void display_menu();
void display_pass_Tip();

class user
{
private:
    string name;
    string ID;
    string password;
    string email;
    string phone_num;
public:
    void setName(string n);
    void setID(string ids);
    void setPassword(string pass);
    void setEmail(string Em);
    void setPn(string pn);
    void fill_users_data(string Name,string id, string Email_u, string pass);
    bool check_register(string Id, string EMAIL_u);
    bool check_passwords(string p1,string p2);
    void set_data();
    string Cipher_password(string message);
    string hide_password();
    string getName();
    string getID();
    string getPassword();
    string getEmail();
    string getPn();
};


#endif // REGISTER_H_INCLUDED
