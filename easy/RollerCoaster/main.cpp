#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        bool upper = true;
        for (int i = 0; i < line.size(); ++i) {
            if (isalpha(line[i])) {
                if (upper) {
                    line[i] = (char)toupper(line[i]);
                    upper = false;
                } else {
                    line[i] = (char)tolower(line[i]);
                    upper = true;
                }
            }
        }
        cout << line << endl;
    }
}