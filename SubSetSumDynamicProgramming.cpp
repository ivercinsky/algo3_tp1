#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <chrono>
#include <string>
using namespace std;

class SubSetSumDynamicProgramming{
    public:
        int solve();
        int solveWithTimeTracking();
        SubSetSumDynamicProgramming(istream& in);
        SubSetSumDynamicProgramming(int argc, char** argv);
    
    private:
        vector<int> values;
        unsigned int size;
        int targetValue;
        void solution(vector <bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter);
        void loadData(istream& input);
};

void SubSetSumDynamicProgramming::loadData(istream& in) {
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    in >> size;
    in >> targetValue;
    unsigned int agregados = 0;
    while(!in.eof() && agregados < size) {
        int input;
        in >> input;
        values.push_back(input);
        agregados++;
    }
    assert(agregados < size || in.eof());
}

SubSetSumDynamicProgramming::SubSetSumDynamicProgramming(int argc, char** argv) {
    assert(argc == 2);
    ifstream instanceData(argv[1]);
    loadData(instanceData);
}
SubSetSumDynamicProgramming::SubSetSumDynamicProgramming(istream& in) {
    loadData(in);
}

int SubSetSumDynamicProgramming::solveWithTimeTracking() {
    auto startSolveTime = chrono::steady_clock::now();
    int res = solve();
    auto endSolveTime = chrono::steady_clock::now();
    auto diffTime = endSolveTime - startSolveTime;
    cout << chrono::duration <double, milli> (diffTime).count() << endl;
    return res;
}

int SubSetSumDynamicProgramming::solve() {
    int minCardinality = size;
    vector<bool> valuesUsedInSolution = vector<bool>();
    int iterationsCounter = 0;
    int solutionsCounter = 0;
    solution(valuesUsedInSolution, minCardinality, iterationsCounter, solutionsCounter);
    //cout << "Probo " << iterationsCounter << " Combinaciones" << endl;
    //cout << "Encontro " << solutionsCounter << " Soluciones" << endl;
    if (solutionsCounter > 0) {
        //cout << "La minima cantidad de elementos necesaria es " << minCardinality << endl;
        return minCardinality;
    }
    return 0;
}


void SubSetSumDynamicProgramming::solution(vector<bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter) {
    
}




