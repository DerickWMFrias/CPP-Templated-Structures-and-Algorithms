#include <vector>
#include <iostream>

#include "structures.h"

void testqueue();
void teststack();
void testminheap(){return;}
void testmaxheap(){return;}
void testgraph(){return;}
void testunionfind(){return;}
void testbstree(){return;}
void testbstreeST(){return;}
void testarbtree(){return;}
void testarbtreeST(){return;}

int main() {
    int invalidCounter = 0;
    bool stop = false;

    while(!stop){
        int i;
        cout << "What do you want to do?" << endl;
        cout << "0: EXIT";
        cout << "1: RUN QUEUE TEST";
        cout << "2: RUN STACK TEST";
        cout << "3: RUN MINHEAP TEST";
        cout << "4: RUN MAXHEAP TEST";
        cout << "5: RUN GRAPH TEST";
        cout << "6: RUN U.F TEST";
        cout << "7: RUN BINARY SEARCH TREE TEST";
        cout << "8: RUN ST BINARY SEARCH TREE TEST";
        cout << "9: RUN RED-BLACK TREE TEST";
        cout << "10: RUN ST RED-BLACK TREE TEST";
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
                testgraph();
                invalidCounter = 0;
            break;
            case 6:
                testunionfind();
                invalidCounter = 0;
            break;
            case 7:
                testbstree();
                invalidCounter = 0;
            break;
            case 8:
                testbstreeST();
                invalidCounter = 0;
            break;
            case 9:
                testarbtree();
                invalidCounter = 0;
            break;
            case 10:
                testarbtreeST();
                invalidCounter = 0;
            break;
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






void testqueue() {
    queue<int> q;
    int i = 0;

    cout << endl << endl;
    cout << "TEST MODULE FOR QUEUE<INT>" << endl << "STARTING" << endl << endl;

    q.enqueue(1);
    q.dump();
    q.enqueue(2);
    q.dump();
    q.enqueue(3);
    q.dump();
    q.enqueue(4);
    q.dump();
    i = q.dequeue();
    cout << "Popped: " << i << endl;
    i = q.dequeue();
    cout << "Popped: " << i << endl;
    q.enqueue(90);
    q.dump();
    q.clear();
    i = q.dequeue();
    cout << "isempty: " << q.isempty() << endl;
    q.enqueue(90);
    cout << "isempty: " << q.isempty() << endl;
    q.dump();
    for (int j = 0; j < 40; j++) {
        q.enqueue(j);
    }
    cout << q.howmany() << endl;
    q.dump();
    q.clear();
    cout << q.howmany() << endl;

}

void teststack() {
    stack<int> stk;
    int i;

    cout << "TEST MODULE FOR STACK<INT>" << endl << "STARTING" << endl << endl;

    stk.push(1);
    stk.dump();
    stk.push(2);
    stk.dump();
    stk.push(3);
    stk.dump();
    stk.push(4);
    stk.dump();
    i = stk.pop();
    cout << "Popped: " << i << endl;
    i = stk.pop();
    cout << "Popped: " << i << endl;
    stk.push(90);
    stk.dump();
    stk.clear();
    i = stk.pop();
    cout << "isempty: " << stk.isempty() << endl;
    stk.push(90);
    cout << "isempty: " << stk.isempty() << endl;
    stk.dump();
    for (int j = 0; j < 40; j++) {
        stk.push(j);
    }
    cout << stk.howmany() << endl;
    stk.dump();
    stk.clear();
    cout << stk.howmany() << endl;

}