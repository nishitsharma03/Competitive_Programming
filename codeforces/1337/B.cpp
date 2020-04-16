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
		ll int x,n,m;
		cin>>x>>n>>m;
		int cnt=0;
		while(cnt<n and x>=20)
		{
			x=x/2+10;
			cnt++;
		}
		cnt=0;
		while(cnt<m and x>0)
		{
			x-=10;
			cnt++;
		}
		if(x>0)
			cout<<"NO"<<endl;
		else
			cout<<"YES\n";
	}
	

	return 0;
}