#ifndef FOO_STRUCTURES_MAIN_CPP
#define FOO_STRUCTURES_MAIN_CPP

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

#include "Structures/Trees/bstree.hpp"
#include "Structures/SymbolTables/bstreeST.hpp"
#include "Structures/PrioQueues/minheap.hpp"
#include "Structures/PrioQueues/maxheap.hpp"
#include "Structures/Stacks/stack.hpp"
#include "Structures/Queues/queue.hpp"
#include "Structures/LinkedLists/linkedlist.hpp"
#include "Structures/UnionFind/unionfind.hpp"
#include "Structures/indevelopment/Graphs/graph.hpp"
#include "Structures/Advanced/SkewBinary/skewbinary.hpp"

using namespace std;



void testqueue();
void teststack();
void testminheap();
void testmaxheap();
void testbstree();
void testbstreeST();
void testlinkedlist();
void testunionfind();
void testgraphbasics();
void testcsb();


int main() {
    int invalidCounter = 0;
    bool stop = false;

    while(!stop){
        int i;
        cout << "What do you want to do?" << endl;
        cout << "0: EXIT" << endl;
        cout << "1: RUN QUEUE TEST" << endl;
        cout << "2: RUN STACK TEST" << endl;
        cout << "3: RUN MINHEAP TEST" << endl;
        cout << "4: RUN MAXHEAP TEST" << endl;
        cout << "5: RUN U.F TEST" << endl;
        cout << "6: RUN BINARY SEARCH TREE TEST" << endl;
        cout << "7: RUN ST BINARY SEARCH TREE TEST" << endl;
        cout << "8: RUN LINKED LIST TEST" << endl;
        cout << "9: RUN GRAPH TEST" << endl;
        cout << "10: RUN CSB TEST" << endl;
        cout << "ENTER INPUT:  ";
        cin >> i;

        switch(i){
            case 0:
                cout << "Ending routine" << endl;
                stop = true;
            break;
            case 1:
                testqueue();
                invalidCounter = 0;
            break;
            case 2:
                teststack();
                invalidCounter = 0;
            break;
            case 3:
                testminheap();
                invalidCounter = 0;
            break;
            case 4:
                testmaxheap();
                invalidCounter = 0;
            break;
            case 5:
                testunionfind();
                invalidCounter = 0;
            break;
            case 6:
                testbstree();
                invalidCounter = 0;
            break;
            case 7:
                testbstreeST();
                invalidCounter = 0;
            break;
            case 8:
                testlinkedlist();
                invalidCounter = 0;
                break;
            case 9:
                testgraphbasics();
                invalidCounter = 0;
            case 10:
                testcsb();
                invalidCounter = 0;
            default:
                cout << "Invalid input. Try again" << endl;
                invalidCounter++;
                if(invalidCounter >= 3){
                    cout << "Ending routine" << endl;
                    stop = true;
                }
            break;
        }
    }


    return 0;
}




                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:LINKEDLIST TEST*/
