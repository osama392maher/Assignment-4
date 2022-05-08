#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

fstream userdatafile, userspasswordfile;

struct user {
    int id;
    string name;
    string username;
    vector<string> passwords;
    string email;
    string mobilenumber;
};

vector<user> users_vector;


//_____________________________________________________
void vector_to_file()
{
    userdatafile.open("userdata.txt", ios::out);
    userspasswordfile.open("passwords.txt", ios::out);

    for (int i = 0; i < users_vector.size(); i++)
    {
        userdatafile << i << " " << users_vector[i].name << " " <<  users_vector[i].username << " " << users_vector[i].email << " " << users_vector[i].mobilenumber <<endl;
    }

    for (int i = 0; i < users_vector.size(); i++)
    {
        for (int j = 0; j < users_vector[i].passwords.size(); j++)
        {
            userspasswordfile << i << " " << users_vector[i].passwords[j] << endl;
        }
    }

    userdatafile.close();
    userspasswordfile.close();
}

//_____________________________________________________
void file_to_vector()
{
    users_vector.clear();

    user newuser;

    int id;
    string password;

    userdatafile.open("userdata.txt", ios::in);
    userspasswordfile.open("passwords.txt", ios::in);


    while (userdatafile >> newuser.id >> newuser.name >> newuser.username >> newuser.email >> newuser.mobilenumber)
    {
        users_vector.push_back(newuser);
    }

    while (userspasswordfile >> id >> password)
    {
        users_vector[id].passwords.push_back(password);
    }

    userdatafile.close();
    userspasswordfile.close();

}

//_____________________________________________________
string encrypt(string word) {

    for (int i = 0; i < word.size(); i++) {
        word[i] = word[i] + 1;
    }

    return word;
}

//_____________________________________________________
string decrypt(string word) {

    for (int i = 0; i < word.size(); i++) {
        word[i] = word[i] - 1;
    }

    return word;
}

//_____________________________________________________
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

//_____________________________________________________
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

//_____________________________________________________
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

//_____________________________________________________
bool valid_email(string email)
{
    const regex emailpattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(email, emailpattern);
}

//_____________________________________________________
bool valid_mobile(string mobile)
{
    const regex mobilepattern("01[0-9]{9}");

    return regex_match(mobile, mobilepattern);
}

//_____________________________________________________
bool valid_name(string name)
{
    const regex namepattern("^[a-zA-z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*");

    return regex_match(name, namepattern);
}

//_____________________________________________________
bool valid_password(string password)
{
    const regex strongPassword("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?.,<>:;'@#$%^&*-=+~_\\]\\[}{)(/|])[a-zA-Z0-9!?.,<>:;'@#$%^&*-=+~_\\]\\[}{)(/|]{8,})");

    return regex_match(password, strongPassword);
}

//_____________________________________________________
string takestrongpassword()
{
    string password;
    cout << endl << "------------------------------------------------------------------------------" << endl;
    cout << "The letters are allowed, requiredand conditions that must apply to the password." << endl;
    cout << "1.You can choose uppercase letters, lowercase letter, digits, and special chararcters." << endl;
    cout << "2.It must contain at least 8 character" << endl;
    cout << "3.It should include at least an uppercase letter, a lowercase letter, and one digit." << endl;
    cout << "4.Remember that uppercase letters are different from lowercase letters." << endl;
    
    do {
        cout << "Enter a strong password: ";
        char ch;
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
    } while (!(valid_password(password)));

    return encrypt(password);
}

