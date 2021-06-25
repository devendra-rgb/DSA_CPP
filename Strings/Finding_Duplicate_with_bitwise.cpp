#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    char A[]="findinig";
     int x=0,H=0;
    for(int i=0;A[i]!='\0';i++)
    {
        x=1;
        int c=A[i]-97;
        x=x<<c;//shifting elements to do masking (means checking bits)
        if((x&H)>0)
        {
            printf("%c is duplicate\n",A[i]);
        }
        else
        H=x|H;//merging to add bit
    }
}