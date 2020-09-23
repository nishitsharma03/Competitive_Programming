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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<string> v(n);
	map<string,int> m;
	fab(0,n,i)
	{
		cin>>v[i];
		set<string> s;
		fab(0,v[i].size(),j)
		{
			string tem="";
			fab(j,v[i].size(),k)
			{
				tem+=v[i][k];
				//cout<<"teml:"<<tem<<endl;
				s.insert(tem);

			}
		}

		for( auto j: s)
			m[j]++;

	}

	fab(0,n,i)
	{
		string ans="hh";
		fab(1,10,j)
		{
			//cout<<"ind:"<<v[i].size()-j+1<<endl;
			fab(0,v[i].size()-j+1,k)
			{
				//cout<<"k;"<<k<<endl;
				string check=v[i].substr(k,j);
				//cout<<"chec:"<<check<<endl;
				if(m[check]==1)
				{
					ans=check;
					break;
				}
			}
			if(ans!="hh")
				break;
		}
		assert(ans!="hh");
		cout<<ans<<endl;
	}

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}