void linkedliststats(LinkedList<int> *ll){
    cout << "LINKEDLIST: ";
    ll->dump();
    cout << "LINKEDLIST TOP: " << ll->top() << endl;
    cout << "LINKEDLIST HOWMANY: " << ll->howmany() << endl;
    cout << "LINKEDLIST ISEMPTY?: " << ll->isempty() << endl;
    cout << endl << endl;
}
void testlinkedlist(){
    LinkedList<int>* ll = new LinkedList<int>();
    int i;

    cout << "TEST MODULE FOR LINKEDLIST<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED LINKEDLIST<GENERICTYPE> METHODS:" << endl;
    cout << "void add(genericArg nk)" << endl;
    cout << "genericArg get()" << endl;
    cout << "genericArg top()" << endl;
    cout << "void dump()" << endl;
    cout << "bool isempty()" << endl;
    cout << "int howmany()" << endl;
    cout << "void clear()" << endl;

    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{10, 20, 30, 40, 50, 60, 90}" << endl;
    ll->add(10);
    ll->add(20);
    ll->add(30);
    ll->add(40);
    ll->add(50);
    ll->add(60);
    ll->add(90);
    linkedliststats(ll);

    cout << "REMOVING 5 ELEMENTS:" << endl;
    i = ll->get();
    cout << "REMOVED: " << i << endl;
    i = ll->get();
    cout << "REMOVED: " << i << endl;
    i = ll->get();
    cout << "REMOVED: " << i << endl;
    i = ll->get();
    cout << "REMOVED: " << i << endl;
    i = ll->get();
    cout << "REMOVED: " << i << endl;
    linkedliststats(ll);

    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{10, 20}" << endl;
    ll->add(10);
    ll->add(20);
    linkedliststats(ll);

    cout << "CLEARING LIST:" << endl;
    ll->clear();
    linkedliststats(ll);

    cout << "INSERTING INTEGER 1-40 {IN ORDER}:" << endl;
    for(int j = 1; j <=40; j++) ll->add(j);

    linkedliststats(ll);

    cout << "CLEARING LIST:" << endl;
    ll->clear();
    linkedliststats(ll);

    cout << "ENDING TEST" << endl << endl << endl;

    delete ll;
}






                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:UNIONFIND TEST*/
void testunionfind(){
    UnionFind* uf = new UnionFind(10);
    int i = 0, sz = 0;
    cout << endl << endl;
    cout << "TEST MODULE FOR UNION-FIND" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED UNION-FIND METHODS:" << endl;
    cout << "unionfind()" << endl;
    cout << "unionfind(int n)" << endl;
    cout << "void addclasses(int n)" << endl;
    cout << "int find(int p)" << endl;
    cout << "void uni(int p, int q)" << endl;
    cout << "int numofelements()" << endl;

    sz = uf->numofelements();

    cout << "TEST FOR FIND ON INITIAL UF STATE" << endl;
    for(int j = 0; j < sz; j++){
        cout << "FIND OF " << j << "= " << uf->find(j) << endl;
    }
    cout << endl;

    cout << endl;
    cout << "TEST FOR UNION METHOD" << endl;
    cout << "UNITING(1, 3)" << endl;
    uf->uni(1, 3);
    cout << "UNITING(3, 8)" << endl;
    uf->uni(3, 8);
    cout << "UNITING(9, 4)" << endl;
    uf->uni(9, 4);
    cout << "UNITING(7, 6)" << endl;
    uf->uni(7, 6);
    cout << "UNITING(6, 1)" << endl;
    uf->uni(6, 1);
    cout << endl;
    

    cout << "TEST FOR FIND ON NEW UF STATE" << endl;
    for(int j = 0; j < sz; j++){
        cout << "FIND OF " << j << "= " << uf->find(j) << endl;
    }
    cout << endl;

    cout << endl;
    cout << "ADDING 17 MORE CLASSES" << endl;
    uf->addclasses(17);
    sz = uf->numofelements();
    cout << endl;


    cout << endl;
    cout << "TEST FOR FIND ON NEW UF STATE" << endl;
    for(int j = 0; j < sz; j++){
        cout << "FIND OF " << j << "= " << uf->find(j) << endl;
    }
    cout << endl;


    cout << endl;
    cout << "TEST FOR UNION METHOD" << endl;
    cout << "UNITING(1, 3)" << endl;
    uf->uni(1, 3);
    cout << "UNITING(3, 8)" << endl;
    uf->uni(3, 8);
    cout << "UNITING(12, 6)" << endl;
    uf->uni(12, 6);
    cout << "UNITING(13, 1)" << endl;
    uf->uni(13, 1);
    cout << "UNITING(17, 8)" << endl;
    uf->uni(17, 8);
    cout << endl;


    cout << endl;
    cout << "TEST FOR FIND ON NEW UF STATE" << endl;
    for(int j = 0; j < sz; j++){
        cout << "FIND OF " << j << "= " << uf->find(j) << endl;
    }
    cout << endl;

    cout << "ENDING TEST" << endl << endl << endl;

delete uf;
}



