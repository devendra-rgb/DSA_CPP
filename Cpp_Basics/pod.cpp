#include <cstdio>
struct Book
{
    char name[3];
    int age;
    int gender;
};

int main(){
    Book ob1;
    ob1.age=12;
    printf("%d%s",ob1.age);
}