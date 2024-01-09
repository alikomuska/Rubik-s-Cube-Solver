#include<stdlib.h>
#include<stdio.h>
#include"heap.h"

#define InitialHeapSize 512

Heap* createMinHeap(){

   Heap* heap = malloc(sizeof(Heap));

   heap->heapSize = InitialHeapSize;
   heap->heapList = malloc(sizeof(Node*)*(InitialHeapSize+1));
   heap->lastItemIndex = 0;
   heap->isMin = 0;
   return heap;
}




void insertMinHeap(Heap* heap, void* pointer, heapValuesDataType value){

   Node* node = malloc(sizeof(Node));
  
   node->value = value;
   node->pointer = pointer;

   if(heap->heapSize == heap->lastItemIndex){
      heap->heapList = realloc(heap->heapList, (2 * (heap->heapSize) + 1) * sizeof(Node*));
      heap->heapSize*=2;
   }

   if(heap->heapList == NULL){
      printf("Heap got to big");
   }
      
   heap->heapList[++(heap->lastItemIndex)] = node;   


}




void deleteMinHeap(){



}


void destroyHeap(Heap* heap){
   
   free(heap);

}

