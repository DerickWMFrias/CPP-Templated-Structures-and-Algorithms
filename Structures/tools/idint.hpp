#ifndef FOO_STRUCTURES_TOOLS_IDINT_H
#define FOO_STRUCTURES_TOOLS_IDINT_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>


using namespace std;

class IdInt{
    private:
        int i_;
        int id_;
    public:
        IdInt();
        ~IdInt();
        bool operator == (const IdInt &obj);
        bool operator >= (const IdInt &obj);
        bool operator <= (const IdInt &obj);
        bool operator > (const IdInt &obj);
        bool operator < (const IdInt &obj);
        void operator = (const IdInt &obj);
        
        int  geti();
        int  getid();
        void seti(int j);
        void setid(int j);
};



IdInt::IdInt(){}
IdInt::~IdInt(){}

bool IdInt::operator == (const IdInt &obj){ return (this->i_ == obj.i_)? true : false; }
bool IdInt::operator >= (const IdInt &obj){ return (this->i_ <= obj.i_)? true : false; }
bool IdInt::operator <= (const IdInt &obj){ return (this->i_ >= obj.i_)? true : false; }
bool IdInt::operator > (const IdInt &obj) { return (this->i_ < obj.i_)? true : false; }
bool IdInt::operator < (const IdInt &obj) { return (this->i_ > obj.i_)? true : false; }
void IdInt::operator = (const IdInt &obj) { this->i_ = obj.i_; this->id_ = obj.id_; }

int IdInt::geti()       { return i_; }
int IdInt::getid()      { return id_; }
void IdInt::seti(int j) { i_ = j; }
void IdInt::setid(int j){ id_ = j; }

#endif