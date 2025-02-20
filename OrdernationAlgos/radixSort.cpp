using namespace std;

#include <iostream>
#include <vector>

void radixSort(vector<int> v, int maxorder, int base){
    int order = 0, mod = 0, tentimes = 10;
    vector<vector<int>> organizer;
    vector<int> dummy, auxv;

    for(int i = 0; i < base; i++) organizer.push_back(dummy);
    for(int i = 1; i < maxorder; i++) tentimes = tentimes*10;
    for(int i = 0; i < (int) v.size(); i++) auxv.push_back(v[i]);


    while(order < maxorder){
        for(int i = 0; i < (int) v.size(); i++){
            mod = auxv[i]%10;
            auxv[i] = auxv[i]/10;

            organizer[mod].push_back(v[i]);
        }

        tentimes = tentimes/10;
        order++;
    }
}



int main(){

    int aux = 350;
    vector<int> v;

    for(int i = 0; i < 35; i++){
        v.push_back(aux);
        aux = aux-10;
    }
    for(int i = 0; i < (int) v.size(); i++) cout << v.[i] << " ";
    cout << endl;

    radixSort(v, 3, 10);
    return 0;
}