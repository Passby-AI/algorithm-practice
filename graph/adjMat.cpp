#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Graph
{

    private:
        //使用邻接矩阵
        vector<int> vertices;
        vector<vector<int>> adjmat;
    public:
        //构造方法
        Graph(const vector<int> &dots, const vector<vector<int>>& edges )//:vertices(vertices)
        {
            for(int a:dots)
            {
                addVertex(a);
            }
            for(const vector<int>& edge:edges)
            {
                addEdge(edge[0],edge[1]);
            }
            
        }
        //获取顶点数量
        int size()
        {
            return vertices.size();
        }
        void addEdge(int i ,int j)
        {
            if(i<0||j<0||i==j||i>=size()||j>=size())
                throw out_of_range("error");
            adjmat[i][j]=1;
            adjmat[j][i]=1;
        }
        void removeEdge(int i,int j)
        {
            if(i<0||j<0||i==j||i>=size()||j>=size())
                throw out_of_range("error");
            adjmat[i][j]=0;
            adjmat[j][i]=0;
        }
        //添加顶点
        void addVertex(int val)
        {
            int n=size();
            vertices.push_back(val);
            adjmat.emplace_back(vector<int>(n,0));
            for(vector<int>&row:adjmat)
                row.push_back(0);

        }
        void removeVertex(int index)
        {
            if(index<0||index>size()-1)
                throw out_of_range("error");
            vertices.erase(vertices.begin()+index);
            adjmat.erase(adjmat.begin()+index);
        
            for(vector<int> & row:adjmat)
                row.erase(row.begin()+index);
        }
        friend ostream& operator<<(ostream& os,const Graph& g);
};

ostream& operator<<(ostream& os,const Graph& g)
{
   for(auto row:g.adjmat)
   {
       for(int a:row)
           os<<a;
       os<<"\n";
   }
   return os;
}


int main()
{
    vector<int> dots{1,4,6,7};
    vector<vector<int>> edges;
    cout<<"Input:\n";
    for(int i=0;i<3;i++)
    {
        vector<int> row;
        int a,b;
        cin>>a>>b;
        row.push_back(a);
        row.push_back(b);
        edges.push_back(row);
    }
    cout<<"graph\n";
    Graph graph(dots,edges);
    cout<<"Matrix:\n";
    cout<<graph<<endl;
    
}
