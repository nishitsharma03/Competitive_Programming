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
		ll int a,b,n;
		cin>>n>>a>>b;
		char c='a';
		string s="";
		fab(0,b,i)
		{
			s+=c;
			c++;
		}
		string rep=s;
		ll int cnt=n/b;
		fab(1,cnt,i)
		s+=rep;
		int i=0;
		while(s.size()<n)
		{
			s+=rep[i];
			i++;
		}
		cout<<s<<endl;

	}
	

	return 0;
}