#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(token);

        for (int i = 0; i < tokens.size(); ++i) {
            tokens[i][0] = (char)toupper(tokens[i][0]);
            cout << tokens[i] << " ";
        }
        cout << endl;
    }
}