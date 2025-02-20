#ifndef FOO_STRUCTURES_TOOLS_TYPELIST_H
#define FOO_STRUCTURES_TOOLS_TYPELIST_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;


template<typename genericType>
class TypeList {
public:
    genericType value_;
    TypeList* next_;

    TypeList();
    ~TypeList();

    void addvalue(genericType v);
    bool contains(genericType v);
    void dump();
    void getvalues(vector<genericType> vec);
};




template<typename genericType>
TypeList<genericType>::TypeList() { next_ = nullptr; }

template<typename genericType>
TypeList<genericType>::~TypeList() 
{
    if(this == nullptr) return;
    if (this->next_ != nullptr) delete this->next_;
    delete this;
}



template<typename genericType>
void TypeList<genericType>::addvalue(genericType v)
{
    if (this == nullptr) return;

    TypeList<genericType>* newvalue = new TypeList<genericType>();
    newvalue->value_ = v;
    newvalue->next_ = nullptr;

    TypeList<genericType>* aux = this->next_;
    this->next_ = newvalue;
    newvalue->next_ = aux;
}

template<typename genericType>
bool TypeList<genericType>::contains(genericType v) 
{
    if (this == nullptr) return false;
    if (this->value_ == v) return true;

    return this->next_->contains(v);
}

template<typename genericType>
void TypeList<genericType>::dump() {
    TypeList* aux = this;

    while (aux->next_ != nullptr) {
        aux = aux->next_;
        cout << aux->value_ << " ";
    }
    cout << endl;
}

template<typename genericType>
void TypeList<genericType>::getvalues(vector<genericType> vec) 
{
    TypeList<genericType>* aux = this;

    while (aux->next_ != nullptr) {
        aux = aux->next_;
        vec.push_back(aux->value_);
    }
    cout <<"tamanho do retorno " << vec.size() << endl;
}
#endif