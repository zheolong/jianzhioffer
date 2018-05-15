#include <stdio.h>
#include <stdlib.h>
#include <exception>

#define ROWS 4
#define COLUMES 3

void print_matrix_lean(int arr[ROWS][COLUMES], int rows, int columns);
void print_matrix_clockwise(int arr[ROWS][COLUMES], int row_start, int row_end, int col_start, int col_end);
int main(void)
{
    int arr[ROWS][COLUMES] = {  1,2,8,
                                2,4,9,
                                4,7,10,
                                6,8,11};
    print_matrix_clockwise(arr, 0, ROWS - 1, 0, COLUMES - 1);
    //print_matrix_lean(arr, ROWS, COLUMES);
}

void print_matrix_clockwise(int arr[ROWS][COLUMES], int row_start, int row_end, int col_start, int col_end)
{
    if ((row_start > row_end) || (col_start > col_end))
        return;

    for (int j = col_start; j <= col_end - 1; ++j)
        printf("%d ", arr[row_start][j]);

    for (int i = row_start; i <= row_end - 1; ++i)
        printf("%d ", arr[i][col_end]);

    if (row_end - row_start > 0) {
        for (int j = col_end; j > 0; --j)
            printf("%d ", arr[row_end][j]);
    }

    if (col_end - col_start > 0) {
        for (int i = row_end; i > 0; --i)
            printf("%d ", arr[i][col_start]);
    }

    print_matrix_clockwise(arr, row_start + 1, row_end -1, col_start + 1, col_end - 1);
}

void print_matrix_lean(int arr[ROWS][COLUMES], int rows, int columns)
{
    for (int sum = 0; sum <= columns - 1; ++ sum)
    {
        int i = 0;
        while (i < rows) {
            int j = sum - i;
            if (j >= 0)
                printf("%d ", arr[i][j]);
            else
                break;

            ++i;
        }
    }

    for (int sum = columns; sum <= rows + columns - 2; ++ sum)
    {
        int j = columns - 1;
        while (j >= 0)
        {
            int i = sum - j;
            if (i <= rows - 1)
                printf("%d ", arr[i][j]);
            else
                break;

            --j;
        }
    }
}
