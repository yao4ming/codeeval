#include <iostream>
#include <fstream>
#include <vector>
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

        for (int i = 0; i < tokens[1].size(); ++i) {
            if (tokens[1][i] == '1')
                tokens[0][i] = (char)toupper(tokens[0][i]);
        }

        cout << tokens[0] << endl;
    }
}