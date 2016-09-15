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
    for (j = trimmedStr.size()-1; j > 0 ; --j) {
        if (str[j] != ' ')
            break;
    }

    return trimmedStr.substr(0, j+1);
}

int convertFaces(char face) {
    switch (face) {
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return face - '0';
    }
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
        vector<string> cards;
        while (getline(ss2, token, ' '))
            cards.push_back(token);

        int num1, num2;
        char face1, face2;

        if (cards[0].size() == 3) {
            num1 = stoi(cards[0].substr(0, 2));
            face1 = cards[0][2];
        } else {
            num1 = convertFaces(cards[0][0]);
            face1 = cards[0][1];
        }

        if (cards[1].size() == 3) {
            num2 = stoi(cards[1].substr(0, 2));
            face2 = cards[1][2];
        } else {
            num2 = convertFaces(cards[1][0]);
            face2 = cards[1][1];
        }

        if (face1 == face2) {
            (num1 > num2) ? cout << cards[0] << endl : cout << cards[1] << endl;
            continue;
        }

        if (face1 == tokens[1][0]) {
            cout << cards[0] << endl;
            continue;
        }

        if (face2 == tokens[1][0]) {
            cout << cards[1] << endl;
            continue;
        }

        if (num1 > num2) {
            cout << cards[0] << endl;
        } else if (num1 == num2) {
            cout << cards[0] << " " << cards[1] << endl;
        } else {
            cout << cards[1] << endl;
        }
    }
}