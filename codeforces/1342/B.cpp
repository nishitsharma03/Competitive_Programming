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
		string s;
		cin>>s;
		if(count(all(s),'0')==0 or count(all(s),'1')==0)
		{
			cout<<s<<endl;
			continue;
		}

		string ans="";
		ll int n=s.length();
		s+='a';
		fab(0,n,i)
		{
			ans+=s[i];
			if(s[i+1]==s[i])
			{
				
				if(s[i]=='0')
					ans+='1';
				else
					ans+='0';
			}
			

		}
		cout<<ans<<endl;
	}
	

	return 0;
}