void testcsb(){
    CSB eve("1120200");
    CSB basic("111001");

    std::cout << "CSB values" << std::endl;
    std::cout << eve.getValue() << std::endl;
    std::cout << basic.getValue() << std::endl << std::endl;

    std::cout << "CSB binaries" << std::endl;
    std::cout << eve.getBin() << std::endl;
    std::cout << basic.getBin() << std::endl << std::endl;

    eve.dec();
    basic.dec();

    std::cout << "CSB values decremented" << std::endl;
    std::cout << eve.getValue() << std::endl;
    std::cout << basic.getValue() << std::endl << std::endl;

    std::cout << "CSB binaries decremented" << std::endl;
    std::cout << eve.getBin() << std::endl;
    std::cout << basic.getBin() << std::endl << std::endl;
}



                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:QUEUE TEST*/
void queuestats(Queue<int> q){
    cout << "QUEUE: ";
    q.dump();
    cout << "QUEUE TOP: " << q.top() << endl;
    cout << "QUEUE HOWMANY: " << q.howmany() << endl;
    cout << "QUEUE ISEMPTY?: " << q.isempty() << endl;
    cout << endl << endl;
}
void testqueue() {
    Queue<int> q;
    int i = 0;

    cout << endl << endl;
    cout << "TEST MODULE FOR QUEUE<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED QUEUE<GENERICTYPE> METHODS:" << endl;
    cout << "1: void enqueue(genericArg obj)" << endl;
    cout << "2: genericArg dequeue()" << endl;
    cout << "3: bool isempty()" << endl;
    cout << "4: void clear()" << endl;
    cout << "5: void dump()" << endl;
    cout << "6: int howmany()" << endl;
    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{10, 20, 30, 40, 50, 60, 90}" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(90);
    queuestats(q);

    cout << "REMOVING 5 ELEMENTS:" << endl;
    i = q.dequeue();
    cout << "REMOVED: " << i << endl;
    i = q.dequeue();
    cout << "REMOVED: " << i << endl;
    i = q.dequeue();
    cout << "REMOVED: " << i << endl;
    i = q.dequeue();
    cout << "REMOVED: " << i << endl;
    i = q.dequeue();
    cout << "REMOVED: " << i << endl;
    queuestats(q);

    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{10, 20}" << endl;
    q.enqueue(10);
    q.enqueue(20);
    queuestats(q);

    cout << "CLEARING QUEUE:" << endl;
    q.clear();
    queuestats(q);

    cout << "INSERTING INTEGER 1-40 {IN ORDER}:" << endl;
    for(int j = 1; j <=40; j++) q.enqueue(j);
    queuestats(q);

    cout << "CLEARING QUEUE:" << endl;
    q.clear();
    queuestats(q);

    cout << "ENDING TEST" << endl << endl << endl;
}




                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:STACK TEST*/
void stackstats(Stack<int> stk){
    cout << "STACK: ";
    stk.dump();
    cout << "STACK TOP: " << stk.top() << endl;
    cout << "STACK HOWMANY: " << stk.howmany() << endl;
    cout << "STACK ISEMPTY?: " << stk.isempty() << endl;
    cout << endl << endl;
}
void teststack() {
    Stack<int> stk;
    int i = 0;

    cout << endl << endl;
    cout << "TEST MODULE FOR STACK<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED STACK<GENERICTYPE> METHODS:" << endl;
    cout << "genericArg pop()" << endl;
    cout << "genericArg top()" << endl;
    cout << "bool isempty()" << endl;
    cout << "void clear()" << endl;
    cout << "void dump()" << endl;
    cout << "int howmany()" << endl;



    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{10, 20, 30, 40, 50, 60, 90}" << endl;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(90);
    stackstats(stk);

    cout << "REMOVING 2 ELEMENTS:" << endl;
    i = stk.pop();
    cout << "REMOVED: " << i << endl;
    i = stk.pop();
    cout << "REMOVED: " << i << endl;
    stackstats(stk);

    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{60, 90}" << endl;
    stk.push(60);
    stk.push(90);
    stackstats(stk);

    cout << "CLEARING STACK:" << endl;
    stk.clear();
    stackstats(stk);

    cout << "INSERTING INTEGER 1-40 {IN ORDER}:" << endl;
    for(int j = 1; j <=40; j++) stk.push(j);

    stackstats(stk);

    cout << "CLEARING STACK:" << endl;
    stk.clear();
    stackstats(stk);

    cout << "ENDING TEST" << endl << endl << endl;
}





                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:MINHEAP TEST*/
