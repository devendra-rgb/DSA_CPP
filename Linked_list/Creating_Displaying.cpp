#include<iostream>
using namespace std;

struct Node
{   
    int data;
    struct Node * next;
};


struct Node *first=NULL,*second=NULL,*third=NULL;
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


//second Linked List
void create2(int A[],int n)
{
    
    struct Node *last,*t;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

//Using while loop
void Display(struct Node *p)
{   //this is how we transverse a linked list
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

//Using recursion for display forward

void Rdisplay_forward(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Rdisplay_forward(p->next);
    }
}


//Using Recursion to display reverse

void Rdisplay_reverse(struct Node *p)
{
    if(p!=NULL)
    {
        Rdisplay_reverse(p->next);
        printf("%d ",p->data);
    }
}


//Using Recusrion to Count the nodes in the linked list
int count(struct Node *p)
{
    if(p==0)
    return 0;
    else
    return count(p->next)+1;
}

//Using Loop to Add the linked list
int add(struct Node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//Using Recursion to add Linked list
int Radd(struct Node *p)
{
    if(p==0)
    return 0;
    else
    return Radd(p->next)+p->data;
}

//Using Recursion for finding Maximum in a Linked list
int max(struct Node *p)
{
    int x=0;
    if(p==0)
    return INT32_MIN;
    x=max(p->next);
    return x>p->data?x:p->data;//We used terinary operator here to reduce statements

}

//Searching in a Linked List using Recursion
Node * Rsearch(struct Node *p,int key)
{
    if(p==0)
    return NULL;
    if(key==p->data)
    return p;
    return Rsearch(p->next,key);
}

//Searching in a Linked list with Move Head method

Node * Headsearch(struct Node *p,int key)
{
    struct Node *q=NULL;
    while(p!=0)
    {
        if(p->data==key)
        {
            if(p==first)//condition for fist element as we don't have anything to move
            return p;
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }

        q=p;
        p=p->next;
    }
    return NULL;
}


//Inserting in a linked list
void insert(struct Node *p,int index,int element)
{
    int i;
    struct Node *t;
    if(index<0 || index>count(p))
    return;
    t=new Node;
    t->data=element;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }

    
}


//Inserting Linked List at last 
void last_Inesert(int element)
{   
    
    struct Node *t,*last=NULL;
    t=new Node;
    t->data=element;
    t->next=NULL;
    if(first==NULL)
    {
        last=first=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}




//Inserting in Sorted LinkedList
void Sorted_insert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    
    else
    {
            while(p!=NULL && p->data<x)
            {
                q=p;
                p=p->next;
            }
            if(p==first)
            {
                t->next=first;
                first=t;

            }
            else
            {
                t->next=q->next;
                q->next=t;
            }
    }
}

//Deleting in Linked List
void Delete(struct Node *p,int index)
{
struct Node *q=NULL;

    if(index==1)
    {   
        q=first;
        int x=q->data;
        first=first->next;
        delete q;
    }
else{ 
    for(int i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;
    }
}

//Checking Linked List is Sorted

void is_Sorted(struct Node *p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            cout<<"Not Sorted";
            return;
        }
        else
        { 
            x=p->data;
            p=p->next;
        }
    }
    cout<<"Sorted";
    return;
}

//Removing Duplicates from a Linked List

void remove_Duplicates(struct Node *p)
{
    struct Node *q;
    q=p->next;
while(q!=NULL)
{ 
    if(p->data!=q->data)
    {
        p=q;
        q=q->next;
    }

    else
    {
        p->next=q->next;
        delete q;
        q=p->next;
    }
}
}

//Sliding Pointers for Reversing linked list

void slideReverse(struct Node* p)
{   
    struct Node *r=NULL,*q=NULL;
    while(p!=NULL)
    {   
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}






//Recursive Reverse of Linked List

void rReverse(struct Node *q,struct Node *p)
{
    if(p!=NULL)
    {
        rReverse(p,p->next);//here we are passing sliding pointers
        p->next=q; //While Returning the links will be changed

    }

    else
    {
        first=q;//when we reached the last we are making it as first

    }
}



//concatenation of two link lists
void concatenate(struct Node *p,struct Node *q)
{   third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;

}

void  Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }

    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;

    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
        
        last->next=p;
        last=p;
        p=p->next;
        last->next=NULL;
        }
        else
        {
        last->next=q;
        last=q;
        q=q->next;
        last->next=NULL;

        }

    }

    if(p)
    {
        last->next=p;
    }

    if(q)
    {
        last->next=q;
    }
}



//Checking Loop of a LinkedList
int isLoop(struct Node *f)
{
    struct Node *q,*p;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
        
    } while (p && q && p!=q);

    if(p==q)
    return 1;
    else 
    return 0;
    
}



int main()
{   struct Node * q=NULL;
    int A[]={2,4,6,8,10};
    int B[]={3,7,9,12,15};
    //creating a loop
    create(A,5);
    struct Node *t1,*t2;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first);


}