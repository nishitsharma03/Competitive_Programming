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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll a[n];
		fab(0,n,i)
		cin>>a[i];
		vector<int> o,e;
		fab(0,n,i)
		{
			if(a[i]%2!=i%2)
			{
				if(i%2)
					o.pb(i);
				else
					e.pb(i);
			}
		}
		if(o.size()==e.size())
		{
			cout<<o.size()<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}