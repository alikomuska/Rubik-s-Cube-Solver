#ifndef HEAP_H
#define HEAP_H

#define heapValuesDataType float

typedef struct
{
   heapValuesDataType value;
   void* pointer;
}Node;

typedef struct
{
   int heapSize;
   Node **heapList;
   int lastItemIndex;
   int isMin; // 0 for MIN_HEAP      
	      // 1 for MAX_HEAP
}Heap;


Heap* createMinHeap();

void insertMinHeap(Heap* heap, void* pointer, heapValuesDataType);

void deleteMInHeap(Heap* heap);

void destroyHeap(Heap* heap);


#endif
