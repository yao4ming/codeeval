#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' ')) {
            if (stoi(token) % 2 == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}