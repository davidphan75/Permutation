//
//  cVector.h
//  PermutaionEC
//
//  Created by David Phan on 4/9/15.
//  Copyright (c) 2015 David Phan. All rights reserved.
//

#ifndef __PermutaionEC__cVector__
#define __PermutaionEC__cVector__

#include <stdio.h>

typedef struct node node;
typedef struct cVector cVector;

struct node{
    int number;
    node *next;
    node *prev;
};

struct cVector{
    int count;
    node *head;
    node *tail;
};

void pushBack(cVector *thiscVector,int number);
int popFront(cVector *thiscVector);
int popBack(cVector *thiscVector);
void printVector(cVector *thiscVector);
void printVectorReverse(cVector *thiscVector);



#endif /* defined(__PermutaionEC__cVector__) */
