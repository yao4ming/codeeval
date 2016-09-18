#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        string word = "";
        while (getline(ss, token, ' ')) {
            if (token.size() > word.size())
                word = token;
        }

        for (int i = 0; i < word.size(); ++i) {
            for (int j = 0; j < i; ++j)
                cout << "*";
            cout << word[i] << " ";
        }
        cout << endl;
    }
}