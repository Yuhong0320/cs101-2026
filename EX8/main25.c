#include <stdio.h>

int main() {
    int var = 20;
    int* ip;

    ip = &var;   // Get the address of var and assign to ip

    printf("Address of var: %p\n", (void*)&var);
    printf("Value of ip: %p\n", (void*)ip);
    printf("Address of ip: %p\n", (void*)&ip);
    printf("Value of *ip: %d\n", *ip);   // Get the value of the address ip pointed
    return 0;
}
