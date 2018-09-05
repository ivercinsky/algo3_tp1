#include <vector>
#include <iostream>
#include <assert.h>
#include <chrono>
using namespace std;

class SubSetSumBruteForce{
    public:
        int solve();
        int solveWithTimeTracking();
        SubSetSumBruteForce(istream& in);
    
    private:
        vector<int> values;
        int tamaño;
        int targetValue;
        void bruteForceSolution(vector <bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter);
};

SubSetSumBruteForce::SubSetSumBruteForce(istream& in) {
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    in >> tamaño;
    in >> targetValue;
    int agregados = 0;
    while(!cin.eof() && agregados < tamaño) {
        int input;
        in >> input;
        values.push_back(input);
        agregados++;
    }
    assert(agregados < tamaño || cin.eof());
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
    bruteForceSolution(valuesUsedInSolution, minCardinality, iterationsCounter, solutionsCounter);
    //cout << "Probo " << iterationsCounter << " Combinaciones" << endl;
    //cout << "Encontro " << solutionsCounter << " Soluciones" << endl;
    if (solutionsCounter > 0) {
        //cout << "La minima cantidad de elementos necesaria es " << minCardinality << endl;
        return minCardinality;
    }
    return 0;
}


void SubSetSumBruteForce::bruteForceSolution(vector<bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter) {
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
    bruteForceSolution(fb, currentMinCardinality, iterationsCounter, solutionsCounter);
    bruteForceSolution(tb, currentMinCardinality, iterationsCounter, solutionsCounter);
}

