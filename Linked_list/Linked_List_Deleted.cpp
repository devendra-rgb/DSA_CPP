#include<iostream>
using namespace std;



struct Node
{   
    int data;
    struct Node * next;
};


struct Node *first=NULL;
//struct Node *last;

//Creating Linked List
void create(int A[],int n)
{
    
    struct Node *last,*t;
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
    }
}




void Display(struct Node *p)
{   //this is how we transverse a linked list
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

void Delete(struct Node *p,int element )
{
    struct Node *q=NULL,*g=p;
    while(p)
    {
    
    }
    Display(g);



};

int main()
{
    int A[]={1,2,6,3,4,5,6};
    struct Node *a;
    create(A,7);
    Delete(first,1);  
    
    
}