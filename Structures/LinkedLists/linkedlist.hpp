#ifndef FOO_STRUCTURES_LINKEDLISTS_LINKEDLIST_H
#define FOO_STRUCTURES_LINKEDLISTS_LINKEDLIST_H


#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

//Please also clone Structures\LinkedLists\linkedlist.hpp
#include "C:\Users\steam\Desktop\EstudosGerais\Portfolio\Cpp\Libraries\dataStructures\Structures\tools\listitem.hpp"



template<typename genericArg>
class LinkedList {
private:
    ListItem<genericArg>* head_;
    string list_type_;
    string type();
public:
    LinkedList();
    LinkedList(string s);
    ~LinkedList();
    void                add(genericArg nk);
    void                clear();
    void                dump();
    bool                isempty();
    genericArg          get();
    vector<genericArg>  getvalues();
    int                 howmany();
    genericArg          top();
};







template<typename genericArg>
LinkedList<genericArg>::LinkedList() 
{
    head_ = new ListItem<genericArg>();
    list_type_ = "lifo";
}

template<typename genericArg>
LinkedList<genericArg>::LinkedList(string s) 
{
    head_ = new ListItem<genericArg>();
    list_type_ = "lifo";

    if (s == "fifo") list_type_ = "fifo";
}

template<typename genericArg>
LinkedList<genericArg>::~LinkedList() { delete head_; }



template<typename genericArg>
void LinkedList<genericArg>::add(genericArg nk) { head_->add(nk); }

template<typename genericArg>
void LinkedList<genericArg>::clear() 
{
    delete head_;
    head_ = new ListItem<genericArg>();
}

template<typename genericArg>
void LinkedList<genericArg>::dump() { head_->dump(); }

template<typename genericArg>
bool LinkedList<genericArg>::isempty() { return head_->isempty(); }

template<typename genericArg>
genericArg LinkedList<genericArg>::get() 
{
    if (isempty()) 
    {
        genericArg corrupted;
        return corrupted;
    }

    if (type() == "lifo") return head_->lifoget();
    return head_->fifoget();
}

template<typename genericArg>
vector<genericArg> LinkedList<genericArg>::getvalues(){
    if (isempty()) 
    {
        vector<genericArg> corrupted;
        return corrupted;
    }
    //cout << "IN LINKEDLIST::GETVALUES()" << endl;

    return head_->getvalues();
}

template<typename genericArg>
int LinkedList<genericArg>::howmany() 
{
    if (isempty()) return 0;
    return head_->count();
}

template<typename genericArg>
string LinkedList<genericArg>::type() 
{
    if (list_type_ == "fifo") return "fifo";
    return "lifo";
}

template<typename genericArg>
genericArg LinkedList<genericArg>::top() 
{
    if (isempty()) 
    {
        genericArg corrupted;
        return corrupted;
    }

    if (type() == "lifo") return head_->lifotop();
    return head_->fifotop();
}

#endif
