#include <cstdio>

int main(){
    int eluru;
    printf("Eluru : %d\n",eluru);
    //Referencing
    int *eluru_address=&eluru;
    printf("&Eluru Address : %p\n",eluru_address);
    //Dereferencing
    *eluru_address=555;
    printf("Eluru : %d\n",eluru);
    printf("&Eluru Address : %p\n",eluru_address);

}