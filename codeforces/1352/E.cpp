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
		ll int a[n],b[n];
		bool chk[n];
		map<ll int,ll int> m;
		fab(0,n,i)
		{cin>>a[i];
		b[i]=a[i];
		chk[i]=false;
		m[a[i]]++;
		}
		sort(b,b+n);
		//map<ll int,ll int> m;
		ll int cnt=0;
		fab(0,n-1,i)
		{
			ll int sum=a[i];
			fab(i+1,n,j)
			{
				sum+=a[j];
				if(sum>b[n-1])
					break;
				auto tm=lower_bound(b,b+n,sum);
				if(tm!=b+n and *tm==sum and chk[tm-b]==false  )
					{chk[tm-b]=true;
					cnt+=m[sum];}
					//cout<<sum<<" "<<cnt<<endl;
			}
		}
		
		cout<<cnt<<endl;
	}
	

	return 0;
}