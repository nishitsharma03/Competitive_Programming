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
ll kadane(int n,ll a[])
{
	ll bigg=0;
	ll sum=0;
	fab(0,n-1,i)
	{
		sum+=(a[i]+a[i+1]);
		bigg=max(bigg,sum);
		if(sum<0)
			sum=0;
		i++;

	}
	sum=0;
	fab(1,n-1,i)
	{
		sum+=(a[i]+a[i+1]);
		bigg=max(bigg,sum);
		if(sum<0)
			sum=0;
		i++;
	}
	return bigg;
}
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
		ll sum=0;
		fab(0,n,i)
		{cin>>a[i];
		if(!(i&1))
		sum+=a[i];}
		fab(0,n,i)
		{
			if((i%2)==0)
				a[i]*=-1;
		}
		//cout<<"kadane:"<<kadane(n,a)<<endl;
		cout<<sum+kadane(n,a)<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}