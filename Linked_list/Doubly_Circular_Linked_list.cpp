#include<iostream>
using namespace std;


class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
};


class Circular_Doubly_Linked_list
{
    private:
    Node* first;
    public:
    
    Circular_Doubly_Linked_list()
    {
        first=NULL;
        
    }

    Circular_Doubly_Linked_list(int A[],int n);
    ~Circular_Doubly_Linked_list();
    void Delete(int index);
    void Insert(int index,int element);
    void Display();
    int Length();

};

Circular_Doubly_Linked_list  :: Circular_Doubly_Linked_list(int A[],int n)
{
    Node * t,*last;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=first;
    first->prev=first;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        last->next=t;
        t->prev=last;
        t->next=first;
        first->prev=t;
        last=t;
    }
        
};



Circular_Doubly_Linked_list::~Circular_Doubly_Linked_list()
{
    Node *p=first,*t;
    do
    {   t=p;
        cout<<"Deleted "<<p->data<<endl;
        delete t;
        p=p->next;

    }while(p!=first);

}

void Circular_Doubly_Linked_list::Display()
{
    Node *p=first;
    do
    {
        cout<<p->data<<' ';
        p=p->next;
    }while(p!=first);
    cout<<endl;
    
} ;


int Circular_Doubly_Linked_list::Length()
{   
    int count=0;
    Node *p=first;
    do
    {   
        count++;
        p=p->next;
    }while(p!=first);
    return count;
}

void Circular_Doubly_Linked_list::Insert(int index,int element)
{
    int i=0;
    Node *p=first;
    if(index<-1 || index>Length())
    return ;
    else if(index==1)
    {
        Node *t=new Node;
        t->data=element;
        first->prev->next=t;
        t->next=first;
        t->prev=first->prev;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=1;i<index;i++)
        {
            p=p->next;
        };
        Node *t=new Node;
        t->data=element;
        t->next=p->next;
        p->next->prev=t;
        t->prev=p;
        p->next=t;
    }
}


void Circular_Doubly_Linked_list::Delete(int index)
{
    int i=0;
    Node *p=first;
    for(i=0;i<index-1;i++)
    {
        p=p->next;

    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    int x=p->data;
    first=p->next;
    delete p;
    
}


int main()
{
    int A[]={1,2,3,4,5};
    Circular_Doubly_Linked_list LinkedList(A,5);
    LinkedList.Insert(1,60);
    LinkedList.Delete(1);
    LinkedList.Display();

    
}