#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        int arrows = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '>') {
                if (line[i+1] == '>') {
                    if (line[i+2] == '-') {
                        if (line[i+3] == '-') {
                            if (line[i+4] == '>') {
                                arrows++;
                            }
                        }
                    }
                }
            } else if (line[i] == '<') {
                if (line[i+1] == '-') {
                    if (line[i+2] == '-') {
                        if (line[i+3] == '<') {
                            if (line[i+4] == '<') {
                                arrows++;
                            }
                        }
                    }
                }
            }
        }

        cout << arrows << endl;
    }
}