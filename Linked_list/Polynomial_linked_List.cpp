#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

struct Node{
    int coef;
    int exp;
    struct Node *next;
};

struct Node *first=NULL;

void create()
{
   int i=0,terms;
   struct Node * last,*t;
   cout<<"Enter the number of terms";
   cin>>terms;
   for(i=0;i<terms;i++)
   {    
       t=new Node;
       cout<<"Enter the coef and power of "<<i+1<<" ";
       cin>>t->coef>>t->exp;
       t->next=NULL;
        if(first==NULL)
        {
            first=t;
            last=t;
        }
        else
        {
         last->next=t;
         last=t;   
        }
   }
};

void Evaluate(int x)
{
    long sum=0 ;
    struct Node *p=first;
    while(p)
    {
        sum+=p->coef*pow(x,p->exp);
        p=p->next;
    };
    cout<<sum;
}
int main()
{
    create();
    Evaluate(1);
}