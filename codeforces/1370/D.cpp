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
int n,k;
ll a[200005];
bool subseqk(int x,bool chk)
{
	ll cnt=0;
	for(int i=0; i<n;i++)
	{
		if(chk==0)
		{
			cnt++;
			chk=1;
		}


		else
		{
		if(a[i]<=x)
		{
			cnt++;
			chk=0;
		}
		}
	}
	if(cnt>=k)
		return 1;
	return 0;

}
ll binsearch(ll low,ll high)
{
	while(high>low)
	{
	ll mid=(low+high)/2;
	if(subseqk(mid,0) or subseqk(mid,1))
	{
		high=mid;

	}
	else
		low=mid+1;
	
	}

	return low;
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   	cin>>n>>k;
   	fab(0,n,i)
   	cin>>a[i];
   	cout<<binsearch(1,1e9+1);
	



 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}