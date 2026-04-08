#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> S(m,vector<int>());
    vector<vector<int>> T(m,vector<int>());
    vector<int> collection;
    collection.push_back(0);
    for(int i=1;i<n+1;i++)
    {
        int a;
        cin>>a;
        collection.push_back(a);
    }


    for(int i=0;i<m;++i)
    {
        int size;
        cin>>size;
        vector<int> vec(size);
        for(int j=0;j<size;++j)
        {
            int index=1;
            cin>>index;
            vec[j]=collection[index];
        }
        S[i]=vec;
    }

    for(int i=0;i<m;++i)
    {
        int size;
        cin>>size;
        vector<int> vec(size);
        for(int j=0;j<size;++j)
        {
            
            int index=1;
            cin>>index;
            vec[j]=collection[index];
        }
        T[i]=vec;

    }

    //origin method
    for(int i=0;i<m;++i)
    {
        bool isEqual=true;
        if(S[i].size()!=T[i].size())
            isEqual=false;
        else
        {
            for(int j=0;j<S[i].size();j++)
            {
                if(S[i][j]!=T[i][j])
                    isEqual=false;
            }

        }

    //new method
        int ans1=0;
        int ans2=0;
       for(int j=0;j<S[i].size();j++)
       {
          ans1^=S[i][j];
          //cout<<S[i][j]<<endl;
       }

       for(int j=0;j<T[i].size();j++)
       {
          ans2^=T[i][j]; 
          //cout<<T[i][j]<<endl;
       }
       bool isEqual2=true;
       if(ans1!=ans2)
           isEqual2=false;
       if(isEqual==isEqual2)
           cout<<"correct\n";
       else
           cout<<"wrong\n";
      // cout<<isEqual<<" "<<isEqual2<<endl;

       //cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}