void minhpstats(MinHeap<int>* minhp){
    cout << "MINHEAP: ";
    minhp->dump();
    cout << "MINHEAP TOP: " << minhp->peekmin() << endl;
    cout << "MINHEAP SIZE: " << minhp->size() << endl;
    cout << "MINHEAP ISEMPTY?: " << minhp->isempty() << endl;
    cout << endl << endl;
}
void testminheap(){
    MinHeap<int>* minhp = new MinHeap<int>();
    int i = 0;


    cout << endl << endl;
    cout << "TEST MODULE FOR MINHEAP<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED MINHEAP<GENERICTYPE> METHODS:" << endl;
    cout << "void insert(genericType p)" << endl;
    cout << "genericType getmin()" << endl;
    cout << "genericType peekmin()" << endl;
    cout << "int size()" << endl;
    cout << "bool isempty()" << endl; 
    cout << "void clear()" << endl; 



    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{72, 32, 61, 11, 82, 92, 22, 21, 62, 71, 81, 41, 42, 52, 51}" << endl;
    minhp->insert(72);
    minhp->insert(32);
    minhp->insert(61);
    minhp->insert(11);
    minhp->insert(82);
    minhp->insert(92);
    minhp->insert(22);
    minhp->insert(21);
    minhp->insert(62);
    minhp->insert(71);
    minhp->insert(81);
    minhp->insert(41);
    minhp->insert(42);
    minhp->insert(52);
    minhp->insert(51);
    minhpstats(minhp);
//minhp->showsons();
    cout << "REMOVING 5 MIN ELEMENTS:" << endl;
    i = minhp->getmin();
    cout << "REMOVED: " << i << endl;
    i = minhp->getmin();
    cout << "REMOVED: " << i << endl;
    i = minhp->getmin();
    cout << "REMOVED: " << i << endl;
    i = minhp->getmin();
    cout << "REMOVED: " << i << endl;
    i = minhp->getmin();
    cout << "REMOVED: " << i << endl;
    minhpstats(minhp);

    cout << endl << "INSERTING 3 INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{111, 1, 22}" << endl;
    minhp->insert(111);
    minhp->insert(1);
    minhp->insert(22);
    minhpstats(minhp);
//minhp->showsons();
    cout << "CLEARING MINHEAP:" << endl;
    minhp->clear();
    minhpstats(minhp);


    cout << endl << "RE-INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{72, 32, 61, 11, 82, 92, 22, 21, 62, 71, 81, 41, 42, 52, 51}" << endl;
    minhp->insert(72);
    minhp->insert(32);
    minhp->insert(61);
    minhp->insert(11);
    minhp->insert(82);
    minhp->insert(92);
    minhp->insert(22);
    minhp->insert(21);
    minhp->insert(62);
    minhp->insert(71);
    minhp->insert(81);
    minhp->insert(41);
    minhp->insert(42);
    minhp->insert(52);
    minhp->insert(51);
    minhpstats(minhp);

    cout << "REMOVING ELEMENTS TILL HEAP IS EMPTY:" << endl;
    while(!minhp->isempty()){
        i = minhp->getmin();
        cout << "REMOVED: " << i << endl;
    }

    cout << "ENDING TEST" << endl << endl << endl;
}





                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:MAXHEAP TEST*/
