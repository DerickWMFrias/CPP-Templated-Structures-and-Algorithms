#include <iostream>
#include <vector>


std::vector<int> countingSort(std::vector<int> v, int lo, int hi){

    std::vector<int> ret;
    int spam = hi - lo + 1, size = v.size();
    int count[spam], auxret[size];

    std::cout << spam << " " << size << std::endl;

    for(int i = 0; i < spam; i++) count[i] = 0;
    for(int i = 0; i < spam; i++) std::cout << count[i] << " ";
    std::cout << std::endl;

    for(int i = 0; i < size; i++) count[v[i]-lo]++;
    for(int i = 0; i < spam; i++) std::cout << count[i] << " ";
    std::cout << std::endl;

    for(int i = 1; i < spam; i++) count[i] += count[i-1];
    for(int i = 0; i < spam; i++) cout << count[i] << " ";
    std::cout << std::endl;


    std::cout << "AUXRET" << std::endl;
    for(int i = size-1; i >=0; i--){
        std::cout << v[i] << " " << count[v[i]-lo] << "       ";

        auxret[count[v[i]-lo]-1] = v[i];
        count[v[i]-lo]--;
        for(int i = 0; i < size; i++) std::cout << auxret[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "end" << std::endl;

    for(int i = 0; i < size; i++) ret.push_back(auxret[i]);

    return ret;
}


void bucketSort(std::vector<double> v, double lo, double hi){

    int size = v.size(); 
    double step = (hi-lo)/size;

    int n = size;
    while(step == 0.0){
        n = n/2;
        step = (hi-lo)/n;
    }

    std::vector<std::vector<double>> buckets;
    std::vector<double> ret;
    std::vector<double> dummy;
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

    int at = 0;
    for(int i = 0; i < n; i++){
        int vecmin;
        int vecmax;
        std::vector<double> atvec = ordination of buckets[i];
        
        for(int j = 0; j < (int) atvec.size(); i++){
            v[at] = atvec[j];
            at++;
        }
    }

    //Ordenaria os buckets
    std::cout << "Statistics" << std::endl;
    std::cout << "Total of elements: " << size << std::endl;
    std::cout << "Lo = " << lo << "    Hi = " << hi << std::endl;
    std::cout << "Number of Buckets: " << n << std::endl;
    std::cout << "Step size: " << step << std::endl;
    
    std::cout << std::endl;
    std::cout << "Showing Intervals" << std::endl;

    for(int i = 0; i < n; i++){
        if(i == n-1){ 
            std::cout << "[" << lo + (i*step) << ", " << hi << "] ";
            continue;
        }
        std::cout << "[" << lo + (i*step) << ", " << lo + ((i+1)*step) << "] ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Dumping Buckets" << std::endl << std::endl;

    for(int i = 0; i < n; i++){
        std::cout << "BUCKET " << i << std::endl;
        std::cout << buckets[i].size() << " elements:  ";
        for(int j = 0; j < (int) buckets[i].size(); j++) std::cout << buckets[i][j] << " ";
        std::cout << std::endl;
    }

}




void radixSort(std::vector<int> v, int maxorder, int base){
    int order = 0, mod = 0, tentimes = 10;
    std::vector<std::vector<int>> organizer;
    std::vector<int> dummy, auxv;

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

    int at = 0;
    for(int i = 0; i < (int) organizer.size(); i++){
        for(int j = 0; j < (int) organizer[i].size(); j++){
            v[at] = organizer[i][j];
            at++;
        }
    }
}











