#ifndef FOO_STRUCTURES_GRAPHS_GRAPH_H
#define FOO_STRUCTURES_GRAPHS_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using std::cout;
using std::cin;

typedef int color;

class Node{
    private:
        bool is_deleted_;
        color color_;
    public:
        Node(){ this->is_deleted_ = false; this->color_ = -1;}
        Node(color cc) { this->is_deleted_ = false; this->color_ = cc;}
        ~Node() { }
        bool isDeleted() { return this->is_deleted_; }
        color Color() { return this->color_; }
        void setColor(color cc) { this->color_ = cc; }
        void deleteNode() { this->is_deleted_ = true; }
        void undeleteNode() { this->is_deleted_ = false; }
};

class Edge{
    private:
        int adjacent_to_;
        bool is_directed_;
        bool removed_;
        color color_;
    public:
        Edge(){ 
            adjacent_to_ = -1 ; 
            is_directed_ = false; 
            removed_ = false; 
            color_ = -1; }

        Edge(int to){ 
            adjacent_to_ = to ; 
            is_directed_ = false; 
            removed_ = false; 
            color_ = -1; }

        Edge(int to, color cc){ 
            adjacent_to_ = to ; 
            is_directed_ = false; 
            removed_ = false; 
            color_ = cc; }

        Edge(int to, bool directed){ 
            adjacent_to_ = to ; 
            is_directed_ = directed; 
            removed_ = false; 
            color_ = -1; }

        Edge(int to, bool directed, color cc){ 
            adjacent_to_ = to ; 
            is_directed_ = directed; 
            removed_ = false; 
            color_ = cc; }

        bool directed(){ return is_directed_; }
        bool removed(){ return removed_; }
        int adjacency(){ return adjacent_to_; }

        void remove_edge(){ }
        ~Edge(){}
};

class GraphImpl{
    private:
        std::vector<Node> nodes_;
        std::vector<std::vector<Edge>> adj_list_;
        int** adj_matrix_;
        int number_nodes_;
        bool is_digraph_;
    public:
        GraphImpl() { number_nodes_ = 0; is_digraph_ = false; }
        GraphImpl(int nd) { number_nodes_ = 0; for(int i = 0; i < nd; i++) this->addNode();  
                            is_digraph_ = false; }

        ~GraphImpl() { deleteAdjMatrix(); }

        void addNode() { Node new_node; nodes_.push_back(new_node); number_nodes_++; }
        void addNode(color cc) { Node new_node(cc); nodes_.push_back(new_node); }

        void addEdge(int u, int v) { 
            assert(containsNode(u) && containsNode(v)); 
            Edge e_u(v); adj_list_[u].push_back(e_u);
            Edge e_v(u); adj_list_[v].push_back(e_v); }
        void addEdge(int u, std::vector<int> vec_v) { 
            assert(containsNode(u));
            for(int v : vec_v){
                assert(containsNode(v)); 
                Edge e_u(v); adj_list_[u].push_back(e_u);
                Edge e_v(u); adj_list_[v].push_back(e_v); } }
        void addEdge(int u, int* vec_v, int sz_v) { 
            assert(containsNode(u));
            int v = 0;
            for(int i = 0; i < sz_v; i++){
                v = vec_v[i];
                assert(containsNode(v)); 
                Edge e_u(v); adj_list_[u].push_back(e_u);
                Edge e_v(u); adj_list_[v].push_back(e_v); } }

        Node getNode(int nd){ assert(nodeExists(nd)); return nodes_[nd]; }
        Edge getEdge(int nd_from, int nd_to){
            assert(nodeExists(nd_from) && nodeExists(nd_to));
            for(Edge e : adj_list_[nd_from]){
                if(e.adjacency() == nd_to) return e;
            }
            Edge empty_e;
            return empty_e;
        }
        void delNode(int at) { std::string ss(""); assertRoutine(ss, at); nodes_[at].deleteNode(); number_nodes_--; }

    public:
        int nodeCount() { return number_nodes_; }
        int getAdjacencyCountOf(int nd) { std::string ss(""); assertRoutine(ss, nd); return adj_list_[nd].size(); }
        int** getAdjMatrix() { return adj_matrix_; }
        void deleteAdjMatrix() { for(int i = nodes_.size() - 1; i >= 0; i--) delete(adj_matrix_[i]); 
                                 delete(adj_matrix_); }

    public:
        bool containsNode(int nd){ return nodeExists(nd)? 
                                   nodeIsNotDeleted(nd): false; }

        bool containsEdge(int nd_from, int nd_to){ return false; }
        bool isEmpty() { return number_nodes_ == 0; }
        bool nodeExists(int nd){ return (nd > 0 && nd < nodeCount()); }
        bool nodeIsNotDeleted(int nd){ return (!nodes_[nd].isDeleted()); }

