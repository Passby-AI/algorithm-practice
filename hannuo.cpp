#include <iostream>

using namespace std;

void move(int,char,char,char);

int main()
{
    int n;
    cin>>n;

    move(n,'A','B','C');
}

// 递归函数：将 n 个圆盘从 A 移动到 C，借助 B
void move(int n, char A, char B, char C) {
if (n == 1) {
cout << "将圆盘 1 从 " << A << " 移动到 " << C << endl;
} else {
// 第一步：将 n-1 个圆盘从 A 移动到 B，借助 C
move(n - 1, A, C, B);
// 第二步：将第 n 个圆盘从 A 移动到 C
cout << "将圆盘 " << n << " 从 " << A << " 移动到 " << C << endl;
// 第三步：将 n-1 个圆盘从 B 移动到 C，借助 A
move(n - 1, B, A, C);
}
}
