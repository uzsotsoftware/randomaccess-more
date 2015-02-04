/* 
 * File:   main.cpp
 * Author: R135278L
 *
 * Created on February 3, 2015, 11:15 AM
 */

#include <cstdlib>
#include <iostream>
#include<fstream>
#include <cstring>

using namespace std;

/*
 * 
 */
int Addrecs();
int Viewrecs();
void Viewall();
//int recordCounter;

class Students {
    char regNum[9];
    char name[35];
    int age;

public:

    Students(char *thisReg, char *thisName, int thisAge) {
        strcpy(regNum, thisReg);
        strcpy(name, thisName);
        age = thisAge;

    }

    void  Viewall(){
     cout << "Registration Number, is.." <<regNum<< endl;
     cout << "Name, is.." <<name<< endl;
     cout << "Age, is.." <<age<< endl;
    
    }
    
    
    Students(){}
};

int Addrecs() {
    char regNum[9];
    char name[35];
    int age;

    cout << "Enter Registration Number..\t" << endl;
    cin >> regNum;
    cout << "Enter First Name..";
    cin >> name;
    cout << "Enter Age..";
    cin >> age;
    
    Students student(regNum, name, age);
    ofstream studentFile("students.dat", ios::binary | ios::app);
    studentFile.write((char *) &student, sizeof (Students));
    studentFile.close();
    
   
}

int Viewrecs() {
    
    
    
    
    
}
void  Viewall() {

    ifstream studentFile("students.dat", ios::binary);
    Students student;
    int count;
    int limit=recordCounter();
    for (count = 0; count < limit; count++) {
        studentFile.read((char *) &student, sizeof (Students));
        student.Viewall();
    }
    studentFile.close();

    }


int recordCounter(string Filename){
    int counter = 0;
    Students obj;
    ifstream file("students.dat", ios::binary);
    while (file) {
        file.read((char *) &obj, sizeof (Students));
        counter++;
        cout << counter << endl;

    }
    return counter-1;
    

}

int main(int argc, char** argv) {
    Students student;
    int a;
    cout << "Menu" << endl;
    cout << "1.EnterRecords" << endl;
    cout << "2.DisplayRecords" << endl;
    cout << "3.ViewallRecords" << endl;
    cout << "0.Exit" << endl;

    
//    do {
//        cout << "New record N OR Y" << endl;
//        cin >> opt;
//        if (opt! == 'n')
//            Addrecs();
//        return 0;
//        Viewall;
//
//    } while (opt! == 'n'); 
//    
 
    
    switch (a) {
        case 1:
            int Addrecs();
            break;
        case 2:
            int Viewrecs();
            break;
        case 3:
            int Viewall();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Enter a number between 0 and 3 of your choice" << endl;
            break;
    return 0;
}

    
    
//   char opt;
//   recordCounter()
//    
    
}
