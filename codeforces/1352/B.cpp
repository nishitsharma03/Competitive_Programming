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
		ll int n,k;
		cin>>n>>k;
		if(k>n)
		{
			cout<<"NO\n";
			continue;
		}
		if((n-k+1)%2==0)
		{
			if((n-(k-1)*2)%2 or (n-(k-1)*2)<=0)
				cout<<"NO\n";
			else
			{
				cout<<"YES\n";
				cout<<(n-(k-1)*2)<<" ";
				fab(1,k,i)
				cout<<2<<" ";
				cout<<endl;

			}

		}
		else
		{
			if((n-(k-1))%2 and (n-(k-1))>0)
			{cout<<"YES\n";
			cout<<n-k+1<<" ";
			fab(1,k,i)
			cout<<1<<" ";
			cout<<endl;}
			else
			{
				cout<<"NO\n";
			}
		}

	}
	

	return 0;
}