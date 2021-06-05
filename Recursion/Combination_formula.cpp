#include<cstdio>
//formula nCr=n!/r!(n-r)!
int nCr(int n,int r)
{
    if(n==r||r==0)
    return 1;
    else
    return nCr(n-1,r-1)+nCr(n-1,r);
}


int main()
{
    int a;
    a=nCr(5,2);
    printf("%d",a);
}