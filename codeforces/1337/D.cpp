//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
//#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll ans;
ll pow(ll x)
{return (1ll*x*x);}
void mainkarlega(vector<ll > d, vector<ll> e, vector<ll> f)
{
	for(auto i:d)
	{
		auto ub=upper_bound(all(f),i);
		auto lb=lower_bound(all(e),i);
		if(lb==e.end()||ub==f.begin())
			continue;
		ub--;
		//cout<<fixed<<"SDF:"<<pow(i-*lb,2)<<" "<<pow(i-*(ub),2)<<" "<<pow(*lb-*(ub),2);
		ans=min(ans,(ll)(pow(i-*lb)+pow(i-*(ub))+pow(*lb-*(ub))));
	}
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll int nr,nb,ng;
		cin>>nr>>ng>>nb;
		vector<ll> r(nr),g(ng),b(nb);
		fab(0,nr,i)
		cin>>r[i];
		fab(0,ng,i)
		cin>>g[i];
		fab(0,nb,i)
		cin>>b[i];
		//cout<<"Nn"<<nr<<endl;
		
		sort(all(b));
		sort(all(g));
		sort(all(r));
		//fab(0,nb,i)
		//cout<<b[i]<<" ";
		//cout<<fixed<<"SDGSF"<<pow((1000000000-1),2)<<endl;
		ans=9e18+123;
		mainkarlega(r,b,g);
		mainkarlega(r,g,b);
		mainkarlega(g,r,b);
		mainkarlega(g,b,r);
		mainkarlega(b,r,g);
		mainkarlega(b,g,r);
		
		cout<<ans<<endl;

	}
	

	return 0;
}