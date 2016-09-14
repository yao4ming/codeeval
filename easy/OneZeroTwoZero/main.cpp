#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;

int getNumOfZeroes(unsigned int value) {
    int exponent = log2(value);
    int temp = exponent;
    int numZero = 0;
    for(int i = 0; i <= exponent; i++) {
        if(value >= pow(2,temp))
            value -= pow(2,temp);
        else
            numZero++;
        temp--;
    }
    return numZero;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<int> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(stoi(token));

        int count = 0;
        for (int i = 1; i <= tokens[1]; ++i) {
            if (getNumOfZeroes(i) == tokens[0])
                count++;
        }
        cout << count << endl;
    }
}