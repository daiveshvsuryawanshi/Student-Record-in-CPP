#include <iostream>
#include <fstream>
using namespace std;

// define a class to store student data
class student
{
    int roll;
    char name[30];
    float mark;

public:
    student() {}
    void getData();     // get student data from user
    void displayData(); // display data
};

void student ::getData()
{
    cout << "\nEnter Roll No. :: ";
    cin >> roll;
    cin.ignore(); // ignore the newline char inserted when you press enter
    cout << "\nEnter Name :: ";
    cin.getline(name, 30);
    cin.ignore();
    cout << "Enter Mark  : ";
    cin >> mark;
}

void student ::displayData()
{
    cout << "\nRoll No. :: " << roll << endl;
    cout << "\nName     :: " << name << endl;
    cout << "\n Mark      :: " << mark << endl;
}

int main()
{
    student s[5]; // array of 5 student objects
    fstream file;
    int i, num, arr[5];
    int ch;
   
    while (1)
    {
        cout << "1. Enter Details : " << endl;
        cout << "2. View Details :" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            file.open("F:\\c++ project\\student record\\file4.txt", ios ::out); // open file for writing
            cout << "\nWriting Student information to the file :- " << endl;
            cout << "\nEnter 5 students Details to the File :- " << endl;

            for (i = 0; i < 5; i++)
            {
                s[i].getData();
                // write the object to a file
                file.write((char *)&s[i], sizeof(s[i]));
            }

            file.close(); // close the file
            break;

        case 2:
            file.open("F:\\c++ project\\student record\\file4.txt", ios ::in); // open file for reading
            cout << "\nReading Student information to the file :- " << endl;

            for (i = 0; i < 5; i++)
            {
                // read an object from a file
                file.read((char *)&s[i], sizeof(s[i]));
                s[i].displayData();
            }

            file.close(); // close the file
            break;

        default:
            cout << "Invalid ";
            break;
        }
    }
    return 0;
}
