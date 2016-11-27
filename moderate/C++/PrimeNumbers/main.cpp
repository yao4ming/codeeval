#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int num) {

    bool prime[num+1];
    memset(prime, true, sizeof(prime));

    for (int j = 2; j * j <= num; ++j) {
        if (prime[j]) {
            for (int i = j * 2; i <= num; i += j)
                prime[i] = false;
        }
    }

    stringstream ss;
    for (int k = 2; k <= num; ++k) {
        if (prime[k] && k != num)
            ss << k << ",";
    }

    cout << ss.str().substr(0, ss.str().size()-1) << endl;
}

int main(int argc, char** argv) {

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        sieveOfEratosthenes(stoi(line));
    }
}