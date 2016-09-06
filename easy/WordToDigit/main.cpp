#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ';'))
            tokens.push_back(token);

        for (int i = 0; i < tokens.size(); ++i) {
            if (strncmp(tokens[i].c_str(), "zero", 4) == 0)
                cout << 0;
            else if (strncmp(tokens[i].c_str(), "one", 3) == 0)
                cout << 1;
            else if (strncmp(tokens[i].c_str(), "two", 3) == 0)
                cout << 2;
            else if (strncmp(tokens[i].c_str(), "three", 5) == 0)
                cout << 3;
            else if (strncmp(tokens[i].c_str(), "four", 4) == 0)
                cout << 4;
            else if (strncmp(tokens[i].c_str(), "five", 4) == 0)
                cout << 5;
            else if (strncmp(tokens[i].c_str(), "six", 3) == 0)
                cout << 6;
            else if (strncmp(tokens[i].c_str(), "seven", 5) == 0)
                cout << 7;
            else if (strncmp(tokens[i].c_str(), "eight", 5) == 0)
                cout << 8;
            else if (strncmp(tokens[i].c_str(), "nine", 4) == 0)
                cout << 9;
        }
        cout << endl;
    }
}