    public:
        void initAdjMatrix();
        std::vector<int> getAdjacencyVectorOf(int nd);
        int* getAdjacencyArrayOf(int nd);
        void assertRoutine(std::string s, int at);
        void mountErrorMessage(char* msg, std::string s1, std::string s2, int msg_size);
};

std::vector<int> GraphImpl::getAdjacencyVectorOf(int nd){
    std::vector<int> ret;

    std::string ss("");
    assertRoutine(ss, nd);

    for(Edge e : adj_list_[nd]){
        ret.push_back(e.adjacency());
    }

    return ret;
}
int* GraphImpl::getAdjacencyArrayOf(int nd){
    int* ret;
    int sz = adj_list_[nd].size();
    std::string ss("");
    assertRoutine(ss, nd);

    ret = new int[sz];
    for(int i = 0; i < sz; i++){
        ret[i] = adj_list_[nd][i].adjacency();
    } 

    return ret;
}

void GraphImpl::initAdjMatrix(){
    int sz = nodes_.size();

    adj_matrix_= new int*[sz];

    for(int i = 0; i < sz; i++){
        adj_matrix_[i]= new int[sz];
    }

    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            adj_matrix_[i][j] = 0;
        }
    }

    int i = 0;
    for(std::vector<Edge> vec : adj_list_){
        for(Edge e : vec){
            adj_matrix_[i][e.adjacency()] = 1;
        }
        i++;
    }
}
/*
void GraphImpl::deleteAdjMatrix(){
    for(int i = nodes_.size() - 1; i >= 0; i--){
        delete(adj_matrix_[i]);
    }
    delete(adj_matrix_);
}
*/

 void GraphImpl::assertRoutine(std::string s_called_from, int at){
    char msg_from_exists[256];
    char msg_from_isnt_deleted[256];
    
    std::string s_exists = ": Node " + std::to_string(at) + " não existe";
    std::string s_isnt_deleted = ": Node " + std::to_string(at) + " foi deletado e não pode ser chamado";

    mountErrorMessage(msg_from_exists, s_called_from, s_exists, 256);
    mountErrorMessage(msg_from_exists, s_called_from, s_isnt_deleted, 256);

    const char *error_msg_from_exists = msg_from_exists;
    const char *error_msg_from_isnt_deleted = msg_from_isnt_deleted;

    assert(nodeExists(at) && error_msg_from_exists) ;
    assert(nodeIsNotDeleted(at) && error_msg_from_isnt_deleted);
}

void GraphImpl::mountErrorMessage(char* msg, std::string s1, std::string s2, int msg_size){
    int c_general = 0;
    int at = 0;
    int s1_size = s1.size();
    int s2_size = s2.size();

    for(int c_string = 0; c_string < s1_size; c_string++){
        assert(c_general < msg_size && "Mounted ErrorString size is bigger than 256!");

        msg[c_general] = s1[at];
        c_general++;
        at++;
    }

    at = 0;
    for(int c_string = 0; c_string < s2_size; c_string++){
        assert(c_general < msg_size && "Mounted ErrorString size is bigger than 256!");

        msg[c_general] = s2[at];
        c_general++;
        at++;

        if(c_string == s2_size-1){
            msg[c_general] = (char) '\0';
        }
    }
}

class Graph{
    private:
        GraphImpl g_;
    public:
        Graph() {}
        Graph(int n) { this->addNode(n); }
        ~Graph() {}

        void addNode() { g_.addNode(); }
        void addNode(color cc) { g_.addNode(cc); }
        void addNode(int n, color cc) { for(int i = 0; i < n; i++) g_.addNode(cc); }
        void addNode(int n, color* cc) { for(int i = 0; i < n; i++) g_.addNode(cc[i]); }

        void addEdge(int nd_from, int nd_to){ g_.addEdge(nd_from, nd_to); }
        void addEdge(int nd_from, std::vector<int> nd_to_list){ g_.addEdge(nd_from, nd_to_list); }
        void addEdge(int nd_from, int* nd_to_list, int sz_list){ g_.addEdge(nd_from, nd_to_list, sz_list); }

        void delNode(int at) { g_.delNode(at); }
        void delNodeBetween(int a, int b) { for(int i = a; i < b; i++) this->delNode(i); }
        bool isEmpty() { return g_.isEmpty(); }
        std::vector<int> getAdjacencyVectorOf(int nd) { return g_.getAdjacencyVectorOf(nd); }
        int* getAdjacencyArrayOf(int nd) { return g_.getAdjacencyArrayOf(nd); }
        int getAdjacencyCountOf(int nd) { return g_.getAdjacencyCountOf(nd); }
        int nodeCount() { return g_.nodeCount(); }
};

class GraphManager{
    private:
    public:
};

#endif