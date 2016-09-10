#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        if (line.size() <= 55) {
            cout << line << endl;
        }
        else {
            string trimmedStr = line.substr(0, 40);
            int i;
            for (i = trimmedStr.size()-1; i >= 0; --i) {
                if (trimmedStr[i] == ' ')
                    break;
            }
            cout << trimmedStr.substr(0, i) << "... <Read More>" << endl;
        }
    }
}