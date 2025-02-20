#ifndef FOO_STRUCTURES_UNIONFIND_UNIONFIND_H
#define FOO_STRUCTURES_UNIONFIND_UNIONFIND_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>


using namespace std;

class UnionFind {
private:
    vector<int> id_;
    vector<int> size_;
public:
    UnionFind();
    UnionFind(int n);
    ~UnionFind();
    void    addclasses(int n);
    int     find(int p);
    void    uni(int p, int q);
    int     numofelements();
};


UnionFind::UnionFind() {}
UnionFind::UnionFind(int n) {addclasses(n); }
UnionFind::~UnionFind() {}


void UnionFind::addclasses(int n) 
{
    int sz = this->numofelements();
    for (int i = 0; i < n; i++)
    {
        id_.push_back(sz+i);
        size_.push_back(1);
    }
}
int UnionFind::numofelements() { return id_.size(); }

void UnionFind::uni(int p, int q) 
{
    p = find(p);
    q = find(q);

    if (p == q) return;
    if (size_[p] > size_[q]) 
    {
        int a = p;
        p = q;
        q = a;
    }
    id_[p] = q;
    size_[q] += size_[p];

}
int UnionFind::find(int p) 
{
    if (id_[p] == p) return p;
    return (id_[p] = find(id_[p]));
}

#endif