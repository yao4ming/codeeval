#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        char prev = line[0];
        string str = "";
        str += prev;
        for (int i = 1; i < line.size(); ++i) {
            if (line[i] != prev)
                str += line[i];
            prev = line[i];
        }
        cout << str << endl;
    }
}