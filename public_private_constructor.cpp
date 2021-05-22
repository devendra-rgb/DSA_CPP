#include <cstdio>

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
int main(){
    Clock_year ob;
    ob.set_year(2002);
    printf("%d",ob.get_year());
};