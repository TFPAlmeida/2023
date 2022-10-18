//
// Created by tiago on 15/10/2022.
//

#include "pr01.h"

int main_pr01() {
    char frase[] = "aaaad";
    //print_ascii_for_char(' ');
    //float x = divide_two_ints_into_float(4, 2);
    //printf("X = %.0f", x);
     //print_ascii_table_letters();
    //int i = is_digit('1');
    // printf("X = %d", i);
    //is_digit_v2('a');
    //read_key_print_digit_or_notdigit();
    //parse_inputstream_count_chartypes();

   // int e = read_input_stream_count_given_char(frase, sizeof(frase));
    //printf("%d", e);
    //find_longest_word_inputstream ();
    find_longest_sequence_repeated_chars_from_inputstream ();
    return 0;
}

/**
* print the ascii value of a given character
* output -> readCharPrintAscii('a') : 97
* @param c - char to be converted
*/
void print_ascii_for_char(char c) {
    printf("ascii value of '%c' is : %d\n", c, c);
}

/**
* Divide two integer values, e.g. 10 / 3 = 3.33
* @param a - dividend
* @param b - divisor
* @return - (float) a / b
*/
float divide_two_ints_into_float(int a, int b) {
    return a / b;
}

/**
* Print ascii table letters from 'a' to 'z' and from 'A' to 'Z'
* output:  |       A       |       65      ||      a       |       97      |
       |       B       |       66      ||      b       |       98      |
*/
void print_ascii_table_letters(void) {
    // Declare Variables
    int i = 0;
    printf("Character \t ASCII Value\n\n");
    //Print ASCII Values
    for (i = 65; i <= 122; i++) {
        printf("%c \t\t %d\n", i, i);
    }
}

/**
 * This function checks if a char is a digit or not.
 * @param c - char to be checked.
 * @return 1 (if is digit); 0 otherwise.
 */
int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Verifica se um char é digito:
 * @param c - char
 * @return 1 se "digito" ou 0 se "nao digito".
 */
int is_digit_v2(char c) {
    return (c >= '0' && c <= '9');
}

/**
* Iteratively checks if a user input char is a digit (exists with 'e' or 'E')
* e.g.: '0' is a digit; 'a' is not a digit
*/
void read_key_print_digit_or_notdigit() {
    char c = '\0';
    printf("Insira um digito: \n");
    scanf("%c", &c);

    if (is_digit(c)) {
        printf("is digit");
    } else if (toupper(c) >= 'A' && toupper(c) <= 'Z') {
        printf("is not a digit");
    }
}

/**
* Counts how many times a given char appears in a
* series of chars entered by the user in input stream.
* @param charToCount - char to count
* @return - number of occurrences
*/
int read_input_stream_count_given_char(const char charToCount[], int size) {
    int count = 0;
    char c = '\0';
    printf("Input char that you what to verify: \n");
    scanf("%c", &c);
    for (int i = 0; i < size; i++) {
        if(charToCount[i] == c){
            count++;
        }
    }
    return count;
}

/**
* Finds the longest sequence of repeated chars in a series of chars entered by the user tthrough inputstream.
 e.g.
* input: "abcccdedededef"; output: "The character c appeard consecutively 3 times\n"
* input: "abcdef"; output: "The character a appeard consecutively 1 times\n"
* input: "abdddccdddefffff"; output: "The character f appeard consecutively 5 times\n"
*/
void find_longest_sequence_repeated_chars_from_inputstream (void){
   char c[10];
   int count = 1, aux = 0, maior= 0;
   scanf(" %s", c);
   char dp[10][2];
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 2; y++){
           dp[x][y] = 0;
        }
    }
   for(int i = 0; c[i] != '\0'; i++){
       if(c[i] == c[i+1]){
           count++;

       }else{
           dp[i][0] = c[i];
           dp[i][1] = count;
           count = 1;
       }
   }

   for(int x = 0; x < 10; x++){
       aux = dp[x][1];
       if(aux > maior){
           maior = aux;
       }
   }

    for(int x = 0; x < 10; x++){

        if(dp[x][1] == maior){
            printf("%c, %d",dp[x][0],dp[x][1]);
        }
    }
}

/**
* Finds the logest word in a series of chars iteratively entered by the user through inputstream, e.g.
* input: "ab ccc dededede f"; output: "The longest word has 8 characters\n"
* input: "aa 123 ababa23"; output: "The longest word has 7 characters"
* input: "a b c d e"; output: "The longest word has 1 characters"
*/
void find_longest_word_inputstream (void){
    char frase[] = "Tiago Almeida";
    int letters = 0, longest = 0;

    for(int i = 0; frase[i] != '\0'; i++){
        letters++;
        if(frase[i] == ' '){
            if(letters > longest){
                longest = letters;
            }
            letters = 0;
        }
    }
}

