#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int n;
int dest;
int found;
vector<int>path;
vector<bool>vis;
void dfs(int cur)
{
    vis[cur]=true;
    path.push_back(cur);
    if(cur==dest)
    {
        cout<<"printing the path"<<endl;
        found=1;
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
            dfs(it);
        }
    }
    path.pop_back();
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
    int source=0;
    dest=4;
    vis.assign(n,false);
    found=0;
    dfs(source);
    if(found==0)
    {
        cout<<"element not found"<<endl;
    }
    
}
