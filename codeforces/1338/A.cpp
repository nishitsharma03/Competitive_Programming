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
		vector<ll int> a(n);
		for(auto &i: a)
			cin>>i;
		vector<ll int> br;
		ll int cnt,ans=0;
		fab(0,n-1,i)
		{
			cnt=0;
			if(a[i]>a[i+1])
			{
				ll int diff=a[i]-a[i+1];

				ans=max(ans,(ll int)(log2(diff)+1));
			a[i+1]=a[i];
			}

			
		}
		//ll int cp=a[br-1];
		//fab(0,n,i)
	//	cout<<a[i]<<" ";

		cout<<ans<<endl;
	}
	

	return 0;
}