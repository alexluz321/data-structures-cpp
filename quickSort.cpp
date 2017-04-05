//
//  quickSort.cpp
//  QuickSort
//
//  Created by Alexandre Costa
//  Copyright © 2017 Alexandre Costa. All rights reserved.
//

#include <iostream>

int getPivot(int A[], int start, int end){
    int wall = start;
    int pivot = end;
    int temp, i;
    for(i = start; i < end; ++i){
        if(A[i] < A[pivot]){
            temp = A[i];
            A[i] = A[wall];
            A[wall] = temp;
            ++wall;
        }
    }
    if(A[pivot] <= A[wall]){
        temp = A[wall];
        A[wall] = A[pivot];
        A[pivot] = temp;
    }
    
    return wall;
}

void quickSort(int *A, int start, int end){
    if(start >= end)
        return;
    
    int pivotIndex = getPivot(A, start, end);
    quickSort(A, start, pivotIndex-1);
    quickSort(A, pivotIndex+1, end);
}

int main(int argc, const char * argv[]){
    int A[] = {4,5,7,1,2,8,4,9,3,4};
    for(int i = 0; i < 10; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    quickSort(A, 0, 9);
    for(int i = 0; i < 10; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
