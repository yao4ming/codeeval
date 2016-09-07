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

        string longestWord = tokens[0];
        int maxSize = (int)tokens[0].size();
        for (int i = 1; i < tokens.size(); ++i) {
            if (tokens[i].size() > maxSize) {
                maxSize = (int)tokens[i].size();
                longestWord = tokens[i];
            }
        }
        cout << longestWord << endl;
    }
}