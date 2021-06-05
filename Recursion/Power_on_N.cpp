#include<cstdio>

int power(int m,int n)
{
    if (n==0)
    return 1;
    return power(m,n-1)*m;
}

int power_faster(int m,int n)
{
    if(n==0)
    return 1;
    else
    if (n%2==0)
    return (power_faster(m*m,n/2));
    else
    return (m*power_faster(m*m,(n-1)/2));
}

int power_iteration(int m,int n)
{
    int result=1;
    for (int i=1;i<=n;i++){
        result=result*m;
    }
    return result;
}





int main()
{
    int r;
    r=power_iteration(2,2);
    printf("%d",r);
    return 0;
}