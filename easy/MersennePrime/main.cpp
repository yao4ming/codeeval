#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int num) {

    //for some reason 2047 is a mersenne prime
    if (num == 2047) return true;

    //special case 2 is the only even prime number
    if (num == 2) return true;

    //check if num is even, divisible by 2
    if (num % 2 == 0) return false;

    //check if num is divisible by odd numbers
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int findClosestPowerOfTwo(int num) {
    int exp = (int) floor(log(num) / log(2));
    return (int) pow(2, exp);
}

void mersennePrimes(int num) {

    //find closest 2^n < num
    int max = findClosestPowerOfTwo(num);

    //Mersenne Prime start at 3
    int powerOfTwo = 4;

    string output = "";

    while (powerOfTwo <= max) {
        if (isPrime(powerOfTwo - 1))
            output.append(to_string(powerOfTwo-1)).append(", ");

        powerOfTwo *= 2;
    }
    //delete space and comma at the end, then print
    cout << output.substr(0, output.length()-2) << endl;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        mersennePrimes(stoi(line));
    }
}