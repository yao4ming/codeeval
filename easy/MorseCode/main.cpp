#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>
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

        for (int i = 0; i < tokens.size(); ++i) {
            if (strncmp(tokens[i].c_str(), ".-", tokens[i].size()) == 0 && tokens[i].size() == 2)
                cout << "A";
            else if (strncmp(tokens[i].c_str(), "-...", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "B";
            else if (strncmp(tokens[i].c_str(), "-.-.", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "C";
            else if (strncmp(tokens[i].c_str(), "-..", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "D";
            else if (strncmp(tokens[i].c_str(), ".", tokens[i].size()) == 0 && tokens[i].size() == 1)
                cout << "E";
            else if (strncmp(tokens[i].c_str(), "..-.", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "F";
            else if (strncmp(tokens[i].c_str(), "--.", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "G";
            else if (strncmp(tokens[i].c_str(), "....", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "H";
            else if (strncmp(tokens[i].c_str(), "..", tokens[i].size()) == 0 && tokens[i].size() == 2)
                cout << "I";
            else if (strncmp(tokens[i].c_str(), ".---", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "J";
            else if (strncmp(tokens[i].c_str(), "-.-", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "K";
            else if (strncmp(tokens[i].c_str(), ".-..", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "L";
            else if (strncmp(tokens[i].c_str(), "--", tokens[i].size()) == 0 && tokens[i].size() == 2)
                cout << "M";
            else if (strncmp(tokens[i].c_str(), "-.", tokens[i].size()) == 0 && tokens[i].size() == 2)
                cout << "N";
            else if (strncmp(tokens[i].c_str(), "---", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "O";
            else if (strncmp(tokens[i].c_str(), ".--.", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "P";
            else if (strncmp(tokens[i].c_str(), "--.-", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "Q";
            else if (strncmp(tokens[i].c_str(), ".-.", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "R";
            else if (strncmp(tokens[i].c_str(), "...", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "S";
            else if (strncmp(tokens[i].c_str(), "-", tokens[i].size()) == 0 && tokens[i].size() == 1)
                cout << "T";
            else if (strncmp(tokens[i].c_str(), "..-", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "U";
            else if (strncmp(tokens[i].c_str(), "...-", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "V";
            else if (strncmp(tokens[i].c_str(), ".--", tokens[i].size()) == 0 && tokens[i].size() == 3)
                cout << "W";
            else if (strncmp(tokens[i].c_str(), "-..-", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "X";
            else if (strncmp(tokens[i].c_str(), "-.--", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "Y";
            else if (strncmp(tokens[i].c_str(), "--..", tokens[i].size()) == 0 && tokens[i].size() == 4)
                cout << "Z";
            else if (strncmp(tokens[i].c_str(), "", tokens[i].size()) == 0 && tokens[i].size() == 0)
                cout << " ";
            else if (strncmp(tokens[i].c_str(), ".----", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "1";
            else if (strncmp(tokens[i].c_str(), "..---", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "2";
            else if (strncmp(tokens[i].c_str(), "...--", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "3";
            else if (strncmp(tokens[i].c_str(), "....-", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "4";
            else if (strncmp(tokens[i].c_str(), ".....", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "5";
            else if (strncmp(tokens[i].c_str(), "-....", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "6";
            else if (strncmp(tokens[i].c_str(), "--...", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "7";
            else if (strncmp(tokens[i].c_str(), "---..", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "8";
            else if (strncmp(tokens[i].c_str(), "----.", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "9";
            else if (strncmp(tokens[i].c_str(), "-----", tokens[i].size()) == 0 && tokens[i].size() == 5)
                cout << "0";
            else
                cout << "NONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNE";
        }
        cout << endl;
    }
}