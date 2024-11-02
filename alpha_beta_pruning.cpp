#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<int>a;
int maxdepth;
int abfn(int depth,int index,bool ismax,int alpha,int beta)
{
    if(depth==maxdepth)
    {
        return a[index];
    }
    if(ismax)
    {
        int best=-1e9;
        for(int i=0;i<2;i++)
        {
            int temp=abfn(depth+1,index*2+i,false,alpha,beta);
            best=max(best,temp);
            alpha=max(alpha,temp);
            if(beta<=alpha)
            {
                break;
            }
        }
        return best;
    }
    else
    {
        int best=1e9;
        for(int i=0;i<2;i++)
        {
            int temp=abfn(depth+1,index*2+i,true,alpha,beta);
            best=min(best,temp);
            alpha=min(alpha,best);
            if(beta<=alpha)
            {
                break;
            }
        }
        return best;
    }
}
int main()
{
    a={3,5,6,9,1,2,0,-1};
    int n=a.size();
    maxdepth=log2(n);
    int ans=abfn(0,0,true,-1e9,1e9);
    cout<<ans<<endl;
}
