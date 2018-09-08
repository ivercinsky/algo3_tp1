
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> datos;

int solucion(int i, int v, vector<int>& values) {
	if (datos[i][v] != -1) return datos[i][v];
	
	int res;
	if (v == 0) res = 0;
	else if (i >= values.size()) res =  0;
	else if (values[i] == v) res =  1;
	else if (values[i] > v) {
		res = solucion(i+1,v,values);
	}
	else if (values[i] < v) {
		res =  max(1 + solucion(i+1,v-values[i],values), solucion(i+1,v,values));
	}
	datos[i][v] = res;
	return res;
}

void pd() {
    int n = 7;
    vector<int> values({5,4,3,2});

    datos = vector<vector<int>>(values.size()+1,vector<int>(n+1,-1));
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<solucion(0,n,values)<<endl;
}

int main() {
    pd();
}


