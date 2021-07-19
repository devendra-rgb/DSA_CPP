#include<stdio.h>
#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{

    public:
    Node *first;
    LinkedList()
    {Node *first=NULL;};
    LinkedList(int A[],int n);
    void Delete(int Element);
    void Display();
};

 LinkedList::LinkedList(int A[],int n)
{
    Node *last,*t;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    };

}


void LinkedList::Display()
{
    Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}


void LinkedList::Delete(int n)
{
    Node*p=first;Node *q=NULL;Node *d;

    if(p->data==n)
    {
        p=p->next;
        first=p;
    }
    else
    {

        while(p!=NULL)
        {
            q=p;
            p=p->next;
            if(p->data==n)
            {
                d=p;
                q->next=p->next;
                delete d;
                break;
            }
            

        }
    }

    
}

int main()
{
 int A[]={1,2,3,4,5};
 LinkedList a(A,5);
 a.Delete(1);
 a.Display();
 
}