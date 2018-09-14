#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <chrono>
#include <string>
using namespace std;

class SubSetSumBackTracking{
    public:
        int solve();
        int solveWithTimeTracking();
        SubSetSumBackTracking(istream& in);
        SubSetSumBackTracking(int argc, char** argv);
        SubSetSumBackTracking(unsigned int psize, unsigned int ptargetValue, vector<unsigned int>& pvalues);
    
    private:
        vector<unsigned int> values;
        unsigned int size;
        unsigned int targetValue;
        void solution(vector <bool> &valuesUsedInSolution, unsigned int &currentMinCardinality, unsigned int &iterationsCounter, unsigned int &solutionsCounter);
        void loadData(istream& input);
};

void SubSetSumBackTracking::loadData(istream& in) {
    in >> size;
    in >> targetValue;
    unsigned int agregados = 0;
    while(!in.eof() && agregados < size) {
        unsigned int input;
        in >> input;
        values.push_back(input);
        agregados++;
    }
    assert(agregados < size || in.eof());
}

SubSetSumBackTracking::SubSetSumBackTracking(int argc, char** argv) {
    assert(argc == 2);
    ifstream instanceData(argv[1]);
    loadData(instanceData);
}
SubSetSumBackTracking::SubSetSumBackTracking(istream& in) {
    loadData(in);
}

SubSetSumBackTracking::SubSetSumBackTracking(unsigned int psize, unsigned int ptargetValue, vector<unsigned int>& pvalues) {
    size = psize;
    targetValue = ptargetValue;
    values = pvalues;
} 

int SubSetSumBackTracking::solveWithTimeTracking() {
    auto startSolveTime = chrono::steady_clock::now();
    int res = solve();
    auto endSolveTime = chrono::steady_clock::now();
    auto diffTime = endSolveTime - startSolveTime;
    //cout << "El Tiempo Utilizado fue " << chrono::duration <double, milli> (diffTime).count() << "ms" << endl;
    cout << chrono::duration <double, milli> (diffTime).count();
    return res;
}

int SubSetSumBackTracking::solve() {
    unsigned int minCardinality = size;
    vector<bool> valuesUsedInSolution = vector<bool>();
    unsigned int iterationsCounter = 0;
    unsigned int solutionsCounter = 0;
    //Existe Solucion Posible? Suma de los valores es > al target. No es garantia, pues puede haber huecos. Pero si ni siquiera usando todos los elementos llegamos al target, no hay solucion
    unsigned int acum = 0;
    for (unsigned int i = 0; i < values.size() ; i++) {
        acum += values[i];
    }
    if (acum > targetValue) {
        //Los elementos suman un valor mayor al esperado.
        solution(valuesUsedInSolution, minCardinality, iterationsCounter, solutionsCounter);
        //cout << "Probo " << iterationsCounter << " Combinaciones" << endl;
        //cout << "Encontro " << solutionsCounter << " Soluciones" << endl;
        if (solutionsCounter > 0) {
            //cout << "La minima cantidad de elementos necesaria es " << minCardinality << endl;
            return minCardinality;
        }
        return 0;
    } else if (acum == targetValue) {
        //Todos los elementos suma un valor menor al buscado, luego no existe sub set que sume el valor.
        return values.size();
    } else {
        return 0;
    }
}


void SubSetSumBackTracking::solution(vector<bool> &valuesUsedInSolution, unsigned int &currentMinCardinality, unsigned int &iterationsCounter, unsigned int &solutionsCounter) {
    if(valuesUsedInSolution.size() == size) {
        //cout << "Probando Solucion ";
        //for (const bool &val : valuesUsedInSolution) {
        //    cout << val << " ";
        //}
        iterationsCounter++;
        unsigned int elementsUsed = 0;
        unsigned int acum = 0;
        for(unsigned int i=0;i<size;i++){
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
    } else {
        //Chequear si la solucion parcial es factible o si ya tiene mas elementos que el minimo actual
        int acum = 0;
        int elementsUsed = 0;
        for(unsigned int i = 0; i < valuesUsedInSolution.size() ; i++) {
            
            if (valuesUsedInSolution[i]) {
                acum+=values[i];
                elementsUsed++;
            }
        }
        if (acum <= targetValue || elementsUsed <= currentMinCardinality) {
            vector<bool> fb = valuesUsedInSolution;
            fb.push_back(false);
            vector<bool> tb = valuesUsedInSolution;
            tb.push_back(true);
            solution(fb, currentMinCardinality, iterationsCounter, solutionsCounter);
            solution(tb, currentMinCardinality, iterationsCounter, solutionsCounter);
        }
    }
}

