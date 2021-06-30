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
    private:
    Node * first;
    public:
    LinkedList(){first=NULL;};
    LinkedList(int A[],int n);
    ~LinkedList();

    void Middle();
    void Display();
};

void LinkedList::Display()
{
    Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
};

LinkedList::LinkedList(int A[],int n)
{
    int i=0;
    Node *last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;


    for(i=1;i<n;i++)
    {
        Node *t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
};


LinkedList::~LinkedList()
{

};


void LinkedList::Middle()
{
    Node *p,*q;
    p=q=first;
    while(q->next!=NULL)
    {
        q=q->next;
        if(q->next!=NULL)
        q=q->next;
        p=p->next;

         
    }
    cout<<endl;
    cout<<p->data;
};
int main()
{
    int A[]={1,2,3,4,5};
    LinkedList list(A,5);
    list.Display();
    list.Middle();


}