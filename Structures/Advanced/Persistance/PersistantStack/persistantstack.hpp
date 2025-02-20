#ifndef FOO_STRUCTURES_MAIN_CPP
#define FOO_STRUCTURES_MAIN_CPP

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>


class persistantStackNode{
    private:
        int content_;
        persistantStackNode* pt_;
    public:
        persistantStackNode(){ pt_ = nullptr; }
        persistantStackNode(int i_new) { content_ = i_new;  pt_ = nullptr; }
        persistantStackNode(int i_new, persistantStackNode* pt_new) {  content_ = i_new;  pt_ = pt_new; }
        ~persistantStackNode(){}
        int geti() { return content_; }
        int getcontent() {  return content_; }
        persistantStackNode* getpt() {  return pt_; }
};


class persistantStack{
    private:
        std::vector<persistantStackNode> stack_timeline_;

    public:
        persistantStack();
        ~persistantStack();
        void push();
        void pop();
        void top();
};

#endif