#include <stdlib.h>

typedef struct _ptr_t{
    void* ptr;
} ptr_t;

static ptr_t* listing;
static int listing_ptrcount;

int init_listing(int ptrcount){
    void* ptr = calloc(ptrcount, sizeof(ptr_t));
    if (!ptr) return 1;
    listing_ptrcount = ptrcount;
    listing = ptr;
}

void* lcalloc(int size){
    void* ptr = calloc(size, 1);
    int free_element = 0;
    while (free_element < listing_ptrcount && !listing[free_element].ptr);
    listing[free_element].ptr = ptr;
    return ptr;
}

void* lmalloc(int size){
    void* ptr = malloc(size);
    int free_element = 0;
    while (free_element < listing_ptrcount && listing[free_element].ptr) free_element++;
    listing[free_element].ptr = ptr;
    return ptr;
}

void lfree(void* ptr){
    int offset = 0;
    while (listing[offset].ptr != ptr && offset < listing_ptrcount) offset++;
    listing[offset].ptr = 0;
    free(ptr);
}

void free_all(){
    for (int i = 0; i < listing_ptrcount; i++)
        if (listing[i].ptr){
            free(listing[i].ptr);
            listing[i].ptr = 0;
        }
    free(listing);
}