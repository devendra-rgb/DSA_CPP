#include<stdio.h>
#include<iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchld;
}*root=NULL;

struct Node * Delete(struct Node *p,int key)
{
    struct Node *q;
    if(key>p->data)
        Delete(p->rchild,key);
    else if (key<p->data)
        Delete(p->lchild,key);


    else
    {
        if(Height(p->lchild)>Height(p->rchild))
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