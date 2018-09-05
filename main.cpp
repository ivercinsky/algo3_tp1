#include <iostream>
#include "SubSetSumBruteForce.cpp"


using namespace std;


int main(int argc, char **argv) {
    SubSetSumBruteForce problem(cin);
    int res = problem.solveWithTimeTracking();
    cout << "Respuesta al problema " << res << endl;
}

