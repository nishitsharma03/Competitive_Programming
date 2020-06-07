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
	int n;
	cin>>n;
	map<int,int> m;
	int a[n];
	fab(0,n,i)
	{cin>>a[i];
		m[a[i]]=i;

	}
	ll b[n];
	map<int,int> freq;
	fab(0,n,i)
	{
		cin>>b[i];
		int shift=m[b[i]]-i;
		if(m[b[i]]-i<0)
			shift=(n-i+m[b[i]]);
		freq[shift]++;
	}
	int ans=0;
	for(auto i:freq)
	{
		//cout<<i.f<<" ";
		ans=max(ans,i.se);

	}
	cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}