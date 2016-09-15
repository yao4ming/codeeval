#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ';'))
            tokens.push_back(token);

        stringstream ss2(tokens[1]);
        vector<int> nums;
        while (getline(ss2, token, ' '))
            nums.push_back(stoi(token));

        int maxSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < i + stoi(tokens[0]); ++j) {
                if (j == nums.size())
                    break;
                sum += nums[j];
            }
            if (maxSum < sum)
                maxSum = sum;

            if (i + stoi(tokens[0]) >= nums.size())
                break;
        }
        cout << maxSum << endl;
    }
}