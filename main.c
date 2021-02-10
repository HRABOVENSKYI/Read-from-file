#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ELEMENTS 81
#define LONG_DIAGONAL_LEN 9
#define SHORT_DIAGONAL_LEN 8
#define MAX_LINE_LENGTH 9
#define MAX_ELEMENT_INDEX 8

int numberArray[NUM_OF_ELEMENTS];
int k;
int i, j, n;
int a[MAX_LINE_LENGTH][MAX_LINE_LENGTH] = {0};

void read_file();
void fill_matrix();
void print_matrix();

int main() {
    read_file();
    fill_matrix();
    print_matrix();
    return 0;
}

void read_file() {
    //read file into array
    FILE *myFile;
    myFile = fopen("D:/NoteBook/matrix.txt", "r");

    if (myFile == NULL) {
        printf("Error Reading File\n");
        exit(0);
    }

    for (k = 0; k < NUM_OF_ELEMENTS; k++) {
        fscanf(myFile, "%d", &numberArray[k]);
    }

    fclose(myFile);
}

void fill_matrix() {
    // put the numbers in correct order
    k = 0;
    // n - the length of current diagonal
    // fill matrix form [0][0] to long diagonal
    for (n = 0; n < LONG_DIAGONAL_LEN; n++) {
        for (i = 0; i <= n; i++) {
            a[n - i][i] = numberArray[k];
            k++;
        }
    }

    k = NUM_OF_ELEMENTS - 1;
    // fill matrix from [MAX_ELEMENT_INDEX][MAX_ELEMENT_INDEX] to short diagonal
    for (n = 0; n < SHORT_DIAGONAL_LEN; n++) {
        for (i = 0; i <= n; i++) {
            a[MAX_ELEMENT_INDEX - (n - i)][MAX_ELEMENT_INDEX - i] = numberArray[k];
            k--;
        }
    }
}

void print_matrix() {
    // print the matrix
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        for (j = 0; j < MAX_LINE_LENGTH; j++) {
            printf("%02d ", a[i][j]);
        }
        printf("\n");
    }
}
