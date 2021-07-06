#include<stdio.h>
#include<iostream>
using namespace std;


struct Que{
    int front;
    int rear;
    int size;
    int *q;

};


int  Deque(struct Que *Q)
{

    if(Q->rear==Q->front)
    {
        cout<<"The Que is Empty ";
        return 0;
    }
    else
    {
        
        Q->front++;
        int X=Q->q[Q->front];
        return X;
    }
};



void Enque(struct Que *Q,int element)
{
    if(Q->size-1==Q->rear)
    {   
        cout<<"Que is Full";
        return ;
    }
    else
    {
        Q->rear++;
        Q->q[Q->rear]=element;
        return;
    }
}


void Display(struct Que *Q)
{
    for(int i=0;i<Q->size;i++)
    {
        cout<<Q->q[i]<<" ";
    }
};


int main()
{


    struct Que q;
    q.size=5;
    q.front=-1;
    q.rear=-1;
    q.q=new int[q.size];

    Enque(&q,1);
    Enque(&q,2);
    Enque(&q,3);
    Enque(&q,4);
    Enque(&q,5);
    Display(&q);
    cout<< Deque(&q);
    cout<< Deque(&q);
    cout<< Deque(&q);
    cout<< Deque(&q);
    cout<< Deque(&q);
    
    






}