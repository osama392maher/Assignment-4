#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

fstream userdatafile;

struct user {
    string name;
    string username;
    string password;
    string email;
};

vector<user> users;


void vector_to_file()
{
    userdatafile.open("userdata.txt", ios::app);

    for (int i = 0; i < users.size(); i++)
    {
        userdatafile << users[i].name << " " <<  users[i].username << " " << users[i].email << " " << users[i].password << endl;
    }

    userdatafile.close();
}

void file_to_vector()
{
    users.clear();

    user newuser;

    userdatafile.open("userdata.txt", ios::in);

    while (userdatafile >> newuser.name >> newuser.username >> newuser.email >> newuser.password)
    {
        users.push_back(newuser);
    }
    userdatafile.close();
}