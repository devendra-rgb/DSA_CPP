#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    Node * prev;
    int data;
    Node * next;
};
struct Node *first,*last;

void create(int A[],int n)
{
    struct Node *t;
    int i=0;
    first=new Node;
    first->data=A[i];
    first->prev=NULL;
    first->next=NULL;
    last=first;

    for (i=1;i<=n;i++)
    {
        t=new Node ;
        t->data=A[i];
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


//Length of a Doubly Linked List
int length()
{
    int count=0;
    struct Node*p=first;
    while(p->next!=NULL)
   {  count++;
      p=p->next;
   }
   return count;
}




//Inserting Doubly LinkedList
void Insert(struct Node *p,int index,int element)
{
    int i=0;
    struct Node *t;

    if(index < -1 || index > length())
    return ;

    else if(index==0)
    {
        t=new Node;
        t->data=element;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else
    {
        //here we should iterate one position to reach exact location
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }

        t=new Node;
        t->data=element;
        t->next=p->next;
        t->prev=p;
        if(p->next!=NULL)
        p->next->prev=t;
        p->next=t;
    }

}


//Deleting In Doubly Linked List
void Delete(struct Node *p,int index)
{   
    struct Node *t;

    if(index<-1 || index>length())
    return ;

    else if(index==1)
    {
        t=p->next;
        t->prev=NULL;
        first=t;
    }
    
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        //Using double Pointer
        /*t=p->prev;
        t->next=p->next;
        p->next->prev=t;
        delete p;*/

        p->prev->next=p->next;// Using single Pointer 
        if(p->next)
        p->next->prev=p->prev;
        delete p;
    }
}



//Reversing an Doubly LinkedList by swaping the pointers

void Reverse(struct Node *p)
{
    p=first;
    struct Node *temp;
    while(p!=NULL)
    {
     temp=p->next;
     p->next=p->prev;
     p->prev=temp; 
     p=p->prev;
    if(p!=NULL && p->next==NULL)
    first=p;
    }
    
}

//Displaying the Doubly LinkedList
void Display(struct Node *p)
{   

     while(p)
     {
        p=p->next;
        cout<<p->data<<" ";
        
     }
}
int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    //Insert(first,3,66);
    Reverse(first);
    //Delete(first,5);
    Display(first);
}