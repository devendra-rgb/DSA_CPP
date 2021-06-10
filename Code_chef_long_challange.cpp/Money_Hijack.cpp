#include<iostream>
using namespace std;


int main()
{
    int test_cases;
    cin>>test_cases;
    for(int j=0;j<test_cases;j++)
    {
        int D,d,p,q;
        cin>>D>>d>>p>>q;
        int total=0;
        for(int i=1;i<=D;i++)
        {
            total=total+p;
            if(i%d==0)
            p=p+q;
        }
        cout<<total<<endl;

    }
    return 0;
}