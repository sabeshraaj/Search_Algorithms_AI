#include<bits/stdc++.h>
using namespace std;
vector<int>h;
int n;
int oracle;
int beamwidth;
vector<vector<int>>adj[7];
void printpath(vector<int>path)
{
    cout<<"path : "<<endl;
    for(auto it:path)
        {
            cout<<it<<" ";
        }
    cout<<endl;
}
void best()
{
    vector<bool>vis(n,false);
    vector<int>dist(n,1e9);
    int cur=0;
    int goal=6;
    set<pair<int,pair<int,vector<int>>>>st; //dis, elem, path
    st.insert({h[0],{0,{0}}});
    while(!st.empty())
    {
        auto[dis,path1]=*st.begin();
        int elem=path1.first;
        vector<int>path=path1.second;
        st.erase(st.begin());
        if(vis[elem]){continue;}
        vis[elem]=true;
        dist[elem]=dis;
        cout<<"node: "<<elem<<" distance covered: "<<dis<<endl;
        printpath(path);
        if(elem==goal)
        {
            cout<<"goal reached, final path:"<<endl;
            printpath(path);
            return;
        }
        for(auto it:adj[elem])
        {
            int edw=it[1]; int node=it[0];
            vector<int>np=path;
            np.push_back(node);
            st.insert({h[node],{node,np}});
        }
    }
    cout<<"path not found"<<endl;
}
void ae(int u,int v,int wt=1)
{    
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
int main()
{
    h={4,3,3,1,1,1,0};
    ae(0,1);
    ae(0,2);
    ae(1,3);
    ae(1,4);
    ae(2,5);
    ae(3,6);
    ae(4,6);
    ae(5,6);
    n=7;
    cout<<"Best first search algorithm : "<<endl;
    best();
}
