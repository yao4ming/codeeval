#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    int n = 256;
    int matrix[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(token);
        if (strncmp(tokens[0].c_str(), "SetRow", 6) == 0) {
            for (int i = 0; i < n; ++i)
                matrix[stoi(tokens[1])][i] = stoi(tokens[2]);
        } else if (strncmp(tokens[0].c_str(), "SetCol", 6) == 0) {
            for (int i = 0; i < n; ++i)
                matrix[i][stoi(tokens[1])] = stoi(tokens[2]);
        } else if (strncmp(tokens[0].c_str(), "QueryRow", 8) == 0) {
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += matrix[stoi(tokens[1])][i];
            cout << sum << endl;
        } else if (strncmp(tokens[0].c_str(), "QueryCol", 8) == 0) {
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += matrix[i][stoi(tokens[1])];
            cout << sum << endl;
        }
    }
}