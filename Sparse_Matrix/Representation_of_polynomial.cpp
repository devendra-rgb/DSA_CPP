#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
struct Term
{
    int coef;
    int exp;

};
struct Poly
{
    int n;
    struct Term *e;
};


void display(struct Poly e)
{
    for(int i=0;i<e.n;i++)
    {
        printf("%dx%d+",e.e[i].coef,e.e[i].exp);
    }
    cout<<endl;
}

struct Poly * add(struct Poly *p1,struct Poly *p2)
{
    struct Poly *p3;
    p3->n=p1->n+p2->n;
    p3->e=new Term[p3->n];
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n)

    { 
        if(p1->e[i].exp==p2->e[j].exp)
        {
            p3->e[k].exp=p1->e[i].exp+p2->e[j].exp;
            p3->e[k++].coef=p1->e[i++].coef+p2->e[j++].coef;
        }
        
        else if(p1->e[i].exp>p2->e[j].exp)
        {
            p3->e[k++]=p1->e[i++];

        }
        else if(p1->e[i].exp<p2->e[j].exp)
        {
            p3->e[k++]=p2->e[j++];

        }

    }
    
    for(;i<=p1->n;i++)
    {
        p3->e[k++]=p1->e[i];
    }

    for(;j<=p2->n;j++)
    {
        p3->e[k++]=p2->e[i];
    }


    p3->n=k;
    
    return p3;
};









int main()
{   
    int x;
    struct Poly p1,p2,*p3;
    p1.n=3;
    p1.e=new Term[p1.n];
    for (int i=0;i<p1.n;i++)
    {
        cout<<"Enter the coef"<<endl;
        cin>>p1.e[i].coef;
        cout<<"Enter the exp"<<endl;
        cin>>p1.e[i].exp;

    }

    p2.n=4;
    p2.e=new Term[p2.n];
    for (int i=0;i<p2.n;i++)
    {
        cout<<"Enter the 2ndcoef"<<endl;
        cin>>p2.e[i].coef;
        cout<<"Enter the 2nd exp"<<endl;
        cin>>p2.e[i].exp;

    }
    display(p1);
    display(p2);
    p3=add(&p1,&p2);
    display(*p3);

   /* //Getting the sum of polynomials
    p3=add(&p1,&p2);
    cout<<"Enter the value of X";
    cin>>x;
    int sum=0;
    for (int j=0;j<p3->n;j++)
    {   cout<<p3->e[j].coef*x<<endl;
        sum+=p3->e[j].coef*pow(x,p3->e[j].exp); 
    }
    cout<<sum;
    
        */
}