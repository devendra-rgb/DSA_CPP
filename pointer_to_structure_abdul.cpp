#include<stdio.h>
#include<iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
int main(){

   /* Declaring Normal Structure 
    Rectangle a;
    a.length=4;
    a.breadth=5;
    cout<<a.length<<endl<<a.breadth;
    */

   /* Declaring pointer to struct
   Rectangle a{2,40};
   Rectangle *p=&a;
   cout<<p->length<<p->breadth;
    */

   Rectangle *p;
   //this are used for c to allocate in heap
   p=(struct Rectangle *)malloc(sizeof(Rectangle));
   //this is used in cpp for allocating
   p=new Rectangle;
   
   p->breadth=20;
   p->length=30;
   cout<<p->length<<p->breadth;


}