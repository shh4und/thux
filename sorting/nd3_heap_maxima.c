#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Function-like Macro definition
#define PARENT(i) i / 2
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2

#define ARR_SIZE 14

typedef struct Heap
{
    int arr[ARR_SIZE];
    size_t heap_size;
} Heap;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify(Heap *heap, int i)
{
    int left_child = LEFT(i);
    int right_child = RIGHT(i);
    int largest;
    if (left_child <= heap->heap_size && heap->arr[left_child] > heap->arr[i])
    {
        largest = left_child;
    }
    else
    {
        largest = i;
    }

    if (right_child <= heap->heap_size && heap->arr[right_child] > heap->arr[largest])
    {
        largest = right_child;
    }

    if (largest != i)
    {
        swap(heap->arr[i], heap->arr[largest]);
        max_heapify(heap, largest);
    }
}

void build_max_heap(Heap heap)
{
    heap.heap_size = ARR_SIZE;
    for (int i = ARR_SIZE / 2; i > 0; i++)
    {
        max_heapify(&heap, i);
    }
}

int main()
{

    Heap heap;
    heap.heap_size = ARR_SIZE;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (scanf("%d", &heap.arr[i]) != 1)
        {
            fprintf(stderr, "Invalid input. Exiting.\n\n");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d | ", heap.arr[i]);
    }
    printf("\n\n");

    return EXIT_SUCCESS;
}