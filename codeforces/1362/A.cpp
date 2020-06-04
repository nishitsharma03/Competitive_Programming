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
		ll a,b,cnt=0;
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		while(a*8<=b)
		{
			a=a*8;
			cnt++;
		}
		while(a*4<=b)
		{
			a=a*4;
			cnt++;

		}
		while(a*2<=b)
		{
			a=a*2;
			cnt++;
		}
		if(a!=b)
			cout<<-1<<endl;
		else
			cout<<cnt<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}