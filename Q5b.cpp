//using 1 queue

#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x){
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }    

    void pop() {
        if(q.empty()) cout << "Stack empty!\n";
        else q.pop();
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }

    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
}
