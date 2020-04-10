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
		ll int n,x;
		cin>>n>>x;
		vector<ll int> a(n);
		for(auto &i:a)
			cin>>i;
		sort(all(a));
		ll int sum=0,ans=0;
		fab(0,n,i)
		sum+=a[i];
		fab(0,n,i)
		{
			if(sum/(n-i)>=x)
			{	ans=n-i;
				break;
			}
			sum-=a[i];

		}
		cout<<ans<<endl;
	}
	

	return 0;
}