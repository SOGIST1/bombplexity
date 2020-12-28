#include <stdio.h>

#define BOARD_NUMBER 5


int A[BOARD_NUMBER][BOARD_NUMBER] = {
    1,1,1,1,1,
    0,0,0,1,1,
    1,1,1,1,1,
    1,0,0,0,0,
    1,1,1,1,1
};

int path[BOARD_NUMBER][BOARD_NUMBER] = {0};

int findPath(int i, int j, int n) // i and j are coordinates, n is square size of array
{
    if(i == n - 1 && j == n - 1) // checks for endpoint
    {
        path[i][j] = 1;
        return 1;
    }

    if(A[i][j] == 1) // checks if current square is movable
    {
        path[i][j] = 1;  // writes to square that it is path

        if (path[i][j + 1] == 0 && findPath(i, j + 1, n) == 1) return 1; // checks right square
        if (path[i + 1][j] == 0 && findPath(i + 1, j, n) == 1) return 1; // checks down square
        if (path[i][j - 1] == 0 && findPath(i, j - 1, n) == 1) return 1; // checks left square
        if (path[i - 1][j] == 0 && findPath(i - 1, j, n) == 1) return 1; // checks up square

        path[i][j] = 0; // writes zero if no nearby squares are movable
    }

    return 0;
}


int main() // start program
{
    int i0;
    int j0;

    printf("What is starting point i --> ");
    scanf("%d", &i0);

    printf("What is starting point j --> ");
    scanf("%d", &j0);

    findPath(i0, j0, BOARD_NUMBER); // starting point (0, 0) and 4x4 grid
                       // makes the path grid

    // prints the path grid
    int count = -1; // -1 so the starting place does not get counted as a move
    for(int i = 0; i < BOARD_NUMBER; i++) // goes through i values
    {
        for(int j = 0; j < BOARD_NUMBER; j++) // goes through j values
        {
            printf("%d ",path[i][j]);
            if(path[i][j])
            {
                count++;
            }
        }
        printf("\n");
    }

    printf("moves -> %d\n", count);

    return 0; // end program
}
