#include<iostream>
using namespace std;

class Diagnol
{
    private:
    int *p;
    int n;
    public:

    Diagnol()
    {
        n=2;
        p=new int[n];
    }
    Diagnol(int n)
    {   this->n=n;
        p=new int[n];
    }
    
    ~ Diagnol()
    {
     delete [] p;
    }

    void set(int i,int j,int num);
    int  get(int i,int j);
    void display();
};


void Diagnol::set(int i,int j,int num)
{
    if(i==j)
    {
        p[i-1]=num;
    }
}


int Diagnol::get(int i,int j)
{
    if(i==j)
    return p[i-1];
    else
    return 0;   
}


void Diagnol:: display()
{
    for (int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        { 
          if(i==j)
          cout<<p[i]<<" ";
          else
          cout<<"0 ";
        }
        cout<<endl;
    }
}


int main()
{
    Diagnol hello(5);
    hello.set(1,1,5);
    hello.set(2,2,5);
    hello.set(3,3,5);
    hello.set(4,4,5);
    hello.set(5,5,5);
    
    hello.get(2,2);
    hello.display();

}