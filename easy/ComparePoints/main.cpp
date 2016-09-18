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
        vector<int> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(stoi(token));

        if (tokens[0] == tokens[2] && tokens[1] == tokens[3]) {
            cout << "here" << endl;
        } else if (tokens[0] < tokens[2] && tokens[1] < tokens[3]) {
            cout << "NE" << endl;
        } else if (tokens[0] > tokens[2] && tokens[1] < tokens[3]) {
            cout << "NW" << endl;
        } else if (tokens[0] < tokens[2] && tokens[1] > tokens[3]) {
            cout << "SE" << endl;
        } else if (tokens[0] > tokens[2] && tokens[1] > tokens[3]) {
            cout << "SW" << endl;
        } else if (tokens[0] == tokens[2] && tokens[1] > tokens[3]) {
            cout << "S" << endl;
        } else if (tokens[0] == tokens[2] && tokens[1] < tokens[3]) {
            cout << "N" << endl;
        } else if (tokens[0] < tokens[2] && tokens[1] == tokens[3]) {
            cout << "E" << endl;
        } else if (tokens[0] > tokens[2] && tokens[1] == tokens[3]) {
            cout << "W" << endl;
        }
    }
}