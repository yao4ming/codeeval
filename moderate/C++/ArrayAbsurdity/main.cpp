#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char** argv) {

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        set<int> mySet;
        while (getline(ss, token, ';'))
            tokens.push_back(token);

        stringstream ss2(tokens[1]);
        while (getline(ss2, token, ',')) {
            if (mySet.find(stoi(token)) != mySet.end())
                cout << *mySet.find(stoi(token));
            else
                mySet.insert(stoi(token));
        }
        cout << endl;
    }
}