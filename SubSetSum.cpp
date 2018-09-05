#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class SubSetSum {
    public:
        int solveByBruteForce();

        int solveByBacktracking();

        int solveByDynamicProgramming();

        SubSetSum();
        SubSetSum(istream& in);
    private:
        vector<int> values;
        int tamaño;
        int targetValue;
        void bruteForceSolution(vector <bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter);
};

SubSetSum::SubSetSum(void) {
    values = vector<int>();
    targetValue = 0;
}

SubSetSum::SubSetSum(istream& in) {
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

int SubSetSum::solveByBruteForce() {
    int minCardinality = tamaño;
    vector<bool> valuesUsedInSolution = vector<bool>();
    int iterationsCounter = 0;
    int solutionsCounter = 0;
    bruteForceSolution(valuesUsedInSolution, minCardinality, iterationsCounter, solutionsCounter);
    cout << "Probo " << iterationsCounter << " Combinaciones" << endl;
    cout << "Encontro " << solutionsCounter << " Soluciones" << endl;
    if (solutionsCounter > 0) {
        cout << "La minima cantidad de elementos necesaria es " << minCardinality << endl;
    }
    return minCardinality;
}

int SubSetSum::solveByBacktracking() {
    return values[0];
}

int SubSetSum::solveByDynamicProgramming() {
    return values[0];
}

void generate(vector<bool> &v, int tamaño, vector<vector<bool>> vs) {
    if (v.size() == tamaño) {
       vs.push_back(v);
       return;
    }
    vector<bool> fb = v;
    fb.push_back(false);
    vector<bool> tb = v;
    tb.push_back(true);
    generate(fb, tamaño, vs);
    generate(tb, tamaño, vs);
}

void SubSetSum::bruteForceSolution(vector<bool> &valuesUsedInSolution, int &currentMinCardinality, int &iterationsCounter, int &solutionsCounter) {
    if(valuesUsedInSolution.size() == tamaño) {
        cout << "Probando Solucion ";
        for (const bool &val : valuesUsedInSolution) {
            cout << val << " ";
        }
        iterationsCounter++;
        int elementsUsed = 0;
        int acum = 0;
        for(int i=0;i<tamaño;i++){
            if(valuesUsedInSolution[i]) {
                acum += values[i];
                elementsUsed++;
            }    
        }
        cout << "el acumulado fue " << acum << " y el target es " << targetValue << endl;
        if (acum == targetValue) {
            if (currentMinCardinality > elementsUsed) {
                currentMinCardinality = elementsUsed;
            }
            solutionsCounter++;
            cout << "Solucion" << endl;
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

