/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
using namespace std;
int main(int argc, char *a[])
{
    int packets=0;
    int moves=0;
    int balls=0;
    int total_moves=0;
    cin>>packets;
    for(int i=0;i<packets;i++)
    {
        cin>>balls;
        if(balls%2 == 0)
        {
            moves=balls+(balls/2)+1;
            total_moves+=moves;
        }
        else if (balls%2!=0)
        {
            total_moves+=1;
        }

    }
    cout<<total_moves;
    
    //Write code here
}
