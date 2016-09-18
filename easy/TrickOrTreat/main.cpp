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
        vector<int> tokens;
        while (getline(ss, token, ',')) {
            token = trim(token);
            stringstream ss2(token);
            while (getline(ss2, token, ':')) {
                token = trim(token);
                if (isdigit(token[0]))
                    tokens.push_back(stoi(token));
            }
        }

        int candies = (tokens[0] * 3 + tokens[1] * 4 + tokens[2] * 5) * tokens[3];
        int kids = tokens[0] + tokens[1] + tokens[2];
        cout << candies / kids << endl;
    }
}