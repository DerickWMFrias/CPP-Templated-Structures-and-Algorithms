#ifndef FOO_STRUCTURES_SYMBOLTABLES_ARBTREEST_H
#define FOO_STRUCTURES_SYMBOLTABLES_ARBTREEST_H


#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

#include "C:\Users\steam\Desktop\EstudosGerais\Portfolio\Cpp\Libraries\dataStructures\Structures\LinkedLists\linkedlist.hpp"

template<typename key, typename value>
class ArbNodeST {
private:
    key* k_;
    LinkedList<value>* v_;
    ArbNodeST* l_;
    ArbNodeST* r_;

    bool            corruptedcall();
    bool            corruptedcall(key akey);
    bool            isleaf();
    vector<value>   privget(key akey);
    int             privheight();
    int             privlevel(key akey);
    int             privrank(key akey);
    key             privselect(int rk);

public:
    ArbNodeST(key nk, value nv);
    ~ArbNodeST();

    void    add(key newkey, value newvalue);
    key     ceiling(key akey);
    bool    contains(key akey);
    void    del(key akey);
    void    delat(int at);
    void    delmax();
    void    deletemin();
    void    dump();
    key     floor(key akey);
    vector<value> get(key akey);
    int     height();
    bool    isempty();
    int     level(key akey);
    key     max();
    key     min();
    int     rank(key akey);
    key     select(int rk);
    int     size();
    int     size(key low, key high);
};

template<typename key, typename value>
class ArbTreeST {
private:
    ArbNodeST<key, value>* root_;
public:
    ArbTreeST(key nk, value nv);
    ~ArbTreeST();
    void    add(key newkey, value newvalue);
    key     ceiling(key akey);
    bool    contains(key akey);
    void    del(key akey);
    void    delat(int at);
    void    delmin();
    void    delmax();
    void     dump();
    vector<value> getvalues(key akey);
    int     height();
    bool    isempty();
    key     floor(key akey);
    int     level(key akey);
    key     max();
    key     min();
    key     select(int rk);
    int     size();
    int     size(key low, key high);
    int     rank(key akey);
    //iterator
    /*All keys left to right
      All keys right to left
      All keys on a given height
    */
};







template<typename key, typename value>
ArbNodeST<key, value>::ArbNodeST(key nk, value nv)
{
    k_ = new key(nk);
    v_ = new LinkedList<value>();
    v_->add(nv);
    l_ = nullptr;
    r_ = nullptr;
}

template<typename key, typename value>
ArbNodeST<key, value>::~ArbNodeST()
{
    if (this == nullptr) return;

    delete this->l_;
    delete this->r_;
    delete this->k_;
    delete this->v_;
}


template<typename key, typename value>
void ArbNodeST<key, value>::add(key newkey, value newvalue) 
{
    if (this->k_ == nullptr) 
    {
        this->k_ = new key(newkey);
        if(this->v_ == nullptr) this->v_ = new LinkedList<value>();
        this->v_->add(newvalue);
        return;
    }


    if(*(this->k_) == newkey)
    {
        this->v_->add(newvalue);
        return;
    }

    if (*(this->k_) < newkey) 
    {
        if (this->r_ != nullptr)
        { 
            this->r_->add(newkey, newvalue);
            return;
        }
        //arbnodeST* newcel = new arbnodeST(newkey, newvalue);

        this->r_ = new ArbNodeST<key, value>(newkey, newvalue);
        return;
    }

    if (this->l_ != nullptr)
    { 
        this->l_->add(newkey, newvalue);
        return;
    }
    //arbnodeST* newcel = new arbnodeST(newkey, newvalue);
    this->l_ = new ArbNodeST<key, value>(newkey, newvalue);;
}


template<typename key, typename value>
key ArbNodeST<key, value>::ceiling(key akey) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    key retceil;
    ArbNodeST* aux = nullptr;

    aux = this;

    while (aux != nullptr) 
    {
        if (*(aux->k_) > akey) 
        {
            retceil = *(aux->k_);
            aux = aux->l_;
        }
        else aux = aux->r_;
    }

    return retceil;
}

