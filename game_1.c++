#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include<conio.h>
using namespace std;
void compressleft(int board[4][4])
{
   int i,j,k;
   for(j=0;j<4;j++)
   {
    int temp[4]={0};
    k=0;
   for(i=0;i<4;i++)
   {
    if(board[j][i]!=0)
    {
       temp[k++]=board[j][i];
    }
   }
   for(i=0;i<4;i++)
   {
    board[j][i]=temp[i];
   }
   }
}
void mergeleft(int board[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
     for(j=0;j<3;j++)
     {
          if(board[i][j]!=0 && board[i][j]==board[i][j+1])
          {
                board[i][j]=board[i][j]*2;
                board[i][j+1]=0;
          }
     }
    }
   
}
void moveleft(int board[4][4])
{
    
    compressleft(board);
    mergeleft(board);
    compressleft(board);
}
   
void generation_of_numbers(int board[4][4])
{
    int empty = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == 0)
                empty++;
        }
    }
    if(empty == 0)
        return;

    int r, c;
    do
    {
        r = rand() % 4;
        c = rand() % 4;
    }
    while(board[r][c] != 0);
    if(rand() % 10 == 0)
        board[r][c] = 4;
    else
        board[r][c] = 2;
}

void printboard( int board[4][4])
{

    for(int i = 0; i < 4; i++)
    {
        cout << "+------+------+------+------+----"
             << endl;

        for(int j = 0; j < 4; j++)
        {
            cout << "|" << setw(4) << board[i][j] << "\t";
        }

        cout << "|" << endl;
    }

    cout << "+------+------+------+------+----"
         << endl;
    
  
    
}
void compressright(int board[4][4])
{
   int i,j,k;
   for(j=0;j<4;j++)
   {
    int temp[4]={0};
    k=3;
   for(i=3;i>=0;i--)
   {
    if(board[j][i]!=0)
    {
       temp[k--]=board[j][i];
    }
   }
   for(i=0;i<4;i++)
   {
    board[j][i]=temp[i];
   }
   }
  
}
void mergeright(int board[4][4])
{
    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 3; j > 0; j--)
        {
            if(board[i][j] != 0 && board[i][j] == board[i][j-1])
            {
                board[i][j] *= 2;
                board[i][j-1] = 0;
            }
        }
    }
}
void moveright(int board[4][4])
{
    compressright(board);
    mergeright(board);
    compressright(board);
}
void compressup(int board[4][4])
{
   int i,j,k;
   for(j=0;j<4;j++)
   {
    int temp[4]={0};
    k=0;
   for(i=0;i<4;i++)
   {
    if(board[i][j]!=0)
    {
       temp[k++]=board[i][j];
    }
   }
   for(i=0;i<4;i++)
   {
    board[i][j]=temp[i];
   }
   }
   
  
}
void mergeup(int board[4][4])
{
    int i, j;

    for(i = 0; i <3; i++)
    {
        for(j = 0; j <4; j++)
        {
            if(board[i][j] != 0 && board[i][j] == board[i+1][j])
            {
                board[i][j] *= 2;
                board[i+1][j] = 0;
            }
        }
    }
}
void moveup(int board[4][4])
{
    compressup(board);
    mergeup(board);
    compressup(board);
}
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
bool gameOver(int board[4][4])
{
    // Check for any empty cell
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == 0)
                return false;
        }
    }

    // Check horizontal neighbors
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == board[i][j+1])
                return false;
        }
    }

    // Check vertical neighbors
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][j] == board[i+1][j])
                return false;
        }
    }

    return true;
}
bool checkWin(int board[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == 2048)
                return true;
        }
    }
    return false;
}

int main()
{
    int board[4][4] = {0};

    srand(time(0));

    // Generate first two tiles
    generation_of_numbers(board);
    generation_of_numbers(board);

    system("cls");
    printboard(board);

    while(true)
    {
        int key = getch();

        if(key == 224 || key == 0)
        {
            key = getch();
            int oldBoard[4][4];
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    oldBoard[i][j] = board[i][j];
                }
            }
            switch(key)
            {
                case 75:    
                    moveleft(board);
                    break;

                case 77:    
                    moveright(board);
                    break;

                case 72:    
                    moveup(board);
                    break;

                case 80:   
                    movedown(board);
                    break;

                default:
                    continue;
            }
            bool changed = false;

            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(oldBoard[i][j] != board[i][j])
                    {
                        changed = true;
                        break;
                    }
                }
                if(changed)
                    break;
            }
            if(changed)
            {
                generation_of_numbers(board);
            }

            system("cls");
            printboard(board);
            if(checkWin(board))
            {
                cout << "\nCongratulations! You reached 2048!\n";
                break;
            }

            if(gameOver(board))
            {
                cout << "\nGame Over! No more moves possible.\n";
                break;
            }
        }

        // ESC key to quit
        if(key == 27)
        {
            cout << "\nGame exited.\n";
            break;
        }
    }

    return 0;
}