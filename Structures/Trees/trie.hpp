#ifndef FOO_STRUCTURES_TREES_TRIE_H
#define FOO_STRUCTURES_TREES_TRIE_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

#include "C:\Users\steam\Desktop\EstudosGerais\Portfolio\Cpp\Libraries\dataStructures\Structures\tools\typelist.hpp"

template<typename genericType>
class TrieNode {
    private:
        char c_;
        bool marked_;
        TypeList<genericType>* values_;
        TrieNode<genericType>* l_;
        TrieNode<genericType>* m_;
        TrieNode<genericType>* r_;
    public:
        TrieNode(char cc);
        ~TrieNode();
        TrieNode<genericType>*  addtotrie(char c);
        void                    addvalue(genericType p);
        TrieNode<genericType>*  findend(string s);
        bool                    ismarked();
        void                    mark();
        TrieNode<genericType>*  searchletter(char c);
};


template<typename genericType>
class Trie {
private:
    TrieNode<genericType>* root_;
    int N_;
public:
    Trie();
    ~Trie();
    void    add(string s, genericType v);
    void    addvalue(string s, genericType v);
    bool    contains(string s);
    int     numberofwords();
    /* TO BE IMPLEMENTED
    vector<string> wordswithprefix(string prefix);
    vector<string> wordscontained();
    */
};







template<typename genericType>
TrieNode<genericType>::TrieNode(char cc) 
{
    l_ = nullptr;
    m_ = nullptr;
    r_ = nullptr;
    marked_ = false;
    c_ = cc;
    values_ = nullptr;
}

template<typename genericType>
TrieNode<genericType>::~TrieNode() 
{
    if (this == nullptr) return;
    delete this->l_;
    delete this->m_;
    delete this->r_;

    if (values_ != nullptr) delete values_;
    delete this;
}





template<typename genericType>
TrieNode<genericType>* TrieNode<genericType>::addtotrie(char c) {
    if (this->c_ < c) {
        if (this->r_ != nullptr) {
            return this->r_->addtotrie(c);
        }
        TrieNode<genericType>* newnode;
        newnode = new TrieNode<genericType>(c);
        this->r_ = newnode;
        return newnode;
    }
    if (this->c_ > c) {
        if (this->l_ != nullptr) {
            return this->l_->addtotrie(c);
        }
        TrieNode<genericType>* newnode;
        newnode = new TrieNode<genericType>(c);
        this->l_ = newnode;
        return newnode;
    }
    return this->m_->addtotrie(c);
}

template<typename genericType>
void TrieNode<genericType>::addvalue(genericType p) 
{
    if (this->values_ == nullptr)
    {
        this->values_ = new TypeList<genericType>(p);
        return;
    }
    this->values_->addvalue(p);
}

template<typename genericType>
TrieNode<genericType>* TrieNode<genericType>::findend(string s) 
{
    if (this == nullptr) return nullptr;
    TrieNode<genericType>* aux = this;
    int end = s.size();

    for (int at = 0; at != end && aux != nullptr; at++) { aux = aux->searchletter(s[at]); }

    return aux;
}

template<typename genericType>
bool TrieNode<genericType>::ismarked() { return (marked_) ? true : false; }

template<typename genericType>
void TrieNode<genericType>::mark() { marked_ = true; }

template<typename genericType>
TrieNode<genericType>* TrieNode<genericType>::searchletter(char c) 
{
    if (this == nullptr) return nullptr;

    if (this->c_ < c) return this->r_->searchletter(c);
    if (this->c_ > c) return this->l_->searchletter(c);

    return this;
}









/*::START=trie*/
template<typename genericType>
Trie<genericType>::Trie() {
    root_ = nullptr;
    N_ = 0;
}
template<typename genericType>
Trie<genericType>::~Trie() {
    if (this == nullptr) return;
    delete root_;
}




template<typename genericType>
void Trie<genericType>::add(string s, genericType v) 
{
    int end = s.size();
    TrieNode<genericType>* aux = root_;

    for (int at = 0; at != end; at++) 
    {
        if (root_ == nullptr) 
        {
            root_ = new TrieNode<genericType>(s.at(at));
            aux = root_;
            continue;
        }
        aux = aux->addtotrie(s.at(at));
    }


    if (aux->ismarked()) 
    {
        N_++;
        aux->mark();
    }


    aux->addvalue(v);
}

template<typename genericType>
void Trie<genericType>::addvalue(string s, genericType v) {
    TrieNode<genericType>* p = root_->findend(s);

    if (p == nullptr) return;
    p->addvalue(v);
}

template<typename genericType>
bool Trie<genericType>::contains(string s) 
{
    TrieNode<genericType>* p = root_->findend(s);
    if (p == nullptr) return false;
    return true;
}

template<typename genericType>
int Trie<genericType>::numberofwords() { return N_; }

/*TO BE IMPLEMENTED
vector<string> wordswithprefix(string prefix) {}
vector<string> wordscontained() {}
*/

#endif
