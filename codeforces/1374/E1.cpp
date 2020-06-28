//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
//ll lcm(ll x, ll y) {ll res = (x * y) / __gcd(x, y); return res;}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int inf=1e5+5;
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n,req;
	cin>>n>>req;
	vector<ll> alice(n,inf),bob(n,inf),both(n,inf);
	vector< pair< ll, pair<int,int>  > > v;
	ll cnt1=0,cnt2=0;
	fab(0,n,i)
	{
	ll x,y,z;
	cin>>x>>y>>z;
	
	if(y==1 and z==1)
		{both[i]=x;
		cnt1++;cnt2++;}
	else if(y==1)
		{alice[i]=x;
			cnt1++;}
	else if (z==1)
		{bob[i]=x;
	cnt2++;}
	}
	if(cnt1<req or cnt2<req)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(all(alice));
	sort(all(both));
	sort(all(bob));
	//sort(all(v));

	/*fab(0,both.size(),i)
	cout<<both[i]<<" ";
	cout<<endl;
	fab(0,alice.size(),i)
	cout<<alice[i]<<" ";
	cout<<endl;
	fab(0,bob.size(),i)
	cout<<bob[i]<<" ";
	cout<<endl;*/
	ll l1=0,l2=0;
	int i=0,j=0,k=0;
	//while(l1<req and l2<req and )
	vector<int> ans;
		/*while(l1<req and i<alice.size() and alice[i]<both[k])
		{
			l1++;
			ans.pb(alice[i]);
			i++;
		}
		while(l2<req and j<bob.size() and bob[j]<both[k])
		{
			l2++;
			ans.pb(bob[j]);
			j++;
		}*/


				while(k<both.size() and i<alice.size() and j<bob.size() and l1<req and l2<req)
				{
					if(alice[i]+bob[j]>=both[k])
					{
						l1++;
						l2++;
						ans.pb(both[k]);
						k++;
					}
					else
					{
						l1++;
						l2++;
						ans.pb(alice[i]);
						ans.pb(bob[j]);
						i++;
						j++;
					}
				}
				//cout<<"ADFS"<<endl;
				//cout<<"l1:"<<l1<<" "<<l2<<endl;
			/*	while(l1<req)
				{
					if(k<both.size() and both[k]<alice[i])
					{
						
						ans.pb(both[k]);
						k++;
						l1++;
						l2++;
					}
					else
					{
						ans.pb(alice[i]);
						i++;
						l1++;
					}
				}
				while(l2<req)
				{
					if(k<both.size() and j<bob.size() and both[k]<bob[j])
					{
						
						ans.pb(both[k]);
						k++;
						l2++;
					}
					else if(k>=both.size())
					{
						ans.pb(bob[j]);
						j++;
						l2++;
						l1++;
					}
					else if (j>=bob.size())
					{
						ans.pb(both[k]);
						k++;
						l2++;
					}

				}*/
				ll sum=0;
				for(auto i:ans)
					sum+=i;
				cout<<sum<<endl;
			



 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}