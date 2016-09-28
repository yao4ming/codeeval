#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int getNumOfOnes(unsigned int value) {
    int exponent = log2(value);
    int temp = exponent;
    int numOfOnes = 0;
    for(int i = 0; i <= exponent; i++) {
        if(value >= pow(2,temp)) {
            value -= pow(2,temp);
            numOfOnes++;
        }
        temp--;
    }
    return numOfOnes;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        unsigned int num = (unsigned int)stoi(line);
        cout << getNumOfOnes(num) << endl;

    }
}