void maxhpstats(MaxHeap<int>* maxhp){
    cout << "MAXHEAP: ";
    maxhp->dump();
    cout << "MAXHEAP TOP: " << maxhp->peekmax() << endl;
    cout << "MAXHEAP SIZE: " << maxhp->size() << endl;
    cout << "MAXHEAP ISEMPTY?: " << maxhp->isempty() << endl;
    cout << endl << endl;
}
void testmaxheap(){
    MaxHeap<int>* maxhp = new MaxHeap<int>();
    int i = 0;


    cout << endl << endl;
    cout << "TEST MODULE FOR MAXHEAP<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED MAXHEAP<GENERICTYPE> METHODS:" << endl;
    cout << "void insert(genericType p)" << endl;
    cout << "genericType getmin()" << endl;
    cout << "genericType peekmin()" << endl;
    cout << "int size()" << endl;
    cout << "bool isempty()" << endl;
    cout << "void clear()" << endl; 




    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{72, 32, 61, 11, 82, 92, 22, 21, 62, 71, 81, 41, 42, 52, 51}" << endl;
    maxhp->insert(72);
    maxhp->insert(32);
    maxhp->insert(61);
    maxhp->insert(11);
    maxhp->insert(82);
    maxhp->insert(92);
    maxhp->insert(22);
    maxhp->insert(21);
    maxhp->insert(62);
    maxhp->insert(71);
    maxhp->insert(81);
    maxhp->insert(41);
    maxhp->insert(42);
    maxhp->insert(52);
    maxhp->insert(51);
    maxhpstats(maxhp);
    cout << endl;
 //   maxhp->showsons();


    cout << "REMOVING 5 MAX ELEMENTS:" << endl;
    i = maxhp->getmax();
    cout << "REMOVED: " << i << endl;
    i = maxhp->getmax();
    cout << "REMOVED: " << i << endl;
    i = maxhp->getmax();
    cout << "REMOVED: " << i << endl;
    i = maxhp->getmax();
    cout << "REMOVED: " << i << endl;
    i = maxhp->getmax();
    cout << "REMOVED: " << i << endl;
    maxhpstats(maxhp);

    cout << endl << "INSERTING 3 INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{111, 1, 22}" << endl;
    maxhp->insert(111);
    maxhp->insert(1);
    maxhp->insert(22);
    maxhpstats(maxhp);
   // maxhp->showsons();


    cout << "CLEARING MAXHEAP:" << endl;
    maxhp->clear();
    maxhpstats(maxhp);


    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{72, 32, 61, 11, 82, 92, 22, 21, 62, 71, 81, 41, 42, 52, 51}" << endl;
    maxhp->insert(72);
    maxhp->insert(22);
    maxhp->insert(61);
    maxhp->insert(11);
    maxhp->insert(82);
    maxhp->insert(92);
    maxhp->insert(22);
    maxhp->insert(21);
    maxhp->insert(62);
    maxhp->insert(71);
    maxhp->insert(81);
    maxhp->insert(41);
    maxhp->insert(42);
    maxhp->insert(52);
    maxhp->insert(51);

    cout << "REMOVING ELEMENTS TILL HEAP IS EMPTY:" << endl;
    while(!maxhp->isempty()){
        i = maxhp->getmax();
        cout << "REMOVED: " << i << endl;
    }

    cout << "ENDING TEST" << endl << endl << endl;
}




                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:BSTREE TEST*/
