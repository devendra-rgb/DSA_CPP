#include<stdio.h>
#include<iostream>
using namespace std;


struct Node 
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

void preorder_transverse(struct Node *p)
{
    if(p)
    {
        preorder_transverse(p->lchild);
        cout<<p->data<<" ";
        preorder_transverse(p->rchild);
    }
}

int Nodeheight(struct Node *p)
{
    int Hr,Hl;
    Hr=p && p->rchild ? p->rchild->height:0;
    Hl=p && p->lchild ? p->lchild->height:0;
    return Hl>Hr? Hl+1:Hr+1;

}

int BalanceFactor(struct Node *p)
{
    int Hr,Hl;
    Hr=p && p->rchild ? p->rchild->height:0;
    Hl=p && p->lchild ? p->lchild->height:0;
    return Hl-Hr;
    
}
// Rotating left left 
struct Node * LLRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=p->lchild->rchild;
    
    pl->rchild=p;
    p->lchild=plr;
    p->height=Nodeheight(p);
    pl->height=Nodeheight(pl);
    
    if(root=p)
        root=pl;
    return pl;

}
//Rotating Righ Right
struct Node * RRRotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=p->rchild->lchild;
    
    pr->lchild=p;
    p->rchild=prl;
    p->height=Nodeheight(p);
    pr->height=Nodeheight(pr);
    
    if(root=p)
        root=pr;
    return pr;

}

//Rotating Left Right
struct Node * LRRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=p->lchild->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    
    plr->rchild=p;
    plr->lchild=pl;

    plr->height=Nodeheight(plr);
    p->height=Nodeheight(p);
    pl->height=Nodeheight(pl);
    
    if(root==p)
    root=plr;


    return plr;


}

//RL rotation
struct Node * RLRotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;

    prl->rchild=pr;
    prl->lchild=p;

    p->height=Nodeheight(p);
    pr->height=Nodeheight(pr);
    prl->height=Nodeheight(prl);

    if(root==p)
        root=prl;
    return prl;

}

struct Node * RInsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key>p->data)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    p->height=Nodeheight(p);//will pass height for the node

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    
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
    p->height=Nodeheight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
        
    return p;
}

int main()
{
    struct Node *i;
    //i=root;
    root=RInsert(root,5);
    RInsert(root,10);
    RInsert(root,8);
    preorder_transverse(root);
    i=root;
    cout<<"hello";
}