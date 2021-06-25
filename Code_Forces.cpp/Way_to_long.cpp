#include<iostream>
using namespace std;
int main()
{
    int iterations;
    cin>>iterations;
    int k;
    for(k=0;k<iterations;k++)
    {

        string A;
        cin>>A;
        if(A.length()>10)
        cout<<A[0]<<A.length()-2<<A[A.length()-1]<<endl;
        else
        cout<<A<<endl;
    }
}