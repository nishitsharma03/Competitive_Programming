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
		string s;
		cin>>s;
		int n=s.size();
		int prev=0;
		int max=0,cnt=0;
		
		fab(1,n+1,i)
		{
			if(s[i-1]=='R')
			{	cnt++;
				if(i-prev>max)
					max=i-prev;
				prev=i;
			}
		}
		if(n-prev+1>max)
			max=n-prev+1;
		if(cnt==n)
			cout<<1<<endl;
		else if(cnt==0)
			cout<<n+1<<endl;
		else
		cout<<max<<endl;
	}
	

	return 0;
}