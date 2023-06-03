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
void hint()
{
    cout<<"This is a way to solve\n";
    cout<<"1. (6;4) a\n2. (4;3) s\n3. (5;1) d\n4. (6;3) w\n5. (5;5) a\n6. (4;3) s\n";
    cout<<"7. (6;2) d\n8. (3;4) s\n9. (6;4) w\n10. (3;6) a\n11. (3;4) s\n12. (4;6) a\n13. (5;4) w\n";
    cout<<"14. (3;2) s\n15. (4;0) d\n16. (5;2) w\n17. (2;2) s\n18. (3;0) f\n19. (4;2) w\n20. (1;2) s\n";
    cout<<"21. (2;0) d\n22. (3;2) w\n23. (3;4) a\n24. (1;4) s\n25. (2;6) a\n26. (3;4) w\n27. (0;4) s\n";
    cout<<"28. (1;2) d\n29. (2;4) a\n30. (3;2) w\n31. (1;5) a\n32. (0;3) s\n33. (0;2) s\n34. (2;3) a\n";
    cout<<"35. (1;1) s\n";
}
