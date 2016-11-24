#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

int main(int argc, char** argv) {

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        vector<string> tokens = split(line, ' ');
        int m = stoi(tokens[tokens.size()-1]);
        int i = (int)tokens.size()-1-m;
        if (i >= 0)
            cout << tokens[i] << endl;
    }
}