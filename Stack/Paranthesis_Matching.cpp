#include<stdio.h>
#include<iostream>
using namespace std;


struct Node
{
    char data;
   struct  Node *next;
};

struct Node *top=NULL;


void push(char element)
{
    
    if(top==NULL)
    {   
        struct Node *t=new Node;
        t->data=element;
        t->next=NULL;
        top=t;
    }
    else
    {
        struct Node *t;
        t=new Node;
        t->data=element;
        t->next=top;
        top=t;
    }
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
        return;
    }

    else
    {
        struct Node *p;
        p=top;
        top=p->next;
        delete p;
    }
}


void Display()
{
    struct Node *p=top;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    };
    }
    
int isBalanced(char *exp)
{
    int i=0;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push('(');
        }
        else if(exp[i]==')')
        {
            if(top==NULL)
            return  0;
            
            pop();
        }

    }
    if(top==NULL)
    {
        cout<<"Balanced";
        return 1; 
    }

    else
    {   cout<<"UnBalanced";
        return 0;
    }
}


int main()
{
    char *exp="(((a+b)*(b+c))";
    isBalanced(exp);


}