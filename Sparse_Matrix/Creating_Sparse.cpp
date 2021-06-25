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
}




int main()
{
struct Sparse mat;
create(&mat);
display(mat);
}