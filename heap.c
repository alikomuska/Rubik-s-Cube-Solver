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
   int unsortedNodeIndex = heap->lastItemIndex;
   int parentIndex = heap->lastItemIndex/2;
   Node* temp;

   while(parentIndex!=0){
      if(heap->heapList[parentIndex]->value <= heap->heapList[unsortedNodeIndex]->value){
         return;
      } 
      
      temp = heap->heapList[parentIndex];
      heap->heapList[parentIndex] = heap->heapList[unsortedNodeIndex];
      heap->heapList[unsortedNodeIndex] = temp;
      unsortedNodeIndex = parentIndex;
      parentIndex = unsortedNodeIndex/2;
   }
}




void* deleteMinHeap(Heap* heap){
   Node* returnNode = heap->heapList[1];

   heap->heapList[1] = heap->heapList[heap->lastItemIndex];
   Node* unsortedNode = heap->heapList[1];
   Node* temp;
   int unsortedNodeIndex = 1;
   int unsortedNodeFirstChildeIndex = 2;

   while(unsortedNodeFirstChildeIndex < heap->lastItemIndex){
   
      if(heap->heapList[unsortedNodeIndex*2] < heap->heapList[unsortedNodeIndex*2 + 1]){
         if(heap->heapList[unsortedNodeIndex] < heap->heapList[unsortedNodeIndex*2]) return returnNode;    
            temp = heap->heapList[unsortedNodeIndex];
	    heap->heapList[unsortedNodeIndex] = heap->heapList[unsortedNodeIndex*2];
	    heap->heapList[unsortedNodeIndex*2] = temp;
	    unsortedNodeIndex*=2;
	    unsortedNodeFirstChildeIndex = unsortedNodeIndex*2;
      	    
      }else{
         if(heap->heapList[unsortedNodeIndex] < heap->heapList[unsortedNodeIndex*2 + 1]) return returnNode;    
            temp = heap->heapList[unsortedNodeIndex];
	    heap->heapList[unsortedNodeIndex] = heap->heapList[unsortedNodeIndex*2 + 1];
	    heap->heapList[unsortedNodeIndex*2] = temp;
	    unsortedNodeIndex = unsortedNodeIndex*2 + 1;
	    unsortedNodeFirstChildeIndex = unsortedNodeIndex*2;      
      }
   }
}


void destroyHeap(Heap* heap){
   
   for(int index=0; index <= heap->lastItemIndex; index++){
      free(heap->heapList[index]);
   }

   free(heap);

}

