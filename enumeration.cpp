#include <cstdio>
int main(){
    printf("Hello\n");
 // Scoped Enumeration 
    enum class Option{Rice,Biriyani};
    Option value = Option::Biriyani;
    printf("%d",value);
 //Unscoped Enumeration 
    enum  Gender{Male,Female};
    Gender category = Male;

}
