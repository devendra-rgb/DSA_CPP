#include<iostream>
using namespace std;
int main()
{
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int *B[3];
    B[0]=new int[3];
    B[1]=new int [3];
    B[2]=new int [3];
    int **C;
    C=new int *[3];
    C[0]=new int[3];
    C[1]=new int [3];
    C[2]=new int [3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }
    
}
