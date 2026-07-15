#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
void printboard(int row,int col)
{
    int board[row][col];
    int i,j;
    for (i=0;i<row;i++)
    {
        
        for(j=0;j<col;j++)
        {
            board[i][j]=0;
        }
    }
    for (i=0;i<row;i++)
    {
        if(row==4) 
         cout<<"+------+------+-----+-----+-----+"<<endl;
        else
          cout<<"+------+------+-----+-----+-----+------+"<<endl;
        for(j=0;j<col;j++)
        {
            cout <<"|"<<setw(4)<<board[i][j]<<"\t";
        }
        cout<<"|";
        cout << endl;
    }
    if(col==4)
     cout<<"+------+------+-----+-----+-----+"<<endl;
    else
          cout<<"+------+------+-----+-----+-----+------+"<<endl; 
    generation_of_numbers(board) ;    
}
void generation_of_numbers(int board)
{
 int r,c;  
 srand(time(0));
 r=rand()%4;
 c=rand()%4;
 int board[r][c]=2;
 
}

int main()
{
    int row,col;
    cout << "Enter the board size you want 4x4 or 5x5:";
    cin >> row >> col;
    printboard(row,col);
}