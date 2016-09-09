#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int partition(int arr[], int start, int last) {

    int pivotValue = arr[last];
    int pivotPosition = start;

    for (int pos = start; pos < last; pos++) {
        if (arr[pos] <= pivotValue) {
            swap(arr[pivotPosition], arr[pos]);
            pivotPosition++;
        }
    }
    swap(arr[last], arr[pivotPosition]);
    return pivotPosition;
}

void quickSort(int arr[], int start, int last) {

    if(start < last) //base case
    {
        int pivot = partition(arr, start, last);

        quickSort(arr, start, pivot - 1);     //sort recursively sort elements less than the pivot
        quickSort(arr, pivot + 1 , last);     //sort recursively sort elements greater than the pivot
    }
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        int pos = 0;
        int tokens[900];

        while (getline(ss, token, ';')) {
            stringstream ss2(token);
            while (getline(ss2, token, ',')) {
               if (isdigit(token[0]))
                   tokens[pos++] = stoi(token);
            }
        }
        quickSort(tokens, 0, pos-1);

        cout << tokens[0] << ",";
        for (int i = 1; i < pos; ++i) {
            (i == pos-1) ? cout << tokens[i] - tokens[i-1]:
                                     cout << tokens[i] - tokens[i-1] << ",";
        }
        cout << endl;
    }
}