#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;



template<typename genericType>
class minheap {
private:
    vector<genericType> hp;

    void            heapifyup();
    void            heapifydown();
    bool            isleaf(int at);
    genericType     min(genericType a, genericType b);
public:
    minheap();
    ~minheap();
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
class maxheap {
private:
    vector<genericType> hp;

    void        heapifydown();
    void        heapifyup();
    bool        isleaf(int at);
    genericType max(genericType a, genericType b);
public:
    maxheap<genericType>();
    ~maxheap<genericType>();
void showsons();
    void        clear();
    void        dump();
    bool        isempty();
    void        insert(genericType p);
    genericType getmax();
    genericType peekmax();
    int         size();
};






template<typename genericType>
minheap<genericType>::minheap() {}

template<typename genericType>
minheap<genericType>::~minheap() {}





template<typename genericType>
void minheap<genericType>::clear() { hp.clear(); }

template<typename genericType>
void minheap<genericType>::dump()
{
    for(int i = 0; i < (int) hp.size(); i++){ cout << " " << hp[i]; }
    cout << endl;
}

template<typename genericType>
genericType minheap<genericType>::getmin() 
{
    if (this->isempty()) 
    {
        genericType corrupted;
        return corrupted;
    }

    genericType ret = hp.front();
    genericType aux = hp.back();

    hp[0] = aux;
    hp.pop_back();

    heapifydown();

    return ret;
}


template<typename genericType>
void minheap<genericType>::heapifydown() 
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
        if (hp[at] <= hp[son1]) 
        {
            if(son2 == this->size()){
                stop = true;
                continue;
            }
            if(hp[at] <= hp[son2]){
                stop = true;
                continue;
            }
        }

        genericType m = min(hp[son1], hp[son2]);
        if (m == hp[son1]) 
        {
            genericType aux = hp[son1];
            hp[son1] = hp[at];
            hp[at] = aux;
            at = son1;
            continue;
        }

        genericType aux = hp[son2];
        hp[son2] = hp[at];
        hp[at] = aux;
        at = son2;
    }
}

template<typename genericType>
void minheap<genericType>::heapifyup() 
{
    int at = this->size() - 1;
    bool stop = false;

    while (!stop) 
    {
        int father = (at-1) / 2;
        //cout << "Comparing " << hp[father] << "  " << hp[at];
        if (hp[father] <= hp[at]) 
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
        genericType aux = hp[father];
        hp[father] = hp[at];
        hp[at] = aux;
        at = father;
    }
}



template<typename genericType>
void minheap<genericType>::insert(genericType p) 
{
    hp.push_back(p);
    heapifyup();
}

template<typename genericType>
bool minheap<genericType>::isempty() { return (this->size() == 0) ? true : false; }

template<typename genericType>
bool minheap<genericType>::isleaf(int at) 
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
genericType minheap<genericType>::min(genericType a, genericType b) { return (a < b) ? a : b; }

template<typename genericType>
genericType minheap<genericType>::peekmin() { return hp[0]; }

template<typename genericType>
int minheap<genericType>::size() { return hp.size(); }











/*::START=maxheap*/
template<typename genericType>
maxheap<genericType>::maxheap() {}
template<typename genericType>
maxheap<genericType>::~maxheap() {}





template<typename genericType>
void maxheap<genericType>::clear() { hp.clear(); }

template<typename genericType>
void maxheap<genericType>::dump()
{
    for(int i = 0; i < (int) hp.size(); i++){ cout << " " << hp[i]; }
    cout << endl;
}

template<typename genericType>
void maxheap<genericType>::insert(genericType p) 
{
    hp.push_back(p);
    heapifyup();
}

template<typename genericType>
bool maxheap<genericType>::isempty() { return (this->size() == 0) ? true : false; }

template<typename genericType>
bool maxheap<genericType>::isleaf(int at) 
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
genericType maxheap<genericType>::getmax() 
{
    if (this->isempty()) 
    {
        genericType corrupted;
        return corrupted;
    }
    genericType ret = hp.front();
    genericType aux = hp.back();

    hp[0] = aux;
    hp.pop_back();

    heapifydown();

    return ret;
}

template<typename genericType>
void maxheap<genericType>::heapifydown() 
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
        if (hp[at] >= hp[son1] && hp[at] >= hp[son2]) 
        {
            //cout << "Stopped here " << hp[at] << " " << son1 << " " << son2 << endl; 
            stop = true;
            continue;
        }
        genericType m = max(hp[son1], hp[son2]);
        if (m == hp[son1]) 
        {
            genericType aux = hp[son1];
            hp[son1] = hp[at];
            hp[at] = aux;
            at = son1;
            continue;
        }
        genericType aux = hp[son2];
        hp[son2] = hp[at];
        hp[at] = aux;
        at = son2;
    }
}

template<typename genericType>
void maxheap<genericType>::heapifyup() 
{
    int at = this->size() - 1;
    bool stop = false;

    while (!stop) 
    {
        int father = (at-1) / 2;
        if (hp[father] >= hp[at]) 
        {
            stop = true;
            continue;
        }
        if (father == 0 && at == 0) 
        {
            stop = true;
            continue;
        }
        genericType aux = hp[father];
        hp[father] = hp[at];
        hp[at] = aux;
        at = father;
    }
}




template<typename genericType>
genericType maxheap<genericType>::max(genericType a, genericType b) { return (a > b) ? a : b; }

template<typename genericType>
genericType maxheap<genericType>::peekmax() { return hp[0]; }

template<typename genericType>
int maxheap<genericType>::size() { return hp.size(); }

template<typename genericType>
void maxheap<genericType>::showsons() { 

    int sz = this->size();

    for(int i = 0; i < sz; i++){
        if(2*(i)+1 < sz){
            cout << "Node: " << hp[i] << "   LSON: " << hp[2*(i)+1];;
            if(2*(i)+2  < sz) cout << "   RSON: " << hp[2*(i)+2] << endl;
        }
    }
}

template<typename genericType>
void minheap<genericType>::showsons() { 

    int sz = this->size();

    for(int i = 0; i < sz; i++){
        if(2*(i)+1 < sz){
            cout << "Node: " << hp[i] << "   LSON: " << hp[2*(i)+1];;
            if(2*(i)+2  < sz) cout << "   RSON: " << hp[2*(i)+2] << endl;
        }
    }
}