#include<iostream>
#include<array>
#include "ordenation.h"
using namespace std;


template<typename genericArg>
void merge(int a, int b, int c, genericArg arr[]);






template<typename genericArg>
void mergesort(int a, int b, genericArg arr[]){
    if(a < b){
        int c = (a+b)/2;
        mergesort <genericArg> (a,c, arr);
        mergesort <genericArg> (c+1, b, arr);
        merge <genericArg> (a, b, c, arr);
    }
}



template<typename genericArg>
void merge(int a, int b, int c, genericArg arr[]){
    int n1 = a;
    int n2 = c+1;
    int at = 0;
    genericArg* auxarray;

   // cout << "auxarray size: " << b-a+1 << endl;
    //cout << "a: " << a << "    b: " << b << endl; 
    auxarray = new genericArg[b-a+1]();

    while(n1 <= c && n2 <= b){
           // cout << "Comparing " << n1 << " to " << n2 << endl;
        if(arr[n1] >= arr[n2]){
            auxarray[at] = arr[n1];
          //  cout << "Putting at " << at << endl;
            n1++;
            at++;
        }
        else{
            auxarray[at] = arr[n2];
            //cout << "Putting at " << at << endl;
            n2++;
            at++;
        }

        if(n1 > c){
            while(n2<=b){
                auxarray[at] = arr[n2];
               // cout << "Putting at " << at << endl;
                n2++;
                at++;
            }
        }
        else if(n2 > b){
            while(n1<=c){
                auxarray[at] = arr[n1];
               // cout << "Putting at " << at << endl;
                n1++;
                at++;
            }
        }
    }

    for(int i = a; i <=b; i++) arr[i] = auxarray[i-a];
    delete [] auxarray;
}