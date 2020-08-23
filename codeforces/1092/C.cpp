//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
bool comp(string a, string b)
{
	return a.size()<b.size();
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<string> v(2*n-2);
	for(auto &i: v)
		cin>>i;
	vector<string> alt=v;
	sort(all(v),comp);
	string pref=v[0];
	string suff=v[1];
	map<string , int> m;
	m[pref]++;
	
	m[suff]--;
	//cout<<"pppp:"<<pref<<" "<<suff<<endl;
	bool ok=1;
	fab(2,2*n-2,i)
	{
		//	cout<<" str:"<<v[i]<<" "<<v[i+1]<<endl;
		//	cout<<"substr:"<<v[i].substr(0,v[i].size()-1)<<endl;
		
		if(v[i].substr(0,v[i].size()-1)==pref and v[i+1].substr(1,v[i+1].size()-1)==suff)
		{
			pref+=v[i].back();
			suff=v[i+1][0]+suff;
		}
		else if(v[i+1].substr(0,v[i+1].size()-1)==pref and v[i].substr(1,v[i].size()-1)==suff)
		{
			suff=v[i][0]+suff;
			pref+=v[i+1].back();
		}
		else
		{
			ok=0;
			m.clear();
			break;
		}
		//cout<<"pref:"<<pref<<" "<<suff<<endl;

		m[pref]++;
		m[suff]--;

		i++;

	}
	/*for(auto i: alt)
	{
		cout<<i<<" "<<m[i]<<endl;
	}*/
	if(!ok)
	{
		pref=v[1];
		suff=v[0];

		m[pref]++;
		m[suff]--;
		fab(2,2*n-2,i)
		{
	//		cout<<" str:"<<v[i]<<" "<<v[i+1]<<endl;
	//		cout<<"substr:"<<v[i].substr(0,v[i].size()-1)<<endl;
		
		if(v[i].substr(0,v[i].size()-1)==pref)
		{
			pref+=v[i].back();
			suff=v[i+1][0]+suff;
		}
		else
		{
			suff=v[i][0]+suff;
			pref+=v[i+1].back();
		}
	//	cout<<"pref:"<<pref<<" "<<suff<<endl;

		m[pref]++;
		m[suff]--;

		i++;

	}
	}
	for(auto i: alt)

		if(m[i]>=0)
		{
			cout<<"P";
			m[i]--;
		}
		else
		{
			cout<<"S";
		}




 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}