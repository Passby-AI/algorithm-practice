#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Student
{
    int age;
    string name;
    Student(int a,string b)
    {
        age=a;
        name=b;
    }
};
/*
 * Java的HashSet/HashMap对自定义类默认使用内存地址，
 * C++的unordered_set/unordered_map需对自定义类手动提供哈希函数，否则编译报错
*/
/*
struct StudentHash{
    size_t operator() (const Student& s) const
    {
        return hash<int>()(s.age) ^ hash<string>()(s.name);
    }
};
struct StudentEqual{
    bool operator() (const Student& a,const Student& b) const
    {
        return a.age==b.age && a.name==b.name;
    }
};
*/
int main()
{
   // unordered_map<Student,string,StudentHash,StudentEqual> map;

    string str1="hello";
    string str2="hello";

    cout<<"=========Compare Their value============="<<endl;
    cout<<(str1==str2 ? "True":"False")<<endl;
    cout<<(&str1==&str2? "True":"False")<<endl;
    //地址不同
    //java的HashSet--> C++的std::unordered_set
    unordered_set<string> set;
    //C++中用count()/find()判断是否包含
    set.insert(str1);
    cout<<(set.count("hello") ? "True":"False")<<endl;
    cout<<(set.count(str2) ? "True":"False")<<endl;

    set.insert(str2);//值相同，不会重复插入
    cout<<set.size()<<endl;
    set.erase(str1);
    set.clear();
    cout<<set.size()<<endl;
    cout<<"Is the set empty?:  "<<(set.empty()? "True":"False")<<endl;
    cout<<"==========================================="<<endl;

    //java的HashMap->C++的std::unordered_map
    unordered_map<string, string> map1;
    map1[str1]="World";
    cout<<(map1.count("hello") ? "True":"False")<<endl;
    cout<<(map1.count(str2)? "True":"False")<<endl;
    cout<<map1[str2]<<endl;
    
    //C++直接用map["你好"],当key不存在时，会插入默认指；
    //要模拟Java的map.get("你好")==null,要检查它在map中是否存在(count==0)
    cout<<(map1.count("你好")==0 ? "true":"false")<<endl;
    map1.erase("hello");
    cout<<map1.size()<<endl;
    map1.clear();
    cout<<(map1.empty() ? "true":"False")<<endl;

    cout<<"======================="<<endl;
    //一般笔试中未必要申请哈希表
    unordered_map<int,int> map2;
    map2[56]=7285;
    map2[34]=3671263;
    map2[17]=716311;
    map2[24]=1263161;

    //上面map2的行为，可以用如下数组替代
    int arr[100]={0};
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161; 
    //哈希表的增删查改都可以用数组替代，前提是key的范围可控，固定
    std::cout<<"笔试场合中哈希表往往会被数组替代"<<endl;

    //原java的代码中，Student没有重写hashCode()和equal()；
    //因此不同的实例即使内容相同，也会被当作不同的key
    //在c++中，为了完美复刻“按地址引用”的哈希行为，我们使用对象指针做key
    Student* s1=new Student(17,"Zhang");
    Student* s2=new Student(17,"Zhang");
    unordered_map<Student*, string> map3;
    map3[s1]="This is Zhang";
    map3[s2]= "This is another Zhang";
    std::cout << (map3.count(s1) ? "true" : "false") << std::endl;
    std::cout << (map3.count(s2) ? "true" : "false") << std::endl; // false，因为是不同的指针
    
    map3[s2] = "这是另一个张三";
    std::cout << map3.size() << std::endl; // size 为 2
    std::cout << map3[s1] << std::endl;
    std::cout << map3[s2] << std::endl;
    delete s1;
    delete s2;

    return 0;
}
