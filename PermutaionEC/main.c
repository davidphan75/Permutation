//
//  main.c
//  PermutaionEC
//
//  Created by David Phan on 4/8/15.
//  Copyright (c) 2015 David Phan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "cVector.h"


long long int ipow(int base, int exp);



//====================Calculate===================
// Works by taking a vector (permutaion of 10 unique digits)
// determining if ab^c = def * ghij if so
// then we return 1 else we return 0.The first element
// of the vector is a, second is b, third is c, ect.
//      (note thate: if a = 1, b = 5 then ab = 15)
//================================================

int calculate(cVector *thiscVector){
    

    int numbers[10];
    node *nodePTR = thiscVector->head;
    int i = 0;
    while (nodePTR != NULL) {
        numbers[i] = nodePTR->number;
        nodePTR = nodePTR->next;
        i++;
    }
    if (numbers[0] == 0 || numbers[3] == 0 || numbers[6] ==0) {return 0;}
    
    int x = (numbers[0] * 10) + numbers[1];
    long long int x1 = ipow(x, numbers[2]);
    
    long long int y = (numbers[3] * 100) + (numbers[4] * 10) + numbers[5];
    long long int z = (numbers[6] * 1000) + (numbers[7]*100) + (numbers[8]*10) + numbers[9];
    
    if (x1 == y*z) {
        return 1;
    }else{
        return 0;
    }

}


//======================Math======================

long long int ipow(int base, int exp){
    long long int result = 1;
    while (exp){
        if (exp & 1){result *= base;}
        exp >>= 1;
        base *= base;
    }
    
    return result;
}


//=============Permutate Vector====================
// This function works recusively by looping through the vector
// taking one element off the vetor to build onto the new vector then
// taking another element from the remaining vector
//
//=================================================

void permutateVector(cVector *baseVec, cVector *buildVec){

    
    // If the base vector is empty then we have created a new permutaion
    // stored in the build vector and we print this vector
    if (baseVec->count == 0) {
        if (calculate(buildVec)) {
            printf("Solution: ");
            printVector(buildVec);
        }
        
    // Otherwise we pop an element off the base vector and append it to
    // the build vector
    }else{
        for (int i = 0; i < baseVec->count; i++) {
            int number = popFront(baseVec);
            pushBack(buildVec, number);
            permutateVector(baseVec, buildVec);
        }
    }
    
    // when finishes permutating a each level restore the previous
    if (buildVec->count != 0) {
        int x = popBack(buildVec);
        pushBack(baseVec, x);

    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Starting search!\n");
    

    cVector *baseVector;
    baseVector = malloc(sizeof(cVector));
    baseVector->head = NULL;
    baseVector->tail = NULL;
    baseVector->count = 0;
    
    cVector *buildVector;
    buildVector = malloc(sizeof(cVector));
    buildVector->head = NULL;
    buildVector->tail = NULL;
    buildVector->count = 0;

    
    for (int i = 0; i < 10; i++) {
        pushBack(baseVector, i);
    }

    
    permutateVector(baseVector, buildVector);
    
    printf("finished\n\n");
    
    
    return 0;
}









