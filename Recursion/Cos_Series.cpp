//Cos Series taylor 
#include <cstdio>
double cos(int x, int n)
{
    static double  p=1,f=1,count=0;//here count starts with 0 so we can get even nums
    static int sign=1;
    double r;
    if (n==0)
    return 1;
    else{
        r=cos(x,n-1);
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
    a=cos(2,5);
    printf("%2lf",a);
}