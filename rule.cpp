#include <iostream>
#define num 7
using namespace std;
void guide()
{
    cout<<"a. 'O' represent an egg, '.' represent an empty place"<<endl;
    cout<<"b. Your mission is break eggs until there's only 1 egg left\n";
    cout<<"c. You chose an egg, if there is an egg next to it and next to an empty position you can break that 2 eggs, that 2 positions will become empty. There will be an new egg at the first empty position. A"<<endl;
    cout<<"d. Enter row -1 and Column -1 to exit the program"<<endl;
}
bool rule(int a[][num],int row, int col, char direc)// move includes 'w','s','a','d'
{
    if (row>=num||col>=num||row<0||col<0||a[row][col]==0||a[row][col]==2)
        return false;
    if (direc=='w'&&row>=2)
    {
        if (a[row-1][col]==1&&a[row-2][col]==2)
        {
            a[row][col]=2;
            a[row-1][col]=2;
            a[row-2][col]=1;
            return true;
        }
        else
            return false;
    }
    if (direc=='s'&&row<=4)
    {
        if (a[row+1][col]==1&&a[row+2][col]==2)
        {
            a[row][col]=2;
            a[row+1][col]=2;
            a[row+2][col]=1;
            return true;
        }
        else
            return false;
    }
    if (direc=='a'&&col>=2)
    {
        if (a[row][col-1]==1&&a[row][col-2]==2)
        {
            a[row][col]=2;
            a[row][col-1]=2;
            a[row][col-2]=1;
            return true;
        }
        else
            return false;
    }
    if (direc=='d'&&col<=4)
    {
        if (a[row][col+1]==1&&a[row][col+2]==2)
        {
            a[row][col]=2;
            a[row][col+1]=2;
            a[row][col+2]=1;
            return true;
        }
        else
            return false;
        
    }
    return false;
}
void back1step(int a[][num], int step[35][3], int& move)
{
    //    step        0 1 2 3 4 5 6 7
    //    row
    //    column
    //    direction
    
    //    about direction
    //    1 mean 'w'
    //    2 mean 's'
    //    3 mean 'a'
    //    4 mean 'd'
    int row, col, direc;
    direc=step[move][2];
    row=step[move][0];
    col=step[move][1];
    if (direc==1)
    {
        a[row][col]=1;
        a[row-1][col]=1;
        a[row-2][col]=2;
    }
    else if (direc==2)
    {
        a[row][col]=1;
        a[row+1][col]=1;
        a[row+2][col]=2;
    }
    else if (direc==4)
    {
        a[row][col]=1;
        a[row][col+1]=1;
        a[row][col+2]=2;
    }
    else if (direc==3)
    {
        a[row][col]=1;
        a[row][col-1]=1;
        a[row][col-2]=2;
        
    }
    
}
