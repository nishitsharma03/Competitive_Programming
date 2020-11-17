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
vector<string> v;
void toggle(int i, int j)
{
	if(v[i][j]=='0')
	v[i][j]='1';
	else
		v[i][j]='0';
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector< vector<int> > ans;
		v=vector<string> (n);
		fab(0,n,i)
		cin>>v[i];
		fab(0,n-1,i)
		{
			fab(0,m,j)
			{
				if(v[i][j]=='1')
				{
					vector<int> temp;
					temp.pb(i+1);
					temp.pb(j+1);
					temp.pb(i+2);
					temp.pb(j+1);
					temp.pb(i+2);
					int ok=(j==m-1?m-1:j+2);
					temp.pb(ok);
					ans.pb(temp);
					//cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<" "<<i+2<<" "<<(j==m-1?m-1:j+2)<<endl;
					toggle(i,j);
					toggle(i+1,j);
					toggle(i+1,(j==m-1?m-2:j+1));


				}
			}


		}
		// fab(0,n,i)
		// {
		// 	fab(0,m,j)
		// 	{
		// 		cout<<v[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }	
		// cout<<endl;


		fab(0,m-1,i)
		{
			
			if(v[n-1][i]=='1' and v[n-1][i+1]=='1')
			{
				vector<int> temp;
				temp.pb(n);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				ans.pb(temp);

				//cout<<n<<" "<<i+1<<" "<<n-1<<" "<<i+1<<" "<<n-1<<" "<<i+2<<endl;
				temp.clear();
				temp.pb(n);
				temp.pb(i+2);
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				ans.pb(temp);
				//cout<<n<<" "<<i+2<<" "<<n-1<<" "<<i+1<<" "<<n-1<<" "<<i+2<<endl;
				toggle(n-1,i);
				toggle(n-1,i+1);

			}
			else if(v[n-1][i]=='0' )
			{
				if(i!=m-2 or v[n-1][i+1]=='0')
				continue;

				vector<int> temp;
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				temp.pb(n);
				temp.pb(i+2);
				toggle(n-2,i);
				toggle(n-2,i+1);
				toggle(n-1,i+1);
				ans.pb(temp);
				temp.clear();

				temp.pb(n);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n);
				temp.pb(i+2);
				ans.pb(temp);
				toggle(n-1,i+1);
				toggle(n-2,i);
				toggle(n-1,i);
				temp.clear();

				temp.pb(n);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				temp.pb(n);
				temp.pb(i+2);
				toggle(n-1,i);
				toggle(n-2,i+1);
				toggle(n-1,i+1);
				ans.pb(temp);


			}
			else if(v[n-1][i]=='1' and v[n-1][i+1]!='1')
			{
				vector<int> temp;
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				temp.pb(n);
				temp.pb(i+1);
				toggle(n-2,i);
				toggle(n-2,i+1);
				toggle(n-1,i);
				ans.pb(temp);
				temp.clear();

				temp.pb(n);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+1);
				temp.pb(n);
				temp.pb(i+2);
				ans.pb(temp);
				toggle(n-1,i+1);
				toggle(n-2,i);
				toggle(n-1,i);
				temp.clear();

				temp.pb(n);
				temp.pb(i+1);
				temp.pb(n-1);
				temp.pb(i+2);
				temp.pb(n);
				temp.pb(i+2);
				toggle(n-1,i);
				toggle(n-2,i+1);
				toggle(n-1,i+1);
				ans.pb(temp);

			}

			
		}
		// fab(0,n,i)
		// {
		// 	fab(0,m,j)
		// 	{
		// 		cout<<v[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }	

		cout<<ans.size()<<endl;
		fab(0,ans.size(),i)
		{
			for(auto j: ans[i])
				cout<<j<<" ";
			cout<<endl;
		}
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}