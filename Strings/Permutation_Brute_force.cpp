#include<stdio.h>
#include<iostream>
using namespace std;
void permut(char A[],int k)
{
    static char Result[6];
    static int Flag[6]={0};
    static int i;

    if (A[k]=='\0')
    {
        Result[k]='\0';
        cout<<Result<<endl;
        i--;
        k--;
        
    }
    else
    {
        for( i=0;A[i]!='\0';i++)
        {
            if (Flag[i]==0)
            {
                Result[i]=A[i];
                k++;
                Flag[i]=1;
                permut(A,k);
                Flag[i]=0;
            }
        }
        
    }

}


int main()
{
    char C[]="ABC";
    permut(C,0);

}
