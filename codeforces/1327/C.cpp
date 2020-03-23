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
	int n,m,k;
	cin>>n>>m>>k;
	ll int p;
	fab(0,2*k,i)
	cin>>p;
	if(((n-1)*m+n-1+m-1)>2*n*m)
	{
		cout<<-1;
		return 0;
	}
	cout<<(n*m+n-1+m-2)<<endl;
	fab(1,n,i)
	cout<<"U";
	fab(0,m-1,i)
	cout<<"L";

	fab(0,n,i)
	{
		if(i%2)
		{
			fab(0,m-1,i)
			cout<<"L";
		}
		else
		{
			fab(0,m-1,i)
			cout<<"R";
		}
		if(i!=n-1)
		cout<<"D";
	}


	return 0;
}