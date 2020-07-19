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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	string p="abacaba";
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool qn[n]={0};
		fab(0,n,i)
		{
			if(s[i]=='?')
				qn[i]=1;
			else
				qn[i]=0;

		}
		if(n<p.size())
		{
			
			cout<<"NO\n";
			continue;
		}

		int cnt=0;
		fab(0,n-p.size()+1,i)
		{
			bool ok=1;
			fab(i,i+p.size(),j)
			{
				ok&=(s[j]==p[j-i]);
			}
			if(ok)
				cnt++;
		}
		if(cnt>1)
		{
			
			cout<<"NO\n";
			continue;
		}
		else if (cnt==1)
		{
			fab(0,n,i)
		{
			if(s[i]=='?')
				s[i]='z';
		}
		
			cout<<"YES\n";
		cout<<s<<endl;
		continue;
		}
		//cout<<"cnt:"<<cnt<<endl;
		fab(0,n-p.size()+1,i)
		{
			///cout<<"i:"<<i<<endl;
			bool ok=1;
			fab(i,i+p.size(),j)
			{
				if(s[j]!=p[j-i] and s[j]=='?' )
				{
					
					s[j]=p[j-i];
				


				}
				else if(s[j]!=p[j-i])
					{
						ok=0;
						break;
						
					}
			}

			
				
		//			cout<<"I:"<<i<<endl;
					int cnt1=0;
					fab(0,n-p.size()+1,k)
		{
			bool ok=1;
			fab(k,k+p.size(),j)
			{
				ok&=(s[j]==p[j-k]);
			}
			if(ok)
				cnt1++;
		}
		

		if(cnt1==1)
			break;
					
				
		else
			{
				fab(0,n,j)
				{
					if(qn[j])
						s[j]='?';
				}
			}

		}
		
		fab(0,n,i)
		{
			if(s[i]=='?')
				s[i]='z';
		}
		cnt=0;
		fab(0,n-p.size()+1,i)
		{
			bool ok=1;
			fab(i,i+p.size(),j)
			{
				ok&=(s[j]==p[j-i]);
			}
			if(ok)
				cnt++;
		}
		if(cnt==1)
			{cout<<"YES\n";
		cout<<s<<endl;}
	else
		cout<<"NO\n";
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}