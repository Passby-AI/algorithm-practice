#include <vector>
#include <queue>
#include "graph_adjcency_list.cpp"
#include <unordered_set>

using namespace std;

vector<Vertex* >graphBFS(GraphAdjList &graph, Vertex* startVet)
{
    vector<Vertex*> res;
    unordered_set<Vertex*> visited{startVet};
    queue<Vertex*> que;

    que.push(startVet);

    while(!que.empty())
    {
        Vertex* vet=que.front();
        que.pop();
        res.push_back(vet);
        for(auto adjVet: graph.adjList[vet])
        {
            if(visited.count(adjVet))
                continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
    return res;
}

void dfs(GraphAdjList&graph,unordered_set<Vertex*> &visited,vector<Vertex*> res,Vertex* vet)
{
    res.push_back(vet);
    visited.emplace(vet);
    for(Vertex* adjVet:graph.adjList[vet])
    {
        if(visited.count(adjVet))
            continue;
        dfs(graph,visited,res,adjVet);
    }
}

vector<Vertex*>graphDFS(GraphAdjList &graph, Vertex* startVet)
{
    vector<Vertex*> res;
    unordered_set<Vertex*> visited;
    dfs(graph,visited,res,startVet);
    return res;
}