template<typename key, typename value>
bool ArbNodeST<key, value>::contains(key akey) 
{
    if (this == nullptr) return false;

    if (*(this->k_) < akey) return this->r_->contains(akey);
    else if (*(this->k_) > akey) return this->l_->contains(akey);

    return true;
}


template<typename key, typename value>
bool ArbNodeST<key, value>::corruptedcall() 
{
    if (this == nullptr) return true;
    if (this->isempty()) return true;

    return false;
}

template<typename key, typename value>
bool ArbNodeST<key, value>::corruptedcall(key akey) 
{
    if (this == nullptr) return true;
    if (this->isempty()) return true;
    if (!this->contains(akey)) return true;

    return false;
}



template<typename key, typename value>
void ArbNodeST<key, value>::del(key akey) 
{
    if (corruptedcall(akey)) return;

    ArbNodeST* aux = this;

    while (aux->k_ != akey) 
    {
        if (aux->k_ < akey) aux = aux->r_;
        else aux = aux->l_;
    }

    if (aux->isleaf()) 
    {
        if (aux == this) delete aux->k_;
        else delete aux;
        return;
    }

    else if (aux->r_ == nullptr) 
    {
        ArbNodeST* todel = aux->l_;
        aux->k_ = todel->k_;
        aux->l_ = nullptr;

        delete todel;
        return;
    }

    else if (aux->l_ == nullptr) 
    {
        ArbNodeST* todel = aux->r_;
        aux->k_ = todel->k_;
        aux->r_ = nullptr;

        delete todel;
        return;
    }

    ArbNodeST* p = aux;
    ArbNodeST* todel = aux->l_;

    while (todel->r_ != nullptr) 
    {
        p = todel;
        todel = todel->r_;
    }

    aux->k_ = todel->k_;

    if (todel == p->l_) 
    {
        aux->l_ = todel->r_;
        delete todel;
        return;
    }

    aux->l_ = todel->l_;
    delete todel;
}

template<typename key, typename value>
void ArbNodeST<key, value>::delat(int at) 
{
    if (corruptedcall()) return;

    ArbNodeST* todel = nullptr;
    ArbNodeST* aux = nullptr;
    aux = this;

    while (aux != nullptr) 
    {
        int rk = this->rank() + 1;
        at += rk;

        if (at > rk) aux = aux->l_;
        else if (at < rk) aux = aux->r_;
        else 
        {
            todel = aux;
            aux = nullptr;
        }
    }

    if (todel != nullptr) todel->del(todel->k_);
}

template<typename key, typename value>
void ArbNodeST<key, value>::delmax() 
{
    if (corruptedcall()) return;

    if (this->l_ == nullptr && this->r_ == nullptr) 
    {
        delete this->k_;
        return;
    }
    if (this->l_ != nullptr && this->r_ == nullptr) 
    {
        ArbNodeST* todel = this->l_;
        this->k_ = todel->k_;

        this->l_ = todel->l_;
        this->r_ = todel->r_;

        todel->r_ = nullptr;
        todel->l_ = nullptr;

        delete todel;
        return;
    }

    ArbNodeST* p = this;
    ArbNodeST* todel = this->r_;
    while (todel->r_ != nullptr) 
    {
        p = todel;
        todel = todel->r_;
    }

    p->r_ = todel->l_;
    todel->l_ = nullptr;
    delete todel;
}

template<typename key, typename value>
void ArbNodeST<key, value>::deletemin() 
{
    if (corruptedcall()) return;

    if (this->l_ == nullptr && this->r_ == nullptr) 
    {
        delete this->k_;
        return;
    }

    if (this->l_ == nullptr && this->r_ != nullptr) 
    {
        ArbNodeST* todel = this->r_;
        this->k_ = todel->k_;

        this->l_ = todel->l_;
        this->r_ = todel->r_;

        todel->r_ = nullptr;
        todel->l_ = nullptr;

        delete todel;
        return;
    }

    ArbNodeST* p = this;
    ArbNodeST* todel = this->l_;
    while (todel->l_ != nullptr) 
    {
        p = todel;
        todel = todel->l_;
    }

    p->l_ = todel->r_;
    todel->r_ = nullptr;
    delete todel;
}

