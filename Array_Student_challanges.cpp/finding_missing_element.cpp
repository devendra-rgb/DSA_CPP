#include<iostream>
using namespace std;


int sum(int a[])
{
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum=sum+a[i];
    }
    return sum;
}

int main()
{   
    //Finding missing element in sequence of natural numbers sorted array
    int A[10]={1,2,3,4,5,6,8,9,10,11};
    int a;
    a=sum(A);
   int s=(A[9]+1)/2;
   int sum_of_n_numbers=A[9]*s;
   int missed_number=sum_of_n_numbers-a;

   //Finding multiple Missing element in any sequence of elements sorted array
    int B[5]={6,7,8,12};
     //       0,1,2, 3, 4
    int diff=B[0]-0;
    

    for(int i=0;i<5;i++)    
    {
     if(B[i]-i != diff){

     while(diff<B[i]-i)
     {
         //cout<<diff+i<<endl;
         diff++;
     }
     }

    }

//Finding missing elements in an unsorted sequence array

int C[10]={3,7,4,9,12,6,1,11,2,10};
int Hash_array[10]={0};
for (int k=0;k<10;k++)
{
    Hash_array[C[k]]=1;
}

for (int l=1;l<10;l++)
{
    if(Hash_array[l]==0)
    //cout<<l<<endl;
    cout<<'h';
}


//Finding multiple Duplicates in a sorted array with last duplicate
int duplicate_array[10]={3,6,8,8,10,12,15,15,15,20};
int last_duplicate=0;
//cout<<"The Duplicate nums are "<<endl;
for(int i=0;i<10;i++)
{
 if(duplicate_array[i]==duplicate_array[i+1] && duplicate_array[i]!= last_duplicate)
 {
     //cout<<duplicate_array[i]<<endl;
     last_duplicate=duplicate_array[i];
 }   
}

//finding duplicates repetations in sorted array
int j;
for(int i=0;i<9;i++)
{
    if(duplicate_array[i]==duplicate_array[i+1])
    { 
        j=i+1;
        while(duplicate_array[i]==duplicate_array[j])
        {
            j++;
        }
        cout<<duplicate_array[i]<<"is "<<j-i<<endl;
        i=j-1;
    }
    

}


//Finding Duplicates in an unsorted array;
int Un_sort_array[10]={8,3,6,4,6,5,6,8,2,7};
int jm;
for(int i=0;i<9;i++)
{   int count=1;
if(Un_sort_array[i]!=-1){ 
    for(jm=i+1;jm<10;jm++)
    {
        if(Un_sort_array[i]==Un_sort_array[jm])
        { 
        Un_sort_array[jm]=-1;
        count++;
        }
    }
    if(count>1)
    cout<<Un_sort_array[i]<<" Is repeated "<<count<<endl;
    
}
}


//Finding the pair of elements that adds to K

int elements[10]={6,3,8,10,16,7,5,2,9,14};
//traditionl method like comparing every number 
for (int a=0;a<9;a++)
{
    for(int b=a+1;b<10;b++)
    {
        if(elements[a]+elements[b]==10)
        cout<<"";
        //cout<<elements[a]<<" "<<elements[b]<<" "<<10<<endl;
    }
}

//Doing above method using hash table
int hash[16]={0};

for(int d=0;d<10;d++)

{
  if(hash[10-elements[d]]>0 && 10-elements[d]>0){ 
  //cout<<elements[d]<<" "<<10-elements[d]<<" "<<10<<endl;
  elements[d]=0;

  }
  else
  hash[elements[d]]++;
   }


//Finding pair of elements adds upto K with sorted array
int sort[10]={1,3,4,5,6,8,9,10,12,14};
int x=0,y=9;
while(x<y)
{
if(sort[x]+sort[y]==10)
{ 
cout<<sort[x]<<" "<<sort[y]<<endl;
x++;
y--;
}

else if(sort[x]+sort[y]<10){
    x++;
}
else
y--;

}


}