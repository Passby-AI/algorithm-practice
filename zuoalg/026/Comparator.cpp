#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Employee{
public:
    int company;
    int age;
    Employee(int c, int a)
    {
        company=c;
        age=a;
    }
};


struct EmployeeComparator
{
    //返回true认为o1的优先级更高（排在前面）
    //对应Java中的return o1.age - o2.age<0
    bool operator()(const Employee* o1,const Employee* o2) const{
       return o1->age<o2->age; 
    }
       
};

int main()
{
   // 使用指针来完美模拟 Java 的引用类型（为了后面演示内存地址兜底机制）
    Employee* s1 = new Employee(2, 27);
    Employee* s2 = new Employee(1, 60);
    Employee* s3 = new Employee(4, 19);
    Employee* s4 = new Employee(3, 23);
    Employee* s5 = new Employee(1, 35);
    Employee* s6 = new Employee(3, 55); 

    vector<Employee*> arr={s1, s2, s3, s4, s5,s6};

    //1. 使用仿函数对象排序（按age升序）
    sort(arr.begin(),arr.end(),EmployeeComparator());
    for(Employee* e :arr)
    {
        cout<<e->company<<" , "<<e->age<<endl;
    }
    cout<<"========="<<endl;
    //使用Lambda表达式排序（按age降序，对应java的b.age - a.age）
    sort(arr.begin(),arr.end(),[](const Employee* a, const Employee* b){
        return a->age>b->age;
            });
    for(Employee* e:arr)
    {
       cout<<e->company<<" , " <<e->age<<endl;
    }
    cout<<"========="<<endl;
    //所有员工按照公司编号小的在前；如果编号一样，年龄小的在前面
    sort(arr.begin(),arr.end(),[](const Employee* a,const Employee* b){
            if(a->company != b->company)
                return a->company<b->company;
            return a->age<b->age;
            });
   for (Employee* e : arr) {
        cout << e->company << " , " << e->age << endl;
    }
    cout<<"===="<<endl;
    //TreeSet(C++ std::set) 默认会根据比较器去重
    set<Employee*,EmployeeComparator> treeSet1;
    for(Employee* e:arr)
    {
        treeSet1.insert(e);
    }
    cout<<treeSet1.size()<<endl;
    //会去重，因为age(27)在合集中已经存在，被比较器评断为相等
    Employee* dup1=new Employee(2,27);
    treeSet1.insert(dup1);
    cout<<treeSet1.size()<<endl;
    cout<<"==="<<endl;
    //如果不想去重，需要增加更多的比较逻辑（比如对象的内存地址）
    //C++中用Lambda 作set的比较器，需要使用decltype
    auto compNoDedupe=[](const Employee* a,const Employee* b)
    {
        if(a->company!=b->company)
        {
            return a->company<b->company;
        }
        if(a->age!=b->age)
        {
            return a->age<b->age;
        }
        //如果前面属性都一样，比较内存地址
        //这完美等价于java的 a.toString().compareTo(b.toString())
        return a<b;
    };
    set<Employee*, decltype(compNoDedupe)> treeSet2(compNoDedupe);
    for(Employee* e:arr)
    {
        treeSet2.insert(e);
    }
    cout<<treeSet2.size()<<endl;

    Employee* dup2=new Employee(2,27);
    treeSet2.insert(dup2);
    cout<<treeSet2.size()<<endl;

    cout<<"==="<<endl;//不会去重,虽然属性相同，但 dup2 的内存地址是全新的，所以能插进去,
    //字典序
    string str1="abcde";
    string str2="ks";
    string str3="abcde";
    //C++中的string的compare方法返回负数，0,正数和Java 的compareTo一致
    cout<<str1.compare(str2)<<endl;
    cout<<str2.compare(str1)<<endl;
    cout<<str1.compare(str3)<<endl;
    //手动释放内存
    for(Employee* e : arr)
    {
        delete e;
    }
    delete dup1;
    delete dup2;
}
