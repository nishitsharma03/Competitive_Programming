//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
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
	int t;
	cin>>t;
	while(t--)
	{
		ll int n,k;
		cin>>n>>k;
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		map<ll int,ll int> m;
		ll int ind[n/2],ind2[n/2];
		fab(0,n/2,i)
		{
			ll int tot=a[i]+a[n-i-1];
			m[tot]++;
			ind[i]=min(a[i],a[n-i-1]);
			ind2[i]=max(a[i],a[n-i-1]);
		}
		sort(ind,ind+n/2);
		sort(ind2,ind2+n/2);
		//fab(0,n/2,i)
		//cout<<ind2[i]<<" ";
		ll int ans=n/2;
		for(auto i:m)
		{
			//cout<<"sum:"<<i.f<<endl;
			ll int cnt=i.se;
			ll int tt=n/2-i.se;
			//if(i.f>k)
			{
				//cout<<"sum:"<<i.f<<endl;
				ll int po=lower_bound(ind,ind+n/2,i.f)-ind;
			
			ll int lo=upper_bound(ind2,ind2+n/2,i.f-k-1)-ind2;
			tt+=lo;

			
			//cout<<"po:"<<po<<" "<<lo<<endl;
			
			tt+=(n/2-po);
			
			}
			ans=min(ans,tt);

		}
		cout<<ans<<endl;
	}
	

	return 0;
}