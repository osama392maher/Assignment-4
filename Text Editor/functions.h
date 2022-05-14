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

void merge_files()
{

    fstream file2;
    char fileName2[100];


    file.open(filename, ios::app);

    cout << "Please enter The second file name: " << endl;
    cin >> fileName2;
    
    file2.open(fileName2, ios::in);

    if (file2.fail())
        cout << "Invalid file name" << endl;

    else {

        string space = " ";
        string text;
        file << space;

        while (getline(file2, text)) {
            file2 >> text;
            file << text;
        }
    }
    file.close();
    file2.close();
}

void words_of_file() {
    string line;
    int word = 0;

    file.open(filename, ios::in);
    while (file >> line) {
        word++;
    }
    cout << "The number of words in the file is: " << word << endl;
    file.close();
}

void characters_of_file() {

    string line;
    int character = 0;

    file.open(filename, ios::in);

    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ')
                character++;
        }
    }
    file.close();
    cout << "The number of characters in the file is: " << character << endl;
}

void lines_of_file() {

    int number = 0;

    file.open(filename, ios::in);
    string line;

    while (file) {
        getline(file, line);
        number++;
    }
    number -= 1;
    cout << "The number of lines in the file is: " << number << endl;

    file.close();
}

void search_for_word() {

    string line;
    string word;

    file.open(filename, ios::in);

    cout << "Enter a word to search about it the file: ";
    cin >> word;

    while (file >> line) {
        for (int i = 0; i < line.length(); i++) {
            line[i] = tolower(line[i]);
        }

        for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }

        if (word == line) {
            cout << "Word was found in the file" << endl;
            break;
        }

        else if (file.eof()) {
            if (word != line) {
                cout << "Word was not found in the file" << endl;
            }
        }
    }
    file.close();

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
void num_of_word(){
	file.open(filename, ios::in);
	string inputstr;
	string word;
	int count = 0;
	
	cout << "please enter the word you want to count the num of times it exists in the file : " << endl;
	cin >> inputstr;
	for (int i = 0;i < inputstr.length();i++)
			{
				inputstr[i] = toupper(inputstr[i]);
			}

		while (!file.eof()) {
			while (file >> word)
			{
				for (int i = 0;i < word.length();i++) {
					word[i] = toupper(word[i]);
				}
				
				if (inputstr == word) {
					count += 1;
				}
			}
			
		}

		cout <<"number of words in the file is : "<<count;
		file.close();
	
}

void  _1st_caps_file(){
 	file.open(filename, ios::in);
        string new_str;
		while (!file.eof()) {
			new_str += (char)file.get();
		}
		cout << " \n  the original File    : \n ";
		cout << new_str << "\n\n";
		cout << "   File after making the first letter Capital :  \n\n";
		new_str[0] =(char)toupper(new_str[0]);
		cout << (char)toupper(new_str[0]);
		for (int i = 1;i < new_str.length();i++) {
			if ((new_str[i] == ' ') || (new_str[i] == '\n')) {
				new_str[i] = (char)new_str[i];
				(new_str[i + 1]) = (char)toupper(new_str[i + 1]);
				i += 1;
			}
			else
			{
				new_str[i] = (char)tolower((char)new_str[i]);
			}
		}
		for (int i = 1;i < new_str.length();i++) {
			cout << new_str[i];
		}
		file.close();
	
	int len = new_str.length();
	file.open(filename, ios::out);
	for (size_t i = 0; i < len - 1; i++)
	{
		file << new_str[i];
	}

	file.close();
}
void Save(){
        file.open(filename, ios::in);
        string new_str;
		while (!file.eof()) {
			new_str += (char)file.get();
		}
	

        ofstream file2;	char name2[81];
	cout << "Hello user,if you want to save the under different file plaese enter the name: \n";
	cin >> name2;
	file2.open(name2);
	int len = new_str.length();
	for (size_t i = 0; i < len - 1; i++)
	{
		file2 << new_str[i];
	}


}
void display_menu()
{
       loadfile();
    
    int choice;
    bool run = true;
    while (run){
        cout << endl << "-------------------------------------------------" << endl;
        cout << "Hello 😁" << endl;
        cout << "What do you Want to do" << endl;
        cout << "   1. Add new text to the end of the file" << endl;
        cout << "   2. Display the content of the file" << endl;
        cout << "   3. Empty the file" << endl;
        cout << "   4. Encrypt the file" << endl;
        cout << "   5. Decrypt the file" << endl;
        cout << "   6. Merage another file" << endl;
        cout << "   7. Count the number of words in the file" << endl;
        cout << "   8. Count the number of characters in the file" << endl;
        cout << "   9. Count the number of lines in the file" << endl;
        cout << "   10. Search for a word in the file" << endl;
	cout << "   11. count the number of times a word exists in the file"<<endl;
        cout << "   12. Turn the file content to upper case." << endl;
	cout << "   13. Turn the file content to lower case." << endl;
	cout << "   14. Turn file content to 1st caps" << endl;
	cout << "   15. Save" << endl;
        cout << "   16. Exit" << endl;
        cout << "Please Enter your choice ==> ";
        
        if(!(cin >> choice)){
		    cout << "Please enter numbers only: " << endl << endl;
		    cin.clear();
		    cin.ignore(10000, '\n'); 
	    }
        switch (choice)
        {
            case 1:
                write_to_file();
                break;
            case 2:
                display_content();
                break;
            case 3:
                empty_file();
                break;
            case 4:
                encrypt_file();
                break;
            case 5:
                decrypt_file();
                break;
            case 6:
                merge_files();
                break;
            case 7:
                words_of_file();
                break;
            case 8:
                characters_of_file();
                break;
            case 9:
                lines_of_file();
                break;
            case 10:
                search_for_word();
                break;
            case 11:
                num_of_word();
	        break;
            case 12:
                uppercase_file();
                break;
            case 13:
		lowercase_file();
                break;
            case 14:
               _1st_caps_file();
		break;
            case 15:
		Save();
                break;
            case 16:
                file.close();
                run = false;
                break;
            default:
                cout << "invalid option" << endl;
            
        }

    }
}