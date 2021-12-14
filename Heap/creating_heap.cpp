#include<stdio.h>
#include<iostream>
using namespace std;




void insert(int A[],int n)
{
    int i,temp;
    i=n;
    temp=A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}


//Deleting Elements from heap
void Delete(int A[],int n)
{
    int i,j,x,temp;
    x=A[1];
    A[1]=A[n];
    A[n]=A[1]
    i=1,j=2*i;

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j+=1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*i;
        }
        else
        {
            break;
        }

    }

}
int main()
{
    int A[]={0,2,5,9,8,4,10,7};
    for (int i=2;i<=7;i++)
    {
        insert(A,i);
    }


}