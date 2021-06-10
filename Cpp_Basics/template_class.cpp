#include<iostream>
using namespace std;
template<class T>
class Arthematic{
    private:
    T a;
    T b;
    public:
    Arthematic(T a,T b);
    T add();
    T sub();
};

template<class T>
Arthematic<T>::Arthematic(T length,T breadth){
     this->a=length;
     this->b=breadth;
    
}

template<class T>
T Arthematic<T>::add(){
    T c;
    c=a+b;
    return c;
}
template<class T>
T Arthematic<T>::sub()
{
    T c;
    c=a-b;
    return c;
}

int main(){
    Arthematic<int> a(1,2);
    cout<<a.add()<<endl;
    cout<<a.sub()<<endl;

    Arthematic<float> b(1.5,25.2);
    cout<<b.add()<<endl;
    cout<<b.sub()<<endl;

    return 0;

}