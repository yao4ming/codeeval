#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
            tokens.push_back(token);

        stringstream ss2(tokens[1].substr(1));
        string num;
        vector<int> nums;
        while (getline(ss2, num, ' '))
            nums.push_back(stoi(num));

        stringstream out;
        for (int i = 0; i < nums.size(); ++i) {
            cout << tokens[0][nums[i]-1];
        }
        cout << endl;
    }
}