#include<stdlib.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a=10;
    int b=20;
    int *p;
    p=&a;
    cout<<*p<<endl;
    int A[5]={1,2,3,4,5};
    int *p2;
    p2=&A[0];
    for (int i=0;i<5;i++){
        /*cout<<p2[i]<<endl;*/
    }
    /* assiging array to a stack*/
    int *p3;
    /*p3=(int *)malloc(sizeof(int)*5);*/
    /*Allocating in Heap*/
    p3=new int[5];
    p3[0]=1;p3[1]=2;p3[2]=3;p3[3]=4;p3[4]=5;
    for (int j=0;j<5;j++){
        cout<<p3[j]<<endl;
    }
    delete []p3;

    return 0;
}