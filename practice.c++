#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void compressdown(int board[4][4])
{
    int i, j, k;

    for(j = 0; j < 4; j++)
    {
        int temp[4] = {0};
        k = 3;
        for(i = 3; i >= 0; i--)
        {
            if(board[i][j] != 0)
            {
                temp[k--] = board[i][j];
            }
        }
        for(i = 0; i < 4; i++)
        {
            board[i][j] = temp[i];
        }
    }
}
void mergedown(int board[4][4])
{
    int i, j;

    for(i = 3; i > 0; i--)
    {
        for(j = 0; j < 4; j++)
        {
            if(board[i][j] != 0 && board[i][j] == board[i-1][j])
            {
                board[i][j] *= 2;
                board[i-1][j] = 0;
            }
        }
    }
}
void movedown(int board[4][4])
{
    int i;
    compressdown(board);
    mergedown(board);
    compressdown(board);
}
int main()
{
    srand(time(0));
    int board[4][4],i;
    for(i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            board[i][j]=0;
        }
    }
    for(i=0;i<=1;i++)
    {
       int r=rand()%4;
       int c=rand()%4;
       board[r][c]=2;
    }
    for(i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    movedown(board);
}
    