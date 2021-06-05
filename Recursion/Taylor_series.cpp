#include<cstdio>


double e(int x,int n)
{
    static double p=1,f=1;
    static double r;
    if(n==0)
    return 1;
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;

    }
}

double e_horn(int x, int n){
    static double s=1;
    if (n==0)
    return s;
    else
    s=(1+x*s/n); 
    return e_horn(x,n-1);
}


double itereative_e(int x,int n)
{   double s=1;
    for(;n>0;n--){
    s=(x*s/n+1);
    }
    return s;
}

int main()
{
    double a;
    a=itereative_e(1,150);
    printf("%lf",a);
}