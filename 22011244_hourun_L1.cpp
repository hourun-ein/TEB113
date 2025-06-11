#include <iostream>
#include <string> // if error occur

using namespace std;

    struct Students{ // define Struct 
        int id;
        string name;
        int contact;
        string email;
    };


int main() {
    Students student[5];
    
    for (int i = 0; i < 5; i++){
        cout << "Enter student ID " << i + 1 << ":";
        cin >> student[i].id;
        cin.ignore();
        
        cout << "Enter student name: ";
        getline(cin, student[i].name);
        
        cout << "Enter student contact number: ";
        cin >> student[i].contact;
        cin.ignore();
        
        cout << "Enter student UTP email: ";
        cin >> student[i].email;
        
        cout << endl;
    }
    
    for (int i = 0; i < 5; i++){
        cout << "***********************************" << endl;
        cout << "Student " << i + 1 << endl;
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Contact number: " << student[i].contact << endl;
        cout << "Email: " << student[i].email << endl;
    }
    
    return 0;
} 