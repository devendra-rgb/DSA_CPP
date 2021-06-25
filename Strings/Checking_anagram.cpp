#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char A[]="medical";
    char B[]="decimal";
    int H[26]={0};
    int j=0;
    for(int i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;//here we increase the zeors to increase them 
    }
    for( j=0;B[j]!='\0';j++)
    {
        H[B[j]-97]-=1; //here we decrease the numbers in hash table to check it
        if(H[B[j]-97]<0)
        {
            printf("It is not Anagram");
            break;
        }

    }
    if(B[j]=='\0')
    printf("It is Anagram");
}