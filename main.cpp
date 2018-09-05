#include <iostream>
#include "SubSetSumBruteForce.cpp"
#include "SubSetSumBacktracking.cpp"


using namespace std;


int main(int argc, char **argv) {
    
    SubSetSumBruteForce problem1(argc, argv);
    int res = problem1.solveWithTimeTracking();
    cout << "Respuesta al problema con FB = " << res << endl;

    cout << endl << endl;
    
    SubSetSumBackTracking problem2(argc, argv);
    res = problem2.solveWithTimeTracking();
    cout << "Respuesta al problema Backtracking = " << res << endl;


}

