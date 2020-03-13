#pragma GCC optimize "trapv"
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
		int n;
		cin>>n;
		int a[n+1]={0};
		int cnt[n+1]={0};
		bool ans=false;
		fab(1,n+1,i)
		{
			int k;
			cin>>k;
			cnt[k]++;
			if((a[k]!=0&&a[k]!=i-1)||cnt[k]>2)
				ans=true;
			a[k]=i;
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	

	return 0;
}