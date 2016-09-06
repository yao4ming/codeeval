#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
            tokens.push_back(token);

        //find index of char in string
        bool found = false;
        for (int i = tokens[0].size() - 1; i >= 0; --i) {
            const char* c = tokens[1].c_str();
            if (*c == tokens[0][i]) {
                cout << i << endl;
                found = true;
            }
        }
        if (!found)
            cout << -1 << endl;
    }
}