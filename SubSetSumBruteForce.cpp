#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <chrono>
#include <string>
using namespace std;

class SubSetSumBruteForce{
    public:
        int solve();
        int solveWithTimeTracking();
        SubSetSumBruteForce(istream& in);
        SubSetSumBruteForce(int argc, char** argv);
    
    private:
        vector<int> values;
        int tamaño;
        int targetValue;
        void solution(vector <bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter);
        void loadData(istream& input);
};


void SubSetSumBruteForce::loadData(istream& in) {
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    in >> tamaño;
    in >> targetValue;
    int agregados = 0;
    while(!in.eof() && agregados < tamaño) {
        int input;
        in >> input;
        values.push_back(input);
        agregados++;
    }
    assert(agregados < tamaño || in.eof());
}

SubSetSumBruteForce::SubSetSumBruteForce(istream& in) {
    loadData(in);
}

SubSetSumBruteForce::SubSetSumBruteForce(int argc, char** argv) {
    assert(argc == 2);
    ifstream instanceData(argv[1]);
    loadData(instanceData);
}

int SubSetSumBruteForce::solveWithTimeTracking() {
    auto startSolveTime = chrono::steady_clock::now();
    int res = solve();
    auto endSolveTime = chrono::steady_clock::now();
    auto diffTime = endSolveTime - startSolveTime;
    cout << "El Tiempo Utilizado fue " << chrono::duration <double, milli> (diffTime).count() << "ms" << endl;
    return res;
}

int SubSetSumBruteForce::solve() {
    int minCardinality = tamaño;
    vector<bool> valuesUsedInSolution = vector<bool>();
    int iterationsCounter = 0;
    int solutionsCounter = 0;
    solution(valuesUsedInSolution, minCardinality, iterationsCounter, solutionsCounter);
    cout << "Probo " << iterationsCounter << " Combinaciones" << endl;
    cout << "Encontro " << solutionsCounter << " Soluciones" << endl;
    if (solutionsCounter > 0) {
        cout << "La minima cantidad de elementos necesaria es " << minCardinality << endl;
        return minCardinality;
    }
    return 0;
}


void SubSetSumBruteForce::solution(vector<bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter) {
    if(valuesUsedInSolution.size() == tamaño) {
        //cout << "Probando Solucion ";
        //for (const bool &val : valuesUsedInSolution) {
        //    cout << val << " ";
        //}
        iterationsCounter++;
        int elementsUsed = 0;
        int acum = 0;
        for(int i=0;i<tamaño;i++){
            if(valuesUsedInSolution[i]) {
                acum += values[i];
                elementsUsed++;
            }    
        }
        //cout << "el acumulado fue " << acum << " y el target es " << targetValue << endl;
        if (acum == targetValue) {
            if (currentMinCardinality > elementsUsed) {
                currentMinCardinality = elementsUsed;
            }
            solutionsCounter++;
            //cout << "Solucion" << endl;
        }
        return;
    }
    vector<bool> fb = valuesUsedInSolution;
    fb.push_back(false);
    vector<bool> tb = valuesUsedInSolution;
    tb.push_back(true);
    solution(fb, currentMinCardinality, iterationsCounter, solutionsCounter);
    solution(tb, currentMinCardinality, iterationsCounter, solutionsCounter);
}