void printtree(){
    //cout << "WORKING" << endl;
    /*Height  Select*/
    cout << "PROVIDED BSTREE:" << endl;
    cout << "              20               " << endl;
    cout << "             /  \\              " << endl;
    cout << "            /    \\             " << endl;
    cout << "           /      \\            " << endl;
    cout << "          17      29           " << endl;
    cout << "         / \\     / \\          " << endl;
    cout << "        13  18  25  38         " << endl;
    cout << "       / \\  \\       \\        " << endl;
    cout << "      5   15  19      50       " << endl;
    cout << "                        \\      " << endl;
    cout << "                         51    " << endl;
    cout << endl;
}
void bstreestats(BsTree<int>* bs){
    cout << "BSTREE: ";
    bs->dump();
    cout << endl;
    cout << "BSTREE ISEMPTY?: " << bs->isempty() << endl;
    cout << "BSTREE SIZE: " << bs->size() << endl;
    cout << "BSTREE MIN: " << bs->min() << endl;
    cout << "BSTREE MAX: " << bs->max() << endl;
    cout << "BSTREE FLOOR(20): " << bs->floor(20) << endl;
    cout << "BSTREE CEILING(20): " << bs->ceiling(20) << endl;
    cout << "BSTREE FLOOR(MIN) " << bs->floor(bs->min()) << endl;
    cout << "BSTREE CEILING(MAX): " << bs->ceiling(bs->max()) << endl;
    cout << "BSTREE HEIGHT: " << bs->height() << endl;
    cout << endl;
}
void testbstree(){
    BsTree<int>* bs = new BsTree<int>(20);
    int numElements = 0;

    cout << endl << endl;
    printtree();
    cout << "TEST MODULE FOR BSTREE<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED BSTREE<GENERICTYPE> METHODS:" << endl;
    cout << "void add(key newkey)" << endl;
    cout << "bool isempty()" << endl;
    cout << "bool contains(key akey)" << endl;
    cout << "int size()" << endl;
    cout << "int size(key low, key high)" << endl;
    cout << "int rank(key akey)" << endl;
    cout << "key min()" << endl;
    cout << "key max()" << endl;
    cout << "key floor(key akey)" << endl;
    cout << "key ceiling(key akey)" << endl;
    cout << "key select(int rk)" << endl;
    cout << "void del(key akey)" << endl;
    cout << "void delat(int at)" << endl;
    cout << "void delmin()" << endl;
    cout << "void delmax()" << endl;
    cout << "int height()" << endl;
    cout << "int level(key akey)" << endl;
    cout << "void dump()" << endl;


    cout << endl << "INSERTING INTEGER ELEMENTS {IN ORDER}:" << endl;
    cout << "{20, 17, 13, 5, 15, 18, 19, 29, 25, 38, 50, 51}" << endl;
    bs->add(17);
    bs->add(13);
    bs->add(5);
    bs->add(15);
    bs->add(18);
    bs->add(19);
    bs->add(29);
    bs->add(25);
    bs->add(38);
    bs->add(50);
    bs->add(51);
    bstreestats(bs);

    numElements = bs->size();
    int containedElements[numElements] = {5, 13, 15, 17, 18, 19, 20, 25, 29, 38, 50, 51};

    {
        cout << endl << "TESTING METHOD CONTAINS(): NUMBERS 1-60" << endl;
        bool marks[60];
        for(int j = 0; j < 60; j++) marks[j] = bs->contains(j+1);
        cout << "CONTAINED VALUES:   ";
        for(int j = 0; j < 60; j++){ 
            if(marks[j]) cout << j+1 << " ";
        }
        cout << endl;
        cout << "NOT CONTAINED VALUES:   ";
        for(int j = 0; j < 60; j++){ 
            if(!marks[j]) cout << j+1 << " ";
        }
    }


    cout << endl << endl << "TESTING SIZE(LOW, HIGH) METHOD" << endl;
    cout << "SIZE(MIN, MAX):  " << bs->size(bs->min(), bs->max()) << endl;
    cout << "SIZE(MIN-1, MAX+1):  " << bs->size(bs->min()-1, bs->max()+1) << endl;
    cout << "SIZE(20, 21):  " << bs->size(20, 21) << endl;
    cout << "SIZE(20, 20):  " << bs->size(20, 20) << endl;
    cout << "SIZE(14, 14):  " << bs->size(14, 14) << endl;
    cout << "SIZE(19, 38):  " << bs->size(19, 38) << endl;
    cout << "SIZE(19-1, 38+1):  " << bs->size(19-1, 38+1) << endl;
    cout << "SIZE(19, 38):  " << bs->size(19, 38) << endl;
    cout << "SIZE(13, 26):  " << bs->size(13, 26) << endl;
    cout << "SIZE(12, 25):  " << bs->size(12, 25) << endl;
    cout << "SIZE(25, 12):  " << bs->size(25, 12) << endl;

    cout << endl << endl << "TESTING RANK() METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Rank of " << containedElements[j] << ":    " << bs->rank(containedElements[j]) << endl;
    }

    cout << endl << endl << "TESTING SELECT(rk) METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Select key at: " << j+1 << ":    " << bs->select(j+1) << endl;
    }

    cout << endl << endl << "TESTING LEVEL(KEY) METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Level of " << containedElements[j] << ":    " << bs->level(containedElements[j]) << endl;
    }


    cout << endl << endl;