//_____________________________________________________
void user_register()
{
    file_to_vector();
    user newuser;

    do {
        cout << endl << "------------------------------------------------------------------------------" << endl;
        cout << "Enter your name: ";
        cin >> newuser.name;
    }
    while(!valid_name(newuser.name));
  
    do {
        cout << endl << "------------------------------------------------------------------------------" << endl;
        cout << "Enter your mobile number: ";
        cin >> newuser.mobilenumber;
    }
    while(!(valid_mobile(newuser.mobilenumber) && !mobile_exist(newuser.mobilenumber)));
  
    do {
        cout << endl << "------------------------------------------------------------------------------" << endl;
        cout << "Enter your email: ";
        cin >> newuser.email;
    }
    while(!(valid_email(newuser.email) && !email_exist(newuser.email)));
  
    do {
        cout << endl << "------------------------------------------------------------------------------" << endl;
        cout << "Enter your username: ";
        cin >> newuser.username;
    }
    while(username_exist(newuser.username));
   
    newuser.passwords.push_back(takestrongpassword());
   
    
    string password2;
    do {
        cout << endl << "------------------------------------------------------------------------------" << endl;
        cout << "Enter your password again: ";
        char ch;
        ch = _getch();

        while (ch != 13)
        {
            if (ch == 8) {
                if (!password2.empty()) {
                    cout << "\b \b";
                    password2.pop_back();
                }
                ch = _getch();
                continue;
            }
            password2.push_back(ch);
            cout << '*';
            ch = _getch();
        }
    } while (password2!= decrypt(newuser.passwords[newuser.passwords.size() - 1]));

    cout << endl << "------------------------------------------------------------------------------" << endl;
    cout << "Registered Successfuly" << endl; 
    users_vector.push_back(newuser);
    
    vector_to_file();
}

//_____________________________________________________
int user_login(){
    file_to_vector();

    int ch, current_user_index;
	int times = 1;
	string password;
	string username;

	while (times < 4) {
        cout << endl << "------------------------------------------------------------------------------" << endl;
		cout << "Hello,  Please Enter Your Username: ";
		cin >> username;
        cout << endl << "------------------------------------------------------------------------------" << endl;
		cout << "Enter your password: ";
		cin >> password;
        bool found = false;
		for (int i = 0; i < users_vector.size(); i++)//users_vector.size()
		{
			if (username == users_vector[i].username) {//users_vector[i].username
				if (password == decrypt(users_vector[i].passwords[users_vector[i].passwords.size() - 1])) {//users_vector[i].password
                    cout << endl << "------------------------------------------------------------------------------" << endl;
					cout << "Successful login, welcome, " << username << endl;
                    current_user_index = i;
					return current_user_index;
				}
				else {
                    found = true;

					cout << "!wrong password." << endl;
				}

			}

		}
        if (!found)
        {
            cout << endl << "------------------------------------------------------------------------------" << endl;
            cout << "User doesn't exist" << endl;
        }

		if (times == 3) {
            cout << endl << "------------------------------------------------------------------------------" << endl;
			cout <<"Three failed attempts" << endl;
			break;
		}
		times++;
	}
   return 0; 
}

//_____________________________________________________
void change_password()
{
    string current_password, new_password, new_password2;
    int current_user = user_login();

    cout << endl << "------------------------------------------------------------------------------" << endl;

    new_password = takestrongpassword();

    cout << endl <<"Enter the new passworld again: ";
    cin >> new_password2;
    

    if (decrypt(new_password) != new_password2)
    {
        cout << "Passwords doesn't match";
        return;
    }

    for (int i = 0; i < users_vector[current_user].passwords.size(); i++)
    {
        if (new_password == decrypt(users_vector[current_user].passwords[i]))
        {
            cout << "This password is used before";
            return;
        }
    }

    users_vector[current_user].passwords.push_back(new_password);

    vector_to_file();
}

//_____________________________________________________
void display_menu()
{
    while(true){   
        int choice;
        cout << endl << "Hello 😄" << endl;
        cout << "                  --------------------------------------" << endl;
        cout << "                  -        1- Register New User        -" << endl;
        cout << "                  -        2- Login                    -" << endl;
        cout << "                  -        3- Change Password          -" << endl;
        cout << "                  -        4- Exit                     -" << endl;
        cout << "                  --------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            user_register();
        }
        else if (choice == 2)
        {
            user_login();
        }
        else if (choice == 3)
        {
            change_password();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}



