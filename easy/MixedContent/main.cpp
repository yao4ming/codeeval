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
        while (getline(ss, token, ','))
            tokens.push_back(token);

        vector<string> words;
        vector<string> nums;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isalpha(tokens[i][0]))
                words.push_back(tokens[i]);
             else
                nums.push_back(tokens[i]);
        }

        for (int j = 0; j < words.size(); ++j) {
            if (j == words.size()-1)
                (nums.size() == 0) ? cout << words[j] : cout << words[j] << "|";
            else
                cout << words[j] << ",";
        }

        for (int k = 0; k < nums.size(); ++k)
            (k == nums.size()-1) ? cout << nums[k] : cout << nums[k] << ",";

        cout << endl;
    }
}