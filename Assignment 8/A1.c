#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int n;

/* Check whether a queen can be placed at row, col */
int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Same column
        if (board[i] == col)
            return 0;

        // Same diagonal
        if (abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

/* Display the chessboard */
void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

/* Backtracking function to find ALL solutions */
void solveNQueens(int row)
{
    // All queens have been placed
    if (row == n)
    {
        printBoard();
        return;
    }

    // Try placing queen in every column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row] = col;

            // Move to next row
            solveNQueens(row + 1);

            // Backtrack
            board[row] = -1;
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid input! N must be between 1 and 20.\n");
        return 1;
    }

    // Initialize board
    for (int i = 0; i < n; i++)
        board[i] = -1;

    // Find all solutions
    solveNQueens(0);
    return 0;
}