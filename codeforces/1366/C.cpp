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
vector< vector<int>  > final; 
int mat[35][35],vis[35][35];
int n,m;

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

		cin>>n>>m;
		
		fab(0,n,i)
		fab(0,m,j)
		{cin>>mat[i][j];
		vis[i][j]=0;}
		
		ll cnt[70][2];
		fab(0,70,i)
		{
			cnt[i][0]=0;
			cnt[i][1]=0;
		}
		fab(0,n,i)
		fab(0,m,j)
		cnt[i+j][mat[i][j]]++;

		ll ans=0;
		fab(0,n+m-1,i)
		{
			ll j=n+m-i-2;
			if(i>j)
				ans+=min(cnt[i][0]+cnt[j][0],cnt[i][1]+cnt[j][1]);



		}
		cout<<ans<<endl;


		
	

	
	}

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
	
}