#include<iostream>
using namespace std;




int main()
{ 
    int test_case;
    cin>>test_case;
    
    for(int i=0;i<test_case;i++)
    {   //taking one line input from user
        int A[4];
        for(int j=0;j<4;j++){
            cin>>A[j];
        }
        int total=A[2]/A[0]+A[3]/A[1];
        cout<<total<<endl;

    }
}