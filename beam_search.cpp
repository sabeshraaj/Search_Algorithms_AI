#include<bits/stdc++.h>
using namespace std;
vector<int>h;
int n;
int beamwidth;
vector<vector<int>>adj[7];
void beam()
{
    vector<bool>vis(n,false);
    vector<int>dist(n,1e9);
    int cur=0;
    int goal=6;
    set<pair<int,vector<int>>>st;
    st.insert({0,{0}});
    while(!st.empty())
    {
        int dis=st.begin()->first;
        vector<int>path=st.begin()->second;
        int elem=path.back();
        st.erase(st.begin());
        if(vis[elem]){continue;}
        vis[elem]=true;
        cout<<"at node: "<<elem<<endl;
        cout<<"path till now : "<<endl;
        for(auto it:path)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        dist[elem]=dis;
        if(elem==goal)
        {
            cout<<"goal reached, final path is: "<<endl;
            for(auto it:path)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }
        vector<pair<int,vector<int>>>temp;
        for(auto it:adj[elem])
        {
            int edw=it[1];
            int node=it[0];
            vector<int>np=path;
            np.push_back(node);
            if(!vis[node])
            {
                temp.push_back({edw,np});
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<min(beamwidth, (int)temp.size());i++)
        {
            st.insert(temp[i]);
        }
    }
    cout<<"path not found"<<endl;
}
void ae(int u,int v,int wt=1)
{    adj[u].push_back({v,wt});
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
    beamwidth=2;
    cout<<"beam search algorithm: "<<endl;
    beam();
}
