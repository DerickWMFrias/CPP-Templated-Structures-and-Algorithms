#ifndef FOO_STRUCTURES_TOOLS_LISTITEM_H
#define FOO_STRUCTURES_TOOLS_LISTITEM_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;



template<typename genericArg>
class ListItem {
    private:
        genericArg* key_;
        ListItem*   next_;
        ListItem*   prev_;
        void        destroy(ListItem<genericArg>* obj);
    public:
        ListItem();
        ~ListItem();
        void                add(genericArg nk);
        int                 count();
        void                dump();
        bool                isempty();
        genericArg          fifoget();
        genericArg          fifotop();
        vector<genericArg>  getvalues();
        genericArg          lifoget();
        genericArg          lifotop();
        //void clear();
};






template<typename genericArg>
ListItem<genericArg>::ListItem() 
{
    this->key_ = new genericArg();
    this->next_ = this;
    this->prev_ = this;
}

template<typename genericArg>
ListItem<genericArg>::~ListItem() {
    if (this == nullptr) return;
    if(this->next_ ==nullptr && this->prev_ == nullptr){
        delete this->key_;
        return;
    }


    //cout << "Calling listitem destructor  ";
    ListItem* aux = this;
    if (this->next_ != this) destroy(aux);

    delete this->key_;
}





template<typename genericArg>
void ListItem<genericArg>::add(genericArg nk) 
{
    ListItem* nl = new ListItem<genericArg>();
    ListItem* aux = this->next_;

    nl->key_ = new genericArg(nk);
    //nl->key = nk;

    nl->prev_ = this;
    nl->next_ = aux;

    aux->prev_ = nl;
    this->next_ = nl;
}

template<typename genericArg>
int ListItem<genericArg>::count() 
{
    ListItem<genericArg>* aux = this->next_;
    int c = 1;

    while (aux->next_ != this) 
    {
        aux = aux->next_;
        c++;
    }
    return c;
}

template<typename genericArg>
void ListItem<genericArg>::destroy(ListItem<genericArg> *obj)
{
    ListItem<genericArg>* todel = obj->next_;
    ListItem<genericArg>* aux = todel->next_;

    obj->next_ = aux;
    aux->prev_ = obj;
    
    todel->next_ = nullptr;
    todel->prev_ = nullptr;
    delete todel;    
}

template<typename genericArg>
void ListItem<genericArg>::dump() 
{
    if (this == nullptr) return;
    if (this->key_ == nullptr) return;

    ListItem* aux = this;
    while (aux->next_ != this) 
    {
        aux = aux->next_;
        cout << *aux->key_ << " ";
    }
}


template<typename genericArg>
genericArg ListItem<genericArg>::fifoget() 
{
    ListItem* aux = this->prev_->prev_;
    ListItem* todel = this->prev_;
    genericArg* ret = todel->key_;

    todel->next_ = nullptr;
    todel->prev_ = nullptr;

    this->prev_ = aux;
    aux->next_ = this;

    delete todel;
    return *ret;
}

template<typename genericArg>
genericArg ListItem<genericArg>::fifotop() { return *(this->prev_->key_); }


template<typename genericArg>
vector<genericArg> ListItem<genericArg>::getvalues(){
    ListItem* aux = this;
    vector<genericArg> ret;
    while (aux->next_ != this) 
    {
        aux = aux->next_;
        ret.push_back(*(aux->key_));
    }



    //cout << endl;
    //cout << "TAMANHO DO RETORNO: " << ret.size() << endl;
    //this->dump();

    return ret;
} 

template<typename genericArg>
bool ListItem<genericArg>::isempty() 
{
    if (this == nullptr) return true;
    if (this->next_ == this && this->prev_ == this) return true;

    return false;
}



template<typename genericArg>
genericArg ListItem<genericArg>::lifoget() {
    ListItem* aux = this->next_->next_;
    ListItem* todel = this->next_;
    genericArg* ret = todel->key_;

    todel->next_ = nullptr;
    todel->prev_ = nullptr;

    this->next_ = aux;
    aux->prev_ = this;

    delete todel;
    return *ret;
}

template<typename genericArg>
genericArg ListItem<genericArg>::lifotop() {
    return *(this->next_->key_);
}

/*
template<typename genericArg>
void listitem<genericArg>::clear() {
    this->key = new genericArg();
    this->next = this;
    this->prev = this;
}*/

#endif