#include <functional>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    /*while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << a + b << endl;
    }*/
    int n=0;
    cin>>n;
// 使用 vector 替代 C 风格二维数组
    // 初始化一个大小为 n，每个元素是一个大小为 2 的 vector
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[i][1]=max(a,b);
        arr[i][0]=min(a,b);
    }
    sort(arr.begin(),arr.end(),[](const vector<int>& a,vector<int>& b){
            return a[0]<b[0];
            });
    priority_queue<int,vector<int>,greater<int>> queue;
    
    int ans=0;

    for(int i=0;i<n;i++)
    {
        while(!queue.empty()&& queue.top()<=arr[i][0])
        {
            queue.pop();
        }
        queue.push(arr[i][1]);
        int size=queue.size();
        ans=max(ans,size);

    }

    cout<<ans<<endl;
    return 0;

}
// 64 位输出请用 printf("%lld")
