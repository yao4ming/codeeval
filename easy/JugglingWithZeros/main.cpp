#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

long long binToDec(string value) {
    long long decimal = 0;
    short base = 2;
    for(int i = 0; value[i] != '\0'; i++) {
        long long temp = (value[i] - '0') * pow(base, value.size() - 1 - i);
        //cout << value[i] << " * " << pow(base, value.size() - 1 - i) << " = " << temp << endl;
        decimal += temp;
    }
    return decimal;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;

        bool zero;
        int i = 0;
        string bin = "";
        while (getline(ss, token, ' ')) {
            if (i % 2 == 0) {
                zero = (token.size() == 1);
                i++;
                continue;
            }
            if (zero) {
                for (int j = 0; j < token.size(); ++j)
                    bin.append(to_string(0));
            }
            else {
                for (int j = 0; j < token.size(); ++j)
                    bin.append(to_string(1));
            }
            i++;
        }

        cout << binToDec(bin) << endl;
    }
}