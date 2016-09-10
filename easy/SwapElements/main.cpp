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
        while (getline(ss, token, ':'))
            tokens.push_back(token);

        //vector to store elements
        stringstream ss2(tokens[0]);
        vector<int> elem;
        while (getline(ss2, token, ' '))
            elem.push_back(stoi(token));

        //vector to store swap pos
        stringstream ss3(tokens[1]);
        vector<string> posStr;
        vector<int> pos;
        while (getline(ss3, token, ',')) {
            stringstream ss4(token);
            while (getline(ss4, token, '-'))
                pos.push_back(stoi(token));
        }

        for (int i = 0; i < pos.size()-1; i+=2) {
            int left = pos[i];
            int right = pos[i+1];
            swap(elem[left], elem[right]);
        }

        for (int j = 0; j < elem.size(); ++j)
            (j == elem.size()-1) ? cout << elem[j] : cout << elem[j] << " ";
        cout << endl;

    }
}