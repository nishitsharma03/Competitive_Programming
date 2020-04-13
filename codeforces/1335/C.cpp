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
		ll int n;
		cin>>n;
		ll int a[n];
		map<ll int,ll int> m;
		set<ll int> s;
		vector<ll int> cnt(n+1,0);
		fab(0,n,i)
		{cin>>a[i];
			s.insert(a[i]);
			cnt[a[i]]++;
		m[a[i]]++;
		}
		//sort(a,a+n);
		ll int unq=s.size();
		//cout<<"und"<<unq<<endl;
		ll int ans=0;
		for(auto i:s)
		{
			//cout<<"i.se"<<i.se<<" ";
			//if(cnt[i]<=n/2)
			{
				if((unq)<cnt[i])
					ans=max(ans,unq);
				else if(cnt[i]==unq)
					ans=max(ans,unq-1);
				else
					ans=max(ans,cnt[i]);
			}
			
			//cout<<"ans="<<ans<<endl;

		}
		cout<<ans<<endl;
	}
	

	return 0;
}