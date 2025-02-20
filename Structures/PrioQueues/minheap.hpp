#ifndef FOO_STRUCTURES_PRIOQUEUES_MINHEAP_H
#define FOO_STRUCTURES_PRIOQUEUES_MINHEAP_H


#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;



template<typename genericType>
class MinHeap {
private:
    vector<genericType> hp_;

    void            heapifyup();
    void            heapifydown();
    bool            isleaf(int at);
    genericType     min(genericType a, genericType b);
public:
    MinHeap();
    ~MinHeap();
    void            clear();
    void            dump();
    genericType     getmin();
    bool            isempty();
    void            insert(genericType p);
    genericType     peekmin();
    int             size();
    void showsons();
};





template<typename genericType>
MinHeap<genericType>::MinHeap() {}

template<typename genericType>
MinHeap<genericType>::~MinHeap() {}





template<typename genericType>
void MinHeap<genericType>::clear() { hp_.clear(); }

template<typename genericType>
void MinHeap<genericType>::dump()
{
    for(int i = 0; i < (int) hp_.size(); i++){ cout << " " << hp_[i]; }
    cout << endl;
}

template<typename genericType>
genericType MinHeap<genericType>::getmin() 
{
    if (this->isempty()) 
    {
        genericType corrupted;
        return corrupted;
    }

    genericType ret = hp_.front();
    genericType aux = hp_.back();

    hp_[0] = aux;
    hp_.pop_back();

    heapifydown();

    return ret;
}


template<typename genericType>
void MinHeap<genericType>::heapifydown() 
{
    bool stop = false;
    int at = 0;

    while (!stop) 
    {
        int son2 = 2 * (at+1);
        int son1 = son2-1;

        if (isleaf(at)) 
        {
            stop = true;
            continue;
        }
        if (hp_[at] <= hp_[son1]) 
        {
            if(son2 == this->size()){
                stop = true;
                continue;
            }
            if(hp_[at] <= hp_[son2]){
                stop = true;
                continue;
            }
        }

        genericType m = min(hp_[son1], hp_[son2]);
        if (m == hp_[son1]) 
        {
            genericType aux = hp_[son1];
            hp_[son1] = hp_[at];
            hp_[at] = aux;
            at = son1;
            continue;
        }

        genericType aux = hp_[son2];
        hp_[son2] = hp_[at];
        hp_[at] = aux;
        at = son2;
    }
}

template<typename genericType>
void MinHeap<genericType>::heapifyup() 
{
    int at = this->size() - 1;
    bool stop = false;

    while (!stop) 
    {
        int father = (at-1) / 2;
        //cout << "Comparing " << hp[father] << "  " << hp[at];
        if (hp_[father] <= hp_[at]) 
        {   
            //cout  << endl;
            stop = true;
            continue;
        }
        if (father == 0 && at == 0) 
        {
            //cout  << endl;
            stop = true;
            continue;
        }
        //cout << "  SWAPING" << endl;
        genericType aux = hp_[father];
        hp_[father] = hp_[at];
        hp_[at] = aux;
        at = father;
    }
}



template<typename genericType>
void MinHeap<genericType>::insert(genericType p) 
{
    hp_.push_back(p);
    heapifyup();
}

template<typename genericType>
bool MinHeap<genericType>::isempty() { return (this->size() == 0) ? true : false; }

template<typename genericType>
bool MinHeap<genericType>::isleaf(int at) 
{
    if (at == 0) 
    {
        if (this->size() == 1) return true;
        return false;
    }

    int last = this->size() - 1;
    return (2 * at > last) ? true : false;
}

template<typename genericType>
genericType MinHeap<genericType>::min(genericType a, genericType b) { return (a < b) ? a : b; }

template<typename genericType>
genericType MinHeap<genericType>::peekmin() { return hp_[0]; }

template<typename genericType>
int MinHeap<genericType>::size() { return hp_.size(); }


template<typename genericType>
void MinHeap<genericType>::showsons() { 

    int sz = this->size();

    for(int i = 0; i < sz; i++){
        if(2*(i)+1 < sz){
            cout << "Node: " << hp_[i] << "   LSON: " << hp_[2*(i)+1];;
            if(2*(i)+2  < sz) cout << "   RSON: " << hp_[2*(i)+2] << endl;
        }
    }
}

#endif