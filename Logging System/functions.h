#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include<conio.h>
#include<string>

using namespace std;

fstream userdatafile;

struct user {
    string name;
    string username;
    string password;
    string email;
    string mobilenumber;
};

vector<user> users_vector;


void vector_to_file()
{
    userdatafile.open("userdata.txt", ios::app);

    for (int i = 0; i < users_vector.size(); i++)
    {
        userdatafile << users_vector[i].name << " " <<  users_vector[i].username << " " << users_vector[i].email << " " << users_vector[i].password << " " << users_vector[i].mobilenumber <<endl;
    }

    userdatafile.close();
}

void file_to_vector()
{
    users_vector.clear();

    user newuser;

    userdatafile.open("userdata.txt", ios::in);

    while (userdatafile >> newuser.name >> newuser.username >> newuser.email >> newuser.password >> newuser.mobilenumber)
    {
        users_vector.push_back(newuser);
    }
    userdatafile.close();
}

bool username_exist(string username)
{
    bool exist = false;

    for(int i = 0; i < users_vector.size(); i++)
    {
        if (username == users_vector[i].username)
        {
            exist = true;
            return exist;
        }
    }
    return exist;
}

bool email_exist(string email)
{
    bool exist = false;

    for(int i = 0; i < users_vector.size(); i++)
    {
        if (email == users_vector[i].email)
        {
            exist = true;
            return exist;
        }
    }
    return exist;
}
bool mobile_exist(string mobile)
{
    bool exist = false;

    for(int i = 0; i < users_vector.size(); i++)
    {
        if (mobile == users_vector[i].mobilenumber)
        {
            exist = true;
            return exist;
        }
    }
    return exist;
}

bool valid_email(string email)
{
    const regex emailpattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(email, emailpattern);
}

bool valid_mobile(string mobile)
{
    const regex mobilepattern("01[0-9]{9}");

    return regex_match(mobile, mobilepattern);
}

bool valid_name(string name)
{
    const regex namepattern("^[a-zA-z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*");

    return regex_match(name, namepattern);
}

void user_register()
{
    file_to_vector();
    user newuser;

    do {
        cout << "Enter your name: ";
        cin >> newuser.name;
    }
    while(!valid_name(newuser.name));
  
    do {
        cout << "Enter your mobile number: ";
        cin >> newuser.mobilenumber;
    }
    while(!(valid_mobile(newuser.mobilenumber) && !mobile_exist(newuser.mobilenumber)));
  
    do {
        cout << "Enter your email: ";
        cin >> newuser.email;
    }
    while(!(valid_email(newuser.email) && !email_exist(newuser.email)));
  
    do {
        cout << "Enter your username: ";
        cin >> newuser.username;
    }
    while(username_exist(newuser.username));
    
    users_vector.push_back(newuser);
    
    vector_to_file();
}
void user_login(){
user users;
	int ch;
	string password, username;
	int i = 1;
	while (i < 4)
	{
		cout << "Hello,please enter your username :\n ";
		cin >> username;
		cout << "Enter your password :\n ";
		ch = _getch();

		while (ch != 13)
		{
			if (ch == 8) {
				if (!password.empty()) {
					cout << "\b \b";
					password.pop_back();
				}
				ch = _getch();
				continue;
			}
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
	
		if (password == users.password && username == users.username) {
			cout << "Successful login, welcome, "<<username << "\n";
			break;

		}
		else {
			if (i == 3) {
				cout << "!!you are denied access to the sysytem ";
				break;
			}
			cout << "failed login. try again \n";
		}
		i++;
	}

}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
