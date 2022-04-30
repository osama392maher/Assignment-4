#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

fstream file;
char filename[100];

void loadfile()
{

    cout << "Hello 😁" << endl;
    cout << "Enter The File Name: ";

    cin >> filename;
    strcat(filename, ".txt");

    file.open(filename, ios::in);

    if(file){
        cout << "File is Exist and ready" << endl << endl;

    } else {
        cout << "This is a new file. I created it for you 😁" << endl << endl;
        file.open(filename, ios::out);
    }

    file.close(); 
}

void write_to_file()
{
    file.open(filename, ios::app);
    string text;

    cout << "Enter Text you want to add" << endl;
    cout << "press // to quit" << endl;

    while(getline(cin, text))
    {
        if (text == "//")
        {
            break;
        }
        file << text << endl;
    }
    file.close();   
}

void empty_file()
{
    file.open(filename, ios::out);
    file.close(); 
}

void display_content()
{
    cout <<"---------------- Display Content ----------------" << endl;
    file.open(filename, ios::in);
    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }
    cout << endl << endl;
    
    file.close();
}

void encrypt_file()
{
    fstream tempfile;
    file.open(filename, ios::in);
    tempfile.open("temp.txt", ios::out);

    string line;
    while(getline(file, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ' && line[i] != 'z' && line[i] != 'Z')
            {
                line[i] += 1;
            }
            if (line[i] == 'z') line[i] = 'a';
            if (line[i] == 'Z') line[i] = 'A';
        }
        tempfile << line << endl;
    }
    file.close();
    tempfile.close();

    tempfile.open("temp.txt", ios::in);
    file.open(filename, ios::out);

    while(getline(tempfile, line))
    {
        file << line << endl;
    }
    file.close();
    tempfile.close();
}

void decrypt_file()
{
    fstream tempfile;
    file.open(filename, ios::in);
    tempfile.open("temp.txt", ios::out);

    string line;
    while(getline(file, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ' && line[i] != 'a' && line[i] != 'A')
            {
                line[i] -= 1;
            }
            if (line[i] == 'a') line[i] = 'z';
            if (line[i] == 'A') line[i] = 'Z';
        }
        tempfile << line << endl;
    }
    file.close();
    tempfile.close();
    tempfile.open("temp.txt", ios::in);
    file.open(filename, ios::out);
    
    while(getline(tempfile, line))
    {
        file << line << endl;
    }
    file.close();
    tempfile.close();
}

void uppercase_file ()
{
    	file.open(filename, ios::in);
    	string new_str;
		while (!file.eof()) {
			new_str += (char)file.get();
		}
	        cout<<"the original file ";
		cout << new_str;
		cout << endl << endl;
		cout << "The uppercase File .\n" << endl;
		for (int i = 0;i < new_str.length();i++)
		{
			
				new_str[i] = (char)toupper(new_str[i]);
			
		}
		cout << new_str;
		file.close();
		
	int len = new_str.length();
	file.open(filename, ios::out);
	for (size_t i = 0; i < len-1; i++)
	{
		file << new_str[i];
	}

	file.close();
}
void lowercase_file ()
{
    	file.open(filename, ios::in);
    	string new_str;
		while (!file.eof()) {
			new_str += (char)file.get();
		}
	        cout<<"the original file ";
		cout << new_str;
		cout << endl << endl;
		cout << "The lowercase File .\n" << endl;
		for (int i = 0;i < new_str.length();i++)
		{
			
				new_str[i] = (char)tolower(new_str[i]);
			
		}
		cout << new_str;
		file.close();
		
	int len = new_str.length();
	file.open(filename, ios::out);
	for (size_t i = 0; i < len-1; i++)
	{
		file << new_str[i];
	}

	file.close();
}
