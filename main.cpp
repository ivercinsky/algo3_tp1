#include <iostream>
#include "SubSetSum.cpp"
using namespace std;


int main(int argc, char **argv) {
    SubSetSum problem(cin);

    cout << problem.solveByBruteForce() << endl;
    cout << problem.solveByBacktracking() << endl;
    cout << problem.solveByDynamicProgramming() << endl;
    
}

