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
		ll int n0,n1,n2;
		cin>>n0>>n1>>n2;
		string ans="";
		if(n0>0)
		{ans+=string(n0+1,'0');
		}
		if(n2>0)
		{ans+=string(n2+1,'1');
}
			if(n2>0 and n0>0)
				n1--;
			if(n2==0  and n0>0 and n1>0)
				{ans+='1';
			n1--;
			}


			while(n1>0)
			{
				ans+='0';
				n1--;
				if(n1>0)
					{ans+='1';
				n1--;}
			}
			if(n2==0 and n0==0)
				{
					if(ans[ans.size()-1]=='0')
					ans+='1';
				else
					ans+='0';}
			cout<<ans<<endl;

	}
	

	return 0;
}