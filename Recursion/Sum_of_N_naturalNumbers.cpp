#include<stdio.h>
#include<cstdio>


int sum(int n)
{
    if(n==0)
    return 0;
    return sum(n-1)+n;
}

int main()
{
    int r;
    r=sum(5);
    printf("%d",r);
}