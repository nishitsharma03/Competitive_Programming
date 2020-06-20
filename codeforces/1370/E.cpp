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
	string s,t;
	cin>>s>>t;
	if(count(all(s),'1')!=count(all(t),'1'))
	{
		cout<<-1<<endl;
		return 0;
	}
	if(s==t)
	{
		cout<<0<<endl;
		return 0;
	}
	vector<int> a(n,0);
	
	fab(0,n,i)
	{
		if(s[i]!=t[i])
		{
			if(s[i]=='1')
				a[i]=1;
			else
				a[i]=-1;
		}
	}

	ll sum=0;
	ll ans=0;
	fab(0,n,i)
	{
		sum+=a[i];
		ans=max(ans,sum);
		if(sum<0)
			sum=0;

	}
	sum=0;
	fab(0,n,i)
	{
		sum+=-a[i];
		ans=max(ans,sum);
		if(sum<0)
			sum=0;

	}
	cout<<ans<<endl;




 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}