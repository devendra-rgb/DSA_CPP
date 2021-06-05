#include<cstdio>


//Recursion method with increase in excessive recursion
int fib(int n)
{
    if(n<=1)
    return n;
    else
    return fib(n-2)+fib(n-1);

}

//iterative method
int Ifib(int n)
{
    int t0=0,t1=1,s;
    if(n<=1)
    return n;
    else
    for(int i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

//recursion with memoization
int A[10];
int mfib(int n)
{
    if(n<=1){ 
    A[n]=n;
    return n;
    }
    else
    {
        if(A[n-2]==-1)
        {
            A[n-2]=mfib(n-2);
        }
        if(A[n-1]==-1)
        {
            A[n-1]==mfib(n-1);
        }
        A[n]=A[n-2]+A[n-1];
        return A[n-2]+A[n-1];
    }

}



int main()
{
    for(int i=0;i<=10;i++){
        A[i]=-1;
    }
    int a;
    a=mfib(6);
    printf("%d",a);
    return 0;
}