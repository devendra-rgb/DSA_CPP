#include<stdio.h>
#include<iostream>
#include<string.h>
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



char pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
        return '0';
    }

    else
    {
        struct Node *p;
        p=top;
        int x=p->data;
        top=p->next;
        delete p;
        return x;
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



int isEmpty(struct Node * top)
{
    if(top==NULL)
    return 1;
    else
    return 0;
}

//Function for Precedence
int pre(char x)
{
    if(x=='+' || x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 2; 

    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    return 0;
    else 
    return 1;
}

char * InToPost(char *infix)
{
    int i=0,j=0;
    int len=strlen(infix)+2;
    char *postfix;
    postfix=new char[len*(sizeof(char))];

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }

        else
        {
            
            if(pre(infix[i])>pre(top->data))
            push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
            
        }
        
    }

    while(top->data!='#')
    {postfix[j++]=pop();
    };
    postfix[j]='\0';

    return postfix;



}


int Eval(char *postfix)
{

    int x1=0,x2=0,r=0;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i])==1)
        {
        push(postfix[i] -'0');
        }
        else
        {
            x2=pop();
            x1=pop();
            switch (postfix[i])
            {
            case '+':r=x1+x2;break;
            case '-':r=x1-x2; break;
            case '*':r=x1*x2; break;
            case '/':r=x1/x2;break;
            }
            push(r);
        }
    }

    return top->data;

}

int main()
{
    char * postfix="234*+82/-";
    //making sentinal node to  generalize Linked List;
    

    //char *postfix=InToPost(infix);
    cout<<Eval(postfix);
    return 0;
    


}