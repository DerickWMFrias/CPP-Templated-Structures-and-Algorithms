#include <iostream>
#include "ordenationtests.h"
#include "structures.h"

template<typename genericArg>
void testmergesort(genericArg v[], genericArg res[]);


int main(){

    idint v[6];
    idint res[6];

    v[0].seti(40);
    v[0].setid(1);
    v[1].seti(70);
    v[1].setid(2);
    v[2].seti(10);
    v[2].setid(3);
    v[3].seti(40);
    v[3].setid(4);
    v[4].seti(70);
    v[4].setid(5);
    v[5].seti(10);
    v[5].setid(6);

//cout << "Mark0" << endl;
    res[0].seti(10);
    res[0].setid(3);
    res[1].seti(10);
    res[1].setid(6);
    res[2].seti(40);
    res[2].setid(1);
    res[3].seti(40);
    res[3].setid(4);
    res[4].seti(70);
    res[4].setid(2);
    res[5].seti(70);
    res[5].setid(5);

//    cout << "Mark1" << endl;
    testmergesort<idint>(v, res, 6);

    return 0;
}







template<typename genericArg>
void testmergesort(genericArg v[], genericArg res[], int size){

    bool b1 = true;
    bool b2 = true;
//cout << "Mark2" << endl;
    mergesort <genericArg> (0, size-1, v);

//cout << "Mark3" << endl;


    for(int i = 0; i < size; i++){
        if(!(v[i] == res[i])){
            b1 = false;
        }
    }

 //cout << "Mark4" << endl;

    int j = 0;
    for(int i = 0; i < size-1; i++){
        j = i+1;

        if(v[i] == res[j]){
            if((v[i].getid() > res[j].getid())){
                b2 = false;
            }
        }
    }
//cout << "Mark5" << endl;
    cout << "MergeSort test results:" << endl;
    if(b2) cout << "STABLE: TRUE" << endl;
    else cout << "STABLE: FALSE" << endl;
    if(b1) cout << "ORDERED: YES" << endl;
    else cout << "ORDERED: NO" << endl;

    for(int i = 0; i < size; i++){
        cout << v[i].geti() << " ";
    }
  //  cout << "Mark6" << endl;
    cout << endl;
}