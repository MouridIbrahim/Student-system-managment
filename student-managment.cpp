#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Studentinfo {
    string fullname, section, major;
    fstream file;
public:
    void addstudent();
    void viewstudents();
    void searchstudent();
} obj;

int main() {
    while(true){int choice;
    cout << "------------------------------Student system management----------------------------------\n";
    cout << "Choose one of these options:";
    cout << "\n   1. Add Student";
    cout << "\n   2. View Students";
    cout << "\n   3. Search Student";
    cout << "\n   4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;
    system("cls");

    switch (choice) {
        case 1:
            cin.ignore();
            obj.addstudent();
            break;
        case 2:
            cin.ignore();
            obj.viewstudents();
            break;
        case 3:
            cin.ignore();
            obj.searchstudent();
            break;
        case 4:
            cout << "Exiting the program...";
            break;
        default:
            cout << "Invalid option. Please try again!";
    }}
}

void Studentinfo::addstudent() {
    file.open("student-data.txt", ios::out | ios::app);
    if (!file) {
        cout << "Error in opening file!";
        return;
    }
    cout << "Enter the student's full name: ";
    getline(cin, fullname);
    cout << "Enter the student's section: ";
    getline(cin, section);
    cout << "Enter the student's major: ";
    getline(cin, major);
    file << fullname << '*' << section << '*' << major << '\n';
    file.close();
}

void Studentinfo::viewstudents() {
    file.open("student-data.txt", ios::in);
    if (!file) {
        cout << "Error in opening file!";
        return;
    }
    while (getline(file, fullname, '*') && getline(file, section, '*') && getline(file, major)) {
        cout << "--------------------------------------\n";
        cout << "The full name is " << fullname << '\n';
        cout << "The section is " << section << '\n';
        cout << "The major is " << major << '\n';
    }
    file.close();
}


void Studentinfo::searchstudent() {
    system("cls"); // Clear the console screen
    file.open("student-data.txt", ios::in);
    if (!file) {
        cout << "Error in opening file!";
        return;
    }
    string searchName, line;
    cout << "Enter the student's full name to search: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(searchName);
        if (pos != string::npos) {
            found = true;
            size_t pos1 = line.find('*');
            size_t pos2 = line.find('*', pos1 + 1);
            
            string fullname = line.substr(0, pos1);
            string section = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string major = line.substr(pos2 + 1);

            cout << "--------------------------------------\n";  
            cout << "The full name is: " << fullname << '\n';
            cout << "The section is: " << section << '\n';
            cout << "The major is: " << major << '\n';
        }
    }
    if (!found) {
        cout << "Student not found!\n";
    }
    file.close();
}
