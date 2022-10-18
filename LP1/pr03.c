//
// Created by tiago on 18/10/2022.
//

#include "pr03.h"

int main_pr03() {
    //int x = pow_recursive(2, 5);
    //printf("%d", x);
    int a[] = {1,4,2,4};
    //int b[] = {1,2,3,9};
    int size = sizeof(a)/ sizeof(int);
    //int x = int_compare(a, b, size);
    //printf("%d", x);
    int x = lowest_index_number(a, 4, size);
    printf("%d",x);
    return 0;
}

/**
* recursively raises b to the power of e
* @param b - base
* @param e - exponent
* @returns b^e
* e.g. input: (2, 5); output: 32
* e.g. input: (10, 1); output: 10
* e.g. input: (3, 0); output: 1
*/
int pow_recursive(int b, int e) {
    if (e == 0) {
        return 1;
    } else {
        return b * pow_recursive(b, e - 1);
    }
}

/**
* compare two integer arrays with the same size
* @param a - array for comparison
* @param b - array for comparison
* @param size - size for both arrays
* @return 0 if (a == b) ; -1 if (a < b) ; 1 if (a > b)
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 5], 4); output: -1
* e.g. input: ([1, 3, 3, 4], [1, 2, 3, 4], 4); output: 1
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 4], 4); output: 0
*/
int int_compare(int a[], int b[], int size) {
    int soma_arr1 = 0, soma_arr2 = 0;

    for (int i = 0; i < size; i++) {
        soma_arr1 += a[i];
        soma_arr2 += b[i];
    }
    if (soma_arr1 == soma_arr2) {
        return 0;
    } else if (soma_arr1 < soma_arr2) {
        return -1;
    } else {
        return 1;
    }
}

/**
* searches for the lowest index of a given integer
* @param v - array to be searched
* @param n - number to search
* @param size - array size
* @return - lowest index which contains the integer n
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 1
*/
int lowest_index_number(const int v[], int n, int size){
    for(int i = 0; i < size; i++){
        if(v[i] == n){
            return i;
            break;
        }
    }
    return 0;
}

/**
* searches for the highest index of a given integer
* @param v - array to be searched
* @param n - number to search
* @param size - array size
* @return - highest index which contains the integer n
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 3
*/
int highest_index_number(int v[], int n, int size){
   for(int i = 0; i < size; i++){
        if(v[i] == n){
            return i;
        }
   } 
}

/**
* finds the number with the highest frequency (mode) in a given array
* @param v - array to be searched
* @param size - array size
* @return mode of array
* e.g. input: ([1, 4, 2, 4], 4); output: 4
* e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int number_highest_frequency(int v[], int size){
    int count = 0, maxNumber = 0;
    for(int i = 0; i < size; i++){
        count = 1;
        for(int x = i+1; x < size; x++){
            if(v[i] == v[j]){
                count ++;
            }   
        }
         if(count > maxNumber){
                maxNumber = v[i];
         }
    }
    return maxNumber;
}
