#include<stdio.h>
#include<iostream>
using namespace std;


struct Node
{
   struct  Node *lchild;
    int data;
   struct Node *rchild;
} *root=NULL;//Creating global pointer 


void Insert(int key)
{
    struct Node *p=NULL,*r=NULL;
    struct Node *q=root;

    if(q==NULL)
    {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return ;
    }

    else
    {
        while(q!=NULL)
        {
           r=q;
           if(key<q->data)
           q=q->lchild;

           else if (key>q->data)
           q=q->rchild;

           else
           return;
           
        }
    }

    if(key>r->data)
    {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        r->rchild=p;
    }
    else
    {

        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        r->lchild=p;
    }
}


void Inorder(struct Node *root)
{
    if(root)
    {
    Inorder(root->lchild);
    cout<<(root->data)<<" ";
    Inorder(root->rchild);
    }
}


struct Node *  search(int key)
{
    struct Node * q=root;
    while(q!=NULL)
        {
           
           if(key<q->data)
           q=q->lchild;

           else if (key>q->data)
           q=q->rchild;

           else
           return q;
           
        }
    return NULL;
}

struct Node * Rsearch(struct Node *t,int key)
{
    if(t==NULL)
    return NULL;

    if(t->data==key)
    return t;

    else if(key<t->data)
    return Rsearch(t->lchild,key);

    else if(key>t->data)
    return Rsearch(t->rchild,key);
}

struct Node * RInsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {   t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    if(key>p->data)
    p->rchild=RInsert(p->rchild,key);

    else if(key<p->data);
    p->lchild=RInsert(p->lchild,key);

    return t;
}

//Recursive Delete of BST


int Height(struct Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);

    return x>y? x+1: y+1;
}

struct Node * InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;

    return p;
}

struct Node * InSuccessor(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;

    return p;
}

struct Node * Delete(struct Node *p,int key)
{
    struct Node *q;

    if(p==NULL)
    return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }

    //struct Node *q;
    if(key>p->data)
        p->rchild=Delete(p->rchild,key); //taking the pointer to the exact Node to delete it
    else if(key<p->data)
        p->lchild=Delete(p->lchild,key);


    else
    {
        if(Height(p->lchild)>Height(p->rchild)) //comparing the heights to select the 
                                                // Inorder precessoder and successor
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSuccessor(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
}

//Generatin BST from Preorder
void createPre(int A[],int n)
{
    
}

int main()
{
    struct Node *ad=NULL,*p;
    Insert(50);
    Insert(10);
    Insert(40);
    Insert(20);
    Insert(30); 
    Delete(root,50);
    ad=Rsearch(root,50);

    if(ad!=NULL)
    {
        cout<<"Element is  found  at address "<<ad<<" "<<ad->data;
    }
    else
    {
        cout<<"Element Not found ";
    }
    //Inorder(root);


}