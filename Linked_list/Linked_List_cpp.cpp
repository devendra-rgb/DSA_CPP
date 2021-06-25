#include<iostream>
using namespace std;

//class for a single node;

class Node
{
    public:
    int data;
    Node *next;
};
// creating a linked list through this class
class LinkedList
{
    private:
    Node *first;
    public:
    LinkedList(){first=NULL;}
    LinkedList(int A[],int n);
    ~LinkedList();

    void Display();
    void Insert(int index,int x);
    int Length();
    int Delete(int index);
    void Reverse();
    void rReverse();

};



LinkedList::LinkedList(int A[],int n)
{   
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {   
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
};

void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
        
    }
}

void LinkedList::Insert(int index,int x)
{
    Node *p=first,*t;
    t=new Node;
    t->data=x;
    t->next=NULL;
    for(int i=1;i<index-1;i++)
    {
        p=p->next;

    }
    t->next=p->next;
    p->next=t;
}

int LinkedList::Length()
{
    int count=0;
    Node *p=first;
    while(p)
    {
        count++;
        p=p->next;
    };
    cout<<endl<<count;;
}


int LinkedList::Delete(int index)
{
    Node *q,*p=first;
    int i=0;

    if(index==1)
    {   q=first;
        first=first->next;
        delete q;
    }

    else{
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }

}
void LinkedList::Reverse()
{
    Node *r=NULL,*q=NULL,*p=first;
    
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}



int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    Node *q=NULL;
    l.Reverse();
    l.Display();
    l.Length();

}
