#include<iostream>
#include<vector>

#include "linearordenation.h"


void buckettest();
void countingtest();
void radixtest();
void printvector(std::vector<int> v);
void printvector(std::vector<double> v);



int main(){
    buckettest();
    countingtest();
    radixtest();
    return 0;
}



void buckettest(){
    std::vector<double> v;

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


    printvector(v);
    bucketSort(v, 0.8, 12.6);
    printvector(v);
}

void countingtest(){
    std::vector<int> v, ret;

    v.push_back(7);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-2);
    
    printvector(v);
    ret = countingSort(v, -2, 7);
    printvector(ret);
}

void radixtest(){
    int aux = 350;
    std::vector<int> v;

    for(int i = 0; i < 35; i++){
        v.push_back(aux);
        aux = aux-10;
    }
    
    printvector(v);
    radixSort(v, 3, 10);
    printvector(v);
}


void printvector(std::vector<int> v){
    for(int i = 0; i < (int) v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;
}

void printvector(std::vector<double> v){
    for(int i = 0; i < (int) v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;
}
