#ifndef FOO_STRUCTURES_QUEUES_QUEUE_H
#define FOO_STRUCTURES_QUEUES_QUEUE_H


#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;


template<typename genericArg>
class Queue {
    private:
    vector<genericArg> q_;
    int size_;
    int head_;
    int tail_;
    void resize();
public:
    Queue();
    ~Queue();
    void        clear();
    genericArg  dequeue();
    void        dump();
    void        enqueue(genericArg obj);
    bool        isempty();
    int         howmany();
    genericArg  top();
};






template<typename genericArg>
Queue<genericArg>::Queue() 
{
    size_ = q_.capacity()+1;
    head_ = 0;
    tail_ = 0;
}

template<typename genericArg>
Queue<genericArg>::~Queue() { //delete q; 
}


template<typename genericArg>
void Queue<genericArg>::clear() 
{
    q_.clear();
    size_ = q_.capacity()+1;
    head_ = 0;
    tail_ = 0;
}

template<typename genericArg>
genericArg Queue<genericArg>::dequeue() 
{
    if (isempty()) 
    {
        genericArg gen;
        cout << "Error! Corrupted object caused by empty queue calling" << endl;
        return gen;
    }

    int ret = q_[tail_];
    tail_++;
    size_ = q_.capacity()+1;
    if(2*howmany() <= size_){ resize(); }

    return ret;
}

template<typename genericArg>
void Queue<genericArg>::dump() 
{
    int i = tail_;
    size_ = q_.capacity()+1;
    //cout << "Size= " << size << " Tail= " << tail << " Head= " << head << "    "; 

    while (i != head_) 
    {
        //cout << "At" << i << " " << q[i] << " ";
        cout << q_[i] << " ";
        i++;
        i = i % size_;
    }

    cout << endl;
}

template<typename genericArg>
void Queue<genericArg>::enqueue(genericArg obj) 
{
   q_.push_back(obj);
   head_++;
}

template<typename genericArg>
int Queue<genericArg>::howmany() { return head_ - tail_; }

template<typename genericArg>
bool Queue<genericArg>::isempty() { return (head_ == tail_) ? true : false; }

template<typename genericArg>
void Queue<genericArg>::resize() 
{
    vector<genericArg> auxq;
    q_.erase(q_.begin(), q_.begin() + tail_);

    tail_ = 0;
    head_ = q_.size();
}

template<typename genericArg>
genericArg Queue<genericArg>::top() 
{
    if (isempty()) 
    {
        genericArg gen;
        cout << "Error! Corrupted object caused by empty queue calling" << endl;
        return gen;
    }
    return q_[tail_];
}

#endif