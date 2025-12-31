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
    size_t length;
    size_t heap_size;
} Heap;

void show_curr_state(Heap heap)
{
    printf("Estado Atual: ");
    for (int i = 0; i < heap.length; i++)
    {
        if (i == heap.length - 1)
        {
            printf("%d\n", heap.arr[i]);
        }
        else
        {
            printf("%d | ", heap.arr[i]);
        }
    }
}

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
    int largest = i;
    if (left_child < heap->length && heap->arr[left_child] > heap->arr[i])
    {

        largest = left_child;
    }
    if (right_child < heap->length && heap->arr[right_child] > heap->arr[largest])
    {
        {
            largest = right_child;
        }
    }
    if (largest != i)
    {
        swap(&heap->arr[i], &heap->arr[largest]);
        max_heapify(heap, largest);
        // show_curr_state(*heap);
    }
}

void build_max_heap(Heap *heap)
{
    heap->heap_size = heap->length;
    for (int i = (heap->length - 1) / 2; i >= 0; i--)
    {
        max_heapify(heap, i);
        show_curr_state(*heap);
    }
}

int main()
{

    Heap heap = {.length = ARR_SIZE};

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (scanf("%d", &heap.arr[i]) != 1)
        {
            fprintf(stderr, "Invalid input. Exiting.\n\n");
            return EXIT_FAILURE;
        }
    }

    printf("Estado inicial: ");
    for (int i = 0; i < heap.length; i++)
    {
        if (i == heap.length - 1)
        {
            printf("%d\n", heap.arr[i]);
        }
        else
        {

            printf("%d | ", heap.arr[i]);
        }
    }

    build_max_heap(&heap);
    printf("Resultado Final: ");
    for (int i = 0; i < heap.length; i++)
    {
        if (i == heap.length - 1)
        {
            printf("%d\n", heap.arr[i]);
        }
        else
        {

            printf("%d | ", heap.arr[i]);
        }
    }

    return EXIT_SUCCESS;
}