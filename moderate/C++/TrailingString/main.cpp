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

        size_t found = tokens[0].rfind(tokens[1]);
        int foundPos = tokens[0].size() - tokens[1].size();
        if (found != string::npos && found == foundPos)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}