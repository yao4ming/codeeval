#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string trim(string str) {
    string trimmedStr;
    int i, j;

    //trim left end
    for (i= 0; i < str.size(); ++i) {
        if (str[i] != ' ') break;
    }

    trimmedStr = str.substr(i);

    //trim right end
    for (j = (int)trimmedStr.size()-1; j >=0 ; --j) {
        if (trimmedStr[j] != ' ') break;
    }

    return trimmedStr.substr(0, j+1);
}

bool contains(string str, string str2) {
    string temp = str;
    size_t pos;
    for (int i = 0; i < str2.size(); ++i) {
        if ((pos = temp.find(str2[i])) != string::npos)
            temp.erase(pos, 1);
        else
            return false;
    }
    return true;
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

        stringstream ss2(tokens[0]);
        bool wineFound = false;
        while (getline(ss2, token, ' ')) {
            if (contains(token, tokens[1])) {
                cout << token << " ";
                wineFound = true;
            }
        }

        if (!wineFound)
            cout << "False";
        cout << endl;
    }
}