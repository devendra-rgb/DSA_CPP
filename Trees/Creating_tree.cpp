#include<stdio.h>
#include<iostream>
#include "que.h"
using namespace std;


class Tree
{
    public:
    Node *root;
    Que que;
    Tree(){root=NULL;};
    
    void create_tree();
    void preOrder(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void levelOrder(Node *p);
    int Height(Node *root);
    int Count(Node *root);
    int LeafNodes(Node *p);
    int Degree2(Node *p);
    int Degree1(Node *p);
    int Degree1Or2(Node *p);
};


void Tree::create_tree()
{
    int data=0,value=0;
    Node *p,*t;
    cout<<"Enter the Root Value ";
    cin>>data;
    root=new Node;
    root->data=data;
    root->lchild=root->rchild=NULL;
    que.Enque(root);

    while(que.isEmpty() != 1)
    {
        p=que.Deque();
        
        cout<<"Enter the Left child of "<<p->data<<" ";
        cin>>value;
        if(value!=-1)
        {
            t=new Node;
            t->data=value;
            t->lchild=t->rchild=NULL;
            que.Enque(t);//Adding adress to que
            p->lchild=t;//Assigining Right child to it's parent
        }
        
        
        cout<<"Enter the Right child of "<<p->data<<" ";
        cin>>value;
        if(value!=-1)//if it is -1 then stopping adding the childs
        {
            t=new Node;
            t->data=value;
            t->lchild=t->rchild=NULL;
            que.Enque(t);//Adding adress to que
            p->rchild=t;//Assigining Right child to it's parent
        }
       

        
    }

}


void Tree :: preOrder(Node *p)
{
    if(p)

    {
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree :: postOrder(Node *p)
{
    if(p)
    {
        
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}


void Tree :: inOrder(Node *p)
{
    if(p)
    {
        
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}


void Tree::levelOrder(Node *root)
{

    Que que2(100);
    cout<<root->data<<" ";
    que2.Enque(root);

    while(que2.isEmpty() != 1 )
    {
        root=que2.Deque();

        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            que2.Enque(root->lchild);

        }

        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            que2.Enque(root->rchild);

        }
    }

}



int Tree::Height(Node*root)
{
    int x=0,y=0;
    if(root==0)
    {
        return -1;
    }
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
    return (x+1);
    else
    return (y+1);

}


int Tree:: Count(Node *root)
{
    if(root)
    {
        return Count(root->lchild)+Count(root->rchild)+1;
    }
    return 0;
}

//counting Leaf Nodes

int Tree::LeafNodes(Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=LeafNodes(p->lchild);
        y=LeafNodes(p->rchild); 
        
        if(p->lchild==NULL && p->rchild==NULL)
        {
            return x+y+1;
        }   

        else
        {
        return x+y;
        }
    }
    return 0;
    
}


int Tree::Degree1Or2(Node *p)
{
    int x=0,y=0;
    if(p)
    {

        x=Degree1Or2(p->lchild);
        y=Degree1Or2(p->rchild);

        if(p->lchild!=NULL || p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}


int Tree::Degree2(Node *p)
{
    int x=0,y=0;
    if(p)
    {

        x=Degree2(p->lchild);
        y=Degree2(p->rchild);

        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}


int Tree::Degree1(Node *p)
{
    int x=0,y=0;
    if(p)
    {

        x=Degree1(p->lchild);
        y=Degree1(p->rchild);

        if(p->lchild!=NULL ^ p->rchild!=NULL)
        {
            return x+y+1;
        }

        else
        {
            return x+y;
        }
    }
    return 0;
    
}





int main()
{

Tree BinaryTree;
BinaryTree.create_tree();

cout<<"In order ";
BinaryTree.inOrder(BinaryTree.root);
cout<<endl;

cout<<"Post order ";
BinaryTree.postOrder(BinaryTree.root);
cout<<endl;

cout<<"Pre order ";
BinaryTree.preOrder(BinaryTree.root);
cout<<endl;


cout<<"Level order ";
BinaryTree.levelOrder(BinaryTree.root);
cout<<endl;


cout<<"Count of Binary Tree  "<<BinaryTree.Count(BinaryTree.root)<<endl;

cout<<"Height of Binary Tree  "<<BinaryTree.Height(BinaryTree.root)<<endl;

cout<<"Degree1 of Binary Tree "<<BinaryTree.Degree1(BinaryTree.root)<<endl;

cout<<"Degree2 of Binary Tree "<<BinaryTree.Degree2(BinaryTree.root)<<endl;

cout<<"Degree1Or2 of Binary Tree "<<BinaryTree.Degree1Or2(BinaryTree.root)<<endl;

cout<<"Leaf Nodes of Binary Tree "<<BinaryTree.LeafNodes(BinaryTree.root)<<endl;



}