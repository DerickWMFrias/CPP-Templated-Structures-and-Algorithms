#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

template<typename key>
class bnode {
    private:
        key* k; /*Vetor de chaves*/
        int ksz; /*Número de chaves contidas*/
        int t; /*Parâmetro B; Em geral B=t -> Nós de 2t-1 chaves*/
        int adjfactor; /*Numero de adjacentes contidos*/
        int adjsz; /*Tamanho atual de adjList*/
        bnode** adjlist;

        void addat(key newkey, int at);
        bool fullkeys();
        void resizekeys();
        bool maxsizenode();
        bool fulladj();
        void resizeadj();
    public:
        bnode(key nk, int t);
        ~bnode();
        void add(key newkey);
}; 

template<typename key>
bnode<key>::bnode(key nk, int nt){
    adjsz = 4;
    k = new key(adjsz-1);
    k[0] = k;
    ksz = 1;
    t = nt;
    adjfactor = 0;
    adjlist = new bnode*[adjsz];
}

template<typename key>
bnode<key>::~bnode(){
    for(int i = 0; i < adjsz; i++) adjlist[i];

    delete k;
}

template<typename key>
void bnode<key>::add(key newkey){
    if (this->k == nullptr) 
    {
        this->k = new key(newkey);
        return;
    }

    //cout <<"Adding: " << newkey << "   Actual: " << *(this->k) << endl;

    if(!this->isleaf()){
        int at = 0;
        bool stop = false;

        for(at = 0; !stop; at++){
            if(at == ksz){ 
                stop = true;
                continue;
            }
            if(*(this->k[at]) < newkey){
                stop = true;
                continue;
            }
        }

        this->adjlist[at]->add(newkey);
        return;
    }

    int at = 0;
    bool stop = false;

    for(at = 0; !stop; at++){
        if(at == ksz){ 
            stop = true;
            continue;
        }
        if(*(this->k[at]) < newkey){
            stop = true;
            continue;
        }
    }

    this->addat(newkey, at);
}

template<typename key>
void bnode<key>::addat(key newkey, int at){
    if(this->fullkeys()){ 
        this->resizekeys();
        this->resizeadj();
    }
    for(int aux = ksz-1; aux >=at; aux--){
        this->k[aux+1] = this->k[aux];
    } 
    this->k[at] = newkey;
}




template<typename key>
bool bnode<key>::fullkeys(){
    return(ksz == adjsz-1)? true : false;
}

template<typename key>
void bnode<key>::resizekeys(){
    int aux = adjsz*2;


    key *auxk = new key[aux];
    for(int i = 0; i < aux/2; i++){ 
        auxk[i] = k[i];
        k[i] = nullptr;
    }

    delete k;
    auxk = k;
}

template<typename key>
bool bnode<key>::maxsizenode(){
    return(ksz == t)? true : false;
}

template<typename key>
bool bnode<key>::fulladj(){
    return(adjfactor == adjsz)? true : false;
}

template<typename key>
void bnode<key>::resizeadj(){
    adjsz = adjsz*2;


    bnode** auxadj = new key[adjsz];
    for(int i = 0; i < adjsz/2; i++){ 
        auxadj[i] = adjlist[i];
        adjlist[i] = nullptr;
    }

    delete adjlist;
    adjlist = auxadj;   
}