#include<iostream>
using namespace std;

int main()
{
    int n,a,b,c,p=0;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        int sum=a+b+c;
        if(sum>=2)
        p++;

        
    }
    cout<<p;
}