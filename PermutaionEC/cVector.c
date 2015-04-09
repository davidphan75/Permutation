//
//  cVector.c
//  PermutaionEC
//
//  Created by David Phan on 4/9/15.
//  Copyright (c) 2015 David Phan. All rights reserved.
//

#include "cVector.h"
#include <stdio.h>
#include <stdlib.h>

//=====================Vector======================
// Partial C implmentation of Vector to solve problem
//=================================================


void pushBack(cVector *thiscVector,int number){
    
    // Create new node to be added to the vector
    node *newNode;
    newNode = malloc(sizeof(node));
    newNode->number = number;
    newNode->next = NULL;
    
    // If the vector is empty make it the head and the tail
    if (thiscVector->count == 0) {
        newNode->prev = NULL;
        thiscVector->head = newNode;
        thiscVector->tail = thiscVector->head;
        
        // Otherwise set pointers pointing to and from the new node
    }else{
        newNode->prev = thiscVector->tail;
        thiscVector->tail->next = newNode;
        thiscVector->tail = newNode;
    }
    
    // Increment the vector count
    thiscVector->count++;
    
}

int popFront(cVector *thiscVector){
    
    int front = thiscVector->head->number;
    // Create pointer to the new head of the vector
    node *temp = thiscVector->head->next;
    
    // Remove pointer to node we intend to remove
    if (temp != NULL) {
        temp->prev = NULL;
    }
    
    // Deallocate the first node set the new head
    free(thiscVector->head);
    thiscVector->head = temp;
    thiscVector->count--;
    return front;
}

int popBack(cVector *thiscVector){
    
    int back = thiscVector->tail->number;
    // Create pointer to new tail of the vector
    node *temp = thiscVector->tail->prev;
    
    // Remove pointer to node we intend to remove
    if (temp != NULL) {
        temp->next = NULL;
    }
    
    // Deallocate the last node and set the new tail
    free(thiscVector->tail);
    thiscVector->tail = temp;
    thiscVector->count--;
    return back;
}


void printVector(cVector *thiscVector){
    node *nodePTR = thiscVector->head;
    while (nodePTR != NULL) {
        printf("%d ",nodePTR->number);
        nodePTR = nodePTR->next;
    }
    printf("\n");
}

void printVectorReverse(cVector *thiscVector){
    node *nodePTR = thiscVector->tail;
    while (nodePTR != NULL) {
        printf("%d ",nodePTR->number);
        nodePTR = nodePTR->prev;
    }
    printf("\n");
}
