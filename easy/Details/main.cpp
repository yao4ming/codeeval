#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
            tokens.push_back(token);

        int move = 0, minMove = INT32_MAX;
        for (int i = 0; i < tokens.size(); ++i) {
            for (int j = 0; j < tokens[i].size(); ++j) {
                if (tokens[i][j] == '.' && (tokens[i][j-1] != tokens[i][j+1]))
                    move++;
            }
            if (minMove > move)
                minMove = move;
            move = 0;
        }
        cout << minMove << endl;
    }
}