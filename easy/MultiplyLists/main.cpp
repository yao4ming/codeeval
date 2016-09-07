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
        while (getline(ss, token, '|'))
            tokens.push_back(token);

        stringstream ss2(tokens[0]);
        vector<string> list1;
        while (getline(ss2, token, ' '))
            list1.push_back(token);

        stringstream ss3(tokens[1]);
        vector<string> list2;
        while (getline(ss3, token, ' '))
            list2.push_back(token);

        for (int i = 0; i < list1.size(); ++i)
            cout << stoi(list1[i]) * stoi(list2[i + 1]) << " ";
        cout << endl;
    }
}