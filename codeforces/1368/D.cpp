//#pragma GCC optimize "trapv"
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int cnt[22];
ll a[200005];
void setbits(int n)
{
	fab(0,21,i)
	if((1LL<<i)&n)
		cnt[i]++;
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	fab(0,n,i)
	{cin>>a[i];
	setbits(a[i]);}
	ll ans=0;
	fab(0,n,i)
	{
		ll tot=0;
		fab(0,21,j)
		{
			if(cnt[j])
			{
				tot+=(1LL<<j);
				cnt[j]--;
			}
		}
		ans+=tot*tot;
	}
	cout<<ans<<endl;


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}