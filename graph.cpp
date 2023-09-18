#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj_list;
    void add_edge(int u,int v,bool dir)
    {
        adj_list[u].push_back(v);
        if(!dir)
        {
            adj_list[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:adj_list)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
        
    }
    bool check_cycle(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>dfsvisited){
        visited[src]=true;
        dfsvisited[src]=true;
        for(auto nbr:adj_list[src])
        {
            if(!visited[nbr])
            {
                bool aagekacyle=check_cycle(nbr,visited,dfsvisited);
                if(aagekacyle==true)
                {
                    return true;
                }
                if(visited[nbr] && dfsvisited[nbr])
                {
                    return true;
                }
            }

        }
        return false;
    }
};
int main()
{
    graph g;
    g.add_edge(1,2,0);
    g.add_edge(1,3,0);
    g.add_edge(2,4,0);
    g.add_edge(3,4,0);

    g.print();
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsvisited;

    g.check_cycle(1,visited,dfsvisited);
}