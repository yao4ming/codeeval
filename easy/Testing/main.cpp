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
        if (str[j] != ' ')
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

        int bug = 0;
        for (int i = 0; i < tokens[1].length(); i++) {
            if (tokens[0][i] != tokens[1][i])
                bug++;
        }

        if (bug < 1)
            cout << "Done" << endl;
         else if (bug <= 2)
            cout << "Low" << endl;
         else if (bug <= 4)
            cout << "Medium" << endl;
         else if (bug <= 6)
            cout << "High" << endl;
         else
            cout << "Critical" << endl;

    }
}