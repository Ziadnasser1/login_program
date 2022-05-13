#include<iostream>
#include<regex>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<sstream>
#include "register.h"
using namespace std;

void display_menu(){
    cout<<"**********************************************\n";
	cout<<"(1)-->Register.       |   (2)-->Login.       *\n";
	cout<<"                      |                      *\n";
	cout<<"(3)-->Change Password |   (4)-->Exit.        *\n";
    cout<<"                      |                      *\n";
    cout<<"**********************************************\n";

}
void display_pass_Tip(){
                cout<<"Enter your password"<<endl;
                cout<<"___________________________________________________________"<<endl;
                cout<<"Tip-->                                                     |"<<endl;
                cout<<"for a better strong password you should follow some rules: |"<<endl;
                cout<<"(1)At least 12 characters.                                 |"<<endl;
                cout<<"(2)Use a mixture of both Uppercase and Lowercase letters.  |"<<endl;
                cout<<"(3)Use a mixture of letters and numbers.                   |"<<endl;
                cout<<"(4)Inclusion of At least one special character[!,@,#,...]  |"<<endl;
                cout<<"___________________________________________________________|"<<endl;
                cout<<"->>>";
}

void user::setName(string n){
    bool is_ok=true;
    regex user_name ("[a-zA-Z_]+");
    while(is_ok){
    if(regex_match(n,user_name)==true){
        name=n;
        is_ok=false;
        }
    else{
        cout<<"Please enter a valid name format: ";
        cin>>n;
    }
   }
}
string user::getName(){
    return name;
}

void user::setEmail(string Em){
    bool is_ok=true;
    regex Email("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    while(is_ok){
    if(regex_match(Em,Email)==true){
        email=Em;
        is_ok=false;
        }
    else{
        cout<<"Please enter a valid email format: ";
        cin>>Em;
    }
   }
}
string user::getEmail(){
    return email;
}

void user::setPn(string pn){
    bool is_ok=true;
    regex p_num ("01[0-2,5][0-9]{8}");
    while(is_ok){
    if(regex_match(pn,p_num)==true){
        phone_num=pn;
        is_ok=false;
        }
    else{
        cout<<"Please enter a valid phone number format: ";
        cin>>pn;
    }
   }
}
string user::getPn(){
    return phone_num;
}

void user::setPassword(string pass){
    bool is_ok=true;
    regex passwords ("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[-+_!@#$%^&*.,?]).{12,}$");
    while(is_ok){
    if(regex_match(pass,passwords)==true){
        password=pass;;
        is_ok=false;
        }
    else{
        cout<<"Please enter a valid password format: ";
        pass=hide_password();
    }
   }
}
string user::getPassword(){
    return password;
}

void user::setID(string ids){
    ID=ids;
}
string user::getID(){
    return ID;
}

void user::fill_users_data(string Name,string id, string Email_u,string pass){
   fstream myfile("UsersData.txt",ios::in | ios::out | ios::app);
   if(!myfile.is_open())
        cout<<"error while opening the file"<<endl;
   else{
        cout<<"file opened successfully"<<endl;
        cout<<"writing to file"<<endl;
        cout<<"-------------------------"<<endl;

        myfile<<left
        <<setfill(' ')<<setw(27)<<Name
        <<setfill(' ')<<setw(27)<<pass
        <<" : "<<setfill(' ')<<setw(27)<<id
        <<setfill(' ')<<setw(27)<<Email_u<<"|"<<endl;
   }
   myfile.close();
}

bool user::check_register(string Id, string EMAIL_u){
   fstream myfile("UsersData.txt",ios::in | ios::out | ios::app);
   if(!myfile.is_open())
        cout<<"error while opening the file"<<endl;
   else{
        cout<<"-------------------------"<<endl;
        cout<<"file opened successfully"<<endl;
        cout<<"reading from the file"<<endl;

        bool valid =false;
        string line;
        while(myfile.good()){
            getline(myfile,line);
            if(line.find(Id)!=std::string::npos || line.find(EMAIL_u)!=std::string::npos){
                valid=true;
                break;
            }
        }
        return valid;
   }
   myfile.close();
}

bool user::check_passwords(string p1,string p2){
    if(p2==p1)
        return true;
    else
        return false;
}

string user::hide_password(){
   string pass ="";
   char ch;
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
   return pass;
}

