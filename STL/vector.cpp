#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> v={1,3,4};
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    

    list<int>:: iterator itr;
        //cout<<*itr<<endl;

        for(itr=v.begin();itr!=v.end();itr++)
        {
            cout<<*itr<<endl;
        }


}