#include<iostream>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
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
    void topsortbfs(int n)
    {
        queue<int>q;
        unordered_map<int,int>indegree;

        //calculate indegree
        for(auto i:adj_list)
        {
            for(auto nbr:i.second)
            {
                //cout<<nbr<<endl;
                indegree[nbr]++;
            }
            //    cout<<i.first<<" "<<indegree[i.first]<<endl;
        }
        for(int i=1;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto fnode=q.front();
            q.pop();

            cout<<fnode<<" ";
            for(auto nbr:adj_list[fnode])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
                
            }
        }

    }
};
int main()
{
    graph g;
    g.add_edge(1,2,1);
    g.add_edge(2,3,1);
    g.add_edge(2,4,1);
    g.add_edge(3,5,1);
    g.add_edge(4,5,1);
    g.add_edge(5,6,1);
    g.add_edge(5,7,1);

    g.print();

    g.topsortbfs(7);

}