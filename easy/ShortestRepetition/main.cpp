#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        string str1(""), str2("");
        int i;
        for (i = 0; i < line.size(); ++i) {
            if (str1[0] != line[i])
                str1 += line[i];
            else
                break;
        }
        for (int j = i; j < i + str1.size(); ++j)
            str2 += line[j];

        cout << str1.size() << endl;
    }
}