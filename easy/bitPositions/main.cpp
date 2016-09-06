#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

string toBinary(int decimal) {
    stringstream ss;
    int exponent = log2(decimal);
    int temp = exponent;
    for(int i = 0; i <= exponent; i++) {
        if(decimal >= pow(2,temp)) {
            ss << "1";
            decimal -= pow(2,temp);
        }
        else {
            ss << "0";
        }
        temp--;
    }
    return ss.str();
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;

    while(getline(in, line)) {
        vector<string> tokens = split(line, ',');
        string binary = toBinary(stoi(line, nullptr, 10));
        int pos1 = (int)binary.length() - stoi(tokens[1]);
        int pos2 = (int)binary.length() - stoi(tokens[2]);
        //check bit position
        if (binary[pos1] == binary[pos2])
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}