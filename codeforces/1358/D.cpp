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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n,x;
	cin>>n>>x;
	vector<ll> d(2*n+1);
	fab(1,n+1,i)
	{cin>>d[i];
	d[i+n]=d[i];}
	
	ll pref[2*n+1]={0},pref1[2*n+1]={0};
	int j=0;
	ll lsum=0;
	ll tot=0;
	fab(1,2*n+1,i)
	{
		pref[i]=pref[i-1]+(d[i]*(d[i]+1))/2;
		pref1[i]=pref1[i-1]+d[i];

		
	}
	ll ans=0;
	for(int i=2*n;i>n;i--)
	{
		int ind=i;
		int l=0,h=i;
		
		while(l<=h)
		{
			int mid=(l+h)/2;
			if(pref1[i]-pref1[mid]<=x)
			{
				h=mid-1;
				ind=mid;

			}
			else
				l=mid+1;
		}
		ll req=pref1[i]-pref1[ind-1]-x;
		lsum=pref[i]-pref[ind-1];
		lsum-=(req*(req+1))/2;
		ans=max(ans,lsum);

	}
	cout<<ans<<endl;

	return 0;
}