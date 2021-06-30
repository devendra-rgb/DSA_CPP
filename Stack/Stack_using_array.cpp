#include<iostream>
#include<stdio.h>
using namespace std;


struct Stack
{
    int top;
    int size;
    int *s;
};




void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack Overflow\n";
        return ;
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

void pop(struct Stack *st)
{
    if(st->top==-1)
    {
        cout<<"Stack UnderFlow";
        return ;
    }
    else
    {
        st->top--;
    }
}

//finding the index of the element with respect to the position in the stack
void peek(int pos,struct Stack *st)
{
    int x=0;
    if((st->top-pos+1)<0)
    cout<<"invalid position";
    else
    {
        x=st->top-pos+1;
        cout<<x;
    }
};




int isEmpty(struct Stack st)
{
    if(st.top<0)
    cout<<"Empty";

};
int isFull(struct Stack st)
{
    if(st.top==st.size-1)
    cout<<"Full";
};

void Display(struct Stack st)
{
    int i=0;
    for(i=st.top;i>=0;i--)
    cout<<st.s[i]<<endl;
}



int main()
{
    struct Stack st;
    cout<<"Enter the size of the stack ";
    cin>>st.size;
    st.s=new int[st.size];
    st.top=-1;
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    Display(st);

    push(&st,8);

    Display(st);

    peek(2,&st);
    
}


