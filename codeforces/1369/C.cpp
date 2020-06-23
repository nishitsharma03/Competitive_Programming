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
		int n,k;
		cin>>n>>k;
		map<ll,ll,greater<ll> > m;
		ll a[n];
		fab(0,n,i)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		ll w[k];
		fab(0,k,i)
		cin>>w[i];
		sort(w,w+k,greater<ll>());
		sort(a,a+n);
		ll ans=0;
		fab(n-k,n,i)
		ans+=a[i];
		//cout<<"ans:"<<ans<<endl;
		fab(0,k,i)
		w[i]--;
		int j=n-1;
		int pp=0;
		fab(0,k,i)
		{
			if(w[i]==0)
				{
					ans+=a[j];
					j--;
					continue;
				}
			int cnt=0;
			ans+=a[pp];
			while(cnt<w[i])
			{
				pp++;
				cnt++;
				
					

			}

			
		}

		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}