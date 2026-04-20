#include <stdlib.h>
#include <stdio.h>
#include "min_heap.h"

MinHeap* create_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (RequestNode*)malloc(sizeof(RequestNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(RequestNode* a, RequestNode* b) {
    RequestNode temp = *a;
    *a = *b;
    *b = temp;
}

// Yeni eklenen elemanı yukarı taşıma (Bubble-up)
void heapify_up(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        // Urgency değeri küçük olan daha önceliklidir (Min-Heap)
        if (heap->data[index].priority.urgency < heap->data[parent].priority.urgency) {
            swap(&heap->data[index], &heap->data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void insert_request(MinHeap* heap, Priority p) {
    if (heap->size == heap->capacity) return; // Kapasite dolduysa ekleme yapma
    
    heap->data[heap->size].priority = p;
    heapify_up(heap, heap->size);
    heap->size++;
}

// En üstteki eleman alındıktan sonra yapıyı düzenleme (Heapify-down)
void heapify_down(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left].priority.urgency < heap->data[smallest].priority.urgency)
        smallest = left;

    if (right < heap->size && heap->data[right].priority.urgency < heap->data[smallest].priority.urgency)
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapify_down(heap, smallest);
    }
}

Priority extract_min(MinHeap* heap) {
    Priority min_val = heap->data[0].priority;
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);
    return min_val;
}

void free_heap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}