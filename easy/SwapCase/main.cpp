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
            for (int j = 0; j < tokens[i].size(); ++j) {
                if (islower(tokens[i][j]))
                    tokens[i][j] = (char)toupper(tokens[i][j]);
                else
                    tokens[i][j] = (char)tolower(tokens[i][j]);
                cout << tokens[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}