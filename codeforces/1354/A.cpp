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
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d>=c and b<a)
			cout<<-1<<endl;
		else
		{
			if(a-b<=0)
				cout<<b<<endl;
			else
			{
				ll div=abs(c-d);
				ll req=abs(b-a);
				ll tot=b+((req+div-1)/div)*c;
				cout<<tot<<endl;
			}
		}
	}
	

	return 0;
}