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
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		vector<ll int> v;
		fab(0,n,i)
		{
			v.pb((a[i]%n+n)%n);
		}
		bool occ[4*n+1];
		fab(0,4*n+1,i)
		occ[i]=false;
		string ans="YES";
		fab(0,2*n+1,i)
		{
			if(occ[v[i%n]+i])
			{
				ans="NO";
				break;
			}
			occ[v[i%n]+i]=true;
		}
		cout<<ans<<endl;

	}
	

	return 0;
}