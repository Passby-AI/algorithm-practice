#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Graph
{

    private:
        vector<int> vertices;
        vector<vector<int>> adjmat;
    public:
        Graph(const vector<int> &vertices, const vector<vector<int>>& edges ):vertices(vertices)
        {
            for(const vector<int>& edge:edges)
            {
                addEdge(edge[0],edge[1]);
            }
            
        }
        int size()
        {
            return vertices.size();
        }
        void addEdge(int i ,int j)
        {
            if(i<0||j<0||i==j||i>=size()||j>=size())
                throw out_of_range("error");
            adjmat[i-1][j-1]=1;
            adjmat[j-1][i-1]=1;
        }
        void removeEdge(int i,int j)
        {
            if(i<0||j<0||i==j||i>=size()||j>=size())
                throw out_of_range("error");
            adjmat[i-1][j-1]=0;
            adjmat[j-1][i-1]=0;
        }

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
        void print(){}
};
