// //#pragma GCC optimize "trapv"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()

#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


using namespace std;
void getsubset( vector<ll> a,vector<ll> &s, ll k)
{

    int n=a.size();
    fab(0,(1<<n),i)
    {
        ll sum=0;
        fab(0,n,j)
        {
            if(i&(1<<j))
            {
                sum+=a[j];
            }

        }
        if(sum<=k)
            s.pb(sum);

    }

}

int main()
{ quick;

    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    fab(0,n,i)
    {
        cin>>a[i];

    }
    vector<ll> a1,a2;
    fab(0,n/2,i)
    a1.pb(a[i]);
    fab(n/2,n,i)
    {
        a2.pb(a[i]);
    }
    // for(auto p: a1)
    // {
    //     cout<<p<<" ";
    // }
    // cout<<endl;

    // for(auto p: a2)
    // {
    //     cout<<p<<" ";
    // }
    // cout<<endl;

    vector<ll> op,dp;
    getsubset(a1,op,k);
    getsubset(a2,dp,k);
    sort(all(op));
    ll ans=0;
    for(auto i: dp)
    {
        ll rem=k-i;
        auto j=lower_bound(all(op),rem+1)-op.begin();
        j--;
        if(j>=0)
        {
            ans=max(ans,i+op[j]);
        }
    }
    cout<<ans<<endl;
    

 //cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}