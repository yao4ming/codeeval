#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        int num = stoi(line);
        if (num >= 0 && num <= 2)
            cout << "Still in Mama's arms" << endl;
        else if (num >= 3 && num <= 4)
            cout << "Preschool Maniac" << endl;
        else if (num >= 5 && num <= 11)
            cout << "Elementary School" << endl;
        else if (num >= 12 && num <= 14)
            cout << "Middle School" << endl;
        else if (num >= 15 && num <= 18)
            cout << "High School" << endl;
        else if (num >= 19 && num <= 22)
            cout << "College" << endl;
        else if (num >= 23 && num <= 65)
            cout << "Working for the man" << endl;
        else if (num >= 65 && num <= 100)
            cout << "The Golden Years" << endl;
        else if (num < 0 || num > 100)
            cout << "This program is for humans" << endl;
    }
}