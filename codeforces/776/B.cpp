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
	//cin>>t;
	t=1;
	while(t--)
	{
		ll int n;

		cin>>n;
		if(n>2)
		cout<<2<<endl;
	else
		cout<<1<<endl;
		vector<int> v(n+2,-1);
		fab(2,n+2,i)
		{
			if(v[i]==-1)
			{
				int cnt=1;
				v[i]=1;

				for(int j=i+i;j<n+2;j+=i)
				{
					v[j]=2;
					
				}
			}
		}
		fab(2,n+2,i)
		cout<<v[i]<<" ";

	}
	

	return 0;
}