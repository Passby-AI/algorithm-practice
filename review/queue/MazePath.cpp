#include <iostream>
#include <Stack>
using namespace std;
struct Point
{
    int x,y;
    Point (int x,int y):x(x),y(y){}
};
void MazePath(int arr[][10],Point start,Point end)
{
  stack<Point> PointStack;
  Point p=start;
  arr[p.x][p.y]=2;
  PointStack.push(p);
  do{
    if(arr[p.x][p.y+1]==0)    arr[p.x][++p.y]=2;
    else if (arr[p.x+1][p.y]==0)
        arr[++p.x][p.y] = 2;
    else if (arr[p.x][p.y-1]==0)
        arr[p.x][--p.y] =2;
    else if (arr[p.x-1][p.y]==0)
        arr[--p.x][p.y] = 2;
    else
    {
       p=PointStack.top();
       PointStack.pop();
       arr[p.x][p.y]=1;
       p=PointStack.top();
       PointStack.pop();
    }

  }while((p.x!=end.x)||(p.y!=end.y)); 


}

void PrintPath(int arr[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]==-1)   cout<<"#";
            else if(arr[i][j]==2)    cout<<"*";
            else cout<<"[]";

        }
        cout<<"\n";
    }
    cout<<"\n";
}
