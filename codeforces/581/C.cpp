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
 	int n,k;
	cin>>n>>k;
	int a[n];
	vector<int> v;
	int upg=0;

	int ans=0;
	fab(0,n,i)
	{
		cin>>a[i];
		ans+=a[i]/10;
		if(a[i]==100)
			continue;
		else
		{
			v.pb(10-a[i]%10);
			//v.pb(100-a[i]+v.back());
			 upg+=(10-((a[i])/10) -1);
		}
	}	
	sort(all(v));
	//cout<<upg<<endl;
	ll int sum=0;

	fab(0,v.size(),i)
	{
		sum+=v[i];
		if(sum<=k)
		{
			ans++;

		}
		else
			break;
	}

	if(sum<k)
	{
		int left=k-sum;
		ans+=min(upg,left/10);
	}
	cout<<ans;


	return 0;
}