template<typename key, typename value>
void ArbNodeST<key, value>::dump() 
{
    if (corruptedcall()) return;

    this->l_->dump();
    cout << "Key: " << *k_ << "     Values: "; 
    this->v_->dump();
    cout << endl;
    this->r_->dump();
}


template<typename key, typename value>
key ArbNodeST<key, value>::floor(key akey) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    key retfloor;
    ArbNodeST* aux = nullptr;

    aux = this;

    while (aux != nullptr) 
    {
        if (*(aux->k_) < akey) 
        {
            retfloor = *(aux->k_);
            aux = aux->r_;
        }
        else aux = aux->l_;
    }

    return retfloor;
}

template<typename key, typename value>
vector<value> ArbNodeST<key, value>::get(key akey)
{
    if (corruptedcall(akey))
    {
        vector<value> corruptedValue;
        return corruptedValue;
    }
    return privget(akey);
    //privget(akey, vec);
}

template<typename key, typename value>
int ArbNodeST<key, value>::height() 
{
    if (this == nullptr) return -1;
    if (this->isempty()) return -1;

    return this->privheight();
}


template<typename key, typename value>
bool ArbNodeST<key, value>::isempty() 
{
    if (this == nullptr) return true;
    if (this->k_ == nullptr) return true;

    return false;
}

template<typename key, typename value>
bool ArbNodeST<key, value>::isleaf() { return(this->l_ == nullptr && this->r_ == nullptr) ? true : false; }


template<typename key, typename value>
int ArbNodeST<key, value>::level(key akey) 
{
    if (this->isempty()) return -1;
    if (!this->contains(akey)) return -1;

    return privlevel(akey);
}


template<typename key, typename value>
key ArbNodeST<key, value>::max() 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    ArbNodeST* ret = this;
    while (ret->r_ != nullptr) ret = ret->r_;

    return *(ret->k_);
}


template<typename key, typename value>
key ArbNodeST<key, value>::min() 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    ArbNodeST* ret = this;
    while (ret->l_ != nullptr) ret = ret->l_;

    return *(ret->k_);
}

template<typename key, typename value>
vector<value> ArbNodeST<key, value>::privget(key akey) 
{
    if(this == nullptr)
    {
        vector<value> corruptedValue;
        return corruptedValue;
        //return;
    }

    if (*(this->k_) < akey) return this->r_->privget(akey);
    if (*(this->k_) > akey) return this->l_->privget(akey);


    //cout << "IN arbnodeST::PRIVGET" << endl;
    return this->v_->getvalues();
}


template<typename key, typename value>
int ArbNodeST<key, value>::privheight() 
{
    int tol = 0, tor = 0;
    if(this == nullptr) return 0;
    //if (this->l != nullptr) tol = 1 + this->l->privheight();
    //if (this->r != nullptr) tor = 1 + this->r->privheight();
    tol = 1 + this->l_->privheight();
    tor = 1 + this->r_->privheight();

    if (tol > tor) return tol;
    return tor;
}

template<typename key, typename value>
int ArbNodeST<key, value>::privlevel(key akey) 
{
    if (*(this->k_) < akey) return 1 + this->r_->privlevel(akey);
    if (*(this->k_) > akey) return 1 + this->l_->privlevel(akey);

    return 0;
}

template<typename key, typename value>
int ArbNodeST<key, value>::privrank(key akey) 
{
    if (*(this->k_) < akey) return this->l_->size() + 1 + this->r_->privrank(akey);
    if (*(this->k_) > akey) return this->l_->privrank(akey);
    return this->l->size();
}

