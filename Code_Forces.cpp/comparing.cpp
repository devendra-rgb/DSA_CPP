#include<stdio.h>
#include<iostream>
using namespace std;

void change(char A[])
{
    int j;
    for (j=0;A[j]!='\0';j++)
    {
        if(A[j]>=65 && A[j]<=90)
        {
            A[j]+=32;
        }
    }

}


int main()
{
    char A[100];
    char B[100];
    cin>>A;
    cin>>B;
    int i;
    change(A);
    change(B);
    for(i=0;A[i]!='\0';i++)
    {
        if (A[i]>=97 && A[i]<=122 && B[i]>=97 && B[i]<=122)
        {
            if(A[i]!=B[i])
            break;
        }
    }

    if(A[i]==B[i])
    {
        cout<<0;
    }

    else if(A[i]<B[i])
    cout<<-1;
    else
    cout<<1;

}