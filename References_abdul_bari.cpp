#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a=10;
    int &r=a;
    a=49;
    cout<<a<<endl<<r<<endl;
    return 0;
}