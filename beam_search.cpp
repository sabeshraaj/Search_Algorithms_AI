#include<bits/stdc++.h>
using namespace std;
vector<int>h;
int n;
int beamwidth;
vector<vector<int>>adj[7];
void printpath(vector<int>path)
{
    cout<<"path: "<<endl;
    for(auto i:path)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void beam()
{
    vector<bool>vis(n,false);
    vector<int>dist(n,1e9);
    int cur=0;
    int goal=6;
    set<tuple<int,int,vector<int>>>st;
    st.insert({0,0,{0}});
    while(!st.empty())
    {
        auto[dis,elem,path]=*st.begin();
        st.erase(st.begin());
        if(vis[elem])
        {
            continue;
        }
        vis[elem]=true;
        dist[elem]=dis;
        if(elem==goal)
        {
            printpath(path);
            return;
        }
        for(auto i:adj[elem])
        {
            int edw=i[1];
            int node=i[0];
            vector<int>np=path;
            np.push_back(node);
            st.insert({edw+dis,node,np});
        }
    }
    cout<<"path not found"<<endl;
}
void ae(int x,int y, int wt=1)
{
    adj[x].push_back({y,wt});
    adj[y].push_back({x,wt});
}
int main()
{
    h={4,3,3,1,1,1,0};
    n=7;
    ae(0,1);
    ae(0,2);
    ae(1,3);
    ae(1,4);
    ae(2,5);
    ae(3,6);
    ae(4,6);
    ae(5,6);
    beamwidth=2;
    beam();
}
