#include <stdlib.h>

typedef struct _ptr_t{
    void* ptr;
    int valid;
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
    for (int i = 0; i < listing_ptrcount; i++){
        if (!listing[i].valid){
            listing[i].ptr = ptr;
            listing[i].valid = 1;
            break;
        }
    }
    return ptr;
}

void* lmalloc(int size){
    void* ptr = malloc(size);
    for (int i = 0; i < listing_ptrcount; i++){
        if (!listing[i].valid){
            listing[i].ptr = ptr;
            listing[i].valid = 1;
            break;
        }
    }
    return ptr;
}

void lfree(void* ptr){
    int offset = 0;
    while (listing[offset].ptr != ptr) offset++;
    listing[offset].valid = 0;
    free(ptr);
}

void free_all(){
    for (int i = 0; i < listing_ptrcount; i++)
        if (listing[i].valid) free(listing[i].ptr);
    free(listing);
}