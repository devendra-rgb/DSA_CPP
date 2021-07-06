#include<iostream>
using namespace std;


class Que
{
    private:
        int front;
        int rear;
        int size;
        int *q;
    public:
        Que(){front=rear=-1;size=10;q=new int[size];};
        Que(int size){front=rear=-1;this->size=size;q=new int[this->size];};

        void Display();
        int Deque();
        void Enque(int element);
};


void Que::Display()
{
    
    for(int i=front+1;i<=rear;i++)
    {cout<<q[i]<<' '; };
    cout<<endl;
}


void Que::Enque(int element)
{
    if(rear==size-1)
    {
        cout<<"The Que is full";
        return;
    }
    else
    {
        rear++;
        q[rear]=element;
    }
}

int Que::Deque()
{
    if(front==rear)
    {
        cout<<"The Que is empty no item to be deleted";
        return 0;
    }
    else
    {
        front++;
        //cout<<q[front];
        return q[front];
    }
}


int main()
{
    Que tickets_q;
    tickets_q.Enque(1);
    tickets_q.Enque(2);
    tickets_q.Enque(3);
    tickets_q.Enque(4);
    tickets_q.Display();
    tickets_q.Deque();
    tickets_q.Deque();
    tickets_q.Display();


}