#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define N 5

int dx[8]={1,2,-1,-2,-2,-1,2,1};
int dy[8]={2,1,2,1,-1,-2,-1,-2};

int board[N][N];

void printBoard();
bool solveKT(int ,int ,int );

int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            board[i][j]=0;
    }
    int startX=0;
    int startY=0;
    board[startX][startY]=1;

    if(solveKT(startX, startY, 2))
    {
        printf("find\n");
        printBoard();
    }else{
        printf("no solves");
    }

    return 0;
}

bool solveKT(int x,int y,int moveCount)
{
    if(moveCount>N*N) return true;
    for(int i=0;i<8;i++)
    {
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX>=0&&nextY>=0&&nextY<5&&nextX<5&&board[nextX][nextY]==0)
        {
            board[nextX][nextY]=moveCount;
            if(solveKT(nextX,nextY,moveCount+1)) return true;
            board[nextX][nextY]=0;
        }
    }
    return false;

}

void printBoard()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%2d ",board[i][j]);
        }
        printf("\n");
    }
}

    


