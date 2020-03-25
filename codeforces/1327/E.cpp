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
#define MOD 998244353 
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll int jawaab[200005];


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jawaab[0]=1;
    fab(1,200005,i)
    jawaab[i]=(jawaab[i-1]*10)%MOD;
	ll int n;
	cin>>n;
	ll int sum[n+1];
	fab(0,n+1,i)
	sum[i]=1;
	fab(1,n,i)
	{
		sum[i]=(10*(n-i-1)*81*jawaab[n-i-2])%MOD;
		//fab(0,n-i-2,_)
		// sum[i]=(sum[i]*10)%MOD;

		ll int res=(2*10*9*jawaab[n-i-1])%MOD;
		/*fab(0,n-i-1,_)
		
		res=(res*10)%MOD;*/
		sum[i]=(sum[i]+res)%MOD;
	//cout<<sum[i]<<" ii";
	}
	/*fab(1,n+1,i)
	{
		sum[n-i]+=(pow(10,i)%MOD);
	}*/
	fab(1,n,i)
	cout<<sum[i]<<" ";
	cout<<10;

	return 0;
}