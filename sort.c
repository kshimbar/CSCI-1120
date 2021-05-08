#include <stdio.h>
#include <stdlib.h>

int main(void){
    int length, seed;
    printf("How many to sort? \n");
    scanf("%d", &length);
    int seq[length];
    printf("Seed?\n");
    scanf("%d", &seed);
    srand(seed);
    for(int i = 0; i < length;  ++i){
        seq[i] = rand();
    }
    for(int a = 0; a < length; ++a){
        printf("Before %d is %d\n", a, seq[a]);
    }
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(seq[i] > seq[j]){
                int tmp = seq[i];
                seq[i] = seq[j];
                seq[j] = tmp;
            }
        }
    }
    for(int b = 0; b < length; ++b){
        printf("%d is %d\n", b, seq[b]);
    }
    return 1;
}
