
#include <vector>
#include <iostream>

using namespace std;


int solucion(vector<int>&vus, int v, vector<int>& vs, int offset) {
    
    if(vs.size() - offset == 0) return 0;
    int acum =0;
    for(int i = offset; i < vs.size(); i++) //O(n)
    {
        if (vs[i] == v) {
            return 1;
        } else {
            acum+=vs[i];
        }
    }
    if(acum < v) {
        return 0;
    }

    acum = 0;
    
    for(int i = 0; i < vus.size(); i++) //O(n)
    {   
        acum+=vus[i];
    }
    if(acum == v) {
        return 1;
    }

    vector<int> nvus = vus; //O(n)
    nvus.push_back(vs[offset]);
    int a = 1 + solucion(nvus,v - vs[offset], vs, offset +1);
    int b = solucion(vus,v,vs,offset+1);
    return max(a,b);

}

void pd() {
    int n = 6;
    vector<int> values({1,2,9,3,5,7});


    vector<int> vus = vector<int>();
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<"Resultado: " << solucion(vus,18,values,0)<<endl;
}

int main() {
    pd();
}


