#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    //底层是红黑树
    //Java的TreeMap对应C++的std::map
    
    map<int,string> treeMap;
    treeMap[5] = "这是5";
    treeMap[7] = "这是7";
    treeMap[1] = "这是1";
    treeMap[2] = "这是2";
    treeMap[3] = "这是3";
    treeMap[4] = "这是4";
    treeMap[8] = "这是8";

    //containsKey
    cout<<(treeMap[4])<<endl;
    treeMap[4]="Zhang is 4";
    cout<<treeMap[4]<<endl;
    treeMap.erase(4);//remove
    //C++ map取不存在的值会自动插入默认值（空字符串），所以我们用count()判断是否为空
    cout<<(treeMap.count(4)==0?"true":"false")<<endl;
    //first key and last key
    cout<<treeMap.begin()->first<<endl;
    cout<<treeMap.rbegin()->first<<endl;

    //TreeMap中，所用的key,<=4且最近的key是什么（ceiling key)
    //C++ 中用lower_bound 直接找第一个>=4的位置
    auto it_ceil=treeMap.lower_bound(4);
    if(it_ceil !=treeMap.end())
    {
        cout<<it_ceil->first<<endl;

    }
    cout<<"==========="<<endl;

    //Java的TreeSet对应C++的set
    set<int> set;
    set.insert(3);
    set.insert(3);
    set.insert(4);
    set.insert(4);
    cout<<"有序表大小: "<<set.size()<<endl;

    //模拟pollFirst(): 去最小值并弹出
    while(!set.empty())
    {
        cout<<*set.begin()<<endl;
       set.erase(set.begin());
    }
    cout<<"====================="<<endl;

    //堆：Java默认小根堆,C++默认大根堆
    //要在C++实现默认小根堆，需要传入greater<int>比较器
    priority_queue<int,vector<int>,greater<int>> heap1;
    heap1.push(3);
    heap1.push(3);
    heap1.push(5);
    heap1.push(4);
    cout<<"堆大小："<<heap1.size()<<endl;
    while(!heap1.empty())
    {
        cout<<heap1.top()<<" ";
        heap1.pop();
    }
    cout<<endl;
    cout<<"========================"<<endl;
    priority_queue<int> heap2;
    heap2.push(3);
    heap2.push(3);
    heap2.push(5);
    heap2.push(4);
    cout<<"堆大小： "<<heap2.size()<<endl;
    while(!heap2.empty())
    {
        cout<<heap2.top()<<" ";
        heap2.pop();
    }
    cout<<endl;


}
