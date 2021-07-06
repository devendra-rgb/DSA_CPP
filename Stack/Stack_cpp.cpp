#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack
{
    private:
    Node *top=NULL;
    public:
    Stack(){top=NULL;};
    void push(int element);
    void pop();
    void Display();
    
    
};


void Stack::push(int element)
{
    Node *t =new Node;
    t->data=element;
    t->next=NULL;
    if(top==NULL)
    {
        top=t;
    }

    else
    {
        t->next=top;
        top=t;
    }
    

};


void Stack :: pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        Node *p;
        p=top;
        top=top->next;
        delete p;
    }

};


void Stack :: Display()
{
    Node *p=top;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.Display();


}