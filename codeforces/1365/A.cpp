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
		int n,m;
		cin>>n>>m;
		int a[n][m];
		bool row[n]={0};
		bool col[m]={0};
		fab(0,n,i)
		fab(0,m,j)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				row[i]=true;
				col[j]=true;
			}

		}
		int cnt=0;
		fab(0,n,i)
		fab(0,m,j)
		{
			if(!row[i] and !col[j])
			{
				cnt++;
				row[i]=true;
				col[j]=true;
			}
		}
		if(cnt%2)
		{
			cout<<"Ashish\n";
		}
		else
			cout<<"Vivek\n";

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}