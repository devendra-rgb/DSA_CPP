#include<stdio.h>
#include<iostream>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
    
};


struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *p)
{  
    cout<<"Enter the dimension of the matrix"<<endl;
    cin>>p->m>>p->n>>p->num;
    p->e=new Element[p->num];
    for (int i=0;i<p->num;i++)
    {
        cin>>p->e[i].i>>p->e[i].j>>p->e[i].x;

    }


}

void display(struct Sparse e)
{
    int k=0;
    for (int i=1;i<=e.m;i++)
    {
        for(int j=1;j<=e.n;j++)
        {
            if(i==e.e[k].i && j==e.e[k].j)
                cout<<e.e[k++].x<<" ";
            else
            cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}

struct Sparse *  Add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    if (s2->m!=s1->m && s1->n!=s2->n)
    return NULL;
    sum=new  Sparse;
    sum->m=s1->m;
    sum->n=s1->n;
    sum->e=new Element[s1->num+s2->num];
    int i=0,j=0,k=0;
    while(i<s1->num && j<s2->num)
    {
        if(s1->e[i].i < s2->e[j].i)
        {   

            sum->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++]=s2->e[j++];
        }
        else
        {
            if(s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k]=s1->e[i++];
                sum->e[k++].x+=s2->e[j++].x;
            }
        }
    }
    
    for(;i<s1->num;i++)
    {
        sum->e[k++]=s1->e[i];
    }
    for(;j<s2->num;j++)
    {
        sum->e[k++]=s2->e[j];
    }

    sum->num=k;
    return sum;


}










int main()
{
struct Sparse s1,s2,*s3;
create(&s1);
display(s1);

create(&s2);
display(s2);

s3=Add(&s1,&s2);
display(*s3);

}