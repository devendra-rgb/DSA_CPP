#ifndef que_h
#define que_h
#include<iostream>
#include<stdio.h>
using namespace std;

class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Que
{
    public:
        int front;
        int rear;
        int size;
        Node **q;
    public:
        Que(){front=rear=-1;size=100;q=new Node *[size];};
        Que(int size){front=rear=-1;this->size=size;q=new Node * [this->size];};

        void Display();
        Node * Deque();
        void Enque(Node * element);
        int isEmpty();
};


void Que::Display()
{
    
    for(int i=front+1;i<=rear;i++)
    {cout<<q[i]<<' '; };
    cout<<endl;
}


int Que::isEmpty()
{
    if(front==rear)
    return 1;
    else
    return 0;
}
void Que::Enque(Node * element)
{
    if(rear==size-1)
    {
        cout<<"The Que is full";
        return;
    }
    else
    {
        rear++;
        q[rear]=element;
    }
}

Node * Que::Deque()
{

    Node *x=NULL;
    if(front==rear)
    {
        cout<<"The Que is empty no item to be deleted";
        
    }
    else
    {
        
        x= q[front+1];
        front++;
    }
    return x;
}

#endif