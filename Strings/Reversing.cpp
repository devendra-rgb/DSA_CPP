#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char A[]="Python";
    char B[7];
    int temp;
    int i=0,j=0;
    for( j=0;A[j]!='\0';j++)
    {
    }
    j=j-1;

    while(i<j)
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
    }
    printf("%s",A);

}