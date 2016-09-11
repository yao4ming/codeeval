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
        vector<int> tokens;
        while (getline(ss, token, ','))
            tokens.push_back(stoi(token));

        int i = tokens[1];
        while (i < tokens[0])
            i += tokens[1];
        cout << i << endl;
    }
}