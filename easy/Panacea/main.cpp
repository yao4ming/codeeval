#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
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

int getDec(char hex) {
    switch (hex) {
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            return hex - '0';
    }
}

int binToDec(string bin) {
    int dec = 0;
    for(int i = 0; bin[i] != '\0'; i++)
        dec = dec + (bin[i] - '0') * (int)pow(2, bin.size() - 1 - i);
    return dec;
}

int hexToDec(string hex) {
    int dec = 0;
    for (int i = 0; hex[i] != '\0'; i++)
        dec = dec + getDec(hex[i]) * (int)pow(16, hex.size() - 1 - i);
    return dec;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
            tokens.push_back(token);

        stringstream ss2(trim(tokens[0]));
        int hexSum = 0;
        while (getline(ss2, token, ' ')) {
            int dec = hexToDec(token);
            hexSum += dec;
        }

        stringstream ss3(trim(tokens[1]));
        vector<string> bin;
        int binSum = 0;
        while (getline(ss3, token, ' ')) {
            int dec = binToDec(token);
            binSum += dec;
        }

        (hexSum > binSum) ? cout << "False" : cout << "True";
        cout << endl;
    }
}