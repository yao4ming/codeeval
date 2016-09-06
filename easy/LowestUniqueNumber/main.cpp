#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
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

        map<int, int> myMap;
        for (int i = 0; i < tokens.size(); ++i) {
            map<int,int>::iterator it = myMap.find(stoi(tokens[i]));
            if(it != myMap.end())
                myMap[stoi(tokens[i])] += 1;
             else
                myMap.insert(pair<int, int>(stoi(tokens[i]), 1));
        }

        int min;
        for (map<int, int>::reverse_iterator rIter = myMap.rbegin(); rIter != myMap.rend(); ++rIter) {
            if (rIter->second == 1)
                min = rIter->first;
        }

        bool found = false;
        for (int j = 0; j < tokens.size(); ++j) {
            int val = stoi(tokens[j]);
            if (val == min) {
                cout << j + 1 << endl;
                found = true;
            }
        }
        if (!found)
            cout << 0 << endl;
    }
}