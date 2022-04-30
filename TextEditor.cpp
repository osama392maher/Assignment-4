#include <iostream>
#include<limits>
#include "functions.h"

using namespace std;

int main()
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
        cout << "   12. Turn the file content to upper case." << endl;
	cout << "   13. Turn the file content to lower case." << endl;
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
                continue;
            case 7:
                continue;
            case 8:
                continue;
            case 9:
                continue;
            case 10:
                continue;
            case 11:
                continue;
            case 12:
                uppercase_file();
                break;
            case 13:
		lowercase_file();
                break;
            case 14:
                continue;
            case 15:
                continue;
            case 16:
                file.close();
                run = false;
                break;
            default:
                cout << "invalid option" << endl;
            
        }

    }
}

