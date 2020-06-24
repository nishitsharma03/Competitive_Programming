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
		int n,m,k;
		cin>>n>>m>>k;
		ll a[n];
		fab(0,n,i)
		cin>>a[i];
		k=min(k,m-1);
		ll noncont=m-1-k;
		ll ans=1e9+435;
		ll final=0;
		fab(0,k+1,i)
		{
			ans=1e9;
			
			fab(0,noncont+1,j)
			{	
				//cout<<"j:"<<j<<" "<<a[i+j]<<" "<<a[n-m+i+j]<<endl;
				
		

				ans=min(ans,max(a[i+j],a[n-m+i+j]));

			}
			

			final=max(final,ans);
		}
		cout<<final<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}