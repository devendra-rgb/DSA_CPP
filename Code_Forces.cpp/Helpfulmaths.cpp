#include<iostream>
#include<string>
using namespace std;

int main()
{   char B[100];
    cin>>B;
    int H[4]={0};
    std::string sorted="";
    char oper='+';
    char single='0';//used to add each character one by one
    int i=0;
    for( i=0;B[i]!='\0';i++)
    {
        if(B[i]!='+')
        {
         H[B[i]-48]++;   //Creating Hash table for every number 
        }
    }

    for(int j=1;j<=3;j++) //iterating hash table
    {
        for(int k=0;k<H[j];k++) //iteraing on numbers in hash to add them 
        {
            
            single=j+48;
            sorted.push_back(single);
            
            sorted.push_back(oper);
        }
    }
    //Removing last operand "+"
    sorted.erase(sorted.size()-1);

    std::cout<<sorted;
}