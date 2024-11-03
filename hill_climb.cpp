#include<bits/stdc++.h>
using namespace std;
vector<int>h;
int n;
vector<vector<int>>adj[7];
void hillclimb()
{
    vector<bool>vis(n,false);
    vector<int>dist(n,1e9);
    int cur=0;
    int goal=6;
    while(cur!=goal)
    {
        int curh=h[cur];
        cout<<"current node: "<<cur<<" heuristic: "<<h[cur]<<endl;
        int mini=1e9;
        int node=-1;
        for(auto i: adj[cur])
        {
            int adjnode=i[0];
            if(h[adjnode]<mini)
            {
                mini=h[adjnode];
                node=adjnode;
            }
        }
        if(h[cur]>h[node])
        {
            cur=node;
            if(node==goal)
            {
                cout<<"current node: "<<cur<<" heurisitc: "<<h[cur]<<endl;
                cout<<"node found"<<endl;
            }
        }
        else
        {
            cout<<"local minima reached"<<endl;
            break;
        }
    }
}
void ae(int x, int y, int wt=1)
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
    hillclimb();
}
