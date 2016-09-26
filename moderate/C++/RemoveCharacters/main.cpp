#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
        while (getline(ss, token, ','))
            tokens.push_back(trim(token));

        for (int i = 0; i < tokens[0].size(); ++i) {
            tokens[0].erase(remove(tokens[0].begin(), tokens[0].end(), tokens[1][i]), tokens[0].end());
        }

        cout << tokens[0] << endl;
    }
}
