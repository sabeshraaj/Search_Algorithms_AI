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
            cout<<it<<"->";
        }
    cout<<"X"<<endl;
}
void ore()
{
    vector<bool>vis(n,false);
    vector<int>dist(n,1e9);
    int cur=0;//start
    int goal=6;
    set<tuple<int,int,int,vector<int>>>st;
    st.insert({0+h[0],0,0,{0}});
    int cnt=0;
    int maxcnt=9;
    while(!st.empty()&&cnt<maxcnt)
    {
       auto[tot,dis,elem,path]=*st.begin();
       st.erase(st.begin());
        if(vis[elem]){continue;}
        vis[elem]=true;
        dist[elem]=dis;
        cout<<"node: "<<elem<<" dis+heurisitc: "<<tot<<endl;
        if(elem==goal)
        {
            printpath(path);
            return;
        }
        for(auto it:adj[elem])
        {
            int edw=it[1]; int node=it[0];
            int curcost=edw+h[node];
            vector<int>np=path;
            np.push_back(node);
            st.insert({tot+curcost,curcost,node,np});
            if(node==goal)
            {
                cnt++;
            }
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
    oracle=100;
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
    beamwidth=2;
    cout<<"oracle algorithm: "<<endl;
    ore();
}
