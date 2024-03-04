#include <stdio.h>
#include "leakhelper.h"

int main(){
    puts("Initializing listing of size 4...");
    init_listing(4);

    puts("Doing some allocations...");
    void* ptr1 = lmalloc(64);
    void* ptr2 = lmalloc(128);

    puts("Freeing one ptr...");
    lfree(ptr1);
    
    puts("Fully disposing...");
    free_all();
}