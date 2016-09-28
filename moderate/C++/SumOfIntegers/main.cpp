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
        vector<int> tokens;

        while (getline(ss, token, ','))
            tokens.push_back(stoi(token));

        int maxSoFar = tokens[0];
        int currMax = tokens[0];

        for (int i = 1; i < tokens.size(); ++i) {
            currMax = max(tokens[i], currMax+tokens[i]);
            maxSoFar = max(currMax, maxSoFar);
            cout << "";
        }
        cout << maxSoFar << endl;
    }
}