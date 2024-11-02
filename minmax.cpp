#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<int>a;
int maxdepth;
int minmaxfn(int depth, int index, bool ismax)
{
    if(depth==maxdepth)
    {
        return a[index];
    }
    if(ismax)
    {
        return(max(minmaxfn(depth+1,index*2,false),minmaxfn(depth+1,index*2+1,false)));
    }
    else
    {
        return(min(minmaxfn(depth+1,index*2,true),minmaxfn(depth+1,index*2+1,true)));
    }
}
int main()
{
    a={3,5,2,9,12,5,23,23};
    int n=a.size();
    maxdepth=log2(n);
    int ans = minmaxfn(0,0,true);
    cout<<ans<<endl;
}
