#ifndef FOO_STRUCTURES_TREES_BSTREE_H
#define FOO_STRUCTURES_TREES_BSTREE_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;


template<typename key>
class BsNode {
private:
    key* k_;
    BsNode* l_;
    BsNode* r_;

public:
    BsNode(key nk);
    ~BsNode();
    bool    corruptedcall();
    bool    corruptedcall(key akey);
    bool    isleaf();
    int     privheight();
    int     privlevel(key akey);
    int     privrank(key akey);
    key     privselect(int rk);
    
public:
    void    add(key newkey);
    key     ceiling(key akey);
    bool    contains(key akey);
    void    del(key akey);
    void    delat(int at);
    void    delmax();
    void    deletemin();
    void    dump();
    key     floor(key akey);
    int     height();
    bool    isempty();
    int     level(key akey);
    key     max();
    key     min();
    key     select(int rk);
    int     size();
    int     size(key low, key high);
    int     rank(key akey);
};

template<typename key>
class BsTree {
private:
    BsNode<key>* root_;
public:
    BsTree(key nk);
    ~BsTree();

    void    add(key newkey);
    key     ceiling(key akey);
    bool    contains(key akey);
    void    del(key akey);
    void    delat(int at);
    void    delmax();
    void    delmin();
    void    dump();
    key     floor(key akey);
    int     height();
    bool    isempty();
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










template<typename key>
BsNode<key>::BsNode(key nk) 
{
    k_ = new key(nk);
    l_ = nullptr;
    r_ = nullptr;
}

template<typename key>
BsNode<key>::~BsNode() 
{
    if (this == nullptr) return;

    delete this->l_;
    delete this->r_;
    delete this->k_;
}






template<typename key>
void BsNode<key>::add(key newkey) 
{
    if (this->k_ == nullptr) 
    {
        this->k_ = new key(newkey);
        return;
    }

    //cout <<"Adding: " << newkey << "   Actual: " << *(this->k) << endl;


    if (*(this->k_) < newkey) 
    {
        if (this->r_ != nullptr)
        { 
            this->r_->add(newkey);
            return;
        }
        //bsnode<key>* newcel = new bsnode(newkey);
        this->r_ = new BsNode<key>(newkey);
        return;
    }

    if (this->l_ != nullptr)
    { 
        this->l_->add(newkey);
        return;
    }

    //bsnode<key>* newcel = new bsnode(newkey);
    this->l_ = new BsNode<key>(newkey);
}


template<typename key>
key BsNode<key>::ceiling(key akey) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    key retceil;
    BsNode* aux = nullptr;

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


template<typename key>
bool BsNode<key>::contains(key akey) 
{
    if (this == nullptr) return false;

    if (*(this->k_) < akey) return this->r_->contains(akey);
    else if (*(this->k_) > akey) return this->l_->contains(akey);

    return true;
}

template<typename key>
bool BsNode<key>::corruptedcall() 
{
    if (this == nullptr) return true;
    if (this->isempty()) return true;

    return false;
}

template<typename key>
bool BsNode<key>::corruptedcall(key akey) 
{
    if (this == nullptr) return true;
    if (this->isempty()) return true;
    if (!this->contains(akey)) return true;

    return false;
}



template<typename key>
void BsNode<key>::del(key akey) 
{
    if (corruptedcall(akey)) return;

    BsNode* aux = this;

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
        BsNode* todel = aux->l_;
        aux->k_ = todel->k_;
        aux->l_ = nullptr;

        delete todel;
        return;
    }

    else if (aux->l_ == nullptr) 
    {
        BsNode* todel = aux->r_;
        aux->k_ = todel->k_;
        aux->r_ = nullptr;

        delete todel;
        return;
    }

    BsNode* p = aux;
    BsNode* todel = aux->l_;

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

template<typename key>
void BsNode<key>::delat(int at) 
{
    if (corruptedcall()) return;

    BsNode* todel = nullptr;
    BsNode* aux = nullptr;
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

template<typename key>
void BsNode<key>::delmax() 
{
    if (corruptedcall()) return;

    if (this->l_ == nullptr && this->r_ == nullptr) 
    {
        delete this->k_;
        return;
    }
    if (this->l_ != nullptr && this->r_ == nullptr) 
    {
        BsNode* todel = this->l_;
        this->k_ = todel->k_;

        this->l_ = todel->l_;
        this->r_ = todel->r_;

        todel->r_ = nullptr;
        todel->l_ = nullptr;

        delete todel;
        return;
    }

    BsNode* p = this;
    BsNode* todel = this->r_;
    while (todel->r_ != nullptr) 
    {
        p = todel;
        todel = todel->r_;
    }

    p->r_ = todel->l_;
    todel->l_ = nullptr;
    delete todel;
}


template<typename key>
void BsNode<key>::deletemin() 
{
    if (corruptedcall()) return;

    if (this->l_ == nullptr && this->r_ == nullptr) 
    {
        delete this->k_;
        return;
    }

    if (this->l_ == nullptr && this->r_ != nullptr) 
    {
        BsNode* todel = this->r_;
        this->k_ = todel->k_;

        this->l_ = todel->l_;
        this->r_ = todel->r_;

        todel->r_ = nullptr;
        todel->l_ = nullptr;

        delete todel;
        return;
    }

    BsNode* p = this;
    BsNode* todel = this->l_;
    while (todel->l_ != nullptr) 
    {
        p = todel;
        todel = todel->l_;
    }

    p->l_ = todel->r_;
    todel->r_ = nullptr;
    delete todel;
}




template<typename key>
void BsNode<key>::dump() 
{
    if (corruptedcall()) return;

    this->l_->dump();
    cout << " " << *(this->k_);
    this->r_->dump();
}

template<typename key>
key BsNode<key>::floor(key akey) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    key retfloor;
    BsNode* aux = nullptr;

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

template<typename key>
int BsNode<key>::height() 
{
    if (this == nullptr) return -1;
    if (this->isempty()) return -1;

    return this->privheight();
}


template<typename key>
bool BsNode<key>::isempty() 
{
    if (this == nullptr) return true;
    if (this->k_ == nullptr) return true;

    return false;
}

template<typename key>
bool BsNode<key>::isleaf() { return(this->l_ == nullptr && this->r_ == nullptr) ? true : false; }



template<typename key>
int BsNode<key>::level(key akey) 
{
    if (this->isempty()) return -1;
    if (!this->contains(akey)) return -1;

    return privlevel(akey);
}


template<typename key>
key BsNode<key>::max() 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    BsNode* ret = this;
    while (ret->r_ != nullptr) ret = ret->r_;

    return *(ret->k_);
}

template<typename key>
key BsNode<key>::min() 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    BsNode* ret = this;
    while (ret->l_ != nullptr) ret = ret->l_;