string user::Cipher_password(string message){
    string kw="RUN";
    for(int i=0; i<message.length(); i++)
        {
            if(message[i] >= 'a' && message[i] <= 'z')
                message[i] = char(message[i] - 32);
        }

    if (kw.length()>= message.length())
       return kw;
    else{
        int k = message.length();
        for(int i = 0;  ;i++)
        {
            if(k == i)
                i = 0;
            if(kw.length() == message.length())
                break;
            kw.push_back(kw[i]);
        }
    }
    string enc_message;
    int encode;
    for (int i=0;i <=message.length(); i++){

        //check if the character is an alphabet or not.
        if (isalpha(message[i]))
        {
            //the algorithm made to encrypt the message.
            encode = ((char(message[i]) + char(kw[i])) % 26) +65;
            enc_message += char(encode);

            if(enc_message.length() == message.length())
                break;
        }
        else if(message[i] != '@' && message[i] != '~' && message[i]!= '`')
             enc_message += (char(message[i]) + 1);
        else
            enc_message +=(char(message[i]));
    }
    return enc_message;
}

void user::set_data(){
        string N,PNUM,Pass1,Pass2,E,I;
        user employee;
        bool Is_Valid =true,IsOk=true;
        cout<<"Enter your Name(without spaces): ";
        cin>>N;
        employee.setName(N);
        cout<<"Enter your ID: ";
        cin>>I;
        employee.setID(I);
        cout<<"Enter your Email: ";
        cin>>E;
        employee.setEmail(E);
        cout<<"Enter your phone num: ";
        cin>>PNUM;
        employee.setPn(PNUM);

        display_pass_Tip();

        Pass1=employee.hide_password();
        employee.setPassword(Pass1);

        cout<<"Enter your Password one more time :";
        Pass2=employee.hide_password();
            while(IsOk){
                if(employee.check_passwords(employee.getPassword(),Pass2)==true){
                    IsOk=false;
                }
                else{
                    cout<<"Passwords did not match enter your password again: ";
                    Pass1=employee.hide_password();
                    employee.setPassword(Pass1);
                    cout<<"Enter your password one more time: ";
                    Pass2=employee.hide_password();
                    }
                }
            while(Is_Valid){
                if(employee.check_register(employee.getID(),employee.getEmail())== true){
                    cout<<"Enter another ID and Email as the entered id or email are used before: "<<endl;
                    cin>>I>>E;
                    employee.setID(I);
                    employee.setEmail(E);
                }
                else{
                    string ciphered_pass=employee.Cipher_password(employee.getPassword());
                    employee.fill_users_data(employee.getName(),employee.getID(),employee.getEmail(),ciphered_pass);
                    Is_Valid=false;
                }                cout<<endl;
            }
}

void user::login_data(){
        string Pass1,I;
        user employee;
        int n=3;

        while(n--){
            cout<<"Enter your ID: ";
            cin>>I;
            employee.setID(I);

            cout<<"Enter your password: ";
            Pass1=employee.hide_password();
            employee.setPassword(Pass1);
            string ciphered_pass=employee.Cipher_password(employee.getPassword());

            if(employee.check_login(employee.getID(),ciphered_pass)== true){
                    cout<<"-------------------------------------"<<endl;
                    cout<<"Successful login, welcome!"<<endl;
                    break;
            }
            else{
                cout<<"-------------------------------------"<<endl;
                cout<<"Failed Login, Try Again!"<<endl;
            }
            if(n==0){
            cout<<"Sorry, but you are denied to enter the system";
            }
        }
            cout<<endl;

}

bool user::check_login(string Id, string EMAIL_u){
   fstream myfile("UsersData.txt",ios::in | ios::out | ios::app);
   if(!myfile.is_open())
        cout<<"error while opening the file"<<endl;
   else{
        cout<<"-------------------------"<<endl;
        cout<<"file opened successfully"<<endl;
        cout<<"reading from the file"<<endl;

        bool valid =false;
        string line;
        while(myfile.good()){
            getline(myfile,line);
            if(line.find(Id)!=std::string::npos && line.find(EMAIL_u)!=std::string::npos){
                valid=true;
                break;
            }
        }
        return valid;
   }
   myfile.close();
}

string user::get_old_pass(string NAME){
    ifstream file;
	file.open("UsersData.txt");
    string PASS;

	bool isFound=0;
	while(!file.eof())
	{
		string temp = "";
		getline(file,temp);
		for(int i=0;i<NAME.size();i++)
		{
			if(temp[i]==NAME[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}
		if(isFound)
		{
			for(int i = NAME.size()+1;i<temp.size();i++){
				if(temp[i]==':')
                    break;
                else if(temp[i]==' ')
                    continue;
                else{
                    PASS.push_back(temp[i]);
                }
			}
			break;
		}
	}

	if(file.eof()&&(!isFound))
	{
		cout << "Name not found!\n";
	}
	file.close();

	return PASS;
}
