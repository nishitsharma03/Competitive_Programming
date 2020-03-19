#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(ll int i=a;i<b;i++)
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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n ,k;
	cin>>n>>k;
	ll int p[n];
	fab(0,n,i)
	{cin>>p[i];
		

	}
	//sort(tm,tm+n,greater<int>());
	ll int ans=0,ans2=1;
	fab(0,k,i)
	ans+=(n-i);
	ll int start;
	fab(0,n,i)
	{
		if(n-k+1<=p[i])
			{start=i;
		break;}
	}
	//cout<<start<<endl;

	ll int cnt=1;
	ll int kee=0;
	fab(start,n,i)
	{		
		//cout<<"i="<<i<<"\n";
		kee++;
		if(kee==k)
			break;
			cnt=1;
		ll int j=i+1;
		while(j<n&&p[j]<n-k+1&&kee<k)
		{
			cnt++;
			j++;
		}
		//cout<<"cnt="<<cnt<<endl;
		

		i=j-1;
		ans2=(ans2*cnt)%MOD;
		

	}

	cout<<ans<<" "<<ans2%MOD;
	cout<<endl;


	return 0;
}