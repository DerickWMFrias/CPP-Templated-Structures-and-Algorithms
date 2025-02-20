using namespace std;

#include <iostream>
#include <vector>


vector<int> countingSort(vector<int> v, int lo, int hi){

    vector<int> ret;
    int spam = hi - lo + 1, size = v.size();
    int count[spam], auxret[size];

    cout << spam << " " << size << endl;

    for(int i = 0; i < spam; i++) count[i] = 0;
    for(int i = 0; i < spam; i++) cout << count[i] << " ";
    cout << endl;

    for(int i = 0; i < size; i++) count[v[i]-lo]++;
    for(int i = 0; i < spam; i++) cout << count[i] << " ";
    cout << endl;

    for(int i = 1; i < spam; i++) count[i] += count[i-1];
    for(int i = 0; i < spam; i++) cout << count[i] << " ";
    cout << endl;


    cout << "AUXRET" << endl;
    for(int i = size-1; i >=0; i--){
        cout << v[i] << " " << count[v[i]-lo] << "       ";

        auxret[count[v[i]-lo]-1] = v[i];
        count[v[i]-lo]--;
        for(int i = 0; i < size; i++) cout << auxret[i] << " ";
        cout << endl;
    }

    cout << "end" << endl;

    for(int i = 0; i < size; i++) ret.push_back(auxret[i]);

    return ret;
}

int main(){
    vector<int> v, ret;

    v.push_back(7);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-2);
    
    for(int i = 0; i < (int) v.size(); i++) cout << v[i] << " ";
    cout << endl;

    ret = countingSort(v, -2, 7);


    for(int i = 0; i < (int) v.size(); i++) cout << ret[i] << " ";
    cout << endl;
    return 0;
}