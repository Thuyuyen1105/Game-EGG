
#include <iostream>

using namespace std;
#define num 7

void stage1display(int a[][num])
{
    cout<<"   ";
    for (int i=0; i<num; i++)
        cout<<" "<<i<<" ";
    cout<<endl;
    for (int i=0;i<num;i++)
    {
        cout<<i<<"  ";
        for (int j=0; j<num; j++)
        {
            if (a[i][j]==0)
                cout<<"   ";
            if (a[i][j]==1)
                cout<<" O ";
            if (a[i][j]==2)
                cout<<" . ";
        }
        cout<<endl;
    }
}
void createStage1(int a[][num])
{
    
    for (int i=0; i<num; i++)
        for (int j=0; j<num; j++)
            a[i][j]=1;
    a[0][0]=0;
    a[0][1]=0;
    a[0][5]=0;
    a[0][6]=0;
    a[1][0]=0;
    a[1][6]=0;
    a[5][0]=0;
    a[6][1]=0;
    a[6][5]=0;
    a[5][6]=0;
    a[6][0]=0;
    a[6][6]=0;
    a[6][2]=2;
}
bool rule(int a[][num],int row, int col, char move)// move includes 'w','s','a','d'
{
    if (row>=num||col>=num||row<0||col<0||a[row][col]==0||a[row][col]==2)
        return false;
    if (move=='w'&&row>=2)
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
    if (move=='s'&&row<=4)
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
    if (move=='a'&&col>=2)
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
    if (move=='d'&&col<=4)
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
void display()
{
    int count =0;
    int a[num][num], row, col;
    char move;
    createStage1(a);
    while (true)
    {
        stage1display(a);
        while (true)
        {
            
            cout<<endl<<"Enter position:"<<endl<<"Row: ";
            cin>>row;
            cout<<"Column: ";
            cin>>col;
            if (row==-1&&col==-1)
                return;
            cout<<"Enter direction ('w''s''a''d'): ";
            cin>>move;
            bool check = rule(a,row,col,move);
            if (check == false)
                cout<<"ERROR! It's not allowed. Try again"<<endl;
            else break;
        }
        count++;
        if (count ==35)
        {
            cout<< "CONGRATULATIONS!!";
            return;
        }
    }
}
void guide()
{
    cout<<"a. 'O' represent an egg, '.' represent an empty place"<<endl;
    cout<<"b. Your mission is break eggs until there's only 1 egg left\n";
    cout<<"c. To break an egg, you chose another egg next to it, follow the direction, if there is an empty place, the egg you chose will replace that position, the place of 2 eggs will be empty"<<endl;
    cout<<"d. Enter row -1 and Column -1 to exit the program"<<endl;
}
int main()
{
    cout<<"____WElCOME TO EGG GAME_____"<<endl;
    while (true)
    {
        int choice;
        cout<<"1. Rule "<<endl<<"2. Play"<<endl<<"Your choice: ";
        cin>>choice;
        if (choice==2)
            display();
        else if (choice==1)
            guide();
        else
            return 0;
    }
        
}
