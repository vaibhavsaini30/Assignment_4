#include <iostream>
using namespace std;
#define max 100

typedef struct
{
    int element[max];
    int front, rear;
} queue;

queue init()
{
    queue Q;
    Q.front = Q.rear = -1;
    return Q;
}
int isEmpty(queue Q)
{
    return (Q.front == -1 || Q.front > Q.rear);
}

int isFull(queue Q)
{
    return (Q.rear == max - 1);
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
        Q.element[Q.rear] = x;
    }
    else
    {
        ++Q.rear;
        Q.element[Q.rear] = x;
    }
    return Q;
}

queue dequeue(queue Q)
{
    if (isEmpty(Q))
    {
        cout << "UNDERFLOW\n";
    }
    else
    {
        Q.front = Q.front + 1;
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
    
    return 0;
}