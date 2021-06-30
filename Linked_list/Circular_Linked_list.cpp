#include<iostream>
#include<stdio.h>
using namespace std;


struct Node{
    int data;
    Node *next;
};

struct Node *Head;

void create(int A[],int n)
{   
    Head=new Node;
    struct Node *last,*t;
    int i=0;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}


void Display(struct Node *p)
{

    do
    {
        cout<<p->data<<' ';
        p=p->next;
        
    } while (p!=Head /* condition */);
    
}
//Recursively Displaying of Linked List
void rDisplay(struct Node *p)
{   
    static int flag=0;
    if(p!=Head || flag==0)
    {
        cout<<p->data<<" ";
        flag=1;
        p=p->next;
        rDisplay(p);
        
    }
    flag=0;
};

//finding length of the circulr Linked list
int length()
{   
    struct Node *p;
    p=Head;
    int count=0;
    do{
        count++;
        p=p->next;
    } while (p!=Head);
    return count;
}
//Inserting an element in circular linked list
void Insert(struct Node *p,int index,int element )
{   
    int i=0;
    struct Node *t;
    if(index<-1 || index >length())
    {
        return;
    }

    else if(index==0)
    {
        t=new Node;
        t->data=element;
        do
        {
            p=p->next;
        } while (p->next!=Head);

        p->next=t;
        t->next=Head;
        Head=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;

        };
        t= new Node;
        t->data=element;
        t->next=p->next;
        p->next=t;

    
    }

}


//Deleting from  Linked List
void Delete(struct Node *p,int index)
{
    int i=0,x=0;
    if(index==1)
    {
        
        while(p->next!=Head)
        {
            p=p->next;
            
        }
        p->next=Head->next;
        delete Head;
        Head=p->next;

        if(p==Head)
        {
            delete Head;
            Head =NULL;
        }
    }

    else 
    {
        struct Node *q;
        for(int i=0;i<index-2;i++)
        {
           p = p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
        
    }
}


int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
   // Display(Head);

   Insert(Head,5,88);
    Delete(Head,1);
    rDisplay(Head);

}