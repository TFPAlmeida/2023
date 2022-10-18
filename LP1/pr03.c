//
// Created by tiago on 18/10/2022.
//

#include "pr03.h"

int main_pr03() {
    //int x = pow_recursive(2, 5);
    //printf("%d", x);
    int a[] = {30, 41, 42, 18, 24, 25 , 4, 12};
    //int b[] = {1,2,3,9};
    int size = sizeof(a) / sizeof(int);
    //int x = int_compare(a, b, size);
    //printf("%d", x);
    //int x = lowest_index_number(a, 4, size);
    //int x = highest_index_number(a, 4, size);
    //int x = number_highest_frequency(a,size);
    //int x = size_greatest_segment_repeated_ints(a, size);
    int x = count_clumps (a, size);
    printf("%d", x);
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
int lowest_index_number(const int v[], int n, int size) {
    for (int i = 0; i < size; i++) {
        if (v[i] == n) {
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
int highest_index_number(int v[], int n, int size) {
    int aux = 0;
    for (int i = 0; i < size; i++) {
        if (v[i] == n) {
            aux = i;
        }
    }
    return aux;
}

/**
* finds the number with the highest frequency (mode) in a given array
* @param v - array to be searched
* @param size - array size
* @return mode of array
* e.g. input: ([1, 4, 2, 4], 4); output: 4
* e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int number_highest_frequency(int v[], int size) {
    int count = 0, maxNumber = 0;
    for (int i = 0; i < size; i++) {
        count = 1;
        for (int x = i + 1; x < size; x++) {
            if (v[i] == v[x]) {
                count++;
            }
        }
        if (count > maxNumber) {
            maxNumber = v[i];
        }
    }
    return maxNumber;
}

/**
* get the lenght of the greatest sequence of repeated ints
* @param v - array to be searched
* @param size - array size
* @return - lenght of the greatest sequence
* e.g. input: ([55, 22, 22, 33, 44, 44, 44, 1, 1], 9); output: 3
*/
int size_greatest_segment_repeated_ints(int v[], int size) {


    int count = 0, count1 = 0;
/**------------------------- Parte 1 ----------------------*/
//Saber tamanho da matriz
    for (int i = 0; i < size; i++) {
        int z;
        for (z = 0; z < i; z++) {
            if (v[i] == v[z]) {
                break;
            }
        }

        if (i == z) {
            count1++;
        }
    }

    int matrix[count1][2];

    /**------------------------- Parte 2 ----------------------*/
    //Guardar os numeros diferentes na matriz
    int z, k = 0;
    for (int i = 0; i < size; i++) {
        count = 1;

        for (z = 0; z < i; z++) {
            if (v[i] == v[z]) {
                break;
            }
        }
        for (int x = i + 1; x < size; x++) {
            if (v[i] == v[x]) {
                count++;
            }
        }
        matrix[k][1] = count;
        if (i == z && k < count1) {
            matrix[k][0] = v[i];
            k++;
        }
    }
/**------------------------- Parte 3 ----------------------*/
//Saber qual e o maior numero com o maior numero de repeticoes
    int maior1 = 0, maior2 = 0;
    for (int x = 0; x < count1; x++) {
        if (matrix[x][1] > maior1) {
            maior1 = matrix[x][1];
        }
    }

    for (int x = 0; x < count1; x++) {
        if (matrix[x][1] == maior1) {
            maior2 = matrix[x][0];
            if (matrix[x][0] > maior2) {
                maior2 = matrix[x][0];
            }
        }
    }
    for (int x = 0; x < count1; x++) {

        if (matrix[x][0] == maior2) {
            return matrix[x][1];
        }
    }
    return 0;
}

/**
* count the number of clumps (a series of 2 or more adjacent equal
* elements) in a given array
* @param a - array to be searched
* @param size - array size
* @return - number of clumps
* e.g. input: ([30, 41, 41, 18, 24, 24, 4, 12], 8); output: 2
* e.g. input: ([30, 41, 42, 18, 24, 24, 24, 12], 8); output: 1
* e.g. input: ([30, 41, 42, 18, 24, 25 , 4, 12], 8); output: 0
*/
int count_clumps (int a[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(a[i] == a[i+1] && a[i] != a[i + 2]){
            count++;
            i++;
        }
    }
    return count;
}
