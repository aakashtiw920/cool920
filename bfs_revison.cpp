#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj_list;
    void add_edge(int u,int v,int dir)
    {
        adj_list[u].push_back(v);
        if(!dir)
        {
            adj_list[v].push_back(u);
        }
        
    }
    void print_list(){
            for(auto node:adj_list)
            {
                cout<<node.first<<" -> ";
                for(auto n:node.second)
                {
                    cout<<n<<",";
                }
                cout<<endl;
            }
    }
    void bfs(int src)
    {
        unordered_map<int,bool>visited;
        queue<int> q;
        q.push(src);
        visited[src]=1;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            cout<<top<<" ";
            for(auto i:adj_list[top])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    void dfs(int src,unordered_map<int,bool>&visited)
    {
        cout<<src<<" ";
        visited[src]=1;
        for(auto i:adj_list[src])
        {
            if(!visited[i])
            {
                dfs(i,visited);
            }
        }
    }
    bool checkcycle_dfs(int src,unordered_map<int,bool>&vis,int curr_par)
    {
        vis[src]=1;
        int parent=curr_par;
        for(auto node:adj_list[src])
        {
            if(!vis[node])
            {
                checkcycle_dfs(node,vis,src);
            }
            else{
                if(node!=parent)  //isme 1 parent dhoondhna hai::!!confusing 
                {
                    cout<<"hai cycle ";
                    return true;
                }
            }
        }
        return false;
        
    }
    bool checkcyclebfs(int src,unordered_map<int,bool>&vis)
    {
        unordered_map<int,int>parent;
        queue<int>q;

        vis[src]=true;
        parent[src]=-1;
        q.push(src);
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            for(auto node:adj_list[frontnode])
            {
                if(!vis[node])
                {
                    q.push(node);
                    vis[node]=1;
                    parent[node]=frontnode;
                }
                else if(vis[node] && node!=parent[frontnode])
                {
                    cout<<node<<" "<<parent[frontnode]<<endl;
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
    // g.add_edge(0,1,0);
    // g.add_edge(1,2,0);
    // g.add_edge(2,3,0);
    // g.add_edge(3,4,0);
    // g.add_edge(1,5,0);
    // g.add_edge(5,6,0);
    // g.add_edge(6,7,0);
    // g.add_edge(7,8,0);
    g.add_edge(1,2,0);
    g.add_edge(2,3,0);
    g.add_edge(3,4,0);
    g.add_edge(4,5,0);
    g.add_edge(4,6,0);
    g.add_edge(5,6,0);
    // g.add_edge(1,2,0);
    // g.add_edge(2,3,0);
    // g.add_edge(3,4,0);
    // g.add_edge(4,5,0);
    // g.add_edge(5,6,0);


    g.print_list();
    cout<<"Printing bfs: ";
    g.bfs(1);

    cout<<endl;
    // unordered_map<int,bool>visited;
    // cout<<"Printing dfs: ";
    // g.dfs(0,visited);
    unordered_map<int,bool>visited1,visited2;
    bool check=false;
    for(int i=1;i<6;i++)
    {
        if(!visited2[i])
        {
            check=g.checkcycle_dfs(1,visited2,-1);
            if(check)
            {
                cout<<"cycle present hai";
                break;
            }
        }
    }
    if(!check)
    {
        cout<<"No cycle through dfs as well"<<endl;
    }
    
    for(int i=1;i<6;i++)
    {
        if(!visited1[i] )
        {
            bool checkaagekaans=g.checkcyclebfs(i,visited1);
            if(checkaagekaans)
            {
                cout<<"cycle present";
                break;
            }
        }
    }
    
}