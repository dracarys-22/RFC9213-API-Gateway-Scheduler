#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "rfc_parser.h"


typedef struct {
    Priority priority;
    // Buraya istenirse istek içeriği veya ID eklenebilir
} RequestNode;


typedef struct {
    RequestNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity);
void insert_request(MinHeap* heap, Priority p);
Priority extract_min(MinHeap* heap);
void free_heap(MinHeap* heap);

#endif