delete bs;}




                            /*-----------------BEGINNING NEW TEST--------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                            /*-------------------------------------------------------*/
                                                /*=:BSTREEST TEST*/
void bstreeSTstats(BsTreeST<int, int>* bsST){
    cout << "BSTREEST: ";
    bsST->dump();
    cout << "BSTREEST ISEMPTY?: " << bsST->isempty() << endl;
    cout << "BSTREEST SIZE: " << bsST->size() << endl;
    cout << "BSTREEST MIN: " << bsST->min() << endl;
    cout << "BSTREEST MAX: " << bsST->max() << endl;
    cout << "BSTREEST FLOOR(20): " << bsST->floor(20) << endl;
    cout << "BSTREEST CEILING(20): " << bsST->ceiling(20) << endl;
    cout << "BSTREEST FLOOR(MIN) " << bsST->floor(bsST->min()) << endl;
    cout << "BSTREEST CEILING(MAX): " << bsST->ceiling(bsST->max()) << endl;
    cout << "BSTREEST HEIGHT: " << bsST->height() << endl;
    cout << endl << endl;
}
void testbstreeST(){
    BsTreeST<int, int>* bsST = new BsTreeST<int, int>(20, 1);
    int numElements = 0;

    cout << endl << endl;
    printtree();
    cout << "TEST MODULE FOR BSTREEST<INT>" << endl << "STARTING." << endl << endl;
    cout << "PROVIDED BSTREEST<GENERICTYPE> METHODS:" << endl;
    cout << "void add(key newkey, value newvalue)" << endl;
    cout << "bool isempty()" << endl;
    cout << "bool contains(key akey)" << endl;
    cout << "int size()" << endl;
    cout << "int size(key low, key high)" << endl;
    cout << "int rank(key akey)" << endl;
    cout << "key min()" << endl;
    cout << "key max()" << endl;
    cout << "key floor(key akey)" << endl;
    cout << "key ceiling(key akey)" << endl;
    cout << "key select(int rk)" << endl;
    cout << "void del(key akey)" << endl;
    cout << "void delat(int at)" << endl;
    cout << "void deletemin()" << endl;
    cout << "void delmax()" << endl;
    cout << "int height()" << endl;
    cout << "int level(key akey)" << endl;
    cout << "vector<value> get(key akey)" << endl;
    cout << "void dump()" << endl;


    cout << endl << "INSERTING INTEGER ELEMENTS (TWICE){IN ORDER}:" << endl;
    cout << "{20, 17, 13, 5, 15, 18, 19, 29, 25, 38, 50, 51}" << endl;
    bsST->add(17, 1);
    bsST->add(13, 1);
    bsST->add(5, 1);
    bsST->add(15, 1);
    bsST->add(18, 1);
    bsST->add(19, 1);
    bsST->add(29, 1);
    bsST->add(25, 1);
    bsST->add(38, 1);
    bsST->add(50, 1);
    bsST->add(51, 1);
    
    bsST->add(17, 2);
    bsST->add(13, 2);
    bsST->add(5, 2);
    bsST->add(15, 2);
    bsST->add(18, 2);
    bsST->add(19, 2);
    bsST->add(29, 2);
    bsST->add(25, 2);
    bsST->add(38, 2);
    bsST->add(50, 2);
    bsST->add(51, 2);
    bstreeSTstats(bsST);

    numElements = bsST->size();
    int containedElements[numElements] = {5, 13, 15, 17, 18, 19, 20, 25, 29, 38, 50, 51};

    {
        cout << endl << "TESTING METHOD CONTAINS(): NUMBERS 1-60" << endl;
        bool marks[60];
        for(int j = 0; j < 60; j++) marks[j] = bsST->contains(j+1);
        cout << "CONTAINED VALUES:   ";
        for(int j = 0; j < 60; j++){ 
            if(marks[j]) cout << j+1 << " ";
        }
        cout << endl;
        cout << "NOT CONTAINED VALUES:   ";
        for(int j = 0; j < 60; j++){ 
            if(!marks[j]) cout << j+1 << " ";
        }
    }


    cout << endl << endl << "TESTING SIZE(LOW, HIGH) METHOD" << endl;
    cout << "SIZE(MIN, MAX):  " << bsST->size(bsST->min(), bsST->max()) << endl;
    cout << "SIZE(MIN-1, MAX+1):  " << bsST->size(bsST->min()-1, bsST->max()+1) << endl;
    cout << "SIZE(20, 21):  " << bsST->size(20, 21) << endl;
    cout << "SIZE(20, 20):  " << bsST->size(20, 20) << endl;
    cout << "SIZE(14, 14):  " << bsST->size(14, 14) << endl;
    cout << "SIZE(19, 38):  " << bsST->size(19, 38) << endl;
    cout << "SIZE(19-1, 38+1):  " << bsST->size(19-1, 38+1) << endl;
    cout << "SIZE(19, 38):  " << bsST->size(19, 38) << endl;
    cout << "SIZE(13, 26):  " << bsST->size(13, 26) << endl;
    cout << "SIZE(12, 25):  " << bsST->size(12, 25) << endl;
    cout << "SIZE(25, 12):  " << bsST->size(25, 12) << endl;

    cout << endl << endl << "TESTING RANK() METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Rank of " << containedElements[j] << ":    " << bsST->rank(containedElements[j]) << endl;
    }

    cout << endl << endl << "TESTING SELECT(rk) METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Select key at: " << j+1 << ":    " << bsST->select(j+1) << endl;
    }

    cout << endl << endl << "TESTING LEVEL(KEY) METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        cout << "Level of " << containedElements[j] << ":    " << bsST->level(containedElements[j]) << endl;
    }

    cout << endl << endl << "TESTING GETVALUES(KEY) METHOD" << endl;
    for(int j = 0; j < numElements; j++){
        vector<int> v = bsST->getvalues(containedElements[j]);
        int sz = v.size();

        //cout << "sz: " << sz << endl;

        cout << "Values of " << containedElements[j] << ":    ";
        for(int l = 0; l < sz; l++) cout << v[l]  << " ";
        cout << endl;
    }

    cout << endl << endl;

delete bsST;}


void testgraphbasics(){
    Graph g1;
    Graph g2(10);

    cout << endl << endl;
    cout << "IsEmpty test" << endl;
    cout << "G1 should be true: " << g1.isEmpty() << endl;
    cout << "G2 should be false: " << g2.isEmpty() << endl;
    cout << endl;

    cout << "Adding nodes with and withou color" << endl;
    g1.addNode();
    g1.addNode();
    g1.addNode();
    g1.addNode(1);
    g1.addNode(2);
    
    cout << endl;
    cout << "Node count test" << endl;
    cout << "G1 should be 5: " << g1.nodeCount() << endl;
    cout << "G2 should be 10: " << g2.nodeCount() << endl;

    cout << endl;
    cout << "Deleting nodes" << endl;
    g1.delNode(0);
    g1.delNode(1);

    cout << endl;
}



#endif