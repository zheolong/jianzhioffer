#include <stdio.h>
#include <stdlib.h>
#include <exception>

#define ROWS 4
#define COLUMES 4

bool array_search(int arr[ROWS][COLUMES], int rows, int columns, int target);

int main(int argc, char *argv[])
{
    int arr[ROWS][COLUMES] = {  1,2,8,9,
                                2,4,9,12,
                                4,7,10,13,
                                6,8,11,15};
    array_search(arr, ROWS, COLUMES, atoi(argv[1]));
}

bool array_search(int arr[ROWS][COLUMES], int rows, int columns, int target)
{
    bool found = false;

    if (NULL == arr && NULL == *arr) {
        //throw new std::exception("array is null");
    }

    if (rows <= 0) {
        //throw new std::exception("rows must be positive");
    }

    if (columns <= 0) {
        //throw new std::exception("columns must be positive");
    }

    int i = 0, j = columns - 1;
    
    do {
        if (arr[i][j] == target) {
            printf("i: %d, j: %d", i, j);
            found = true;
            break;
        } else if (target > arr[i][j]) {
            ++i;
        } else {
            --j;
        }
    } while (i < rows || j >= 0);

    return found;
}
