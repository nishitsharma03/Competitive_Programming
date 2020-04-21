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
		ll int n;
		cin>>n;
		if((n/2)%2==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		vector<int> o,e;
		int od=3;
		int ev=2;
		
		{
			fab(0,n/4,i)
			{
				o.pb(od);
				o.pb(od+2);
				e.pb(ev);
				e.pb(ev+4);
				ev=ev+6;
				od=ev+1;
			}
			cout<<"YES\n";
			fab(0,e.size(),i)
			cout<<e[i]<<" ";
			fab(0,o.size(),i)
			cout<<o[i]<<" ";
			cout<<endl;

		}
	}
	

	return 0;
}