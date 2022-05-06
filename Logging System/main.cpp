#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "functions.h"

using namespace std;

int main ()
{
/*
    vector<user> users;
    user newuser;
    
    cout << "Enter name: ";
    cin >> newuser.name;
    
    cout << "Enter username: ";
    cin >> newuser.username;
    
    cout << "Enter Email: ";
    cin >> newuser.email;

    cout << "Enter Password: ";
    cin >> newuser.password;

    users.push_back(newuser);
*/

file_to_vector();

for (int i = 0; i < users.size(); i++)
{
    cout << users[i].name << " " << users[i].username << " " << users[i].email << " " << users[i].password << " " << endl;
}
}

