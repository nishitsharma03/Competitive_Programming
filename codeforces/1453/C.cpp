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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		fab(0,n,i)
		cin>>s[i];
		int a[n][n];
		fab(0,n,i)
		{
			fab(0,n,j)
			{
				a[i][j]=s[i][j]-'0';
			}
		}
		vector<int> row[n][10],col[n][10];
		fab(0,n,i)
		{
			fab(0,n,j)
			{
				row[i][a[i][j]].pb(j);
				col[j][a[i][j]].pb(i);
			}
		}
		fab(0,n,i)
		{
			fab(0,10,j)
			sort(all(col[i][j]));

		}
		ll ans[10]={0};
		vector<int> get1[10],get2[10];
		fab(0,n,i)
		{
			fab(0,n,j)
			{
				int val=a[i][j];
				get1[val].pb(i);
				get2[val].pb(j);
			}
		}
		fab(0,10,i)
		{
			sort(all(get1[i]));
			sort(all(get2[i]));
		}

		fab(0,n,i)
		{
			fab(0,n,j)
			{
				int val=a[i][j];
				if(row[i][val].size()>0)
				{
					ll base=j-row[i][val][0];
					ll height=max(i,n-i-1);
					// if(val==3)
					 //cout<<"i:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;
					ans[val]=max(ans[val],base*height);
					base=row[i][val].back()-j;
					// if(val==3)
					 //cout<<"i2:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;

					ans[val]=max(ans[val],base*height);


				}
				if(col[j][val].size()>0)
				{
					ll base=i-col[j][val][0];
					ll height= max(j,n-j-1);
					 // if(val==3)
					 // cout<<"i:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;

					ans[val]=max(ans[val],base*height);
					base=col[j][val].back()-i;
					// if(val==3)
					//  cout<<"i2:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;

					ans[val]=max(ans[val],base*height);
				}

				if(get1[val].size()>0)
				{
					ll base=max(j,n-j-1);
					ll height=abs(i-get1[val][0]);
					 // if(val==3)
					 // cout<<"i:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;
					ans[val]=max(ans[val],base*height);
					height=get1[val].back()-i;
					// if(val==3)
					//  cout<<"i2:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;
					ans[val]=max(ans[val],base*height);
				}

				if(get2[val].size()>0)
				{
					ll base=max(i,n-i-1);
					ll height=abs(j-get2[val][0]);
					 // if(val==3)
					 // cout<<"i:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;
					ans[val]=max(ans[val],base*height);
					height=abs(get2[val].back()-j);
					// if(val==3)
					//  cout<<"i2:"<<i<<" "<<j<<" "<<val<<" "<<base<<" "<<height<<endl;
					ans[val]=max(ans[val],base*height);
				}
				// if(val==3)
				// 	cout<<endl;
			}


		}
		fab(0,10,i)
		cout<<ans[i]<<" ";
		cout<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}