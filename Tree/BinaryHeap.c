#include <stdio.h>
#include <stdlib.h>

// Implement of Max Heap

typedef struct Heap {
    int capacity;
    int size;
    int* data;
} Heap;

int parent_node(int i) { return (i - 1) / 2; }

int left_node(int i) { return (2 * i + 1); }

int right_node(int i) { return (2 * i + 2); }

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heaplify(Heap* heap, int i) {
    int l = left_node(i);
    int r = right_node(i);
    int largest = i;
    if (l < heap->size && heap->data[l] > heap->data[i]) {
        largest = l;
    }
    if (r < heap->size && heap->data[r] > heap->data[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&(heap->data[i]), &(heap->data[largest]));
        heaplify(heap, largest);
    }
}

//初始化堆
Heap* init(int max) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        printf("initial error\n");
        exit(-1);
    }

    heap->capacity = max;
    heap->size = 0;
    heap->data = (int*)malloc(sizeof(int) * (heap->capacity + 1));
    heap->data[0] = -1;

    return heap;
}

//向堆中添加元素
void push(Heap* heap, int val) {
    //堆分配的内存容量已满，重新分配，容量*2
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = realloc(heap->data, sizeof(int) * heap->capacity);
        if (!heap->data) {
            printf("memory allocate failed\n");
            exit(-1);
        }
    }

    int index, parent;
    index = heap->size++;
    heap->data[index] = val;
    while (index != 0 && (heap->data[parent_node(index)] < heap->data[index])) {
        swap(&heap->data[index], &heap->data[parent_node(index)]);
        index = parent_node(index);
    }
}

int pop(Heap* heap) {
    if (heap->size < 1) {
        printf("empty heap\n");
        exit(-1);
    } else if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heaplify(heap, 0);
    return root;
}

int main() {
    Heap* heap = init(10);
    push(heap, 13);
    push(heap, 11);
    push(heap, 7);
    push(heap, 15);
    push(heap, 14);
    push(heap, 10);
    pop(heap);
    pop(heap);
    for (int i = 0; i < heap->size; i++) {
        printf("%d\n", heap->data[i]);
    }
}