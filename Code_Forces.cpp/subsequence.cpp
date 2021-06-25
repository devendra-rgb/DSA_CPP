#include<iostream>
#include<string>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
using namespace std;

int main()
{   
    
    
    int iterations;
    string s1;
    string s2;
    cin>>s1;
    cin>>iterations;
    int a=s1.size();
    for(int k=0;k<iterations;k++)
    {   
        cin>>s2;
        int i=0;
        int j = 0;
        int count = 0;
        while(i<a)
        {
            if(s1[i]==s2[j])
            {
                count ++;
                i ++;
                j ++;
            }
            else{
                i++;

            }
            

        }

        if (count==s2.size())
        cout<<"POSITIVE"<<endl;
        else
        cout<<"NEGATIVE"<<endl;
    }
}