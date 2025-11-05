#include <iostream>
using namespace std;

typedef struct
{
    int element[8];
    int front, rear;
} queue;

queue init()
{
    queue Q;
    Q.front = Q.rear = -1;
    return Q;
}

int isFull(queue Q)
{
    return (Q.front == (Q.rear + 1) % 8);
}
int isEmpty(queue Q)
{
    return (Q.front == Q.rear && Q.rear == -1);
}
queue enqueue(queue Q, int x)
{
    if (isFull(Q))
    {
        cout << "OVERFLOW\n";
    }
    else if (isEmpty(Q))
    {
        Q.front = Q.rear = 0;
        Q.element[Q.rear]=x;
    }
    else{
        Q.rear=(Q.rear+1)%8;
        Q.element[Q.rear]=x;
    }
    return Q;
}

queue dequeue(queue Q){
    if(isEmpty(Q)){
        cout<<"UNDERFLOW\n";
    }
    else if(Q.front==Q.rear){
        Q.front=Q.rear=-1;
    }
    else{
        Q.front=(Q.front+1)%8;
    }
    return Q;
}
void display(queue Q)
{
    int i;
    for (i = Q.front; i <= Q.rear; i++)
    {
        cout << Q.element[i] << "\n";
    }
}

void peek(queue Q)
{
    cout <<"Element at front is: "<< Q.element[Q.front];
}
int main()
{
    queue Q = init();
    Q = enqueue(Q, 4);
    Q = enqueue(Q, 7);
    Q = enqueue(Q, 11);
    Q = enqueue(Q, 20);
    Q = enqueue(Q, 5);
    Q = enqueue(Q, 9);
    display(Q);
    
    display(Q);

    return 0;
}