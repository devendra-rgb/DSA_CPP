#include<cstdio>

double sine(int x,int n)
{
    static int sign=1;
    static double p=x,f=1,count=1;
    double r;
    if(n==0)
    return x;
    else
    {   
        r=sine(x,n-1);
        p=p*x*x;
        f=f*(count+1)*(count+2);
        count=count+2;
        if (sign>0)
        sign=-1;
        else
        sign=1;
        return r+(sign*p/f);

    }
}

int main()
{
    double a;
    a=sine(20,30);
    printf("%lf",a);
}