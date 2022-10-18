//
// Created by tiago on 15/10/2022.
//

#include "pr02.h"

int main_pr02() {
    //int res = read_digits_to_int();
    //printf("%d",res);
    //print_numbers_classes_from_units_upper(218);
    //print_numbers_classes_from_higher_downward(218);
    //print_numbers_classes_from_higher_downward_recursive(218);
    //int mult = multiplication_as_sums (2, 5);
    //printf("%d",mult);
    //print_multiplication_table (5);
    //print_pyramid (5);
    //int x = is_number_triangular (720);
    //printf("%d * %d * %d",x, x+1,x+2);
    splits_in_half(283);
    return 0;
}

/**
	* Iteratively reads chars (from '0' to '9') and returns the complete decimal number
	* @return - decimal number
	* e.g. input: ('2', '1', '8', 'e') => output: 218
	* e.g. input: ('4', '3', 'e') => output: 43
 */
int read_digits_to_int(void) {
    char c = '\0';
    int res = 0;
    int x = 0;
    while (c != 'e') {
        scanf(" %c", &c);
        /* check here if x is bounded by 0 and 9 */
        if (c != 'e') {
            x = c - '0';
            res = res * 10 + x;
            printf("%d\n", res);
        }
    }

    return res;
}

/**
	* Splits a number and prints each class in ascending order
	* @param n - decimal value to be splited
	* e.g. input: (218); output => 8, 1, 2
*/
void print_numbers_classes_from_units_upper(int n) {

    int mod = 0;

    while (n > 0) {
        mod = n % 10;
        printf("%d\n", mod);
        n = n / 10;
    }
}

/**
    * Splits a number and prints each class in a descending order.
    * @param n - decimal value to be splited
    * e.g. input: (218); output => 2, 1, 8
*/
void print_numbers_classes_from_higher_downward(int n){
    int mod = 0;
    int n2 = 0;
    while (n > 0) {
        mod = n % 10;
        n2 = n2 * 10 + mod;
        n = n / 10;

    }

    int mod2 = 0;

    while(n2 > 0){
        mod2 = n2 % 10;
        printf("%d\n", mod2);
        n2 = n2 / 10;
    }
}

/**
	* Splits a number and prints each class in a descending order recursivelly.
	* @param n - decimal value to be splited
	* e.g. input: (218); output => 2, 1, 8
*/
int print_numbers_classes_from_higher_downward_recursive(int n){ //duvida
    int mod, mod2;
    int n2 = 0;
    if (n > 0){
        mod = n % 10;
        n2 = n2 * 10 + mod;
        printf("%d\n",mod);
        n = print_numbers_classes_from_higher_downward_recursive(n/10);
    }

    if(n2 > 0){
        mod2 = n2 % 10;
        printf("%d\n",mod2);
        n2 = print_numbers_classes_from_higher_downward_recursive(n2/10);
    }
    return 0;
}

/**
	* Iteratively multiplies two numbers by unfolding the multiplication into sums
	* @param a - num to be multiplied
	* @param b - multiplier
	* @return - multilpication result
	* e.g. input: (2, 5) => output: 10
*/
int multiplication_as_sums (int a, int b){
    int mult = 0;
    if(a == 0 || b == 0){
        mult = 0;
    }else if(a == 1){
        mult = b;
    }else if(b == 1){
        mult = a;
    }else if(a > b){
        for (int i = 0; i < b; i++){
            mult = mult + a;
        }
    }else{
        for (int i = 0; i < a; i++){
            mult = mult + b;
        }
    }
    return mult;
}

/**
	* Prints the multiplication table for a given number
	* @param num - input number
	* e.g. input: (2) => output: 2x1=2\n2x2=4\n2x3=6 ...
*/
void print_multiplication_table (int num){

    for(int i = 1; i <=10; i++){
        printf(" %d x %d = %d\n",num,i,num*i);
    }
}

/**
	* prints inverted pyramid
	* @param width - pyramid's base width
	* e.g. input: (5); output:
    * 1 2 3 4 5
	*   2 3 4
	*     3
*/
void print_pyramid (int width){

    for(int i = 0; i < width; i++){
        for(int space = 0; space < i; space++){
            printf("  ");
        }
        for (int j = i; j < width; j++) {
            printf("%d ",j+1);
        }
        width -= 1;
        printf("\n");

    }
}

/**
    * Checks if a number is triangular, i.e., the product of three consecutive int numbers.
    * @param num - number to be checked
    * @return - true (0) or false (1)
    * e.g. input: 6 = output: is triangular 6 = 1 x 2 x 3
    * e.g. input: 504 => output: is triangular 504 = 7x8x9
    * e.g. input: 1320 => output: is triangular 1320 = 10x11x12
*/
int is_number_triangular (unsigned int num){ // pedir para ver

    for(int x = 1; x < num; x++){
                if(num == (x * (x+1) * (x+2))){
                    return x;
                }
    }
    return 0;
}

/** Separa e imprime um número int em duas metades, e.g., 284 -> 2 e 4; 4587 -> 45 e 87.
 * @param n - int number to split in half.
 */
void splits_in_half(int n){
    int count = 0;
    int aux1 = n;
    while(n > 0){
        count++;
        n = n/10;
    }
    int x = 0, y = 0;
    int aux = 1;
    if(count % 2 == 0){
        for(int i = 0; i < count/2; i++){
            aux *= 10;
        }
        x = aux1 / aux;
        y = aux1 % aux;
    }else{
        for(int i = 0; i < count-1; i++){
            aux *= 10;
        }
        x = aux1 / (aux);
        y = aux1 % 10;
    }
    printf("%d , %d",x,y);
}