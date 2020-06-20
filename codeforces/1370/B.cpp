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
		ll n;
		cin>>n;
		ll a[2*n];
		vector<int> o,e;
		fab(0,2*n,i)
		{
			cin>>a[i];
			if(a[i]%2)
				o.pb(i+1);
			else
				e.pb(i+1);

		}
		int i=0;
		int cnt=0;
		while(o.size()>i+1 and cnt<n-1)
		{
			cout<<o[i]<<" "<<o[i+1]<<endl;
			cnt++;
			i+=2;

		}
		i=0;
		while(e.size()>i+1 and cnt<n-1)
		{
			cout<<e[i]<<" "<<e[i+1]<<endl;
			cnt++;
			i+=2;

		}
		//cout<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}