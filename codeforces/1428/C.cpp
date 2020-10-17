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
		string s;
		cin>>s;
		int n=s.length();
		int len=0;
		int ans=0;
		int ls=n-1;

		while(ls>=0 and s[ls]=='A')
			{ls--;
			ans++;
			}
			bool ok=1,ok2=1;
			fab(0,n,i)
			{
				ok&=(s[i]=='B');
				ok2&=(s[i]=='A');
			}
			if(ok)
			{
				cout<<n%2<<endl;
				continue;
			}
			else if(ok2)
			{
				cout<<n<<endl;
				continue;
			}
			n=ls+1;
			//cout<<"ls:"<<ls<<endl;
		fab(0,n,i)
		{
			//cout<<"ib:"<<i<<endl;
			if(s[i]=='A' and i<=ls)
			{

				
				int cnt1=0,cnt2=0;
				while(i<=ls)
				{	
					//cout<<"i:"<<i<<endl;
					while(i<=ls and s[i]=='A' )
					{
						cnt1+=1;
						i++;
					}
					while(i<=ls and s[i]=='B')
						{	cnt2++;
							i++;
						}
						//cout<<"cnt:"<<cnt1<<" "<<cnt2<<endl;
					//cout<<"len:"<<len<<" "<<cnt1<<" "<<cnt2<<endl;
					int sm=min(cnt1,cnt2);
					cnt1-=sm;
					cnt2-=sm;

					len+=cnt2%2;

					//cout<<"len:"<<len<<" "<<cnt1<<" "<<cnt2<<endl;
					cnt2=0;

				}
				ans+=cnt1;

			
			
		

			break;

			}

			len++;

		}
		ans+=len%2;
		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}