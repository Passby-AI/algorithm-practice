#include <iostream>
using namespace std;

int main()
{
    long long a[9][5]={0};
    int x,y,c,d;
    cin>>x>>y>>c>>d;
    //for(int i=0;i<x+1;i++)
    //{
      //  for(int j=0;j<y+1;j++)
        //{
          //  a[i][j]=1;
        //}
    //}
    // ... (读入 x, y, c, d)

// 建立一个数组（或函数）来标记马的控制点
// 为了代码简洁，这里我们直接在循环里判断

for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {

        // 1. 优先判断：当前点是否是马或马的控制点？
        if ( (i==c&&j==d) || (i==c-1&&j==d-2) || (i==c+1&&j==d-2) || 
             (i==c-2&&j==d-1) || (i==c+2&&j==d-1) || (i==c-2&&j==d+1) || 
             (i==c+2&&j==d+1) || (i==c-1&&j==d+2) || (i==c+1&&j==d+2) ) 
        {
            a[i][j] = 0; // 障碍点，路径数为0
        } 
        // 2. 其次：是否是起点？
        else if (i == 0 && j == 0) {
            a[i][j] = 1; // 起点（base case），路径数为1
        }
        // 3. 再次：是否在上边界？
        else if (i == 0) {
            a[i][j] = a[i][j-1]; // 只能从左边来
        }
        // 4. 再次：是否在左边界？
        else if (j == 0) {
            a[i][j] = a[i-1][j]; // 只能从上边来
        }
        // 5. 最后：一般情况
        else {
            a[i][j] = a[i-1][j] + a[i][j-1]; // 从上边和左边来
        }
    }
}

    cout<<a[x][y]<<endl;
}
