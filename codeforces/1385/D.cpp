//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
string s;
map<char , vector<int> > m;
int recurse(int i, int j, char c)
{
	if(i==j)
		return s[i]!=c;
	else
	{
		ll ans=0;
		ll mid=(i+j)/2;
		//cout<<"i:"<<i<<" "<<j<<" "<<mid<<" "<<c<<endl;
		auto kim=lower_bound(all(m[c]),mid+1),jim=lower_bound(all(m[c]),i);
		auto pp=lower_bound(all(m[c]),mid),cc=lower_bound(all(m[c]),j);
		int cntleft=lower_bound(all(m[c]),mid)-lower_bound(all(m[c]),i);
		//cout<<"cntleft:"<<cntleft<<endl;
		if(pp!=m[c].end() and jim!=m[c].end() and *jim<=mid and *pp<=mid)
			cntleft++;


		int cntright=lower_bound(all(m[c]),j)-lower_bound(all(m[c]),mid+1);
		if(cc!=m[c].end() and kim!=m[c].end() and *kim<=j and *cc<=j)
			cntright++;
		//cout<<"cnt:"<<cntright<<" "<<cntleft<<endl;
		int rightreq=(j-mid)-cntright;
		int leftreq=(mid-i+1)-cntleft;
		//cout<<"rightreq:"<<rightreq<<" "<<leftreq<<endl;
		ans+=min(recurse(i,mid,c+1)+rightreq, recurse(mid+1,j,c+1)+ leftreq);
		return ans;
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
		int n;
		cin>>n;
		cin>>s;
		m.clear();
		//cout<<"s:"<<s<<endl;

		//int n=s.length();
		fab(0,n,i)
		{
			m[s[i]].pb(i);
		}
		//recurse(0,n-1,'a');
		cout<<recurse(0,n-1,'a')<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}