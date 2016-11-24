#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<int> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(stoi(token));

        set<int> jolly;

        for (int j = 1; j < tokens[0]; ++j)
            jolly.insert(j);

        for (int i = 1; i < tokens.size() - 1; ++i)
            jolly.erase(abs(tokens[i] - tokens[i+1]));

        if (jolly.size() == 0)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
}