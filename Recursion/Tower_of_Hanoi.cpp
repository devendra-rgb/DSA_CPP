#include<cstdio>

int Hanoi(int n,int A,int B,int C)
{
    if(n>0){
    Hanoi(n-1,A,C,B);
    printf("(%d,%d)\n",A,C);
    Hanoi(n-1,B,A,C);
    }
}


int main(){
    int a;
    a=Hanoi(3,1,2,3);

}

