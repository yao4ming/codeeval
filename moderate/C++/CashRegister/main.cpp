#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {

    int cash[] = {1,5,10,25,50,100,200,500,1000,2000,5000,10000};
    string cashStr[] = {"PENNY", "NICKEL", "DIME", "QUARTER", "HALF DOLLAR", "ONE", "TWO", "FIVE", "TEN", "TWENTY", "FIFTY", "ONE HUNDRED"};

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ';'))
            tokens.push_back(token);

        int price = stof(tokens[1]) * 100;
        int money = stof(tokens[0]) * 100;
        int diff = price - money;

        if (diff < 0)
            cout << "ERROR";

        if (diff == 0)
            cout << "ZERO";

        stringstream ss2;

        for (int i = 11; i >= 0; --i) {
            while (diff >= cash[i]) {
                diff -= cash[i];
                ss2 << cashStr[i] << ",";
            }
        }

        cout << ss2.str().substr(0, ss2.str().size()-1) << endl;
    }
}