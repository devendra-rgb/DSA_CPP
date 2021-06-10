#include<iostream>
using namespace std;
int swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    return 0;
}

int main(){
    int a=10;
    int b=20;
    swap(a,b);
    cout<<"a "<<a<<endl<<"b "<<b;

}