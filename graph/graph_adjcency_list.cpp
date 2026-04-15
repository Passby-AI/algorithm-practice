#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
using namespace std;
struct Vertex
{
        int val;
    Vertex(int val):val(val){}
};
class GraphAdjList
{
    public:
        unordered_map<Vertex*, vector<Vertex*>> adjList;
    void remove(vector<Vertex*> & vec, Vertex *vet)
    {
        //删除指定节点
        for(int i=0;i<vec.size();i++ )
        {
            if(vec[i]==vet)
            {
                vec.erase(vec.begin()+i);
                break;
            }
        }
    }
    GraphAdjList(const vector<vector<Vertex*>>& edges){
        for(auto& edge:edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }
    int size(){
        return adjList.size();
    }
    void addEdge(Vertex* vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1)||!adjList.count(vet2))
            throw invalid_argument("不存在顶点");
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    void removeEdge(Vertex* vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1)||!adjList.count(vet2)||vet1==vet2)
            throw invalid_argument("不存在顶点");
        remove(adjList[vet1],vet2);
        remove(adjList[vet2],vet1);
    }
    void addVertex( Vertex* vet)
    {
        if(adjList.count(vet))
            return;
        adjList[vet]=vector<Vertex*>();
    }

    void removeVertex(Vertex *vet)
    {
        if(!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        adjList.erase(vet);
        for(auto & adj:adjList)
        {
            remove(adj.second,vet);
        }
    }

    friend ostream& operator<<(ostream&,const GraphAdjList&);

};

ostream& operator<<(ostream& os,const GraphAdjList& g)
{
    cout<<"AdjList\n";
    for(auto &adj:g.adjList)
    {
        const auto &key=adj.first;
        const auto &vec=adj.second;
        os<<key->val<<": ";
    int size=vec.size();
    for(int i=0;i<size;i++)
    {
        if(i!=size-1)
            os<<vec[i]->val<<"->";
        else
            os<<vec[i]->val;
        
    }
    os<<"\n";
    }
    return os;
}

int main()
{
    Vertex v1(1);
    Vertex v2(2);
    Vertex v3(4);
    Vertex v4(7);
    vector<vector<Vertex*>> edges;
    edges.push_back(vector<Vertex*>{&v1,&v2});
    edges.push_back(vector<Vertex*>{&v2,&v3});
    GraphAdjList g(edges);
    cout<<g<<endl;
    g.removeVertex(&v2);
    cout<<g<<endl;
    g.addVertex(&v4);
    g.addEdge(&v1, &v3);
    cout<<g<<endl;
    cout<<"Done"<<endl;
    return 0;
}