template<typename key, typename value>
key ArbNodeST<key, value>::privselect(int at) 
{
    ArbNodeST<key, value>* aux = nullptr; 
    ArbNodeST<key, value>* auxfather = nullptr;
    ArbNodeST<key, value>*  ret = nullptr;
    aux = this;
    int atnow = 0;
    int lastdiff = 0;

    //cout <<  "SEARCHING FOR " << at << " ";

    while (aux != nullptr) 
    {
        if(auxfather == nullptr)
        {
            int rk = aux->rank(*(aux->k_));
            atnow += rk;
        }
        else if(aux == auxfather->l_)
        {
            int ataux = atnow;
            atnow = lastdiff + aux->rank(*(aux->k_));
            if(lastdiff !=0) lastdiff = ataux - atnow;
        }
        else
        {
            lastdiff = atnow + 1;
            atnow += (aux->rank(*(aux->k_)) + 1);
        }

        //cout << "ATNOW = " << atnow << " " << "LASTDIFF = " << lastdiff << "   " << endl;

        if (atnow + 1 > at)
        { 
        //    cout << "going left" << endl;
            auxfather = aux;
            aux = aux->l_;
        }
        else if (atnow + 1 < at)
        { 
        //    cout << "going right" << endl;
            auxfather = aux;
            aux = aux->r_;
        }
        else 
        {
            ret = aux;
            aux = nullptr;
        }
    }

    if(ret == nullptr) return -1;
    return *(ret->k_);
}

template<typename key, typename value>
int ArbNodeST<key, value>::rank(key akey) 
{
    if (this == nullptr) return 0;
    if (this->contains(akey) == false) return 0;

    return this->privrank(akey);
}

template<typename key, typename value>
key ArbNodeST<key, value>::select(int rk) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    return this->privselect(rk);
}

template<typename key, typename value>
int ArbNodeST<key, value>::size() 
{
    if (this == nullptr) return 0;
    if (this->k_ == nullptr) return 0;

    return 1 + this->l_->size() + this->r_->size();
}

template<typename key, typename value>
int ArbNodeST<key, value>::size(key low, key high) 
{
    if (this == nullptr) return 0;
    if (this->k_ == nullptr) return 0;
    if (*(this->k_) < low) return this->r_->size(low, high);
    if (*(this->k_) > high) return this->l_->size(low, high);

    return 1 + this->l_->size(low, high) + this->r_->size(low, high);
}

















/*::START=arbtreeST*/
template<typename key, typename value>
ArbTreeST<key, value>::ArbTreeST(key nk, value nv) { root_ = new ArbNodeST<key, value>(nk, nv); }

template<typename key, typename value>
ArbTreeST<key, value>::~ArbTreeST() { delete this->root_; }

template<typename key, typename value>
void ArbTreeST<key, value>::add(key newkey, value newvalue) { root_->add(newkey, newvalue); }

template<typename key, typename value>
key ArbTreeST<key, value>::ceiling(key akey) { return root_->ceiling(akey); }

template<typename key, typename value>
bool ArbTreeST<key, value>::contains(key akey) { return root_->contains(akey); }

template<typename key, typename value>
void ArbTreeST<key, value>::del(key akey) { root_->del(akey); }

template<typename key, typename value>
void ArbTreeST<key, value>::delat(int at) { root_->delat(at); }

template<typename key, typename value>
void ArbTreeST<key, value>::delmax() { root_->delmax(); }

template<typename key, typename value>
void ArbTreeST<key, value>::delmin() { root_->delmin(); }

template<typename key, typename value>
void ArbTreeST<key, value>::dump() { root_->dump(); }

template<typename key, typename value>
key ArbTreeST<key, value>::floor(key akey) { return root_->floor(akey); }

template<typename key, typename value>
vector<value> ArbTreeST<key, value>::getvalues(key akey) { return root_->get(akey); }

template<typename key, typename value>
int ArbTreeST<key, value>::height() { return root_->height(); }

template<typename key, typename value>
bool ArbTreeST<key, value>::isempty() 
{
    if (this == nullptr) return true;
    return root_->isempty();
}

template<typename key, typename value>
int ArbTreeST<key, value>::level(key akey) { return root_->level(akey); }

template<typename key, typename value>
key ArbTreeST<key, value>::max() { return root_->max(); }

template<typename key, typename value>
key ArbTreeST<key, value>::min() { return root_->min(); }

template<typename key, typename value>
int ArbTreeST<key, value>::rank(key akey) { return root_->rank(akey); }

template<typename key, typename value>
key ArbTreeST<key, value>::select(int rk) { return root_->select(rk); }

template<typename key, typename value>
int ArbTreeST<key, value>::size() { return root_->size(); }

template<typename key, typename value>
int ArbTreeST<key, value>::size(key low, key high) { return root_->size(low, high); }


#endif