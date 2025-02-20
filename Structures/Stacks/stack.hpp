#ifndef FOO_STRUCTURES_STACKS_STACK_H
#define FOO_STRUCTURES_STACKS_STACK_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;



template<typename genericArg>
class Stack {
private:
    vector<genericArg> s_;
    int size_;
    int t_;
public:
    Stack();
    ~Stack();
    void        clear();
    void        dump();
    int         howmany();
    bool        isempty();
    genericArg  pop();
    void        push(genericArg obj);
    genericArg  top();
};




template<typename genericArg>
Stack<genericArg>::Stack() 
{
    size_ = 0;
    t_ = -1;
}

template<typename genericArg>
Stack<genericArg>::~Stack() {}


template<typename genericArg>
void Stack<genericArg>::clear() 
{
    s_.clear();
    size_ = 0;
    t_ = -1;
}

template<typename genericArg>
void Stack<genericArg>::dump() 
{
    for (int i = 0; i <= t_; i++) cout << s_[i] << " ";
    cout << endl;
}

template<typename genericArg>
int Stack<genericArg>::howmany() { return size_; }

template<typename genericArg>
bool Stack<genericArg>::isempty() { return (t_ < 0) ? true : false; }

template<typename genericArg>
genericArg Stack<genericArg>::pop() 
{
    if (isempty()) 
    {
        genericArg gen;
        cout << "Error! Corrupted top caused by empty stack calling" << endl;
        return gen;
    }
    t_--;
    size_--;

    genericArg ret = s_.back();
    s_.pop_back();
    return ret;
}

template<typename genericArg>
void Stack<genericArg>::push(genericArg obj) 
{
    s_.push_back(obj);
    t_++;
    size_++;
}

template<typename genericArg>
genericArg Stack<genericArg>::top() 
{
    if (isempty()) 
    {
        genericArg gen;
        cout << "Error! Corrupted top caused by empty stack calling" << endl;
        return gen;
    }
    return s_.at(t_);
}


#endif