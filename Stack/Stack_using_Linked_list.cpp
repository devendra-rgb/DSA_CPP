#include<stdio.h>
#include<iostream>
using namespace std;


struct Node
{
    int data;
   struct  Node *next;
};

struct Node *top=NULL;


void push(int element)
{
    
    if(top==NULL)
    {   
        struct Node *t=new Node;
        t->data=element;
        t->next=NULL;
        top=t;
    }
    else
    {
        struct Node *t;
        t=new Node;
        t->data=element;
        t->next=top;
        top=t;
    }
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
        return;
    }

    else
    {
        struct Node *p;
        p=top;
        top=p->next;
        delete p;
    }
}


void Display()
{
    struct Node *p=top;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    };
    }
    



int main()
{
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    pop();
    Display();


}