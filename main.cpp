#include <iostream>
#include <vector>
#include "SubSetSumBruteForce.cpp"
#include "SubSetSumBacktracking.cpp"
#define uint unsigned int

using namespace std;

void loadDataHelper(uint &size, uint &targetValue, vector<uint> &values) {
    cin >> size;
    cin >> targetValue;

    unsigned int agregados = 0;
    while(!cin.eof() && agregados < size) {
        unsigned int input;
        cin >> input;
        values.push_back(input);
        agregados++;
    }
    assert(agregados < size || cin.eof());
} 

int main(int argc, char **argv) {
    int res = 0;
    uint size=0;
    uint targetValue=0;
    vector<uint> values;
    loadDataHelper(size, targetValue, values);
    cout << size << " " << targetValue << " ";
    string arg = argv[1];
    if (arg == "bt") {
        SubSetSumBackTracking problem2(size, targetValue, values);
        res = problem2.solveWithTimeTracking();
    }
    else if (arg == "fb"){
        SubSetSumBruteForce problem1(size, targetValue, values);
        res = problem1.solveWithTimeTracking();
    }
    
    cout << endl;
    return 0;
}


