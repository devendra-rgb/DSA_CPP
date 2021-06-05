#include<cstdio>

int f(int n)
{
static int i = 1;
if (n>=5)return n;
n = n+i;
i++;
return f(n);

}
int main()
{
    int a;
    a=f(1);
    printf("%d",a);
}