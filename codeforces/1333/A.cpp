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
		ll int n,m;
		cin>>n>>m;
		char bw[n][m];
		fab(0,n,i)
		{
			fab(0,m,j)
			{if(i==0)
			{
				bw[i][j]='W';
			}
			else
				bw[i][j]='B';
		}
		}

		bw[0][m-1]='B';
		fab(0,n,i)
		{
			fab(0,m,j)
			cout<<bw[i][j];
			cout<<endl;
		}
	}
	

	return 0;
}