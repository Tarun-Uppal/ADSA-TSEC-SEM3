// Online C compiler to run C program online
#include <stdio.h>

void f(int a){
    printf("\nLocal Varible of a calle f has value=%d and address=%p\n", a, &a);
    if(--a){
        f(a);
    }
}

void main() {
    int z=4;
    printf("\nLocal varible z of caller function main has value=%d and address=%p\n", z, &z);
    f(z);
}