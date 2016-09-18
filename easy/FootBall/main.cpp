#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

string trim(string str) {
    string trimmedStr;
    int i, j;

    //trim left end
    for (i= 0; i < str.size(); ++i) {
        if (str[i] != ' ')
            break;
    }

    trimmedStr = str.substr(i);

    //trim right end
    for (j = trimmedStr.size()-1; j >=0 ; --j) {
        if (trimmedStr[j] != ' ')
            break;
    }

    return trimmedStr.substr(0, j+1);
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
            tokens.push_back(trim(token));

        map<int, vector<int>> m;

        for (int i = 0; i < tokens.size(); ++i) {
            stringstream ss2(tokens[i]);
            while (getline(ss2, token, ' '))
                m[stoi(token)].push_back(i+1);
        }

        for(map<int, vector<int>>::iterator iter = m.begin(); iter != m.end(); iter++) {
            cout << iter->first << ":";
            for (int i = 0; i < iter->second.size(); ++i)
                (i != iter->second.size()-1) ? cout << iter->second[i] << "," : cout << iter->second[i] << "; ";
        }
        cout << endl;
    }
}