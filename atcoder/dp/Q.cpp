//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int n;ll a[200005];

ll seg[4*200005];
void update(int node,int l,int r,ll ind,ll val)
{
    if(l==r)
    {
        seg[node]=val;
        return;
        //cout<<"l:"<<l<<" "<<val<<" "<<seg[node]<<" "<<node<<endl;
        //a[ind]=val
    }
    else
    {
            int mid=(l+r)/2;
            if(ind<=mid)
                update(2*node,l,mid,ind,val);
            else
                update(2*node+1,mid+1,r,ind,val);

    }
    seg[node]=max(seg[2*node],seg[2*node+1]);

}

ll query(int node,int s,int e,int l,int r)
{
    if(s>r or e<l)
        return 0;
    //cout<<"AFdgS";
    if(l<=s and e<=r)
        return seg[node];
    int mid=(s+e)/2;
    return max(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n;
    fab(0,n,i)
    cin>>a[i];
    ll b[n];
    fab(0,n,i)
    cin>>b[i];
    ll dp[n+1]={0};
    fab(0,n,i)
    {
        ll sm=query(1,0,n+1,0,a[i]);
       // cout<<"sm:"<<i<<" "<<sm<<endl;
        dp[a[i]]=max(dp[a[i]],sm+b[i]);
        //cout<<dp[i]<<" ";
        update(1,0,n+1,a[i],dp[a[i]]);

    }    
 //   fab(0,4*n,i)
   // cout<<seg[i]<<" ";
    cout<<query(1,0,n+1,0,n+1)<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}