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

        int i; char op;
        for (i = 0; i < tokens[1].size(); ++i) {
            if (tokens[1][i] == '+') {
                op = '+';
                break;
            } else if (tokens[1][i] == '-') {
                op = '-';
                break;
            }
        }

        (op == '+') ? cout << stoi(tokens[0].substr(0, i)) + stoi(tokens[0].substr(i)) << endl :
                        cout << stoi(tokens[0].substr(0, i)) - stoi(tokens[0].substr(i)) << endl;
    }
}