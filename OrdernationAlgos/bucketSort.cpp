using namespace std;

#include <iostream>
#include <vector>

void bucketSort(vector<double> v, double lo, double hi){

    int size = v.size(); 
    double step = (hi-lo)/size;

    int n = size;
    while(step == 0.0){
        n = n/2;
        step = (hi-lo)/n;
    }

    vector<vector<double>> buckets;
    vector<double> dummy;
    //dummy.push_back(0.0);

    for(int i = 0; i < n; i++) buckets.push_back(dummy);

    for(int i = 0; i < size; i++){
        if(v[i]==hi){ 
            buckets[n-1].push_back(v[i]);
            continue;
        }

        double aux = (v[i]-lo)/step;
        int at = (int) aux;

        buckets[at].push_back(v[i]);
    }

    //Ordenaria os buckets
    cout << "Statistics" << endl;
    cout << "Total of elements: " << size << endl;
    cout << "Lo = " << lo << "    Hi = " << hi << endl;
    cout << "Number of Buckets: " << n << endl;
    cout << "Step size: " << step << endl;
    
    cout << endl;
    cout << "Showing Intervals" << endl;

    for(int i = 0; i < n; i++){
        if(i == n-1){ 
            cout << "[" << lo + (i*step) << ", " << hi << "] ";
            continue;
        }
        cout << "[" << lo + (i*step) << ", " << lo + ((i+1)*step) << "] ";
    }
    cout << endl << endl;

    cout << "Dumping Buckets" << endl << endl;

    for(int i = 0; i < n; i++){
        cout << "BUCKET " << i << endl;
        cout << buckets[i].size() << " elements:  ";
        for(int j = 0; j < (int) buckets[i].size(); j++) cout << buckets[i][j] << " ";
        cout << endl;
    }

}




int main(){

    vector<double> v;

    v.push_back(5.0);
    v.push_back(2.1);
    v.push_back(2.2);
    v.push_back(10.7);
    v.push_back(6.4);
    v.push_back(2.3);
    v.push_back(0.8);
    v.push_back(7.6);
    v.push_back(9.1);
    v.push_back(8.1);
    v.push_back(4.0);
    v.push_back(12.6);
    v.push_back(1.2);


    for(int i = 0; i < (int) v.size(); i++) cout << v[i] << " ";
    cout << endl;

    bucketSort(v, 0.8, 12.6);

    return 0;
}