    return *(ret->k_);
}



template<typename key>
int BsNode<key>::privheight() 
{
    int tol = 0, tor = 0;
    if(this == nullptr) return 0;
    /*if (this->l != nullptr)*/ tol = 1 + this->l_->privheight();
    /*if (this->r != nullptr)*/ tor = 1 + this->r_->privheight();

    if (tol > tor) return tol;
    return tor;
}

template<typename key>
int BsNode<key>::privlevel(key akey) 
{
    if (*(this->k_) < akey) return 1 + this->r_->privlevel(akey);
    if (*(this->k_) > akey) return 1 + this->l_->privlevel(akey);

    return 0;
}

template<typename key>
int BsNode<key>::privrank(key akey) 
{
    if (*(this->k_) < akey) return this->l_->size() + 1 + this->r_->privrank(akey);
    if (*(this->k_) > akey) return this->l_->privrank(akey);
    return this->l_->size();
}

template<typename key>
key BsNode<key>::privselect(int at) 
{
    BsNode* aux = nullptr; 
    BsNode* auxfather = nullptr;
    BsNode*  ret = nullptr;
    aux = this;
    int atnow = 0;
    int lastdiff = 0;

    //cout <<  "SEARCHING FOR " << at << " ";

    while (aux != nullptr) 
    {
        if(auxfather == nullptr)
        {
            int rK = aux->rank(*(aux->k_));
            atnow += rK;
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

template<typename key>
int BsNode<key>::rank(key akey) 
{
    if (this == nullptr) return 0;
    if (this->contains(akey) == false) return 0;

    return this->privrank(akey);
}



template<typename key>
key BsNode<key>::select(int rk) 
{
    if (corruptedcall()) 
    {
        key corruptedkey;
        return corruptedkey;
    }

    return this->privselect(rk);
}

template<typename key>
int BsNode<key>::size() 
{
    if (this == nullptr) return 0;
    if (this->k_ == nullptr) return 0;

    return 1 + this->l_->size() + this->r_->size();
}

template<typename key>
int BsNode<key>::size(key low, key high) 
{
    if (this == nullptr) return 0;
    if (this->k_ == nullptr) return 0;
    if (*(this->k_) < low) return this->r_->size(low, high);
    if (*(this->k_) > high) return this->l_->size(low, high);

    return 1 + this->l_->size(low, high) + this->r_->size(low, high);
}







/*::START=bstree*/
template<typename key>
BsTree<key>::BsTree(key nk) { root_ = new BsNode<key>(nk); }

template<typename key>
BsTree<key>::~BsTree() { delete this->root_; }

template<typename key>
void BsTree<key>::add(key newkey) { root_->add(newkey); }

template<typename key>
key BsTree<key>::ceiling(key akey) { return root_->ceiling(akey); }

template<typename key>
bool BsTree<key>::contains(key akey) { return root_->contains(akey); }

template<typename key>
void BsTree<key>::del(key akey) { root_->del(akey); }

template<typename key>
void BsTree<key>::delat(int at) { root_->delat(at); }

template<typename key>
void BsTree<key>::delmax() { root_->delmax(); }

template<typename key>
void BsTree<key>::delmin() { root_->delmin(); }

template<typename key>
void BsTree<key>::dump() { root_->dump(); }

template<typename key>
key BsTree<key>::floor(key akey) { return root_->floor(akey); }

template<typename key>
int BsTree<key>::height() { return root_->height(); }

template<typename key>
bool BsTree<key>::isempty() 
{
    if (this == nullptr) return true;
    return root_->isempty();
}

template<typename key>
int BsTree<key>::level(key akey) { return root_->level(akey); }

template<typename key>
key BsTree<key>::max() { return root_->max(); }

template<typename key>
key BsTree<key>::min() { return root_->min(); }

template<typename key>
int BsTree<key>::rank(key akey) { return root_->rank(akey); }

template<typename key>
key BsTree<key>::select(int rk) { return root_->select(rk); }

template<typename key>
int BsTree<key>::size() { return root_->size(); }

template<typename key>
int BsTree<key>::size(key low, key high) { return root_->size(low, high); }

#endif