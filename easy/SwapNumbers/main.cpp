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
            swap(token[0], token[token.size()-1]);
            cout << token << " ";
        }
        cout << endl;
    }
}