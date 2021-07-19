#include<iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

struct Node* Front=NULL;
struct Node * Rear=NULL;


void Enque(int element)
{
    struct Node *t=new Node;
    if(t==NULL)//if the t is Null means there is no space in the heap
    {
        cout<<"Que is full";
    }
    else
    {
        t->data=element;
        t->next=NULL;
        if(Front==NULL)
        {
            Front=Rear=t;
        }
        else
        {
            Rear->next=t;
            Rear=t;
        }
    }


}


void Deque()
{
    if(Front==NULL)
    return ;
    else
    {   struct Node *p=Front;
        Front=Front->next;
        delete p;
    }
}


void Display(struct Node *p)
{
    
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
   

}


int main()
{

    Enque(2);
    Enque(3);
    Enque(4);
    Enque(5);
    Display(Front);
    Deque();
    Display(Front);

}