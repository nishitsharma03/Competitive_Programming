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
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		if(a*n!=m*b)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		int shift;
		fab(1,m,i)
		{
			if(i*n%m==0)
			{
				shift=i;
				break;
			}
		}
		int inc=0;
		vector< vector<int> > ans(n,vector<int> (m,0));

		fab(0,n,i)
		{
			fab(0,a,j)
			ans[i][(j+inc)%m]=1;
			inc+=shift;

		}
		fab(0,n,i)
		{
			fab(0,m,j)
			{
				cout<<ans[i][j];
			}
			cout<<endl;
		}

	}
	

	return 0;
}