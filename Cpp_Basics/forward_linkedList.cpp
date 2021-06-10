#include <cstdio>

struct Element{
    Element* next{};
    void insert_after(Element* ob){
        ob->next=next;
        next=ob;
    }

    char prefix[2];
    short operation_number;
};

int main(){
Element ob1,ob2,ob3;
ob1.prefix[0]='T';
ob1.prefix[1]='K';
ob1.operation_number=745;
ob1.insert_after(&ob2);

ob2.prefix[0]='F';
ob2.prefix[1]='R';
ob2.operation_number=755;
ob2.insert_after(&ob3);

ob3.prefix[0]='F';
ob3.prefix[1]='N';
ob3.operation_number=925;


for (Element* cursor=&ob1;cursor;cursor=cursor->next){
    printf("stormtrooper %c%c-%d\n",
    cursor->prefix[0],
    cursor->prefix[1],
    cursor->operation_number);

}





}


