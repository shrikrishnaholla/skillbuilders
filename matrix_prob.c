/**
* You have a matrix of N x N filled with 1 or 0. You can move only 1 step either right or 1 step down. 
* You need to count maximum number of "connected 1s" in given matrix. 
*
* For example
* 0 0 1 1
* 1 1 1 0
* 1 0 1 0
* 0 1 0 1
*
* [Start from top left] maximum no. of 1s is 4
* Locations: [1,0][1,1][1,2][2,2]
*/

#include<stdio.h>

int matrix[10][10];
int maxConnections = 0;
void connect(int, int, int);

int main(int argc, char const *argv[])
{
    int i, j, n ;
    printf("Enter the order of the matrix\n");
    scanf("%d", &n);
    printf("Enter a matrix of order %d\n", n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (matrix[i][j])
                connect(i,j,1);
            else
                continue;
    printf("The maximum number of connected 1s : %d\n", maxConnections);
    return 0;
}

void connect(int i, int j, int count) {
    if (!matrix[i+1][j]  && !matrix[i][j+1]) 
    {
        if (count > maxConnections)
            maxConnections = count;
        return;
    }

    else if (matrix[i+1][j] && matrix[i][j+1]) // If there is a choice to make, take one of the paths,
    {                                          // traverse till the end, update maxConnections if necessary,
        connect(i+1,j,count+1);                // then backtrack, make the next choice and do the same
        connect(i,j+1,count+1);
    }

    else if (matrix[i+1][j])
        connect(i+1,j,count+1);

    else
        connect(i,j+1,count+1);
}