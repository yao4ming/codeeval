#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        int count = 0;
        for (int i = 0; i < line.size(); ++i) {
            switch (line[i]) {
                case 'a': cout << 0; break;
                case 'b': cout << 1; break;
                case 'c': cout << 2; break;
                case 'd': cout << 3; break;
                case 'e': cout << 4; break;
                case 'f': cout << 5; break;
                case 'g': cout << 6; break;
                case 'h': cout << 7; break;
                case 'i': cout << 8; break;
                case 'j': cout << 9; break;
                default: {
                    if (isdigit(line[i]))
                        cout << line[i];
                    else
                        count++;
                }
            }
        }
        if (count == line.size())
            cout << "NONE";
        cout << endl;
    }
}