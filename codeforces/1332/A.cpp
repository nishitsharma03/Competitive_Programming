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
		ll int a,b,c,d;
		cin>>a>>b>>c>>d;
		ll int x,y,x1,x2,y1,y2;
		string ans="YES";
		cin>>x>>y>>x1>>y1>>x2>>y2;
		if(x1==x2&&(a>0||b>0))
			ans="NO";
		if(y1==y2&&(c>0||d>0))
			ans="NO";
		
		if(x+b-x1<a)
		{
			ans="NO";
			cout<<ans<<endl;
			continue;
		}
		if((x2-(x-a))<b)
			ans="NO";
			if((y+d-y1<c))
				ans="NO";
			if((y2-(y-c)<d))
				ans="NO";
			cout<<ans<<endl;
	}
	

	return 0;
}