#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<double> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(stod(token));

        sort(tokens.begin(), tokens.end());

        cout << fixed << setprecision(3);
        for (int i = 0; i < tokens.size(); ++i)
            cout << tokens[i] <<  " ";
        cout << endl;


    }
}