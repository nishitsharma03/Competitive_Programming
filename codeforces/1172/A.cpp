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
	vector<int> a(n),b(n);
	vector<int> have(n+1,0);
	int j=1;
	while(j<n+1 and have[j])
			j++;
	map<int,int> m;
	
	fab(0,n,i)
	{cin>>a[i];
	have[a[i]]++;
	m[a[i]]=-1;
	}
	fab(0,n,i)
	{
		cin>>b[i];
		m[b[i]]=i;
	}

	
		if(m.find(1)!=m.end())
		{
			//cout<<"ADad"<<endl;
			int cnt=n-m[1]+1;
			//cout<<"cnt:"<<cnt<<endl;
			bool ok=1;
			fab(0,m[1],i)
			{
				ok&=((have[cnt]) );
				have[b[i]]=1;
				cnt++;

			}
			cnt=1;
			//cout<<ok<<endl;
			int done =m[1];
			fab(m[1],n,i)
			{
				if(b[i]!=cnt)
				done=i;
				cnt++;
			}
			//cout<<"done:"<<done<<endl;

			cnt=2;
			fab(m[1]+1,done,i)
			{
				if(!have[cnt] )
					ok=0;
				cnt++;
				have[b[i]]=1;

			}
			//cout<<ok<<endl;
			if(ok and done==m[1])
			{
				cout<<done<<endl;
				return 0;
			}
		}

	

	int pos=0;
	fab(0,n,i)
	{
		// int k=i;
		// while(!have[j])
		// {
		// 	have[a[k]]++;
		// 	k++;
		// }
		// pos+=(i-k);
		// if(k>i)
		// 	i=k-1;
		// while(j<n+1 and have[j])
		// 	j++;
		
		

			pos=max(pos,m[i+1]-i+1);
			
	}
	bool ok=1;
	fab(0,n,i)
	ok&=(b[i]==0);
	if(ok)
		cout<<n<<endl;
	else
	 cout<<(pos)+(n)<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}