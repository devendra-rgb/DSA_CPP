#include <cstdio>

class collage{
    public:
    char name[256];
} ;


void print_name(collage* ptr){
    printf("%s",ptr->name);
};

int main(){
collage best_collages[]={"LPU","IIT","NIT"};
print_name(best_collages);

};