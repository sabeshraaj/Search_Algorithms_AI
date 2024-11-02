#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int n;
int dest;
int source;
int found;
vector<int>path;
vector<bool>vis;
void bfs()
{
    queue<int>q;
    q.push(source);
    vis[source]=true;
    while(!q.empty())
    {
        int cur=q.front();
        path.push_back(cur);
        q.pop();
        if(cur==dest)
        {
            found=1;
            cout<<"printing the path"<<endl;
            for(auto it:path)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        for(auto it:adj[cur])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q.push(it);
            }
        }
    }
    
}
void addedge(int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int main()
{
    n=6;
    addedge(0,1);
    addedge(0,2);
    addedge(1,3);
    addedge(1,4);
    addedge(2,5);
    source=0;
    dest=5;
    vis.assign(n,false);
    found=0;
    bfs();
    if(found==0)
    {
        cout<<"element not found"<<endl;
    }
    
}
