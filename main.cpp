#include <iostream>
#include "SubSetSumBruteForce.cpp"


using namespace std;


int main(int argc, char **argv) {
    SubSetSumBruteForce problem(cin);
    cout << problem.solve() << endl;
}

