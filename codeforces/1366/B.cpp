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
		ll n,m,x;
		cin>>n>>x>>m;
		pair<int,int> p={x,x};
		fab(0,m,i)
		{
			int a,b;
			cin>>a>>b;
			if((p.f>=a and p.f<=b) or (p.se>=a and p.se<=b))
			{

				p.f=min(p.f,a);
				p.se=max(p.se,b);
			}
		}
		cout<<p.se-p.f+1<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}