#pragma once

void init_listing(int ptrcount);
void* lcalloc(int size);
void* lmalloc(int size);
void lfree(void* ptr);
void free_all();