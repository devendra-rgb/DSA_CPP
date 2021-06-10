#include<cstdio>

class Clock_year{
    public:
    Clock_year(){
        year=2019;
    };

    public:
    void add_year(){
        year++;
    };

    bool set_year(int yea){
        if(yea<2019) return false;
        year=yea;
        return true;
     };

    int get_year(){
        return year;
    }
private:
    int year;
};

void add_year(Clock_year& ob){
    ob.add_year();
}

int main(){
    Clock_year ob;
    add_year(ob);
    printf("Year %d\n",ob.get_year());  

};