#include <cstdio>
struct collage
{
    /* data */
    char name[256];
};

void print_collages(collage* collages, size_t size){
    for (size_t i=0;i<size;i++){
        printf("%s Collage\n" , collages[i].name);
    }

}



int main(){
collage best_collages[]={"LPU","IIT","NIT"};

print_collages(best_collages,sizeof(best_collages) / sizeof(collage));

}