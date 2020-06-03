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
bool comp(  pair< pair<ll,ll>, ll > a, pair< pair<ll,ll>, ll> b)
{
	if(a.f.f<b.f.f)
		return true;
	if(a.f.f==b.f.f)
	{
		if(a.f.se<b.f.se)
			return true;

	}

	return false;
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	vector< pair< pair < ll, ll > , ll > > v,ans;
	ll n,w,h;
	cin>>n>>w>>h;
	//ans.pb(mp(mp(w,h),-1));
	fab(0,n,i)
	{
		ll x,y;
		cin>>x>>y;
		v.pb(mp(mp(x,y),i));

	}   
	sort(all(v),comp);
	/*fab(0,n,i)
	{
		cout<<v[i].f.f<<" "<<v[i].f.se<<" "<<v[i].se<<endl;
	}*/
	ll dp[n+1]={0};
	
	for(int i=n-1;i>=0;i--)
	{
		ll check=1;
		auto k=v[i];
		if(k.f.f<=w)
			break;
		fab(i+1,n+1,j)
		{if(v[j].f.f<=k.f.f or v[j].f.se<=k.f.se or v[j].f.se<=h)
			continue;
		//cout<<"check:"<<i<<" "<<j<<endl;
		dp[i]=max(dp[i],1+dp[j]);
		}
		//dp[i]=max(dp[i],1LL);


	}
	//vector<ll > comb;
	int res=0,curr=0;
	fab(0,n,i)
	{
		//cout<<dp[i]<< " "; 
		if(dp[i]>res and v[i].f.f>w and v[i].f.se>h)
		{
			res=dp[i];
			curr=dp[i];
			ans.clear();
			ans.pb(v[i]);

		}
		else if(ans.size()>0)
		{
			auto k=ans.back();
			if(dp[i]==curr-1 and v[i].f.se>k.f.se and v[i].f.f>k.f.f and v[i].f.se>h)
			{
				ans.pb(v[i]);
				curr--;



			}
		}
	}
	//cout<<endl;
	cout<<ans.size()<<endl;
	fab(0,ans.size(),i)
	cout<<ans[i].se+1<<" ";

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}	