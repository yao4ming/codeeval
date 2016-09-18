#include <iostream>
#include <fstream>
#include <vector>
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
        while (getline(ss, token, '|'))
            tokens.push_back(trim(token));

        vector<vector<int>> scoreTable;
        for (int i = 0; i < tokens.size(); ++i) {
            stringstream ss2(tokens[i]);
            vector<int> scores;
            while (getline(ss2, token, ' '))
                scores.push_back(stoi(token));

            scoreTable.push_back(scores);
        }

        for (int i = 0; i < scoreTable[0].size(); i++) {
            int max = INT32_MIN;
            for (int j = 0; j < scoreTable.size(); ++j)
                if (scoreTable[j][i] > max) {
                    max = scoreTable[j][i];
            }
            cout << max << " ";
        }
        cout << endl;
    }
}