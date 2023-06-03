#include <iostream>
#include "Header.h"
using namespace std;
#define num 7


void display()
{
    int count =0;
    int step[35][3];
    int a[num][num], row, col;
    char direc, goback;
    createStage1(a);
    stage1display(a);
        while (true)
        {
            cout<<endl<<"Enter position"<<endl<<"Row: ";
            cin>>row;
            cout<<"Column: ";
            cin>>col;
            if (row==-1&&col==-1)
                return;
            cout<<"Enter direction ('w''s''a''d'): ";
            cin>>direc;
            bool check = rule(a,row,col,direc);
            if (check == false)
                cout<<"ERROR! It's not allowed. Try again"<<endl;
            else
            {
                step[count][0]=row;
                step[count][1]=col;
                if (direc=='w')
                    step[count][2]=1;
                else if (direc=='s')
                    step[count][2]=2;
                else if (direc=='a')
                    step[count][2]=3;
                else
                    step[count][2]=4;
                count++;
            }
            stage1display(a);
            while (count >0)
            {
                cout<<"Go back 1 step? y/n: ";
                cin>>goback;
                if (goback=='y')
                {
                    count--;
                    back1step(a,step,count);
                    stage1display(a);
                }
                else
                    break;
            }
                    
            if (count ==35)
            {
                cout<< "CONGRATULATIONS!!";
                return;
            }
        }
    }

    
    
int main()
{
    int count=0;
    cout<<"____WElCOME TO EGG GAME_____"<<endl;
    while (true)
    {
        int choice;
        cout<<"__________\n1. Rule "<<endl<<"2. Play"<<endl;
        if (count >=3)
            cout<<"3. Hint\n";
        cout<<"__________\nYour choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: guide();
                break;
            case 2:
                display();
                break;
            case 3:
                if (count >=3)
                    hint();
                else
                    count--;
                break;
            default: return 0;
        }
        count ++;
    }
    
}
